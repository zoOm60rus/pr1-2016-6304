#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COUNT_OF_NAMES 200
#define MAX_LENGTH_OF_PATH 1000

int list_dir(const char *newcur_path,const char *rootdir, char* nameOfFile, char **nameOfPath);
void printPath();
int findTheSize(char *current_path);
char *readTheFile(char *current_path, int size);

void printPath()
{
    char **nameOfPath=(char**)malloc(MAX_COUNT_OF_NAMES*sizeof(char*));
    int heightOfPath=0;
    char *rootFile="file.txt";
    heightOfPath=list_dir("root","root",rootFile,nameOfPath);
    for(int i=heightOfPath-1; i>=0; i--)
    {
        printf("%s\n",nameOfPath[i]);
        free(nameOfPath[i]);
    }

    free(nameOfPath);
    return;
}

int findTheSize(char *current_path){
    FILE *file=fopen(current_path,"rt");
    fseek(file,0, SEEK_END);
    int sizeOfFile = ftell(file);
    fseek(file,0, SEEK_SET);
    fclose(file);
    return sizeOfFile;
}

char *readTheFile(char *current_path, int size)
{
    FILE *file=fopen(current_path,"rt");
    char c;
    char *str = (char*)malloc(sizeof(char)*size);
    int i=0;
    while(fscanf(file,"%c", &c)>0) str[i++]=c;
    fclose(file);
    return str;
}

int list_dir(const char *newcur_path,const char *rootdir, char* nameOfFile, char **nameOfPath)
{
    char current_path[MAX_LENGTH_OF_PATH];
    int heightOfPath=0;

    strcpy(current_path,newcur_path);
    DIR *dir = opendir(current_path);
    struct dirent *de = readdir(dir);
    
    if(dir){

         while(de){

            int lenOfPath = strlen(current_path);
	    strcat(current_path,"/");
	    strcat(current_path,de->d_name);

	    if(de->d_type==DT_REG &&
	      !strcmp(de->d_name,nameOfFile))
	    {
		int sizeOfFile=findTheSize(current_path);
		char *str = (char*)malloc(sizeof(char)*sizeOfFile);
		str=readTheFile(current_path, sizeOfFile);    
		char stringForToken[MAX_COUNT_OF_NAMES-1][sizeOfFile];
                int j=0;
		char *BrokenStr=strtok(str," \n");
	        while(BrokenStr)
	        {
		        strcpy(stringForToken[j], BrokenStr);
		        j++;
		        BrokenStr=strtok(NULL," \n");
	        }
		int lengthOfStr=strlen(str);
		free(str);
		for(j=0;j<lengthOfStr;j++){
			if(!strcmp(stringForToken[j],"@include"));
			else if(!strcmp(stringForToken[j],"Deadlock")) return heightOfPath;
			else if(!strcmp(stringForToken[j],"Minotaur"))
			{
				nameOfPath[heightOfPath]=(char*)malloc(sizeof(char)*MAX_LENGTH_OF_PATH);
				strcpy(nameOfPath[heightOfPath],current_path);
				heightOfPath=1;
				return heightOfPath;
			}
			else{
				heightOfPath=list_dir(rootdir,rootdir,stringForToken[j],nameOfPath);//root=start
				if(heightOfPath!=0)
				{
					nameOfPath[heightOfPath]=(char*)malloc(sizeof(char)*MAX_LENGTH_OF_PATH);
					strcpy(nameOfPath[heightOfPath],current_path);
					heightOfPath++;
					return heightOfPath;
			        }
			    }
			}
	      }

         if (de->d_type == DT_DIR &&
            0!=strcmp(".",de->d_name) && 
            0!=strcmp("..",de->d_name))
               heightOfPath=list_dir(current_path,rootdir,nameOfFile,nameOfPath);
        if (heightOfPath!=0)
            return heightOfPath;
              
        current_path[lenOfPath] = '\0';
        de = readdir(dir);
    }
    closedir(dir);
    }
    return heightOfPath;
}


int main()
{
    printPath();
    return 0;
}
