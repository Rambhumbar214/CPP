#include<iostream.h>
#include<conio.h>
int main()
{
int a,b,choice;
int add,sub,multi,div;
clrscr();
cout<<"enter two number ";
cin>>a>>b;
cout<<"choose any one of the following";
cout<<"1+\n";
cout<<"2-\n";
cout<<"3*\n";
cout<<"4/\n";
cin>> choice;
switch(choice)
{
case 1:
add=a+b;
cout<<add;
break;
case 2:
sub=a-b;
cout<<sub;
break;
case 3:
multi=a*b;
cout<<multi;
break;
case 4:
div=a/b;
cout<<div ;
break;
 default :
cout<< "unvalid";
break;
}
getch();
return 0;
}