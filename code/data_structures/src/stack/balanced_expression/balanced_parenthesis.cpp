class Solution {
public:
    bool isValid(string s) {
        stack<int>sk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{'||s[i]=='('||s[i]=='[')
            sk.push(s[i]);
            else {
                if(sk.empty())
                    return 0;
                else if((sk.top()=='('&&s[i]==')')||(sk.top()=='{'&&s[i]=='}')||(sk.top()=='['&&s[i]==']'))
                sk.pop();
            else return 0;} 
        }
        if(sk.empty())
            return 1;
        else return 0;
    }
};
