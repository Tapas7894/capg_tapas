#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define length 1024
struct data
{
	char msisdn[20];
	char opname[20];
	char opmmc[20];
       	char calltype[10];
	char duration[10];
	char download[10];
	char upload[10];
	char thirdparmsisdn[10];
	char thirdparmmc[10];

}typedef DATA;


int main()
{
	char lines[length];
	FILE *fp=fopen("data.cdr","r");
	char *tokens;
	DATA user[1000000000000];
	int pos;
	int n=0;
	if(fp == NULL)
	{
		printf("Error occured in opening File");
		return 0;
	}

	while(fgets(lines,length,fp)!=NULL)
	{
		tokens=strtok(lines,"|");
		pos=1;
		while(tokens)
		{
			switch(pos)
			{
				case 1: strcpy(user[n].msisdn,tokens);
				break;

				case 2: strcpy(user[n].opname,tokens);
				break;

				case 3: strcpy(user[n].opmmc,tokens);
			        break;

				case 4: strcpy(user[n].calltype,tokens);
			 	break;
				
				case 5: strcpy(user[n].duration,tokens);
				break;
				
				case 6: strcpy(user[n].download,tokens);
				break;
				
				case 7: strcpy(user[n].upload,tokens);
				break;

				case 8: strcpy(user[n].thirdparmsisdn,tokens);
				break;

				case 9: strcpy(user[n].thirdparmmc,tokens);
				break;

				default: printf("failed");		
			}
			pos++;
			tokens=strtok(NULL,"|");
			
		}
	n++;
	
	}
	printf("\n%d",n);
	return 0;

}
