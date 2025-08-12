#include<iostream.h>
#include<conio.h>
int main()
{
cout<<"enter 1st distance";
cout<<"enter feet";
  cin>>d1.feet;
cout<<"enter inch";
  cin>>d1.inch;
cout<<"enter information of 2nd distance";
cout<<"enter feet";
  cin>>d2.feet;
cout<<"enter inch";
  cin>>d2.inch;
  sum.feet=d1.feet+d2.feet;
  sum.inch=d1.inch+d2.inch;
  if(sum.inch>12)
  {
    int extra=sum.inch/12;
    sum.feet+=extra;
    sum.inch-+(extra*12);
  }
  cout<<"sum of distance=";
  cout<<sum.feet;
  cout<<"sum of inch=";
  cout<<sum.inch;
  return 0;
}
