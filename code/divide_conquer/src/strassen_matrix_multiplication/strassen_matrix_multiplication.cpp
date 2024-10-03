
//The following program contains the strassen algorithm along with the Currently Fastest Matrix Multiplication Algorithm for sparse matrices
// Developed by Raphael Yuster and Uri Zwick

// I have also included a time calculator in case anyone wanted to check time taken by each algorithms

// Although mathematcially the fast multiplication algorithm should take less time, since it is of lesser order O(n^t)
// however it has a large preceeding constant thus the effect of the algorthm can only be seen in larger matrices
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

std::vector<std::vector<int>> generator(int m, int n)
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 1);
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < m; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 5 != 5)
                row.push_back(dist6(rng));
            else
                row.push_back(0);
        }
        ans.push_back(row);
    }
    return ans;
}


int f(const std::vector<std::vector<int>>& a)
{
    return a[0][0];
}
std::vector<std::vector<int>> retriever(const std::vector<std::vector<int>>& matrix, int x, int y)
{
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < x; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < y; j++)
            row.push_back(matrix[i][j]);
        ans.push_back(row);
    }
    return ans;
}


std::vector<std::vector<int>> converter(const std::vector<std::vector<int>>& matrix)
{
    auto noOfRows = matrix.size();
    auto noOfCols = matrix[0].size();
    std::vector<std::vector<int>>::size_type t = 1;
    std::vector<std::vector<int>>::size_type p;
    if (x > y)
        p = noOfRows;
    else
        p = noOfCols;
    while (t < p)
        t *= 2;
    p = t;
    int flag = 0;
    std::vector<std::vector<int>> ans;
    for (vector<vector<int>>::size_type i = 0; i < p; i++)
    {
        if (i >= noOfRows)
            flag = 1;
        std::vector<int> row;
        for (std::vector<int>::size_type j = 0; j < p; j++)
        {
            if (flag == 1)
                row.push_back(0);
            else
            {
                if (j >= noOfCols)
                    row.push_back(0);
                else
                    row.push_back(matrix[i][j]);
            }
        }
        ans.push_back(row);
    }
    return ans;
}

