#include <bits/stdc++.h>
using namespace std;
void linearInsert(int k,int linear[],int m,int &lincoll);
int linearSearch(int k,int linear[],int m,int &lincoll);
void linearDelete(int k,int linear[],int m,int &lincoll);
int quadSearch(int k,int quad[],int m);
void quadInsert(int k,int quad[],int m,int &quadcoll);
void quadDelete(int k,int quad[],int m);
void doubleInsert(int k,int doub[],int m,int &doublecoll);
void doubleDelete(int k,int doub[],int m);
int doubleSearch(int k,int doub[],int m);
int main()
{
	cout<<setprecision(2)<<fixed;//to show 2 decimal places
	int n,m;
	cin>>n>>m;string s;int k;
	int doub[m];
	int linear[m];int lincoll=0;int quadcoll=0;int quad[m];
	int doublecoll=0;
	//lincoll, doublecoll,quadcoll store the number of collissions in linear probing,quad probing,double hashing
	for(int i=0;i<m;i++)
	{
		doub[i]=-9999;//-9999 means NIL in this program
		quad[i]=-9999;
		linear[i]=-9999;
	}
	int denom=0;//denom is the number of elements inserted
	while(n--)
	{
		cin>>s;
		cin>>k;
		if(s=="INSERT")
		{
			denom++;
			//Insert in all three tables
			linearInsert(k,linear,m,lincoll);
			quadInsert(k,quad,m,quadcoll);
			doubleInsert(k,doub,m,doublecoll);
		}
		else if(s=="SEARCH")
		{
			//search function returns -1 if not found else returns index
			int flag=linearSearch(k,linear,m,lincoll);
			if(flag!=-1)
				cout<<k<<" FOUND AT INDEX "<<flag<<" IN LINEAR PROBING\n";
			else
				cout<<k<<" IS NOT PRESENT IN LINEAR PROBING\n";
			flag=quadSearch(k,quad,m);
			if(flag!=-1)
				cout<<k<<" FOUND AT INDEX "<<flag<<" IN QUADRATIC PROBING\n";
			else
				cout<<k<<" IS NOT PRESENT IN QUADRATIC PROBING\n";
			flag=doubleSearch(k,doub,m);
			if(flag!=-1)
				cout<<k<<" FOUND AT INDEX "<<flag<<" IN DOUBLE HASHING\n";
			else
				cout<<k<<" IS NOT PRESENT IN DOUBLE HASHING\n";
		}
		else if(s=="DELETE")
		{
			//Delete in all three lists
			linearDelete(k,linear,m,lincoll);
			quadDelete(k,quad,m);
			doubleDelete(k,doub,m);
		}
		else
		{
			cout<<"Wrong input\n";
			n++;
		}
	}
	//Printing
	cout<<"TOTAL NUMBER OF COLLISIONS IN LINEAR PROBING "<<lincoll<<endl;
	cout<<"TOTAL NUMBER OF COLLISIONS IN QUADRATIC PROBING "<<quadcoll<<endl;
	cout<<"TOTAL NUMBER OF COLLISIONS IN DYNAMIC PROBING "<<doublecoll<<endl;
	cout<<"AVERAGE NUMBER OF REHASING REQUIRED IS "<<lincoll*1.0/denom<<" IN LINEAR PROBING\n";
	cout<<"AVERAGE NUMBER OF REHASING REQUIRED IS "<<quadcoll*1.0/denom<<" IN QUADRATIC PROBING\n";
	cout<<"AVERAGE NUMBER OF REHASING REQUIRED IS "<<doublecoll*1.0/denom<<" IN DOUBLE HASHING\n";
}
void linearInsert(int k,int linear[],int m,int &lincoll)
{
	int i=0;
	do
		{
			int j=(k%m+i)%m;//Linear hash function h'(k)=k%m
			if(linear[j]==-9999 || linear[j]==-999999)
			{//-999999 value stored in table when some element deleted
				linear[j]=k;
				cout<<k<<" INSERTED AT INDEX "<<j<<" IN LINEAR PROBING\n";
				lincoll+=i;//before returning to main(),update number of collisions
				return;
			}
			else
				i++;//incrementing i for rehashing
		} while (i<m);
	lincoll+=m-1;//if it comes out,then number of rehashings not equal to i because i was incremented in end and then no rehashing happened as loop exits
	cout<<k<<" CANNOT BE INSERTED IN LINEAR PROBING\n";	
}
int linearSearch(int k,int linear[],int m,int &lincoll)
{
	int i=0;
	do
		{
			int j=(k%m+i)%m;//Linear hash function h'(k)=k%m
			if(linear[j]==k)
			{
				//returning index at where it was found
				return j;
			}
			else if(linear[j]==-9999)
			{
				//if we encountered NIL then no need to search further
				break;
			}
			else
				i++;//incrementing i for rehashing
		} while (i<m);
	return -1;//if not found return -1	
}
void linearDelete(int k,int linear[],int m,int &lincoll)
{
	int ind=linearSearch(k,linear,m,lincoll);//search for element to be deleted
	if(ind==-1)//not found
	{
		cout<<k<<" CANNOT BE DELETED IN LINEAR PROBING\n";
	}
	else//found
	{
		cout<<k<<" DELETED FROM INDEX "<<ind<<" IN LINEAR PROBING\n";
		linear[ind]=-999999;//changed to value -999999
	}
}
void quadInsert(int k,int quad[],int m,int &quadcoll)
{
	int i=0;
	do
		{
			int j=(k%m+i+3*i*i)%m;//Quadratic probing h(k)=(h'(k)+c1*i+c2*i*i)
			if(quad[j]==-9999 || quad[j]==-999999)
			{//-999999 value stored in table when some element deleted
				quad[j]=k;
				cout<<k<<" INSERTED AT INDEX "<<j<<" IN QUADRATIC PROBING\n";
				quadcoll+=i;
				return;
			}
			else
				i++;//incrementing i for rehashing
		} while (i<m);
	quadcoll+=m-1;//if it comes out,then number of rehashings not equal to i because i was incremented in end and then no rehashing happened as loop exits
	cout<<k<<" CANNOT BE INSERTED IN QUADRATIC PROBING\n";	
}
int quadSearch(int k,int quad[],int m)
{
	int i=0;
	do
		{
			int j=(k%m+i+3*i*i)%m;//Quadratic probing h(k)=(h'(k)+c1*i+c2*i*i)
			if(quad[j]==k)
			{
				return j;//returning index at where it was found
			}
			else if(quad[j]==-9999)//if we encountered NIL then no need to search further
			{
				break;//not found
			}
			else
				i++;
		} while (i<m);
	return -1;//not found	
}
void quadDelete(int k,int quad[],int m)
{
	int ind=quadSearch(k,quad,m);//search for element to be deleted
	if(ind==-1)//not found
	{
		cout<<k<<" CANNOT BE DELETED IN QUADRATIC PROBING\n";
	}
	else
	{
		cout<<k<<" DELETED FROM INDEX "<<ind<<" IN QUADRATIC PROBING\n";
		quad[ind]=-999999;//changed to value -999999
	}
}
void doubleInsert(int k,int doub[],int m,int &doublecoll)
{
	int i=0;
	do
		{
			int j=(k%m+i*(1+k%(m-1)))%m;//Double hashing h(k)=(h'(k)+i*h2(k));
			if(doub[j]==-9999 || doub[j]==-999999)
			{
				doub[j]=k;
				cout<<k<<" INSERTED AT INDEX "<<j<<" IN DOUBLE HASHING\n";
				doublecoll+=i;
				return;
			}
			else
				i++;
		} while (i<m);
	doublecoll+=m-1;
	cout<<k<<" CANNOT BE INSERTED IN DOUBLE HASHING\n";	
}
int doubleSearch(int k,int doub[],int m)
{
	int i=0;
	do
		{
			int j=(k%m+i*(1+k%(m-1)))%m;
			if(doub[j]==k)
			{
				return j;
			}
			else if(doub[j]==-9999)
			{
				break;
			}
			else
				i++;
		} while (i<m);
	return -1;	
}
void doubleDelete(int k,int doub[],int m)
{
	int ind=doubleSearch(k,doub,m);
	if(ind==-1)
	{
		cout<<k<<" CANNOT BE DELETED IN DOUBLE HASHING\n";
	}
	else
	{
		cout<<k<<" DELETED FROM INDEX "<<ind<<" IN DOUBLE HASHING\n";
		doub[ind]=-999999;
	}
}