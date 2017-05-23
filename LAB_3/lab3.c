#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

// ---------------------------------------------
// List of strings to store the path to Minotaur
// ---------------------------------------------
// Represents one item of the list
typedef struct string
{
  char value[1024]; // Lenght of one path
} string;

// Represents list of strings
typedef struct list
{
  string item[200]; // Maximum amount of items in the list according to the requirments of the task
  int count;
} list;

// Add new item to the end of the list
add(list* mylist, char* string)
{
  strcpy(mylist->item[mylist->count].value, string);
  mylist->count++;
}

// Remove last item from the list
remove_last(list* mylist)
{
  mylist->count--;
}

// ---------------------------------------------

// Looking for file with given filename in specific
// directory including subdirectories and return path to the file
// Return value: 1 if found, 0 otherwise
int find_file(char* dir, char* file, char* path)
{
    int result = 0;

    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
// Open given directory
    if((dp = opendir(dir)) == NULL)
    {
        printf("Cannot open directory: %s\n", dir);
        return result;
    }

// Change current working directory to the given one
    chdir(dir);

// Read items from the directory
    while((entry = readdir(dp)) != NULL) 
    {
    // Get additional information about current item      
        lstat(entry->d_name, &statbuf);
        // Check if the found item is a directory        
        if( S_ISDIR(statbuf.st_mode) ) 
        {
            // Found a directory, but ignore current(.) and parent(..) directories
            if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
            {
              continue;
            }
             // Recurse at the level of found directory
            result = find_file(entry->d_name, file, path);
            if (result == 1)
            {
            // If found, run away
              break;
            }
        }
        else // Assume if it's not directory, it is a file
        {
            // Check if the found file is the required one
            if (strcmp(entry->d_name, file) == 0)
            {
              // Build the path to the file 
              char cwd[1024];
              getcwd(cwd, sizeof(cwd)); // Get current working directory 
              strcat(path, cwd);
              strcat(path, "/"); // Add '/'
              strcat(path, entry->d_name); // Add filename

              result = 1;
              // If found, run away
              break;
            } 
        }
    }
    chdir(".."); // Change current working directory back to parent one
    closedir(dp); // Close directory

    return result;
}

// Looking for the Minotaur and return steps to him
// Return value: 1 if found, 0 otherwise
int find_minotaur(char* dir, char* file, list* steps)
{
    int result = 0;

    // Try to find file in the given directory and subdirectories
    char path[1024] = "";
    if (find_file(dir, file, path) == 0)
    {
      // If not found, report the error and stop the program
      printf("Cannot find file: %s\n", file);
      return result;
    }

    // If found, add current file to the list of steps
    add(steps, path);

    // Open found file for reading
    FILE* fp = NULL;
    fp = fopen(path,"r");

    // Read from file line by line
    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
      // We found the Minotaur!
      if (strcmp(line, "Minotaur\n") == 0) // fgets reads lines including trailing '\n'
      {
        result = 1;
        break;
      }
      // Deadlock found
      if (strcmp(line, "Deadlock\n") == 0)
      {
        // Since Deadlock is found, remove last steps from the list
        remove_last(steps);
        break;
      }

      // If not 'Minotaur' nor 'Deadlock', assume it is 'include', try to parse
      char next_file[256] = "";
      int n = sscanf(line,"@include %s", next_file);
      if (n == 0)
      {
        printf("Cannot read file: %s\n", path);
        result = 0;
        return result;
      }
      // Managed to parse included file, try to find Minotaur there...
      result = find_minotaur(dir, next_file, steps);
      if (result == 1)
      {
        // If found, run away
        break;
      }
    }
    // Close the file
    fclose(fp);
    return result;   
}

int main(int argc, char** argv)
{
// Use input argument as starting directory if provided, otherwise use 'root'
  char dir[256] = "root";
  if (argc >= 2)
  {
    strcpy(dir, argv[1]);
  }

// Allocate list of steps to store path to Minotaur
  list steps;
  steps.count = 0;

// Find path to Minotaur
  int result = find_minotaur(dir, "file.txt", &steps);
  if (result == 0)
  {
    printf("Cannot find the Minotaur\n");
    return 0;
  }

// If path is found, print it out
  int i = 0;
  for (i=0;i<steps.count;i++)
  {
    printf("%s\n",steps.item[i].value);
  }

  return 0;
}
