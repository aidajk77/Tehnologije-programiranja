#include <iostream>
#include <iterator>
#include <list>

using namespace std;

template <typename it1, typename it2, typename fun>
it2 KopirajUzUvjetnoUklanjanje(it1 start1, it1 kraj1, it2 start2,fun func){
    while(start1!=kraj1){
        if(!func(*start1)){
            *start2=*start1;
            start2++;
        }
        start1++;
        
    }
    return start2;
}

int main(){

    list<int> lista(5);  
    cout << "Unesite 5 brojeva: "; 
    for(int &e : lista) cin >> e; 
    int dozvoljeno; 
    cout << "Unesite dozvoljeni broj cifara: "; 
    cin >> dozvoljeno; 
    list<int> preostali(5); 
    auto kraj = KopirajUzUvjetnoUklanjanje(lista.begin(), lista.end(), preostali.begin(), 
        [dozvoljeno](int n) { 
        int br_cifara = n == 0; 
        for(; n != 0; n /= 10) br_cifara++; 
        return br_cifara > dozvoljeno; 
        }); 
    preostali.resize(distance(preostali.begin(), kraj)); 
    cout << "Preostali brojevi: "; 
    for(int e : preostali) cout << e << " "; 

    return 0;
}
