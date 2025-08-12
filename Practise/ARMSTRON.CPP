#include<iostream.h>
#include<conio.h>
int main()
{
int num,orinum,rem,result=0;
clrscr();
cout<<"enter three digit number:";
cin>>num;
orinum=num;
while(orinum!=0)
{
	rem=orinum%10;
	result+=rem*rem*rem;
	orinum/=10;
}
if(result==num)
	{
	cout<<num<<"is armstrong";
	}
else
	{
	cout<<num<<"is not armstrong";
	}
getch();
return 0;
}