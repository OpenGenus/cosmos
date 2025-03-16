#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
void imprimeMatriz(int n,int** A){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<A[i][j]<<"\t";
        }
        std::cout<<endl;
    }
}
void imprime_vector_matriz(int n,int j,int** A){
    for(int i=0;i<n;i++){
            std::cout<<A[i][j]<<"\t";
    }
    std::cout<<endl;
}
vector<int> vertex_cover(int n_vertices,int *V,int n_aristas,int **E){
    //Una gráfica G =(V,E)*
    //Otra grafica H =(V,M),M vacio
    srand (time(NULL));
    int M=0;
    int maximo;
    //arreglo de nodos v_C
    vector<int>vertex_C;
    vector<int>maximos(1,0);
    int **A;
    A=new int*[n_vertices+1];
    for(int i=0;i<n_vertices;i++){
        A[i]=new int[n_vertices];
        for(int j=0;j<n_vertices;j++){
            A[i][j]=0;
        }
    }
    for(int i=0;i<n_aristas;i++){
        int j=E[i][0]-1,k=E[i][1]-1;
        A[j][k]=1;
        A[k][j]=1;
    }
    for(int i=0;i<n_vertices;i++){
        A[i][n_vertices]=0;
        for(int j=0;j<n_vertices;j++){
            A[i][n_vertices]+=A[i][j];
        }
    }
    imprimeMatriz(n_vertices,A);
    imprime_vector_matriz(n_vertices,n_vertices,A);
    while(M < n_aristas){//mientras H no sea conexa // mientras |M|<|E|
        maximo=0;
        //tomamos n, el nodo de grado maximo y lo metemos en el arreglo de v_C
        for(int i=1;i<n_vertices;){
            if(A[maximo][n_vertices]==A[i][n_vertices]){
                maximos.push_back(i);
            }else if(A[maximo][n_vertices]<A[i][n_vertices]){
                maximo=i;
                maximos.clear();
                maximos.push_back(i);
            }
            i++;
        }
        //tomamos de las aristas los nodos adyacentes y le restamos uno a su grado máximo
        int tam=maximos.size();
        if (tam!=0){
            maximo = maximos.front();
        }else{
            maximo=maximos[rand() % tam];
        }
        vertex_C.push_back(maximo);
        M+=A[maximo][n_vertices];
        for(int i=0;i<n_vertices;i++){
            if(A[i][maximo]>0){
                A[i][n_vertices]-=1;
            }
        }
        A[maximo][n_vertices]=0;
        imprime_vector_matriz(n_vertices,n_vertices,A);
    }
    return vertex_C;
}

int main() {
    int n_vertices=6;
    int n_aristas=8;
    int *V = new int[n_vertices];
    int **E = new int*[n_aristas];
    for(int i=0;i<n_aristas;i++){
        E[i]=new int[2];
    }
    for(int i=0;i<n_vertices;i++){
        V[i]=i+1;
    }
    E[0][0]=1;E[0][1]=2;
    E[1][0]=1;E[1][1]=3;
    E[2][0]=1;E[2][1]=5;
    E[3][0]=1;E[3][1]=4;
    E[4][0]=3;E[4][1]=4;
    E[5][0]=3;E[5][1]=5;
    E[6][0]=4;E[6][1]=6;
    E[7][0]=5;E[7][1]=6;
    vector<int>v_C;
    v_C=vertex_cover(n_vertices,V,n_aristas,E);
    while(!v_C.empty()){
        cout<<v_C.back()<<"\t";
        v_C.pop_back();
    }
    return 0;
}
