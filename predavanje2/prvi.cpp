#include<iostream>
#include<complex>
#include<cmath>
using namespace std;
int main(){
    const double pi=4*atan(1);
    double a,b;
    complex<double> z,rez=(0,0);
    int broj;
    cout<<"koliko elemenata ce bit?"<<endl;
    cin>>broj;
    for(int i=0;i<broj;i++){
        cout<<"unesi kompleksni broj"<<endl;
        cin>>a>>b;
        b=b*(pi/180);
        z=polar(a,b);
        rez+=1./z;
        
    }
    rez=1./rez;
    cout<<abs(rez)<<" "<<arg(rez)*(180/pi)<<endl;
    


    return 0;
}