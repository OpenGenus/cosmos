/* 
 *
 * Kasai Algorithm 
 * 
 */

vector < int > kasaiAlgorithm(string s , vector < int > suffix_array)
{
    int n = s.size() , m = 0;
    vector < int > LCP(n , 0);
    vector < int > rank(n , 0);

    for (int i = 0 ; i < n ; i ++) rank[suffix_array[i]] = i;

    for (int i = 0 ; i < n ; i ++ , m ? m -- : 0)
    {
        if (rank[i] == n - 1) 
            { 
                m = 0 ; 
                continue ;
            }
        int j = suffix_array[rank[i] + 1];

        while (i + m < n && j + m < n && s[i + m] == s[j + m]) m ++;
        LCP[rank[i]] = m;
    }
    return LCP;
}