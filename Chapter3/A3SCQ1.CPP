 #include<iostream.h>
 #include<conio.h>
 #include<string.h>
 class worker{

 char worker_name[20];
 int No_of_days_work;
 float pay_rate,salary;
 char w[20];
 int nd;
 float p,s;
	public:

	worker()
	{
	strcpy(worker_name,"Ganesh");
	No_of_days_work=30;
	pay_rate=500;
	salary=0;
	}
	worker(const char w_n[20],int nd,float pr)
	{
       strcpy(worker_name,w_n);
	No_of_days_work=nd;
	pay_rate=pr;
	}
   worker(const worker &w) {
	strcpy(worker_name, w.worker_name);
	No_of_days_work = w.No_of_days_work;
	pay_rate = w.pay_rate;
	salary = w.salary;
    }
	void calculate()
	{
	salary=No_of_days_work*pay_rate;
	}

	void display()
	{
	cout<<"worker name:"<<worker_name<<endl;
	cout<<"No_of_days_work"<<No_of_days_work<<endl;
	cout<<"pay rate"<<pay_rate<<endl;
	cout<<"salary"<<salary<<endl;
	}
 };
 void main()
 {
 char name[20];
 int no_d;
 float part,sal;
 clrscr();
 cout<<"enter worker name:"<<endl;
 cin>>name;
 cout<<"enter no_of_days:" <<endl;
 cin>>no_d;
 cout<<"enter pay rate:"<<endl;
 cin>>part;
 worker w1;
 worker w2(name,no_d,part);
 worker w3 = w2;


 w1.calculate();
 w2.calculate();
 w3.calculate();

 w1.display();
 w2.display();
 w3.display();

       getch();
 }