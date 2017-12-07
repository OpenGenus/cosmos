/* 
 *
 * Kasai Algorithm 
 * 
 */

vector<int> kasaiAlgorithm(string s,vector<int> suffix_array)
{
    int m=0;
    vector<int> LCP(s.size(),0);
    vector<int> rank(s.size(),0);

    for (int i=0 ; i<s.size() ; i++) rank[suffix_array[i]]=i;

    for (int i=0 ; i<s.size() ; i++ , m?m--:0)
    {
        if (rank[i]==s.size()-1) 
            { 
                m=0 ; 
                continue ;
            }
        int j=suffix_array[rank[i]+1];

        while (i+m<s.size() && j+m<s.size() && s[i+m]==s[j+m])m++;
        LCP[rank[i]]=m;
    }
    return LCP;
}
