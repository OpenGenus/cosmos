/**
 * Name: Joao Marcelo 
 * Computer Science
*/
#include <bits/stdc++.h>
#define tam 100100
#define MENOR -1e9

using namespace std;

long long arr[tam];
long long st[4*tam];

void build(int id, int left, int right){
    if(left==right){
        st[id] = arr[left];
    }else{
        int mid = (left+right)/2;
        build (2 * id + 1, left, mid);
        build (2 * id + 2, mid + 1, right);
        st[id] = max(st[2*id + 1],st[2 * id + 2]);
    }
}

void update(int id, int left, int right, int pos,  int valor){
    if(left==right){
        st[id] = valor;
    }else{
        int mid = (left+right)/2;
        if(pos<=mid){
            update(2*id + 1, left, mid, pos, valor);
        }else{
            update(2*id + 2, mid+1, right, pos, valor);
        }
        st[id] = max(st[2*id + 1],st[2*id+2]);
    }
}

long long query(int id, int left, int right, int x, int y){
    if(left > y || right < x ){
        return MENOR;
    }else if(left>=x && right<=y){
        return st[id];
    }else{
        int mid = (left+right)/2;
        return max(query(2*id + 1, left, mid, x, y), query(2*id+2, mid+1, right, x, y));
    }
}
int main(){
    int n, m;
    int t;
    scanf("%d", &t);
    for(int k=0;k<t;k++){
        scanf("%d%d", &n, &m);
        long long res[tam];
        for(int i=0;i<n;i++){
            scanf("%lld", &arr[i]);
        }
        build(0, 0, n-1);
        int q;
        scanf("%d", &q);
        char c;
        int i, j, v;
        int x = 0;
        while(q--){
            cin >> c;
            if (c=='A'){
                scanf("%d", &v);
                m+=v;
            }else if(c=='B'){
                scanf("%d%d", &j, &v);
                update(0, 0, n-1, j, v);
            }else{
                long long aux;
                scanf("%d%d", &i, &j);
                aux = query(0, 0, n-1, i, j);
                res[x++] = abs(aux-m);
            }
        }
        printf("Testcase %d:\n", k);
        for(int i=0;i<x;i++){
            printf("%lld\n", res[i]);
        }
        printf("\n");
    }
    return 0;
}
