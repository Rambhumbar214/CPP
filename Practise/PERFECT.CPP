#include<iostream.h>
#include<conio.h>
int main()
{
int i,div,sum=0,num;
clrscr();
cout<<"Enter the number";
cin>>num;
for(i=1;i<num;i++)
{
	div=num%i;
	if(div==0)

	 sum=sum+i;

}
	if(sum==num)
	{
		cout<<"The number is perfect";
	}
	else
	{
		cout<<"The number is not perfect";
	}

getch();
return 0;

}