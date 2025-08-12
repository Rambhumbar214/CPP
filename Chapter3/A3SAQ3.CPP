#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>


class mobile{
		int m_id;
		char m_name[30];
		float m_price;
		public:
		mobile(int id,const char name[30],float price)
		{
		  m_id=id;
		 // m_name[30]=name[30];
		  strcpy(m_name,name);
		  m_price=price;
		}
		void putdata()
		{
		cout<<"mobile id:"<<m_id<<endl;
		cout<<"mobile name:"<<m_name<<endl;
		cout<<"mobile price:"<<setprecision(2)<<m_price<<endl;
		}

};
void main()
{
int mid;
char mname[30];
float mprice;
clrscr();
cout<<"enter mobile id:" <<endl;
cin>>mid;
cout<<"enter mobile name:" <<endl;
cin>>mname;
cout<<"enter mobile price:"<<endl;
cin>>mprice;

mobile m1(mid,mname,mprice);
m1.putdata();
getch();
}