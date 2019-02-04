#include<iostream>
using namespace std;

int gcd(int a,int b)
{
if(a==0)
  return b;
return gcd(b%a,a);
}

int power(int x,int y,int m)
{
if(y==1)
  return x;
int p = power(x,y/2,m)%m;
p= (p*p)%m;
if(y%2==0)
  return p;
return ((x*p)%m);
}

int tot(int n)
{
int i,cnt =0;
for(i=1;i<n;i++)
  {
  if(gcd(n,i) ==1)
    cnt++;
  }
return cnt;
}

void fun(int a,int m)
{
if(gcd(a,m)!=1)
        cout<<"Multiplicative Inverse doesn't exist.";
else
        cout<<"Inverse is "<<power(a,tot(m)-1,m)<<endl;
}

int main()
{
int a,b;
cout<<"Enter the numbers:";
cin>>a>>b;
fun(a,b);
return 0;
}
