// part of cosmos by opengenus foundation

#include <iostream>
#include <vector>
using namespace std;

vector<int> naive_search(string pattern, string text)
{
	vector<int> indeces;
	int plen = pattern.length();
	int tlen = text.length();

	int i,j;

	for(i=0; i<tlen-plen+1; i++)
	{
		for(j=0; j<plen; j++)
		{
			if (text[i+j] != pattern[j])
				break;
		}
		if (j==plen-1)
			indeces.push_back(i);
	}

	return indeces;
}

int main()
{
	cout<<"Total Indeces Found"<<endl;
	// test case

	cout<<naive_search("this", "The this pointer is pointer accessible only within nonstatic members of the class").size()<<endl;


	return 0;

}
