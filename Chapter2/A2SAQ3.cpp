#include<iostream.h>
#include<conio.h>
class district
{
int district_code,area_sqft,pop,lr;
char name[20];
public:
void accept()
{
  cout<<"enter the details:";
  cout<<"district code";
  cin>>district_code;
  cout<<"district Name:";
  cin.ignore(10000,'\n');
  cin.getline(name,sizeof(name));
  cout<<"area in sqft";
  cin>>area_sqft;
  cout<<"district Population";
  cin>>pop;
  cout<<"district literacy rate";
  cin>>lr;
  cout<<"\n details have beeen entered";
}
void display()
{
  cout<<"Entered details are";
  cout<<"district code"<<district_code;
  cout<<"district name"<<name;
  cout<<"area in sqft"<<area_sqft;
  cout<<"district Population"<<pop;
  cout<<"deistrict literacy rate"<<lr;
}
void hlrate(district D[],int n)
{
  int maxx.pos=0;
  maxx=D[0].lr;
  for(int i=0; i<n; i++)
    {
      if(maxx<D[i].lr)
      {
        maxx=D[i].lr;
        pos=i;
      }
    }
  cout<<"details of district having highest literacy rate is:";
  D[pos].display();
}
void lpop(district d[],int n)
{
  int minn, pos1=0;
  minn=d[0].pop;
  for(int i=0;i<n; i++)
    {
      if(minn>d[i].pop)
      {
        minn=d[i].pop;
        pos1=i;
      }
    }
  cout<<"details of district having least population is:";
  d[pos1].display();
}
};
int main()
{
int i,n,ch;
  district d[20];
  cout<<"how many details you want to enterd(max10 details can be entered)";
  cin>>n;
  while(1)
    {
      cout<<"\n\n----MENU----\n 1.Accept\n 2. Display \n 3.Display details of district having highest literacy rate \n 4.Display details of district having least population. \n 5.exit\n";
      cout<<"enter your choice:";
      cin>>ch;
      switch(ch)
        {
          case 1:
          for(i=0;i<n; i++)
            {
              D[i].accept();
            }
          break;
          case 2:
          for(i=0;i<n;i++)
            {
              d[i].display();
            }
          break;
          case 3:
          d[i].hlrate(d,n);
          break;
          case 4:
            {
              d[i].lpop(d,n);
            }
          break;
          case 5:
            {
              exit(1);
            }
          default:
          cout<<"menu parat vach neet";
          break;
        }
    }
  
}
