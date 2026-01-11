#include<stdio.h>
int add(int n1,int n2)
{
	return n1+n2;
}
int div(int n1,int n2)
{
	return n1/n2;
}
int sub(int n1,int n2)
{
	return n1-n2;
}
int mul(int n1,int n2)
{
	return n1*n2;
}

int main()
{
	int n1,n2,ch,re=1;
	do
	{
		printf("Welcome to calculator\nEnter two numbers");
		scanf("%d%d",&n1,&n2);
		printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter the choice");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:printf("\nAddtion=%d",add(n1,n2));
		break;
		case 2:printf("\nSubtraction=%d",sub(n1,n2));
		break;
		case 3:printf("\nMultiplication=%d",mul(n1,n2));
		break;
		case 4:printf("\nDivision=%d",div(n1,n2));
		break;
		default:
			printf("Default choice");
			break;
	}
	printf("\nDo you want to perform operation again press 1");
	scanf("%d",&re);

	}
	while(re==1);
	
	
	return 0;
}
