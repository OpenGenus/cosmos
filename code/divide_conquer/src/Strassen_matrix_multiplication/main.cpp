
//The following program contains the strassen algorithm along with the Currently Fastest Matrix Multiplication Algorithm for sparse matrices
// Developed by Raphael Yuster and Uri Zwick

// I have also included a time calculator in case anyone wanted to check time taken by each algorithms

// Although mathematcially the fast multiplication algorithm should take less time, since it is of lesser order O(n^t)
// however it has a large preceeding constant thus the effect of the algorthm can only be seen in larger matrices

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

vector<vector<int>> generator(int m, int n){
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,1);
    int i, j;
    vector<vector<int>> ans;
    for( i = 0; i < m; i++){
        vector<int> row;
        for(j = 0;j < n ; j++){
            if (i+j % 5 != 5) {
                row.push_back(dist6(rng));
            }
            else{
                row.push_back(0);
            }
        }
        ans.push_back(row);
    }
    return ans;
}


int f(vector<vector<int>> a){
    return a[0][0];
}
vector<vector<int>> retriever(vector<vector<int>> matrix, int x, int y){
    vector<vector<int>> ans;
    for (int i = 0; i < x; i++ )
    {
        vector<int> row;
        for (int j = 0; j < y; j++ )
        {
            row.push_back(matrix[i][j]);
        }
        ans.push_back(row);
    }
    return ans;
}


vector<vector<int>> converter(vector<vector<int>> matrix){
    vector<vector<int>>::size_type x = matrix.size();
    vector<vector<int>>::size_type y = matrix[0].size();
    vector<vector<int>>::size_type t = 1;
    vector<vector<int>>::size_type p;
    if(x > y){
        p = x;
    }
    else{
        p = y;
    }
    while( t < p){
        t = t*2;
    }
    p = t;
    int flag = 0;
    vector<vector<int>> ans;
    for ( std::vector<std::vector<int>>::size_type i = 0; i < p; i++ )
    {
        if(i >= matrix.size()){
            flag = 1;
        }
        vector<int> row;
        for ( std::vector<int>::size_type j = 0; j < p; j++ )
        {
            if(flag == 1){
                row.push_back(0);
            }
            else{
                if(j >= matrix[i].size()){
                    row.push_back(0);
                }
                else{
                    row.push_back(matrix[i][j]);
                }
            }
        }
        ans.push_back(row);
    }
    return ans;
}

