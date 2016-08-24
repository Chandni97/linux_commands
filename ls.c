#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

struct dirent *rdir;

int main(int argc, char* argv[])
{
	DIR *cdir;
	cdir = opendir(".");

	if(cdir==NULL)
	{
		printf("ERROR OPENING THE DIRECTORY");
		exit(0);
	}

	if(argc == 1)
	{
		while((rdir=readdir(cdir)) != NULL )
		{
			if(rdir->d_name[0]!='.')
				printf("%s \n" , rdir->d_name);
		}
	}
	else
	{
		if(strcmp(argv[1],"-a")==0)
			{
				while((rdir=readdir(cdir)) != NULL )
					printf("%s \n" , rdir->d_name);
			}

		if(strcmp(argv[1][0], '*')==0)
		{
			// while((rdir=readdir(cdir)) != NULL )
			// {
			// 	if(rdir->d_name)
			// }
		}
	}

	//printf("%s\n", argv[1]);

	return 0;

}