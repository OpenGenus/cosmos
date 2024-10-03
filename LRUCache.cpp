#include <iostream>
#include <map>
using namespace std;

int LRUcachehits=0;
int LRUcachemiss=0;
int LRUcacheused=0;
bool LRUcachefull=false;
int FIFOcacheused=0;
int FIFOcachehits=0;
int FIFOcachemiss=0;
bool FIFOcachefull=false;

struct dll{
	int value;
	struct dll* left;
	struct dll* right;
};

map<int,dll*> mymapLRU;
map<int,dll*> mymapFIFO;

void make_hash(map<int,dll*> &mymap,int key,dll* address){
	mymap[key]=address;
}

void add_to_cache(int key,map<int,dll*> &mymap,dll** head,dll** end,int* cused){
	//This function adds nodes to the duoubly linked list
	dll* temp=*head;
	if((*cused)==0)
	{
		(*head)->value=key;
		(*head)->left=NULL;
		(*head)->right=NULL;
		*end=*head;
		make_hash(mymap,key,*head);
	}
	else
	{
		dll* temp2=new(dll);
		temp->left=temp2;
		temp2->right=temp;
		temp2->left=NULL;
		temp2->value=key;
		*head=temp2;
		make_hash(mymap,key,*head);
	}
}

void LRUCache(int x,map<int,dll*> &mymapLRU,dll** head,dll** end,int csize){
	if(mymapLRU.find(x)==mymapLRU.end())
		{
			//current key or random number is not available in the current hash map
			FILE *pfile;
			pfile=fopen("log_LRUCache.txt","a");
			fprintf(pfile,"Cache Miss for key = %d\n",x);
			LRUcachemiss++;
			fclose(pfile);
			if(!LRUcachefull)
			{
				//If the cache capacity is not fully utilized, more nodes are added
				add_to_cache(x,mymapLRU,head,end,&LRUcacheused);
				FILE *pfile;
				pfile=fopen("log_LRUCache.txt","a");
				fprintf(pfile,"Key Added to cache !\n");
				fclose(pfile);
				LRUcacheused++;
				if(LRUcacheused==csize)
					LRUcachefull=true;
			}
			else
			{
				//If the cache is fully utilized, the least used element or element at last is removed
				mymapLRU.erase(mymapLRU.find((*end)->value));
				dll* temp=(*end)->left;
				temp->right=NULL;
				delete *end;
				*end=temp;
				dll* temp2=new(dll);
				temp2->value=x;
				temp2->right=*head;
				temp2->left=NULL;
				(*head)->left=temp2;
				*head=temp2;
				make_hash(mymapLRU,x,*head);	
			}
			
		}
	else
		{
			//Its a Cache Hit! Below code updates the position of the current key to be the head
			FILE *pfile;
			pfile=fopen("log_LRUCache.txt","a");
			fprintf(pfile,"Cache Hit for key = %d!\n",x);
			LRUcachehits++;
			fprintf(pfile,"Total Cache Hits = %d\n",LRUcachehits);
			fclose(pfile);
			dll* temp;
			temp=mymapLRU.find(x)->second;
			if(temp!=*head)
				{
					dll* left=temp->left;
					dll* right=temp->right;
					temp->right=*head;
					temp->left=NULL;
					(*head)->left=temp;
					*head=temp;
					left->right=right;
					if(right!=NULL)
					right->left=left;
					else
						*end=left;
				}
		}
}

void FIFOCache(int x,map<int,dll*> &mymapFIFO,dll** head,dll** end,int csize){
	if(mymapFIFO.find(x)==mymapFIFO.end())
		{
			FILE *pfile;
			pfile=fopen("log_FIFOCache.txt","a");
			fprintf(pfile,"Cache Miss for key = %d\n",x);
			FIFOcachemiss++;
			fclose(pfile);
			if(!FIFOcachefull)
			{
				add_to_cache(x,mymapFIFO,head,end,&FIFOcacheused);
				FILE *pfile;
				pfile=fopen("log_FIFOCache.txt","a");
				fprintf(pfile,"Key Added to cache !\n");
				fclose(pfile);
				FIFOcacheused++;
				if(FIFOcacheused==csize)
					FIFOcachefull=true;
			}
			else
			{
				mymapFIFO.erase(mymapFIFO.find((*end)->value));
				dll* temp=(*end)->left;
				temp->right=NULL;
				delete *end;
				*end=temp;
				dll* temp2=new(dll);
				temp2->value=x;
				temp2->right=*head;
				temp2->left=NULL;
				(*head)->left=temp2;
				*head=temp2;
				make_hash(mymapFIFO,x,*head);	
			}
			
		}
	else
		{
			FILE *pfile;
			pfile=fopen("log_FIFOCache.txt","a");
			fprintf(pfile,"Cache Hit for key = %d!\n",x);
			FIFOcachehits++;
			fprintf(pfile,"Total Cache Hits = %d\n",FIFOcachehits);
			fclose(pfile);
		}
}

void printdll(dll* head){
	dll* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->value<<" ";
		temp=temp->right;
	}
	cout<<endl;
}

void testcache(int csize,int totrand){
	//srand ( time(NULL) );
	dll* headLRU=new(dll);
	dll* endLRU;
	dll* headFIFO=new(dll);
	dll* endFIFO;
	cout<<"    # Testing for Cache Size " <<csize<< " and Random Data of "<<totrand<<" integers!"<<endl;

	FILE *pfile;
	pfile=fopen("log_LRUCache.txt","a");
	fprintf(pfile,"____Cache Size %d | Random Data %d integers____\n",csize,totrand);
	fclose(pfile);

	pfile=fopen("log_FIFOCache.txt","a");
	fprintf(pfile,"____Cache Size %d | Random Data %d integers____\n",csize,totrand);
	fclose(pfile);

	for(int i=0;i<totrand;i++)
	{
		int a=rand()%100+1;
		LRUCache(a,mymapLRU,&headLRU,&endLRU,csize);
		FIFOCache(a,mymapFIFO,&headFIFO,&endFIFO,csize);
	}
	cout<<"          Total LRUCache Hits : "<<LRUcachehits<<endl;
	cout<<"          Total LRUCache Miss : "<<LRUcachemiss<<endl;
	cout<<"          Total FIFOCache Hits : "<<FIFOcachehits<<endl;
	cout<<"          Total FIFOCache Miss : "<<FIFOcachemiss<<endl;
	cout<<endl;
}

void autotest(int csize,int totrand){
	LRUcachehits=0;
	LRUcachemiss=0;
	LRUcacheused=0;
	LRUcachefull=false;
	FIFOcacheused=0;
	FIFOcachehits=0;
	FIFOcachemiss=0;
	FIFOcachefull=false;
	mymapLRU.clear();
	mymapFIFO.clear();
	testcache(csize,totrand);
}

int main()
{
	cout<<"Enter number of tests you want to perform : ";
	int t=0;
	cin>>t;
	int totrandarray[]={100,250,500,1000,5000,10000,15000};
	int csizearray[]={4,8,16,32,64};
	for(int j=0;j<t;j++)
	{
		cout<<"Test : #"<<j+1<<" : "<<endl;
		for (int k=0;k<5;k++)
		{
			for(int n=0;n<7;n++)
				{
					autotest(csizearray[k],totrandarray[n]);
				}
		}
	}
	return 0;
}
