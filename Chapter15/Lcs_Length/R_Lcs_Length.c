#include<stdio.h>
int lcs_length(int X[],int i,int a,int Y[],int j,int b)
{
	 int length;
	 int length1,length2;
	 length=0;
	 if(i==a||j==b)
	{
		return length;
	}
	if(X[i]==Y[i])
	{
		length++;
		length+=lcs_length(X,i+1,a,Y,j+1,b);
	}
	else
	{
		length1=lcs_length(X,i+1,a,Y,j,b);
		length2=lcs_length(X,i,a,Y,j+1,b);
		if(length1>length2)
		{
			length+=length1;
		}
		else
		{
			length+=length2;
		}
	}
	return length;
}
void main()
{
	int X[10];
	int Y[10];
	X[0]='A';
	X[1]='C';
	X[2]='C';
	X[3]='T';
	X[4]='C';
	X[5]='G';
	X[6]='C';
	X[7]='C';
	X[8]='G';
	X[9]='A';
	Y[0]='A';
	Y[1]='C';
	Y[2]='C';
	Y[3]='T';
	Y[4]='C';
	Y[5]='T';
	Y[6]='T';
	Y[7]='C';
	Y[8]='G';
	Y[9]='A';
	int length;
	length=lcs_length(X,0,10,Y,0,10);
	printf("%d\n",length);
}
