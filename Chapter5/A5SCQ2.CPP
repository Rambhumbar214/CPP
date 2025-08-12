#include<iostream.h>
#include<conio.h>
class DM;
class DB{
	float feet,inches;

	public :

	void input()
	{
	cout<<"enter distance in feet and inches";
	cin>>feet>>inches;
	}

	void display()
	{
	cout<<feet<<inches;
	}

	friend void add(DM,DB);
};

class DM{
	float m,cm;

	public :

	void input()
	{
	cout<<"enter distance in m and cm";
	cin>>m>>cm;
	}

	void display()
	{
	cout<<m<<cm;
	}

	friend void add(DM,DB)
};

void add(DM dm,DB db)
{

int totalCMDM=(dm.m*100)+dm.cm;

int totalinchesDb=(db.feet*12)+db.inches;

int totalcmdb= totalinchesDb *2.54;

int totalCM=totalCMDM + totalcmdb;

int meters=totalCM / 100;

int centimeters=totalCM % 100;

cout<<"total Distance:"<<meters<<"meters and "<<centimeters;

}

int main()
{
clrscr();

DM dm1;
DB db1;

dm1.input();
db1.input();

cout<<"DM object Distance";

dm1.display();
cout<<endl;

cout<<"DB object Distance:";
db1.display();
cout<<endl;

add(dm1,db1);

getch();
return 0;
}