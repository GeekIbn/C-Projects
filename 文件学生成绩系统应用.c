#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct student)
typedef struct student
{
	int num;
	char name[10];
	float grade[3];
	float aver;
}   stu;

	stu arr[50];
	FILE *fp,*fpsign;
	int n,
		times;
	
void main()
{
	int N;
	void input();
	void sort();
	void insert();
	void read();
	void search();
	void del();
	while(times!=1)
	{
		int i;
		fp=fopen("info.dat","rb");
		if(ferror(fp)!=0)
		{
			printf("Error\n");
		}
		fpsign=fopen("infosign.dat","rb");
		if(ferror(fpsign)!=0)
		{
			printf("Error\n");
		}
		fread(&n,sizeof(n),1,fpsign);
		for(i=0;i<=n;i++)
		{
			fread(&arr[i],LEN,1,fp);
		}
		fclose(fp);
		fclose(fpsign);
		times=1;
	}
	printf("Choose a mode to operate:\n1. Input\n2. Sort\n3. Insert\n4. Search\n5. Delete\n6. Read\n0. Exit\n");
	scanf("%d",&N);
	printf("\n");
	switch(N)
	{
		case 1:
			printf("Inputing data...:\n");
			input();
			break;
		case 2:
			printf("Sorting data...:\n");
			sort();
			break;
		case 3:
			printf("Inserting:\n");
			insert();
			break;
		case 4:
			printf("Searching...\n");
			search();
			break;
		case 5:
			printf("Deleting...:\n");
			del();
			break;
		case 6:
			printf("Reading:\n");
			read();
			break;
		case 0:
			exit(0);
	}
	main();	
}
void input()
{
	int i;
	fp=fopen("info.dat","wb");
	if(ferror(fp)!=0) 
	{
		printf("Error\n");
		exit(0);
	}
	fpsign=fopen("infosign.dat","wb");
	if(ferror(fpsign)!=0)
	{
		printf("Error\n");
	}
	printf("Enter num name and 3 lessons' grades:\n");
	for(i=0;i<50;i++)
	{
		scanf("%d %s %f %f %f",&arr[i].num,arr[i].name,&arr[i].grade[0],&arr[i].grade[1],&arr[i].grade[2]);
		if(strcmp(arr[i].name,"END")==0)
		{
			printf("End loading\n\n");
			break;
		}
		n=i;
		arr[i].aver=(arr[i].grade[0]+arr[i].grade[1]+arr[i].grade[2])/3;
		fwrite(&arr[i],LEN,1,fp);
	}
	fwrite(&n,sizeof(n),1,fpsign);
	fclose(fpsign);
	fclose(fp);
	for(i=0;i<=n;i++)
	{
		printf("NO:%d num:%d name:%-6s grade:%-6.2f %-6.2f %-6.2f aver:%-6.2f\n",i+1,arr[i].num,arr[i].name,arr[i].grade[0],arr[i].grade[1],arr[i].grade[2],arr[i].aver);
	}
	printf("----------------------------------------------------------------\n");
	printf("\n");
}
void sort()
{
	stu sort;
	int i,
		j;
	for(i=1;i<=n;i++)
	{
		for(j=n;j>=i;j--)
		{
			if(arr[j].aver>arr[j-1].aver)
			{
				sort=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=sort;
			}
		}
	}
	fp=fopen("info.dat","wb");
	for(i=0;i<=n;i++)
	{
		fwrite(&arr[i],LEN,1,fp);
		printf("NO:%d num:%d name:%-6s grade:%-6.2f %-6.2f %-6.2f aver:%-6.2f\n",i+1,arr[i].num,arr[i].name,arr[i].grade[0],arr[i].grade[1],arr[i].grade[2],arr[i].aver);
	}
	fclose(fp);
	printf("----------------------------------------------------------------\n");
	printf("\n");
}
void insert()
{
	int i;
	fp=fopen("info.dat","ab");
	if(ferror(fp)!=0) 
	{
		printf("Error\n");
		exit(0);
	}
	fpsign=fopen("infosign.dat","wb");
	if(ferror(fpsign)!=0)
	{
		printf("Error\n");
	}
	printf("Enter num name and 3 lessons' grades:\n");
	for(i=n+1;i<100;i++)
	{
		scanf("%d %s %f %f %f",&arr[i].num,arr[i].name,&arr[i].grade[0],&arr[i].grade[1],&arr[i].grade[2]);
		if(strcmp(arr[i].name,"END")==0)
		{
			printf("End loading\n\n");
			break;
		}
		n=i;
		arr[i].aver=(arr[i].grade[0]+arr[i].grade[1]+arr[i].grade[2])/3;
		fwrite(&arr[i],LEN,1,fp);
	}
	fwrite(&n,sizeof(n),1,fpsign);
	sort();
	fclose(fpsign);
	fclose(fp);
}
void read()
{
	int i=0;
	fp=fopen("info.dat","rb");
	if(ferror(fp)!=0)
	{
		printf("Error\n");
	}
	for(i=0;i<=n;i++)
	{
		fread(&arr[i],LEN,1,fp);
		printf("NO:%d num:%d name:%-6s grade:%-6.2f %-6.2f %-6.2f aver:%-6.2f\n",i+1,arr[i].num,arr[i].name,arr[i].grade[0],arr[i].grade[1],arr[i].grade[2],arr[i].aver);
	}
	fclose(fp);
	printf("Storge:\n");
	int used;
	used=(n+1)/50*50;
	printf("|");
	for(i=0;i<50;i++)
	{
		if(i<=used)
		printf("-");
		else
		printf(" ");
	}
	printf("|\n");
	printf("----------------------------------------------------------------\n");
	printf("\n");
}
void search()
{
	int i;
	char name[10];
	printf("Enter student's name to searching:\n");
	scanf("%s",name);
	for(i=0;i<=n;i++)
	{
		if(strcmp(arr[i].name,name)==0)
		break;
	}
	printf("The infomation of %s is:\n",name);
	printf("num:%d name:%-6s grade:%-6.2f %-6.2f %-6.2f aver:%-6.2f\n",arr[i].num,arr[i].name,arr[i].grade[0],arr[i].grade[1],arr[i].grade[2],arr[i].aver);
	printf("\n");
}
void del()
{
	int i,
		j;
	char name[10];
	printf("Enter the name of stu you wanna delete:\n");
	scanf("%s",name);
	for(i=0;i<=n;i++)
	{
		if(strcmp(arr[i].name,name)==0)
		break;
	}
	for(j=i+1;j<=n;j++)
	{
		arr[j-1]=arr[j];
	}
	n--;
	fp=fopen("info.dat","wb");
	if(ferror(fp)!=0) 
	{
		printf("Error\n");
		exit(0);
	}
	fpsign=fopen("infosign.dat","wb");
	if(ferror(fpsign)!=0)
	{
		printf("Error\n");
	}
	for(i=0;i<=n;i++)
	{
		fwrite(&arr[i],LEN,1,fp);
	}
	fwrite(&n,sizeof(n),1,fpsign);
	fclose(fp);
	fclose(fpsign);
	sort();
}
