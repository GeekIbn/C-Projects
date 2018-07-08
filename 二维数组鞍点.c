#include<stdio.h>
int preserve[3];
int probe()
{
	int arr[3][4]={{10,9,16,21},{5,6,4,20},{3,8,2,22}},
		i,
		j,
		k,
		l,
		row,
		colum, 
		mrow, 
		(*p)[4]; 
	int max=0;
	int min=100;
	int num=0;
	p=arr;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(*(*(p+i)+j)>max)
			{
				max=*(*(p+i)+j);
				row=i;
				colum=j;
			}
		}
		for(k=0;k<3;k++)
		{
			if(*(*(p+k)+colum)<min)
			{
				min=*(*(p+k)+colum);
				mrow=k;
			}
		}
		if(mrow=row)
		{
			preserve[num]=*(*(p+i)+colum);
			num++;
		}
	}
	for(l=0;l<3;l++)
	{
		printf("%d ",preserve[l]);
	}
	return 0;
}
int main()
{
	probe();
	return 0;
}
