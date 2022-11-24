//Q  >> WAP to show as many concepts of Object oriented programing as you can....
#include<iostream>
using namespace std;

class sum1	
{
	public:
	int a,b,c;
 	sum1()
 	{
 	   a=0;b=0;c=0;
	}
	sum1(int x,int y,int z)
	{
		a=x;b=y;c=z;
	}	
	~sum1()
	{
		
	}
	int claculate()
	{
		return (a+b+c);
	}
	virtual void display()
	{
		cout<<"\n"<<a<<"  "<<b<<"  "<<c<<"\nSum 1= "<<sum1::claculate()<<"\n";
	}
};


class product : public sum1
{
	public:
		int p,q,r;
		int pro;
		product ()
		{
			p=0;q=0;r=0;
		}
		product(int s,int t,int u,int x,int y,int z):sum1(x,y,z)
		{
			p=s;q=t;r=u;
		}
		int calculate()
		{	
			int s1=sum1::claculate();
			int s2=p+q+r;
			pro=s1*s2;
			return pro;
		}
		void display()
		{
			cout<<"\n"<<a<<"  "<<b<<"  "<<c<<"\nSum 1= "<<sum1::claculate()<<"\n\n";
			cout<<"\n"<<p<<"  "<<q<<"  "<<r<<"\nSum 1= "<<(p+q+r)<<"\n\n";
			cout<<"Product of Sums = "<<pro<<"\n\n";
		}			
};


class sum2:public sum1
{
	public:
		int d,e,f,sum;
	sum2()
	{
		d=0;e=0;f=0,sum=0;
	}
	sum2(int x,int  y,int z,int s,int t,int u):sum1(s,t,u)
	{
		d=x;e=y;f=z;
	}
	void display()
	{
		cout<<"\n"<<a<<"  "<<b<<"  "<<c<<"  "<<d<<"  "<<e<<"  "<<f<<"\nSum = "<<sum<<"\n";
	}
	int calculate()
	{
		int s=sum1::claculate();
		sum=s+d+e+f;
		return sum;
	}
};

class overload :public product,  public sum2
{
	private :
		int res;
	public:
		
		overload()
		{
			
		}
		overload(int s,int t,int u,int x,int y,int z,int a1,int a2,int a3,int a4,int a5,int a6):product(s,t,u,x,y,z),sum2(a1,a2,a3,a4,a5,a6)
		{
				
		}
		int operator > (overload ob1)
		{
			if(res>ob1.res)
			{
				cout <<"\n\nResult from calculation of class product is greater.\n\n";	
				return 1;
			}
			else 
			{
				cout <<"\n\nResult from calculation of class product is greater.\n\n";	
				return 0;
			}	
		}
		void set(int i)
		{
			res=i;
		}
		
		
		template <typename Template> 
		void result(overload ob1,overload ob2,Template c)
		{
			if(c==0)
			cout<<" Result after final calculation : "<<(ob2.res*ob1.res);
			else
			cout<<" Result after final calculation : "<<(ob1.res/ob2.res);
		}

		
};



int main()
{
	int a1,a2,a3,b1,b2,b3,c1,c2,c3;
	cout<<"Enter 9 integers : \n";
	cin>>a1>>a2>>a3>>b1>>b2>>b3>>c1>>c2>>c3 ;
	
	overload ob1(a1,a2,a3,b1,b2,b3,b1,b2,b3,c1,c2,c3);
	ob1.product::calculate();
	ob1.product::display();
	
//	sum2 ob2(b1,b2,b3,c1,c2,c3);
	ob1.sum2::calculate();
	ob1.sum2::display();
	
	overload ob3;
	overload ob4;
	ob3.set(ob1.pro);
	ob4.set(ob1.sum);
	
	int c = (ob3>ob4);
	overload ob5;
	ob5.result<int>(ob3,ob4,c);
	
	return 0;
}




/*
Enter 9 integers :
1
2
3
4
5
6
7
8
9

4  5  6
Sum 1= 15


1  2  3
Sum 1= 6

Product of Sums = 90


7  8  9  4  5  6
Sum = 39


Result from calculation of class product is greater.

 Result after final calculation : 2
--------------------------------
Process exited after 5.514 seconds with return value 0
Press any key to continue . . .

*/

