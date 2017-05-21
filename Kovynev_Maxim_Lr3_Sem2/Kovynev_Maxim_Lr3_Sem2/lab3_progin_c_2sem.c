#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


long long int readFile(char* current_path, char* prev_path)
{
	int value = 0;
	long long int result = 0;
	int mathOperation;
	FILE* fileTXT = fopen(current_path, "r");

	if (!strcmp(prev_path, "mul"))
	{
		result = 1;
		mathOperation = 1;
	}
	else if (!strcmp(prev_path, "add"))
	{
		result = 0;
		mathOperation = 0;
	}

	while (!feof(fileTXT))
	{
		fscanf(fileTXT, "%d ", &value);
		if (mathOperation)
		{
			result *= value;
		}
		else
		{
			result += value;
		}

	}

	printf("Result: %lld\t File: %s\n",result, current_path);
	fclose(fileTXT);
	return result;

}


long long int searchDir(const char* path, char* prev_path)
{
	long long int result = 0;
	int mathOperation = 0;
	if (!strcmp(prev_path, "mul"))
	{
		result = 1;
		mathOperation = 1;
	}
	else if (!strcmp(prev_path, "add"))
	{
		result = 0;
		mathOperation = 0;
	}

	char current_path[10000];
	strcpy(current_path, path);
	DIR *dir = opendir(current_path);
	struct  dirent *de = readdir(dir);
	if (dir)
	{
		while (de)
		{
			int path_len = strlen(current_path);
			strcat(current_path, "/");
			strcat(current_path, de->d_name);
			if (de->d_type == DT_DIR && strcmp(".", de->d_name) && strcmp("..", de->d_name))
			{

				if (mathOperation)
				{
					result *= searchDir(current_path, de->d_name);
				}
				else
				{
					result += searchDir(current_path, de->d_name);
				}

			}
			else if (strstr(de->d_name, ".txt") && (de->d_type == 8))
			{
				if (mathOperation)
				{
					result *= readFile(current_path, prev_path);
				}
				else
				{
					result += readFile(current_path, prev_path);
				}

			}
			current_path[path_len] = '\0';
			de = readdir(dir);
		}
	}
	closedir(dir);
	return result;

}

int main()
{

	printf("\nTotal result: %lld\n\n", searchDir(".", ""));
	return 0;
}
