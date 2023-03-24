#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define length 1024
typedef struct data
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

}DATA;


int main()
{
	char lines[length];
	FILE *fp=fopen("data.cdr","r");
	char *tokens;
	DATA *user=(DATA *)malloc(100000 * sizeof(DATA));	
	int pos;
	int n=0;
	int msisdn;
	int flag=0;
	if(fp == NULL)
	{
		printf("Error occured in opening File");
		return 0;
	}

	while(fgets(lines,length,fp)!=NULL)
	{
		tokens=strtok(lines,"|");
		pos=1;
		if(n>100000)
		{
			printf("maximum no of user data entered");
			break;
		}
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
	printf("\n%d\n",n);

	printf("enter the MSISDN\n");
	scanf("%d",&msisdn);
	


	for(int i=0;i<n;i++)
	{
		if(atoi(user[i].msisdn)==msisdn)
		{
		printf("MSISDN         :%s\n",user[i].msisdn);		
		printf("OPNAME         :%s\n",user[i].opname);
		printf("OPMMC          :%s\n",user[i].opmmc);
		printf("CALLTYPE       :%s\n",user[i].calltype);
		printf("DURATION       :%s\n",user[i].duration);
		printf("DOWNLOAD       :%s\n",user[i].download);
		printf("UPLOAD         :%s\n",user[i].upload);
		printf("THIRDPARMSISDN :%s\n",user[i].thirdparmsisdn);
		printf("THIRDPARMMC    :%s\n",user[i].thirdparmmc);

		printf("\n\n");
		flag=1;
		break;
		}
	}
	if(flag==0)
		printf("user data not found\n");
	return 0;

}
