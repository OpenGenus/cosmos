class Solution {
public:
    int strStr(string haystack, string needle) {
        int nh = haystack.length();
        int nn = needle.length();
        if(nh==0 && nn==0) return 0;
        int pos = -1;
        int i=0;
        while(i<=nh-nn)
        {
            int j=i;
            while((j-i)<nn && j<nh && haystack[j]==needle[j-i])
            {
                j++;
            }
            if((j-i)>=nn)
            {
                pos = i;
                break;
            }
            i++;
        }
        return pos;
    }
};
