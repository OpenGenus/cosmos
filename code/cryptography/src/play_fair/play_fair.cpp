#include<bits/stdc++.h>
using namespace std;

//owned by cosmos 


// store the coordinate of matrix
class cood{
	public:
		int i;
		int j;
};

class PlayFair{
	private:
//		store the message and key
		string key,msg;
	public:
		PlayFair(string k,string m){
			key = k;
			msg = m;
		}
//		print and check the matrix we will get
		void print(vector<string> v){
			for(int i=0;i<v.size();i++){
				cout<<v[i]<<"\n";
			}
		}
//		remove space and convert to lowercase alphabet from string
		string clean_text(string str){
			string res = "";
			for(int i=0;i<str.length();i++){
				if(str[i]!=' '){
					res+=tolower(str[i]);
				}
			}
			return res;
		}
//		make the string even length, If it is 
		string check(string str){
			if(str.length()%2!=0){
				str+='z';
				return str;	
			}
			return str;
		}
//		remove the duplicate character from string 
		string rem_dup(string str){
			set<char> st;
			string res = "";
			for(int i=0;i<str.length();i++){
				if(st.find(str[i]) == st.end()){
					st.insert(str[i]);
					res+=str[i];
				}
			}
			return res;
		}
//		Genrate table from input string
//		eg:
//			a,b,c,d,e,
//			f,g,h,j,k,
//			l,m,n,o,p,
//			q,r,s,t,u,
//			v,w,x,y,z
		vector<string> genrate(string key){
			char tb[5][5];
			int i=0,j=0;
			set<char> st(key.begin(),key.end());
			for(int k = 0;k<key.length();k++){
				tb[i][j] = key[k];
				j++;
				if(j==5){
					j=0;
					i++;
				}
			}
			for(int k=0;k<26;k++){
				char val = (k+97);
				if(st.find(val)==st.end() && val!='i'){
					tb[i][j] = val;
					j++;
					if(j==5){
						j=0;
						i++;
					}
				}
			}
			
//			store the table in the format of string
			vector<string> table;
			for(int i=0;i<5;i++){
				string tle="";
				for(int j=0;j<5;j++){
					tle+=tb[i][j];
				}
				table.push_back(tle);
			}
			return table;
			
		}

//		find the positon of requested character and return it
		vector<cood> find_index(vector<string> tb,char a,char b){
			vector<cood> cd;
			if(a=='i'){
				a= 'j';
			}
			if(b=='i'){
				b= 'j';
			}
			for(int i=0;i<tb.size();i++){
				for(int j=0;j<tb[i].size();j++){
					if(tb[i][j]==a){
						cd.push_back({i,j});
					}
					else if(tb[i][j]==b){
						cd.push_back({i,j});
					}
				}
			}
			return cd;
		}
		
//		encrypt the data using genrate table using 3 conditions
		void encrypt(){
//			preprocess string
			string ky = rem_dup(clean_text(key));
			string mg = check(clean_text(msg));
			vector<string> table = genrate(ky);
			string res="";
			for(int i=0;i<mg.length();i+=2){
//				process the string in 2 character at time.
				char a = mg[i];
				char b = mg[i+1];
				vector<cood> cd = find_index(table,a,b);
//				case 1: if both of them are present in same row, move cursor left in the row for both character
				if(cd[0].j == cd[1].j){
					res+= table[(cd[0].i+1)%5][cd[0].j];
					res+= table[(cd[1].i+1)%5][cd[1].j];
				}
//				case 2: if both of them are present in same column, move cursor down in the column for both character
				else if(cd[0].i == cd[1].i){
					res+= table[cd[0].i][(cd[0].j+1)%5];
					res+= table[cd[1].i][(cd[1].j+1)%5];
				}
//				case 3: if both of them fail to perform abve condition and then we replace them from alphabet which are intersecting on thier row and column
				else{
					res+= table[cd[0].i][cd[1].j];
					res+= table[cd[1].i][cd[0].j];
				}
			}
			cout<<"User Input Key: "<<key<<"\n";
			cout<<"User Message: "<<msg<<"\n";
			cout<<"Encrypted Message: "<<res<<"\n";
		}
};

#driver function to run program
int main(){
	string key,msg;
	cout<<"Enter key: ";
	cin>>key;
	cout<<"Enter Message: ";
	cin>>msg;
	
	PlayFair playFair(key,msg);
	playFair.encrypt();
	return 0;
}

//Enter key: hello
//Enter Message: abhishek
//
//User Input Key: hello
//User Message: abhishek
//Encrypted Message: hgbqlqcr
