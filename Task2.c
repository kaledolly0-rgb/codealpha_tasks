#include<stdio.h>
void add(int a1[10][10],int a2[10][10],int s1)
{
	int i,j,a3[3][3],sum=0;
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
		
			a3[i][j]=a1[i][j]+a2[i][j];
			
		printf("%d\t",a3[i][j]);
		}
		printf("\n");
	}
}
void sub(int a1[10][10],int a2[10][10],int s1)
{
	int i,j,a3[3][3],sum=0;
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
		
			a3[i][j]=a1[i][j]-a2[i][j];
			
		printf("%d\t",a3[i][j]);
		}
		printf("\n");
	}
}
void transpose(int a1[10][10],int s1)
{
	int i,j;
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
			printf("%d\t",a1[i][j]);
		}
		printf("\n");
	}
	printf("Transposed matrix=\n");
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
			printf("%d\t",a1[j][i]);
		}
		printf("\n");
	}
}
void mul(int a1[10][10],int a2[10][10],int s1)
{
	int i,j,k,sum=0,a3[10][10];
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
			sum=0;
			for(k=0;k<s1;k++)
			{
				sum=a1[j][k]*a2[k][j]	+sum;	
			}
			a3[i][j]=sum;		
		}		
	}
	printf("ultipicationof matrix\n");
		for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
			printf("%d\t",a3[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int a1[10][10],a2[10][10],s1,ch,i,j;
	printf("Enter the size of array1 and array2");
	scanf("%d",&s1);
	printf("enter arr1 elements");
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
			scanf("%d",&a1[i][j]);
		}
	}	
	printf("enter arr2 elements");
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
			scanf("%d",&a2[i][j]);
		}
	}
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s1;j++)
		{
			printf("%d\t",a2[i][j]);
		}
	}
	printf("\nSelect one option to perform matrix operation\n1.Addtion\n2.Subtraction\n3.Multiplication\n4.Transpose");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			add(a1,a2,s1);
			break;
		case 2:
			sub(a1,a2,s1);
			break;
		case 3:
			mul(a1,a2,s1);
			
			break;
		case 4:
			transpose(a1,s1);
			break;
	}
	return 0;
}
