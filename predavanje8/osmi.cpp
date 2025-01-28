#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int SigurnaPozicija(int n, int m){
    list<int> lista;
    for(int i=1;i<=n;i++){
        lista.push_back(i);
    }
    int counter=0;
    auto it=lista.begin();
    while(it != lista.end()){
        if(lista.size()==1) break;
        counter++;
        if(counter==m){
            if(it==lista.begin()){
                auto temp=next(it);
                lista.erase(it);
                it=temp;
                counter=0;
                continue;
            }else if(it==prev(lista.end())){
                lista.erase(it);
                it=lista.begin();
                counter=0;
                continue;
            }else{
                auto temp=prev(it);
                lista.erase(it);
                temp++;
                it=temp;
                counter=0;
                continue;
            }
        }
        it++;
        if(it==lista.end()) it=lista.begin();
    }
    return *lista.begin();
}

int main(){

    int n, m; 
std::cout << "Unesite broj osoba: "; 
std::cin >> n; 
std::cout << "Unesite korak razbrajanja: "; 
std::cin >> m; 
std::cout << "Sigurna pozicija: " << SigurnaPozicija(n, m);


    return 0;
}