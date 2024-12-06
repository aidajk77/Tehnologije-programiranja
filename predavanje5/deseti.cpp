#include<iostream>
#include <type_traits> 
#include <vector>
#include <list>
using namespace std;

template < typename iterTip1, typename iterTip2, typename funTip>
auto GeneraliziraniSkalarniProdukt(iterTip1 a, iterTip1 b,iterTip2 c, funTip f){
    decltype(f(*a,*c)) suma{}; 
    while(a!=b){
        suma+=f(*a,*c);
        a++;
        c++;
    }
    return suma;
}


int main() { 
  int n; 
  std::cout << "Duzina sekvenci: "; 
  std::cin >> n; 
  std::list<double> l1(n), l2(n); 
  std::cout << "Unesite prvu sekvencu: "; 
  for(double &e : l1) std::cin >> e; 
  std::cout << "Unesite drugu sekvencu: "; 
  for(double &e : l2) std::cin >> e; 
  std::cout << "Skalarni produkt: " << GeneraliziraniSkalarniProdukt( 
    l1.begin(), l1.end(), l2.begin(), [](double x, double y) { return x * y; }); 
  return 0; 
}