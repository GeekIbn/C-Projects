#include<stdio.h>
void main()
{
	void len(char *p);
	char *p,
		temp[100];
	p=temp; 
	scanf("%s",p);
	len(p);
	p=temp;
	main();
}
void len(char *p)
{
	int i,
		j;
	j=0;
	for(i=0;i<10;i++)
	{
		if(p[i]=='\0')
		{
			break;
		}
		else
		{
			j++;
		}
	}
	printf("The length of the phrase is: %d",j);
}
