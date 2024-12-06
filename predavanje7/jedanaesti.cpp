#include <iostream>
#include <functional>
#include <memory>
using namespace std;

unique_ptr<double[]> Tabeliraj(function<double(double)> fun,double xmin, double xmax, int n){
    if(n < 2 || xmin > xmax) throw std::domain_error("Neispravni parametri"); 
    double razmak = (xmax-xmin)/(n-1);
    auto niz = make_unique<double[]>(n);
    for(int i=0;i<n;i++){
        niz[i]=fun(xmin+i*razmak);
    }
    return niz;
        
}

int main(){
    cout<<"Vrijednosti funkcije za x od 0 do 5 s korakom 0.5: ";
    auto p = Tabeliraj([](double x){return x*x*x;},0,5,11);
    for(int i=0;i<11;i++){
        cout<<p[i]<<" ";
    }

    return 0;
}