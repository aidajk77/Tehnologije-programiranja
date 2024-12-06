#include <iostream>
#include <vector>
#include <new>
#include <type_traits>
using namespace std;

/*template <typename itertip>
auto KreirajIzvrnutiNiz(itertip start, itertip end) -> remove_reference_t<decltype(*start)>*{

        int velicina=0;
        for(itertip p=start;p<end;p++){
            velicina++;
        }
        auto niz=new remove_reference_t<decltype(*start)>[velicina];
        for(int i=velicina-1;i>-1;i--){
            niz[i]=*start;
            start++;
        }
        return niz;
    
}
*/

template <typename IterTip> 
auto KreirajIzvrnutiNiz(IterTip pocetak, IterTip kraj) { 
int velicina = 0; 
for(IterTip p = pocetak; p != kraj; p++) velicina++; 
auto pok_niz = new std::remove_reference_t<decltype(*pocetak)>[velicina]; 
for(int i = velicina - 1; i >= 0; i--) pok_niz[i] = *pocetak++; 
return pok_niz; 
} 


int main()
{
    try  {
    int n; 
    cout << "Koliko zelite elemenata: "; 
    cin >> n; 
    vector<double> v(n); 
    cout << "Unesite elemente: "; 
    for(double &e : v) cin >> e; 
    cout << "Kreirani niz: "; 
    double *niz = KreirajIzvrnutiNiz(v.begin(), v.end()); 
    for(int i = 0; i < n; i++) cout << niz[i] << " "; 
    delete[] niz; 
    }
  catch(...) { 
    cout << "Nedovoljno memorije!"; 
  } 
  return 0;
}