#include <iostream>
#include<cmath>
using  namespace std;

double trapezno_pravilo(double fun(double), double a, double b, int n){
    double rez=(fun(a)+fun(b))/2;
    for(int i=1;i<n;i++){
        rez+=fun(a+(b-a)*i/n);
    }
    rez=(b-a)*rez/n;
    return rez;
}

int main(){
    const double pi = 4 * atan(1);
    cout<<trapezno_pravilo(sin,0,pi,70)<<endl;
    cout<<trapezno_pravilo([](double x){return x*x*x;},0,10,70);

    return 0;
}