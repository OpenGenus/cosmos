import java.util.*;
import java.io.InputStreamReader;
import java.io.BufferedReader;
/*
	@author Kanika Saini (https://github.com/kanikasaini)
*/
class mystack implements Cloneable //stack class
{
	public int[] s=new int[36000];
	public int top;
	public mystack()
	{
		top=-1;		
	}	
	public void push(int x)
	{
		top+=1;
		s[top]=x;
	}	
	public int pop()
	{
		int temp=s[top];
		top-=1;
		return temp;
	}
	int seek()
	{
		return s[top];
	}
	public void display()
	{
		while(top!=-1)
			System.out.print(this.pop());
			System.out.println();
	}
	
	public Object clone() throws CloneNotSupportedException 
	{
		return super.clone();
	}
}
class FastFactorialUsingStack
{
public static void main(String[] args) throws Exception
{

    BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
	int n= Integer.parseInt(inp.readLine()); //input n
	long current= System.currentTimeMillis();
	mystack f= new mystack();
	f.push(1);
	mystack z= new mystack();
	for(int i=1; i<=n; i++)
	{
		int num= i;
		while (num!=0)
		{
			z.push(num%10);
			num=num/10;
		}

		f=mult(z,f);
	}
	f.display();// prints nth factorial
}

public static mystack add(mystack a1, mystack b1)
{
	mystack sum= new mystack();
	int t, c=0;
	a1 = reverse(a1);
	b1= reverse(b1);
	while(a1.top!=-1 && b1.top!=-1)
	{
		t=a1.pop() + b1.pop() + c;
		sum.push(t%10);
		c= (int)(t/10);
	}
	while (a1.top>-1)
		{	
			t=a1.pop()+c;
			sum.push(t%10);
			c=(int)(t/10);
		}
	while (b1.top>-1)
		{
			t=b1.pop()+c;
            sum.push(t%10);
            c=(int)(t/10);
		}
	if (c>0)
		sum.push(c);
	return sum;
}
public static mystack mult(mystack z, mystack f) throws Exception
{
	mystack dup= new mystack();
	mystack temp = new mystack();
	z=reverse(z);
	f=reverse(f);
	int p=0;
	int l;
	int m;
	int i=0;
	while(z.top!=-1)
	{
		m=z.pop();
		l=0;
		dup=(mystack)f.clone();
		mystack prod= new mystack();
		for (int j=0;j<i; j++)
            prod.push(0);
		while(dup.top!=-1)
		{
			p=m*dup.pop() + l;
			prod.push(p%10);
			l=(int)p/10;
		}
		if (l>0)	
			prod.push(l);	
		temp= add(temp, prod);
		i+=1;
	}
	return temp;
}
public static mystack reverse(mystack a)
{
	mystack rev= new mystack();
	while (a.top!=-1)
	{
		rev.push(a.pop());
	}
	return rev;
}
}
