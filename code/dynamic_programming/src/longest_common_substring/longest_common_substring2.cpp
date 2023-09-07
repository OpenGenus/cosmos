// Space Complexity: O(n)
// Time Complexity: O(m*n) 

#include <iostream>
#include <vector> 

std::string LongestCommonSubstring(std::string string1, std::string string2) 
{ 
    std::string temp;
    // longest string is string1 and the smallest string is string2
    if ( string2.size() > string1.size() ) 
    {
        temp = string1;
        string1 = string2;
        string2 = temp;
    }

    int m = string1.size();
    int n = string2.size();
    int maxLength = 0; // length of longest common Substring
    int end; // ending point of longest common Substring
    int curr = 0; // current row in the matrix 

    std::vector< std::vector<int> > consecutiveRows(2, std::vector<int> (n + 1, 0)); // store result of 2 consecutive rows
    
    // maintaing the array for consequtive two rows
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (string1[i - 1] == string2[j - 1]) 
            { 
                consecutiveRows[curr][j] = consecutiveRows[1 - curr][j - 1] + 1; 
                if ( consecutiveRows[curr][j] > maxLength ) 
                { 
                    maxLength = consecutiveRows[curr][j]; 
                    end = i - 1; 
                }
            } 
            else
                consecutiveRows[curr][j] = 0; 
        } 
        curr = 1 - curr; // changing the row alternatively
    } 

    if (maxLength == 0) 
        return ""; 
    else
    {
        std::string s = "";
        // string is from end-maxLength+1 to end as maxLength is the length of
        // the common substring.
        for (int i = end - maxLength + 1; i <= end; i++)
            s += string1[i];
    	
        return s; 
    }
}

int main()
{
    std::string string1;
    std::string string2;
    std::cout << "Enter String1: ";
    std::cin >> string1;
    std::cout << "Enter String2: ";
    std::cin >> string2;
    std::cout << "String1: " << string1 << "\nString2: " << string2 << "\n";

    std::string lcsStr = LongestCommonSubstring(string1, string2);

    if(lcsStr == "")
        std::cout << "No common substring\n"; 
    else
        std::cout << "Longest Common Substring: " << lcsStr << " (of length: " << lcsStr.size() << ")\n";
    
    return 0;
}
