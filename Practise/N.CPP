#include<iostream.h>
#include<conio.h>
int main()
{
int n,m,i;
clrscr();
cout<<"enter number you to reverse from to from:";
cin>>n>>m;
for(i=m; n>=m; n--)
{
cout<<n<<"\n";
}
getch();
return 0;
}