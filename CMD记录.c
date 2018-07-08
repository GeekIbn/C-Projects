#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof (struct journal)

struct journal
{
	char ch;
	struct journal *next;
}jour;

struct date
{
	char date[10];
	int words;
	struct date *next;
}dt;

int main()
{
	int pages=0;
	int option;
	FILE *fp;
	fp=fopen("pages.dat","rb");
	fread(&pages,sizeof(pages),1,fp);
	fclose(fp);
	
	struct journal *head;
	head=(struct journal *)malloc(LEN);
	
	int write(struct journal *p,struct date dt,int pages); 
	void read(int n);
	
	printf("==============================\n\nChoose the option to continue:\n1.Write\n2.Read\n\n==============================\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			pages=write(head,dt,pages); 
			break;
		case 2:
			read(pages);
			break;
	}
	
	fp=fopen("pages.dat","wb");
	fwrite(&pages,sizeof(pages),1,fp);
	fclose(fp);
}

int write(struct journal *p,struct date dt,int pages)
{
	 FILE *fp;
	 fp=fopen("log.dat","ab");
	 printf("\n");
 	 printf("Enter the log:\n");
	 do
	 {
	 	p->next=(struct journal *)malloc(LEN);	 	
	 	p=p->next;
		p->ch=getchar();
		fputc(p->ch,fp);
	 	dt.words++;
	 }while(p->ch!=' ');
	 dt.words--;
	 fclose(fp);
	 fp=fopen("index.dat","ab");
	 printf("Enter the date:\n");
	 scanf("%s",dt.date);
	 fwrite(&dt,sizeof((struct date)dt),1,fp);
	 fclose(fp);
	 pages++;
	 printf("\n");
	 
	 return (pages);
}

void read(int n)
{
	char ch;
	int i=0;
	int count=0;
	
	FILE *fp_index;
	FILE *fp_log;
	fp_index=fopen("index.dat","rb");
	fp_log=fopen("log.dat","rb");
 	printf("\n");
 	
 	while(n>=1)
 	{
 	 	fread(&dt,sizeof((struct date)dt),1,fp_index);
		while(count<=dt.words)
		{
			ch=fgetc(fp_log);
			printf("%c",ch);
			count++;
		}
		printf("\n");
		printf("%120s\n",dt.date);
		count=0;
		dt.words=0;
		n--;
	}
 	printf("\n");
 	
	fclose(fp_index);
	fclose(fp_log);
}
