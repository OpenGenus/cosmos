
#include <bits/stdc++.h>
using namespace std;


bool is_plaind(string word)
{
	int n = word.length();
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);

	for (int i = 0; i < n; i++,n--)
	if (word.at(i) != word.at(n - 1))
		return false;	
	return true;
}

int func_to_count_plaindrome_words(string sentance)
{		

	sentance = sentance+ " ";

	string single_word = "";
	int ct = 0;
	for (int i = 0; i < sentance.length(); i++)
	{
		char single_charracter = sentance.at(i);

		if (single_charracter != ' ')
			single_word = single_word + single_charracter;
		else {
			if (is_plaind(single_word))
				ct++;
			single_word = "";
		}
	}
	
	return ct;
}

int main()
{
	
	string sentance;
    std::getline(cin,sentance);
    int n;
    cin>>n;
    cout<<func_to_count_plaindrome_words(sentance);
}


