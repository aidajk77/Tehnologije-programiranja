#include <iostream>

using namespace std;

struct Osoba{
    int redni_broj;
    Osoba* sljedeci;
};

int SigurnaPozicija(int n, int m){
    Osoba* pocetak = new Osoba{1,nullptr};
    Osoba* prethodni;
    for(int i=2;i<=n;i++){
        Osoba* novi = new Osoba{i,nullptr};
        if(pocetak->sljedeci==nullptr) pocetak->sljedeci=novi;
        else{
            prethodni->sljedeci=novi;
        }
        prethodni=novi;

    }
    prethodni->sljedeci=pocetak;

    while(pocetak->sljedeci!= pocetak){
        for(int i=1;i<m;i++){
            prethodni=pocetak;
            pocetak=pocetak->sljedeci;
        }
        auto temp=pocetak->sljedeci;
        delete pocetak;
        prethodni->sljedeci=temp;
        pocetak=temp;
    }
    int rezultat = pocetak->redni_broj;
    delete pocetak;
    return rezultat;

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