void print(const std::vector<std::vector<int>>& grid)
{
    for (std::vector<std::vector<int>>::size_type i = 0; i < grid.size(); i++)
    {
        for (std::vector<int>::size_type j = 0; j < grid[i].size(); j++)
            std::cout << grid[i][j] << ' ';
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> add(const std::vector<std::vector<int>>& a,
                                  const std::vector<std::vector<int>>& b)
{
    std::vector<std::vector<int>> ans;
    for (std::vector<std::vector<int>>::size_type i = 0; i < a.size(); i++)
    {
        vector<int> row;
        for (std::vector<int>::size_type j = 0; j < a[i].size(); j++)
        {
            int temp = a[i][j] + b[i][j];
            row.push_back(temp);
        }
        ans.push_back(row);
    }
    return ans;
}

std::vector<std::vector<int>> subtract(const std::vector<std::vector<int>>& a,
                                       const std::vector<std::vector<int>>& b)
{
    std::vector<std::vector<int>> ans;
    for (std::vector<std::vector<int>>::size_type i = 0; i < a.size(); i++)
    {
        vector<int> row;
        for (std::vector<int>::size_type j = 0; j < a[i].size(); j++)
        {
            int temp = a[i][j] - b[i][j];
            row.push_back(temp);
        }
        ans.push_back(row);
    }
    return ans;
}



std::vector<std::vector<int>> naive_multi(const std::vector<std::vector<int>>& a,
                                          const std::vector<std::vector<int>>& b)
{
    int s = 0;
    std::vector<std::vector<int>> ans;
    for (std::vector<std::vector<int>>::size_type i = 0; i < a.size(); i++)
    {
        vector<int> row;
        for (std::vector<int>::size_type j = 0; j < b[i].size(); j++)
        {
            s = 0;
            for (std::vector<int>::size_type k = 0; k < a[i].size(); k++)
                s += a[i][k] * b[k][j];
            row.push_back(s);
        }
        ans.push_back(row);
    }
    return ans;
}


std::vector<std::vector<int>> strassen(const std::vector<std::vector<int>>& m1,
                                       const std::vector<std::vector<int>>& m2)
{
    std::vector<std::vector<int>>::size_type s1 = m1.size();
    std::vector<std::vector<int>>::size_type s2 = m2.size();
    if (s1 > 2 && s2 > 2)
    {
        std::vector<std::vector<int>> a, b, c, d, e, f, g, h, ans;
        for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size() / 2; i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m1[i].size() / 2; j++)
                row.push_back(m1[i][j]);
            a.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size() / 2; i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = m1[i].size() / 2; j < m1[i].size(); j++)
                row.push_back(m1[i][j]);
            b.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m1.size() / 2; i < m1.size(); i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m1[i].size() / 2; j++)
                row.push_back(m1[i][j]);
            c.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m1.size() / 2; i < m1.size(); i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = m1[i].size() / 2; j < m1[i].size(); j++)
                row.push_back(m1[i][j]);
            d.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = 0; i < m2.size() / 2; i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m2[i].size() / 2; j++)
                row.push_back(m2[i][j]);
            e.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = 0; i < m2.size() / 2; i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = m2[i].size() / 2; j < m2[i].size(); j++)
                row.push_back(m2[i][j]);
            f.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m2.size() / 2; i < m2.size(); i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m2[i].size() / 2; j++)
                row.push_back(m2[i][j]);
            g.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m2.size() / 2; i < m2.size(); i++)
        {
            vector<int> row;
            for (std::vector<int>::size_type j = m2[i].size() / 2; j < m2[i].size(); j++)
                row.push_back(m2[i][j]);
            h.push_back(row);
        }


        std::vector<std::vector<int>> p1, p2, p3, p4, p5, p6, p7;
        p1 = strassen(a, subtract(f, h));
        p2 = strassen(add(a, b), h);
        p3 = strassen(add(c, d), e);
        p4 = strassen(d, subtract(g, e));
        p5 = strassen(add(a, d), add(e, h));
        p6 = strassen(subtract(b, d), add(g, h));
        p7 = strassen(subtract(a, c), add(e, f));
        std::vector<std::vector<int>> c1, c2, c3, c4;
        c1 = subtract(add(add(p5, p4), p6), p2);
        c2 = add(p1, p2);
        c3 = add(p3, p4);
        c4 = subtract(add(p1, p5), add(p3, p7));



        int flag1, flag2;
        for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size(); i++)
        {
            std::vector<int> row;
            if (i < m1.size() / 2)
                flag1 = 0;
            else
                flag1 = 1;
            for (std::vector<int>::size_type j = 0; j < m2[i].size(); j++)
            {
                if (j < m2[i].size() / 2)
                {
                    if (flag1 == 0)
                        row.push_back(c1[i][j]);
                    else
                        row.push_back(c3[i - m1.size() / 2][j]);
                }
                else
                {
                    if (flag1 == 0)
                        row.push_back(c2[i][j - m2[i].size() / 2]);
                    else
                        row.push_back(c4[i - m1.size() / 2][j - m2[i].size() / 2]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
    else
    {
        std::vector<std::vector<int>> v;
        v = naive_multi(m1, m2);
        return v;
    }
}

std::vector<std::vector<int>> fast_multi(const std::vector<std::vector<int>>& m1,
                                         const std::vector<std::vector<int>>& m2)
{
    std::vector<int> ranges, ranges_c, ind;
    std::vector<std::vector<int>> ans;
    for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size(); i++)
    {
        int a = 0;
        int b = 0;
        for (std::vector<std::vector<int>>::size_type j = 0; j < m1[i].size(); j++)
        {
            if (m1[j][i] != 0)
                a += 1;
            if (m2[i][j] != 0)
                b += 1;
        }
        ranges.push_back(a * b);
        ranges_c.push_back(a * b);
    }
    sort(ranges.begin(), ranges.end());
    int comp, index;
    for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size(); i++)
    {
        int s = 0;
        for (std::vector<std::vector<int>>::size_type j = 0; j <= i; j++)
            s += ranges[j];
        s += (m1.size() - i - 1) * m1.size() * m1.size();
        if (i == 0)
        {
            comp = s;
            index = 1;
        }
        else if (s < comp)
        {
            comp = s;
            index = i + 1;
        }
    }
    for (int g = 0; g < index; g++)
    {
        for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size(); i++)
            if (ranges_c[i] == ranges[g])
            {
                ind.push_back(i);
                break;
            }
    }
    for (std::vector<vector<int>>::size_type i = 0; i < m1.size(); i++)
    {
        int flag;
        int flag_search = 0;
        for (std::vector<int>::size_type j = 0; j < ind.size(); j++)
            if (i == ind[j])
            {
                flag_search = 1;
                break;
            }
        std::vector<std::vector<int>> row, col;
        for (std::vector<int>::size_type j = 0; j < ind.size(); j++)
        {
            std::vector<int> temp1, temp2;
            temp1.push_back(m1[j][i]);
            temp2.push_back(m2[i][j]);
            col.push_back(temp1);
            row.push_back(temp2);
        }
        if (i == 0)
        {
            if (flag_search == 1)
                ans = naive_multi(col, row);
            else
            {
                std::vector<std::vector<int>> row_c, col_c;
                row_c = converter(row);
                col_c = converter(col);
                ans = retriever(strassen(col_c, row_c), m1.size(), m1.size());
            }
        }
        else
        {
            std::vector<std::vector<int>> v1, v2;
            if (flag_search == 1)
                v1 = naive_multi(col, row);
            else
            {
                std::vector<std::vector<int>> row_c, col_c;
                row_c = converter(row);
                col_c = converter(col);
                v1 = retriever(strassen(col_c, row_c), m1.size(), m1.size());
            }
            ans = add(v1, ans);
        }
    }
    return ans;
}


