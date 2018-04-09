#include <iostream>
#include <cstring>
#define NO_OF_CHARS 256
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void search(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            printf("\n pattern occurs at shift = %d", s);

            s += (s + m < n) ? m - badchar[txt[s + m] - char(0)] : 1;

        }
        else
            s += max(1, j - badchar[txt[s + j] - char(0)]);
    }
}

int main()
{
    using namespace std;
    char txt[] = {}, pat[] = {};

    cin >> txt;
    cin >> pat;
    search(txt, pat);
    return 0;
}
