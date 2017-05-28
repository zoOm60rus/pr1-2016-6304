#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>

char* FindString(char* path) {

    FILE* file = fopen(path, "r");
    char* string = (char*)malloc(1000*sizeof(char));
    fgets(string, 1000, file);
    return(string);
}

int recTreePathFinding (char* path, int* iterator, char** primal_array) {

   DIR* directory = opendir(path);
   struct dirent* de = (struct dirent*)malloc(sizeof(struct dirent));
   de = readdir(directory);

    if(directory != NULL){
        while (de) {
            if((de->d_type == DT_REG)&&(strcmp(de->d_name, "a.out")!=0)&&(strcmp(de->d_name, "main.c")!=0)) {
                int backup = strlen(path);
                strcat(path, "/");
                strcat(path, de->d_name);
                primal_array[*iterator] = (char*) malloc(1000*sizeof(char));
                primal_array[*iterator] = FindString(path);
                (*iterator)++;

                path[backup]='\0';
            }
            if ((de->d_type == DT_DIR)&&(strcmp(de->d_name, ".")!=0)&&(strcmp(de->d_name, "..")!=0)){

            int backup = strlen(path);
            strcat(path, "/");
            strcat(path, de->d_name);

            recTreePathFinding(path, iterator, primal_array);
            path[backup] = '\0';
            }
            de = readdir(directory);
        }
    }

    return 0;
}

int comparator (const void* a, const void* b) {

    return (*(int*)a - *(int*)b);
}

int* set_relativity (int* array, int* copy_of_array, int size){
    int* index = (int*)malloc(size*sizeof(int));
    int i, j;
                                                                                                                   
for(i=0;i<size; i++) {
    j=0;
    while (array[i]!=copy_of_array[j])
        j++;
    index[j] = i;
    }
    return (index);
}


int* sort_index (int* array, int size) {
    int* index = (int*)malloc(size*sizeof(int));
    int i;

    int* copy = (int*)malloc(size*sizeof(int));
    for(i=0; i<size; i++)
        copy[i] = array[i];

    qsort (copy, size, sizeof(int), comparator);
    index = set_relativity(array, copy, size);

   // free(copy);
    return (index);
}

int take_number (char* line) {

 char* number = (char*)malloc(strlen(line)*sizeof(char));
 number = strtok(line, " ");

 return(atoi(number));
}

char* take_str (char* line) {

    int i = 0;

    while (line[i]!=' ')
    i++;

    return (line + i + 1);

}

int main() {
    char** primal_array = (char**)malloc(1000*sizeof(char*));

    int i = 0;
    char path[10000] = ".";

    int size = 0;
    recTreePathFinding(path, &size, primal_array);

    char** array_of_str = (char**)malloc(size*sizeof(char*));
    int* array_of_num = (int*)malloc(size*sizeof(int));

    printf("all strings sucsessfully found\n");
    for(i=0; i<size; i++){
    array_of_str[i] = take_str(primal_array[i]);
    array_of_num[i] = take_number(primal_array[i]);
    }

    int* index = (int*)malloc(size*sizeof(int));
    index = sort_index(array_of_num, size);

    int j;
    for(i=0;i<size; i++) {
    j = index[i];
    printf("%s", array_of_str[j]);
    }

   free(index); free(array_of_num);
   for (i=0; i<size; i++){
   free(primal_array[i]);
   free(array_of_str[i]);
   }
   free(array_of_str);
   free(primal_array);
  return 0;
}

