#include<iostream>
#include<deque>
#include<vector>
#include <type_traits> 
using namespace std;

template< typename kontejner1, typename kontejner2>
auto ZbirKontejnera(kontejner1 a, kontejner2 b) -> vector<decltype(*begin(a) + *begin(b))>{
    auto p1 = a.begin();
    auto p2 = b.begin();
    typedef std::remove_reference_t<decltype(*p1)> TipElemenata1; 
    typedef std::remove_reference_t<decltype(*p2)> TipElemenata2; 
    TipElemenata1 podrazumijevana1;
    TipElemenata2 podrazumijevana2;
    vector<decltype(*p1 + *p2)> v; 
    if(a.size()>=b.size()){
        while(p1!=a.end()){
            if(p2==b.end()){
                auto element = *p1 + podrazumijevana2;
                v.push_back(element);
                p1++;
            }else{
                auto element = *p1 + *p2;
                v.push_back(element);
                p1++;
                p2++;
            }
        }
    }
    else{
        while(p2!=b.end()){
            if(p1==a.end()){
                auto element = *p2 + podrazumijevana1;
                v.push_back(element);
                p2++;
            }else{
                auto element = *p1 + *p2;
                v.push_back(element);
                p1++;
                p2++;
            }
        }
    }
    return v;

}

int main(){
    int n1, n2; 
    std::cout << "Duzina prvog kontejnera: "; 
    std::cin >> n1; 
    std::vector<double> v(n1); 
    std::cout << "Elementi prvog kontejnera: "; 
    for(double &e : v) std::cin >> e; 
    std::cout << "Duzina drugog kontejnera: "; 
    std::cin >> n2; 
    std::deque<int> d(n2); 
    std::cout << "Elementi drugog kontejnera: "; 
    for(int &e : d) std::cin >> e; 
    std::cout << "Zbir kontejnera: "; 
    for(auto e : ZbirKontejnera(v, d)) std::cout << e << " ";
}