// dynamic programming | edit distance | C++
// Part of Cosmos by OpenGenus Foundation

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

class Alignment {
    std::string sx, sy, sa, sb;

    std::vector<std::vector<int>> A;
    int sxL, syL;
    int cost = 0;

//insertion cost
    inline int insC()
    {
        return 4;
    }

//deletion cost
    inline int delC()
    {
        return 4;
    }

//modification cost
    inline int modC(char fr, char to)
    {
        if (fr == to)
            return 0;
        return 3;
    }

public:

//constructor
    Alignment(std::string s1, std::string s2) : sx(s1), sy(s2),
        sxL(s1.length()), syL(s2.length())
    {
        //allocating size to array needed
        A.resize(s2.length() + 4, std::vector<int>(s1.length() + 4, 0));
    }

//recurrence
    int rec(int i, int j)
    {
        return std::min(modC(sx[i - 1], sy[j - 1]) + A[i - 1][j - 1],
                        std::min(delC() + A[i - 1][j], insC() + A[i][j - 1]));
        //i-1, j-1 in sx, sy b/c of 0-indexing in string
    }

//building array of cost
    void form_array()
    {

        //initialising the base needed in dp
        //building up the first column, consider taking first string sx and second as null
        for (int i = 0; i <= sxL; i++)
            A[i][0] = i * (delC());

        //building up the first row, consider taking first string null and second as string sy
        for (int i = 0; i <= syL; i++)
            A[0][i] = i * (insC());

        //building up whole array from previously known values
        for (int i = 1; i <= sxL; i++)
            for (int j = 1; j <= syL; j++)
                A[i][j] = rec(i, j);

        cost = A[sxL][syL];

    }

//finding the alignment
    void trace_back(int i, int j)
    {

        while (true)
        {
            if (i == 0 || j == 0)
                break;
            //A[i][j] will have one of the three above values from which it is derived
            //so comapring from each one
            if (i >= 0 && j >= 0 && rec(i, j) == modC(sx[i - 1], sy[j - 1]) + A[i - 1][j - 1])
            {
                sa.push_back(sx[i - 1]);
                sb.push_back(sy[j - 1]);
                i--, j--;
            }
            else if ((i - 1) >= 0 && j >= 0 && rec(i, j) == delC() + A[i - 1][j])
            {
                sa.push_back(sx[i - 1]);                      //0-indexing of string
                sb.push_back('-');
                i -= 1;
            }
            else if (i >= 0 && (j - 1) >= 0)
            {
                sa.push_back('-');                        //0-indexing of string
                sb.push_back(sy[j - 1]);
                j -= 1;
            }
        }

        if (i != 0)
            while (i)
            {
                sa.push_back(sx[i - 1]);
                sb.push_back('-');
                i--;
            }

        else
            while (j)
            {
                sa.push_back('-');
                sb.push_back(sy[j - 1]);
                j--;
            }
    }

//returning the alignment
    std::pair<std::string, std::string> alignst()
    {
        //reversing the alignments because we have formed the
        //alignments from backward(see: trace_back, i, j started from m, n respectively)
        reverse(sa.begin(), sa.end());
        reverse(sb.begin(), sb.end());
        return make_pair(sa, sb);
    }


//returning the cost
    int kyc()
    {
        return cost;
    }
};

int main()
{
    using namespace std;

    //converting sx to sy
    string sx, sy;
    sx = "GCCCTAGCG";
    sy = "GCGCAATG";

    //standard input stream
    //cin >> sx >> sy;

    pair<string, string> st;

    Alignment dyn(sx, sy);
    dyn.form_array();
    dyn.trace_back(sx.length(), sy.length());
    st = dyn.alignst();
    //Alignments can be different for same strings but cost will be same

    cout << "Alignments of the strings\n";
    cout << st.first << "\n";
    cout << st.second << "\n";
    cout << "Cost associated = ";
    cout << dyn.kyc() << "\n";

    /*	Alignments
     * M - modification, D - deletion, I - insertion for converting string1 to string2
     *
     *                   M M MD
     * string1	-  GCCCTAGCG
     * string2 -  GCGCAAT-G
     *
     */
    return 0;
}