int main()
{
    std::vector<vector<int>> matrix1, matrix2, v1, v2, v3;
    int i1, j1;
    int i2, j2;
    std::cout << "enter the dimensions of matrix1\n";
    std::cin >> i1 >> j1;
    std::cout << '\n';
    std::cout << "enter the dimensions of matrix2\n";
    std::cin >> i2 >> j2;
    std::cout << '\n';
    int x, y;
    for (x = 0; x < i1; x++)
    {
        std::vector<int> row;
        for (y = 0; y < j1; y++)
        {
            int temp;
            std::cout << "enter the " << x + 1 << " , " << y + 1 << " element for matrix1 - ";
            std::cin >> temp;
            row.push_back(temp);
        }
        matrix1.push_back(row);
    }
    for (x = 0; x < i2; x++)
    {
        std::vector<int> row;
        for (y = 0; y < j2; y++)
        {
            int temp;
            std::cout << "enter the " << x + 1 << " , " << y + 1 << " element for matrix2 - ";
            std::cin >> temp;
            row.push_back(temp);
        }
        matrix2.push_back(row);
    }
    //print(matrix1);

    std::vector<std::vector<int>> m1, m2, m3, m4;
    m1 = converter(matrix1);
    m2 = converter(matrix2);
    //print(m1);
    //cout << "a\n";
    //print(m2);
    //cout <<"a\n";
    /*
     * m3 = generator(1024, 1024);
     * m4 = generator(1024, 1024);
     */

    auto start = std::chrono::high_resolution_clock::now();
    v1 = retriever(naive_multi(m1, m2), i1, j2);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<microseconds>(start - stop);

    std::cout << "tiime taken by function" << duration.count() << endl;
    //print(v1);



    auto start2 = std::chrono::high_resolution_clock::now();
    v2 = retriever(strassen(m1, m2), i1, j2);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<microseconds>(start2 - stop2);

    std::cout << "tiime taken by function" << duration2.count() << endl;

    /*
     * auto start_3 = std::chrono::high_resolution_clock::now();
     * v3 = retriever(fast_multi(m1, m2), i_1, j_2);
     * auto stop_3 = std::chrono::high_resolution_clock::now();
     * auto duration_3 = std::chrono::duration_cast<microseconds>(start_3 - stop_3);
     *
     *
     * cout << "tiime taken by function" << duration_3.count() << endl;
     */

    //print(v2);
    print(v1);

    return 0;
}
