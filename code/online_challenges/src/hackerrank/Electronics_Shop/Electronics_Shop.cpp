// Part of Cosmos by OpenGenus
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the getMoneySpent function below.
 */
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b)
{
    int i, sum = 0, j, k = 0, ans = -1;
    sort(keyboards.begin(), keyboards.end());
    sort(drives.begin(), drives.end());
    for (i = 0; i < keyboards.size(); i++)
    {
        for (j = 0; j < drives.size(); j++)
        {
            sum = keyboards[i] + drives[j];
            if (sum <= b && sum > ans)
                ans = sum;
        }
    }
    return ans;
}

int main()
{
    ofstream fout;
    ostream *out_stream = nullptr;
    if (const char *output_path = getenv("OUTPUT_PATH"))
    {
        fout.open(output_path);
        if (!fout)
        {
            cerr << "Failed to open OUTPUT_PATH for writing" << endl;
            return 1;
        }
        out_stream = &fout;
    }
    else
    {
        out_stream = &cout;
    }

    string bnm_temp;
    if (!getline(cin, bnm_temp))
    {
        (*out_stream) << -1 << "\n";
        if (fout.is_open())
            fout.close();
        return 0;
    }

    vector<string> bnm = split_string(bnm_temp);

    if (bnm.size() < 3)
    {
        // malformed first line: cannot parse budget, n, m
        (*out_stream) << -1 << "\n";
        if (fout.is_open())
            fout.close();
        return 0;
    }

    int b = 0, n = 0, m = 0;
    try
    {
        b = stoi(bnm[0]);
        n = stoi(bnm[1]);
        m = stoi(bnm[2]);
    }
    catch (...)
    {
        // malformed numbers
        (*out_stream) << -1 << "\n";
        if (fout.is_open())
            fout.close();
        return 0;
    }

    string keyboards_temp_temp;
    if (!getline(cin, keyboards_temp_temp))
    {
        (*out_stream) << -1 << "\n";
        if (fout.is_open())
            fout.close();
        return 0;
    }

    vector<string> keyboards_temp = split_string(keyboards_temp_temp);

    // safely parse the keyboard prices; ignore malformed tokens
    vector<int> keyboards;
    keyboards.reserve(keyboards_temp.size());
    for (const string &tok : keyboards_temp)
    {
        try
        {
            keyboards.push_back(stoi(tok));
        }
        catch (...)
        {
            // skip malformed token
        }
    }

    string drives_temp_temp;
    if (!getline(cin, drives_temp_temp))
    {
        (*out_stream) << -1 << "\n";
        if (fout.is_open())
            fout.close();
        return 0;
    }

    vector<string> drives_temp = split_string(drives_temp_temp);

    // safely parse the drive prices; ignore malformed tokens
    vector<int> drives;
    drives.reserve(drives_temp.size());
    for (const string &tok : drives_temp)
    {
        try
        {
            drives.push_back(stoi(tok));
        }
        catch (...)
        {
            // skip malformed token
        }
    }

    /*
     * The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
     */

    int moneySpent = getMoneySpent(keyboards, drives, b);

    (*out_stream) << moneySpent << "\n";

    if (fout.is_open())
        fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    // Use istringstream to safely split on whitespace. This handles empty strings
    // and any amount of whitespace between tokens without manual indexing.
    vector<string> splits;
    if (input_string.empty())
        return splits;

    istringstream iss(input_string);
    string token;
    while (iss >> token)
    {
        splits.push_back(token);
    }
    return splits;
}