void print(vector<vector<int>> grid){
    for ( std::vector<std::vector<int>>::size_type i = 0; i < grid.size(); i++ )
    {
        for ( std::vector<int>::size_type j = 0; j < grid[i].size(); j++ )
        {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> ans;
    for ( std::vector<std::vector<int>>::size_type i = 0; i < a.size(); i++ )
    {
        vector<int> row;
        for ( std::vector<int>::size_type j = 0; j < a[i].size(); j++ )
        {
            int temp = a[i][j] + b[i][j];
            row.push_back(temp);
        }
        ans.push_back(row);
    }
    return ans;
}

vector<vector<int>> subtract(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> ans;
    for ( std::vector<std::vector<int>>::size_type i = 0; i < a.size(); i++ )
    {
        vector<int> row;
        for ( std::vector<int>::size_type j = 0; j < a[i].size(); j++ )
        {
            int temp = a[i][j] - b[i][j];
            row.push_back(temp);
        }
        ans.push_back(row);
    }
    return ans;
}



vector<vector<int>> naive_multi(vector<vector<int>> a,  vector<vector<int>> b){
    int s = 0;
    vector<vector<int>> ans;
    for ( std::vector<std::vector<int>>::size_type i = 0; i < a.size(); i++ )
    {
        vector<int> row;
        for ( std::vector<int>::size_type j = 0; j < b[i].size(); j++ )
        {
            s = 0;
            for ( std::vector<int>::size_type k = 0; k < a[i].size(); k++ )
            {
                s += a[i][k] * b[k][j];
            }
            row.push_back(s);
        }
        ans.push_back(row);
    }
    return ans;
}


vector<vector<int>> strassen(vector<vector<int>> m1, vector<vector<int>> m2){
    std::vector<std::vector<int>>::size_type s1 = m1.size();
    std::vector<std::vector<int>>::size_type s2 = m2.size();
    if ( s1 > 2 && s2 > 2) {
        vector<vector<int>> a,b,c,d,e,f,g,h,ans;
        for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size() / 2; i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m1[i].size() / 2; j++) {
                row.push_back(m1[i][j]);
            }
            a.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size() / 2; i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = m1[i].size() / 2; j < m1[i].size(); j++) {
                row.push_back(m1[i][j]);
            }
            b.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m1.size() / 2; i < m1.size(); i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m1[i].size() / 2; j++) {
                row.push_back(m1[i][j]);
            }
            c.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m1.size() / 2; i < m1.size(); i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = m1[i].size() / 2; j < m1[i].size(); j++) {
                row.push_back(m1[i][j]);
            }
            d.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = 0; i < m2.size() / 2; i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m2[i].size() / 2; j++) {
                row.push_back(m2[i][j]);
            }
            e.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = 0; i < m2.size() / 2; i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = m2[i].size() / 2; j < m2[i].size(); j++) {
                row.push_back(m2[i][j]);
            }
            f.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m2.size() / 2; i < m2.size(); i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = 0; j < m2[i].size() / 2; j++) {
                row.push_back(m2[i][j]);
            }
            g.push_back(row);
        }
        for (std::vector<std::vector<int>>::size_type i = m2.size() / 2; i < m2.size(); i++) {
            vector<int> row;
            for (std::vector<int>::size_type j = m2[i].size() / 2; j < m2[i].size(); j++) {
                row.push_back(m2[i][j]);
            }
            h.push_back(row);
        }


        vector<vector<int>> p1, p2, p3, p4, p5, p6, p7;
        p1 = strassen(a, subtract(f, h));
        p2 = strassen(add(a, b), h);
        p3 = strassen(add(c, d), e);
        p4 = strassen(d, subtract(g, e));
        p5 = strassen(add(a, d), add(e, h));
        p6 = strassen(subtract(b, d), add(g, h));
        p7 = strassen(subtract(a, c), add(e, f));
        vector<vector<int>> c1, c2, c3, c4;
        c1 = subtract(add(add(p5, p4), p6), p2);
        c2 = add(p1, p2);
        c3 = add(p3, p4);
        c4 = subtract(add(p1, p5), add(p3, p7));



        int flag1, flag2;
        for (std::vector<std::vector<int>>::size_type i = 0; i < m1.size(); i++) {
            vector<int> row;
            if( i < m1.size()/2){
                flag1 = 0;
            }
            else{
                flag1 = 1;
            }
            for (std::vector<int>::size_type j = 0; j < m2[i].size(); j++) {
                if( j < m2[i].size()/2){
                    if( flag1 == 0){
                        row.push_back(c1[i][j]);
                    }
                    else{
                        row.push_back(c3[i-m1.size()/2][j]);
                    }
                }
                else{
                    if( flag1 == 0){
                        row.push_back(c2[i][j-m2[i].size()/2]);
                    }
                    else{
                        row.push_back(c4[i-m1.size()/2][j-m2[i].size()/2]);
                    }
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
    else{
        vector<vector<int>> v;
        v = naive_multi(m1, m2);
        return v;
    }
}

vector<vector<int>> fast_multi(vector<vector<int>> m1, vector<vector<int>> m2){
    vector<int> ranges, ranges_c, ind;
    vector<vector<int>> ans;
    for( vector<vector<int>>::size_type i = 0; i < m1.size(); i++){
        int a = 0;
        int b = 0;
        for( vector<vector<int>>::size_type j = 0; j < m1[i].size(); j++){
            if( m1[j][i] != 0){
                a += 1;
            }
            if( m2[i][j] != 0){
                b+= 1;
            }
        }
        ranges.push_back(a*b);
        ranges_c.push_back(a*b);
    }
    sort( ranges.begin(), ranges.end());
    int comp, index;
    for( vector<vector<int>>::size_type i = 0; i < m1.size(); i++){
        int s = 0;
        for(vector<vector<int>>::size_type j = 0; j <= i; j++){
            s += ranges[j];
        }
        s += (m1.size()-i-1)*m1.size()*m1.size();
        if(i == 0){
            comp = s;
            index = 1;
        }
        else{
            if(s < comp){
                comp = s;
                index = i+1;
            }
        }
    }
    for( int g = 0; g < index; g++){
        for( vector<vector<int>>::size_type i = 0; i < m1.size(); i++){
            if(ranges_c[i] == ranges[g]){
                ind.push_back(i);
                break;
            }
        }
    }
    for( vector<vector<int>>::size_type i = 0; i < m1.size(); i++ ){
        int flag;
        int flag_search = 0;
        for( vector<int>::size_type j = 0; j < ind.size(); j++ ){
            if( i == ind[j]){
                flag_search = 1;
                break;
            }
        }
        vector<vector<int>> row, col;
        for( vector<int>::size_type j = 0; j < ind.size(); j++ ){
            vector<int> temp1, temp2;
            temp1.push_back(m1[j][i]);
            temp2.push_back(m2[i][j]);
            col.push_back(temp1);
            row.push_back(temp2);
        }
        if( i == 0){
            if(flag_search == 1){
                ans = naive_multi(col, row);
            }
            else{
                vector<vector<int>> row_c, col_c;
                row_c = converter(row);
                col_c = converter(col);
                ans = retriever(strassen(col_c, row_c), m1.size(), m1.size());
            }
        }
        else{
            vector<vector<int>> v1, v2;
            if(flag_search == 1){
                v1 = naive_multi(col, row);
            }
            else{
                vector<vector<int>> row_c, col_c;
                row_c = converter(row);
                col_c = converter(col);
                v1 = retriever(strassen(col_c, row_c), m1.size(), m1.size());
            }
            ans = add(v1, ans);
        }
    }
    return ans;
}









int main() {
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    vector<vector<int>> v1, v2, v3;
    int i_1, j_1;
    int i_2, j_2;

    cout << "enter the dimensions of matrix1\n";
    cin >> i_1 >> j_1;
    cout << '\n';
    cout << "enter the dimensions of matrix2\n";
    cin >> i_2 >> j_2;
    cout << '\n';
    int x,y;
    for(x = 0; x< i_1; x++){
        vector<int> row;
        for(y = 0; y < j_1; y++){
            int temp;
            cout << "enter the " << x+1 << " , " << y+1 << " element for matrix1 - ";
            cin >> temp;
            row.push_back(temp);
        }
        matrix1.push_back(row);
    }
    for(x = 0; x< i_2; x++){
        vector<int> row;
        for(y = 0; y < j_2; y++){
            int temp;
            cout << "enter the " << x+1 << " , " << y+1 << " element for matrix2 - ";
            cin >> temp;
            row.push_back(temp);
        }
        matrix2.push_back(row);
    }
    //print(matrix1);

    vector<vector<int>> m1, m2, m3, m4;
    m1 = converter(matrix1);
    m2 = converter(matrix2);
    //print(m1);
    //cout << "a\n";
    //print(m2);
    //cout <<"a\n";
    /*
    m3 = generator(1024, 1024);
    m4 = generator(1024, 1024);
    */

    auto start = high_resolution_clock::now();
    v1 = retriever(naive_multi(m1, m2), i_1 , j_2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(start - stop);

    cout << "tiime taken by function" << duration.count() << endl;
    //print(v1);



    auto start_2 = high_resolution_clock::now();
    v2 = retriever(strassen(m1, m2), i_1, j_2);
    auto stop_2 = high_resolution_clock::now();
    auto duration_2 = duration_cast<microseconds>(start_2 - stop_2);

    cout << "tiime taken by function" << duration_2.count() << endl;

    /*
    auto start_3 = high_resolution_clock::now();
    v3 = retriever(fast_multi(m1, m2), i_1, j_2);
    auto stop_3 = high_resolution_clock::now();
    auto duration_3 = duration_cast<microseconds>(start_3 - stop_3);


    cout << "tiime taken by function" << duration_3.count() << endl;
    */

    //print(v2);
    print(v1);

    return 0;
}
