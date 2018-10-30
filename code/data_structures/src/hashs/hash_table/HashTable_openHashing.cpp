#include <bits/stdc++.h>
using namespace std;
#define no_have -1
class hashTable{
    private:
        struct node{
            string name;
            int data;
            node *prox;
        };
        node** vetor = nullptr;
        int tam_v;
        int converte_key(string key){
            int tmp, ind= 0, soma = 0;
            while(key[ind] != '\0'){
                soma += key[ind];
                ind++;
                if(ind%3 == 0){
                    soma %= 97;
                }
            }
            return soma%tam_v; 
        }

    public:
       void cria_vetor_hash(int tam){
            vetor = new node*[tam];
            for(int i = 0; i < tam; i++){
                vetor[i] = nullptr;
            }
            tam_v = tam;
        }

        bool find_no(string key){
            int ind = converte_key(key);
            if(vetor[ind] == nullptr){
                return false;
            }else{
                node *no_bus;
                no_bus = vetor[ind];
                while((no_bus->name != key)&&(no_bus->prox != nullptr)){
                    no_bus = no_bus->prox;
                }
                if(no_bus->name == key){
                    return true;
                }else{
                    return false;
                }
            }
        }

        void add_hash(string key, int val){
            int ind = converte_key(key);
            if(!find_no(key)){
                //criando novo no;
                node *no = new node;
                no->name = key;
                no->data = val;
                no->prox = nullptr;
                if(vetor[ind] == nullptr){
                    //indice vazio
                    vetor[ind] = no;
                }else{
                    //indice com elemento
                    node *tmp;
                    tmp = vetor[ind];
                    while(tmp->prox != nullptr){
                        tmp = tmp->prox;
                    }
                    tmp->prox = no;
                }
            }else{
                node* no_bus;
                no_bus = vetor[ind];
                while(no_bus->name != key){
                    no_bus = no_bus->prox;
                }
                no_bus->data = val;
            }
        }

        int get_val(string key){
            int ind = converte_key(key);
            if(vetor[ind] == nullptr){
                return no_have;
            }else{
                node *no_bus;
                no_bus = vetor[ind];
                while((no_bus->name != key)&&(no_bus->prox != nullptr)){
                    no_bus = no_bus->prox;
                }
                if(no_bus->name == key){
                    return no_bus->data;
                }else{
                    return no_have;
                }
            }
        }

        void delete_key(string key){
            if(find_no(key)){
                int ind = converte_key(key);
                node *no_bus, *tmp;
                no_bus = vetor[ind];
                if(no_bus->name == key){
                    delete no_bus;
                    vetor[ind] = nullptr;
                }else{
                    while( no_bus->name != key){
                        tmp = no_bus;
                        no_bus = no_bus->prox;
                    }
                    tmp->prox = no_bus->prox;
                    delete no_bus; 
                }
                
            }
        }
};

int main(){
    hashTable H;
    H.cria_vetor_hash(256);
    H.add_hash("Pedro",19);
    H.add_hash("Silva",25);
    H.add_hash("Paula",17);
    H.add_hash("Ximenes",20);
    H.add_hash("Zilde",27);
    H.add_hash("Wiss",9);

    if(H.find_no("Pedro")){
        printf("Pedro have %d years\n", H.get_val("Pedro"));
    }
    if(H.find_no("Ximenes")){
        printf("Ximenes have %d years\n", H.get_val("Ximenes"));
    }
    if(H.find_no("Zilde")){
        printf("Zilde have %d years\n", H.get_val("Zilde"));
    }
    H.add_hash("Pedro",32);
    //as the key Pedro already exists in the hash your node will be updated
    if(H.find_no("Pedro")){
        printf("Pedro have %d years\n", H.get_val("Pedro"));
    }
    string n = "Silva";
    H.delete_key(n);
    int years = H.get_val(n);
    if( years!= no_have){
        cout << n <<" have "<< years << " years\n";
    }else{
        cout << "No have data at the hashtable about " << n <<"\n";
    }
    return 0;
}
