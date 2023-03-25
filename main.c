/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define LENGTH 1024
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
*/
#include<myHeader.h>

int main()
{
	char lines[LENGTH];
	FILE *fp=fopen("data.cdr","r");
	DATA *user=(DATA *)malloc(100000 * sizeof(DATA));	
	int n=0;
//	char ty[]=","; 
	int i,j=0,count=0;
	int msisdn;
	int flag=0;
	char tokens[8][LENGTH];
	if(fp == NULL)
	{
		printf("Error occured in opening File");
		return 0;
	}

	while(fgets(lines,LENGTH,fp)!=NULL)
	{
		
		if(n>100000)
		{
			printf("maximum no of user data entered");
			break;
		}

		for(i=0;lines[i]!='\0';i++)
		{
			if(lines[i]=='|')
			{
				tokens[count][j]='\0';
				count++;
				j=0;
				continue;
			}
			
			tokens[count][j]=lines[i];
			j++;
		
		}


			 strcpy(user[n].msisdn,tokens[0]);
			 strcpy(user[n].opname,tokens[1]);
			 strcpy(user[n].opmmc,tokens[2]);
			 strcpy(user[n].calltype,tokens[3]);
			 strcpy(user[n].duration,tokens[4]);
			 strcpy(user[n].download,tokens[5]);
			 strcpy(user[n].upload,tokens[6]);
			 strcpy(user[n].thirdparmsisdn,tokens[7]);
			 strcpy(user[n].thirdparmmc,tokens[8]);

				
	count=0;
	j=0;
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

	free(fp);
	free(user);

	return 0;

}
