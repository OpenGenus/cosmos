/* Part of Cosmos by OpenGenus Foundation */

/* Lexicographic String Rank */
/* O(n) time algorithm */
#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
void factorial(ll fact[], int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;
}
void initialize_char_cnt(int char_count[], string s, int len)
{
    for (int i = 0; i < 256; i++)
        char_count[i] = 0;
    for (int i = 0; i < len; i++)
        char_count[s[i] - char(0)]++;
}
void initialize_smaller_char_cnt(int smaller_char_count[], int char_count[])
{
    smaller_char_count[0] = 0;
    for (int i = 1; i < 256; i++)
        smaller_char_count[i] = smaller_char_count[i - 1] + char_count[i - 1];
}
void update_char_count(int char_count[], char c)
{
    --char_count[c - char(0)];
}
void update_smaller_char_count(int smaller_char_count[], char c)
{
    for (int i = c + 1; i < 256; i++)
        smaller_char_count[i]--;
}
ll lexicographic_string_rank(string s)
{
    int len = s.length();
    int char_count[256], smaller_char_count[256];
    ll fact[len + 1], rep_count = 1, lex_string_rank = 0;
    factorial(fact, len);     //////////// Pre-computation of Factorial is needed for avoiding computing them in future again and again
    initialize_char_cnt(char_count, s, len);    //////////// Initialize char_count array
    initialize_smaller_char_cnt(smaller_char_count, char_count);      //////////// Initialize smaller_char_count array
    for (int i = 0; i < 256; i++)
        rep_count *= fact[char_count[i]];    //////////// Repetitive characters will cause duplicate permutations hence rank is divided by rep_count!
    for (int i = 0; i < len; i++)
    {
        lex_string_rank += (fact[len - i - 1] * (smaller_char_count[s[i] - char(0)]) / rep_count);
        rep_count = rep_count / char_count[s[i] - char(0)];
        update_char_count(char_count, s[i]);    //////////// Current character no longer needed as its position is fixed now
        update_smaller_char_count(smaller_char_count, s[i]);
    }
    return lex_string_rank;
}

int main()
{
    string s = "software";
    cin >> s;
    ll lex_string_rank = lexicographic_string_rank(s);
    cout << "Lexicographic String Rank is: " << lex_string_rank << endl;
    return 0;
}
