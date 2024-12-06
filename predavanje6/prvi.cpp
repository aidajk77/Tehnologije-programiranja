#include <iostream>
#include<limits>
using namespace std;

template <typename BrojcaniTip> 
  BrojcaniTip *GenerirajStepeneDvojke(int n) { 
    if(n <= 0) throw std::domain_error("Broj elemenata mora biti pozitivan"); 
    BrojcaniTip *pok_niz {}; 
    try { 
      pok_niz = new BrojcaniTip[n]; 
    } 
    catch(...) { 
      throw std::runtime_error("Alokacija nije uspjela"); 
    } 
    BrojcaniTip stepen = 1; 
    for(int i = 0; i < n; i++) { 
      pok_niz[i] = stepen; 
       if(i != n - 1) 
        if(stepen <= std::numeric_limits<BrojcaniTip>::max() / 2) stepen *= 2; 
        else {
          delete [] pok_niz;
          throw std::overflow_error("Prekoracen dozvoljeni opseg"); 
        }
    } 
    return pok_niz; 
  } 

int main(){
    int n; 
    cout << "Koliko zelite elemenata: "; 
    cin >> n; 
    try { 
        auto niz = GenerirajStepeneDvojke<unsigned long long int>(n); 
        for(int i = 0; i < n; i++) cout << niz[i] << " ";
        delete[] niz; 
    } 
    catch(exception &e) { 
        cout << "Izuzetak: " << e.what(); 
    } 
    return 0;

}