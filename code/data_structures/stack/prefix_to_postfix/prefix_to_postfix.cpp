void prefix_to_postfix(string& prefix, string& postfix)
{
//Convert the input prefix expression to postfix format

postfix = prefix;   //initialize the postfix string to the same length of the         prefix string

stack<stackItem> S;
stackItem x;
int k = 0;  //index for accessing char of the postfix string

for (int i = 0; i < prefix.length(); i++)  //process each char in the prefix string from left to right
{
    char c = prefix[i];

    if(prefix.length() == 1)
        break;

    //Implement the body of the for-loop        
    if(isOperator(c))
    {
        x.symb = c;
        x.count = 0;
        S.push(x);
    }
    else
    {
        S.top().count++;
        postfix[k++] = c;

        if(S.top().count == 2)
        {
            postfix[k++] = S.top().symb;
            S.pop();
            S.top().count++;
        }
    }
    if(i == (prefix.length() - 1))
    {
        postfix[k++] = S.top().symb;
        S.pop();
    }

}
}