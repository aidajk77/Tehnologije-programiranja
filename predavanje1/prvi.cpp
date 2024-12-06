#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cout<<"unesi dimenzije bazena"<<endl;
    cin>>a>>b>>c;
    cout<<"unesi sirinu plocice"<<endl;
    cin>>d;
    a*=100;
    b*=100;
    c*=100;
    int p_bazena=a*b+2*a*c+2*b*c;
    int p_plocice=d*d;
    if((a*c) % p_plocice == 0 && (b*c) % p_plocice == 0 && (a*b) % p_plocice == 0){
        cout<<"Plocica treba "<<p_bazena/p_plocice<<endl;
    }else{
        cout<<"nije moguce poplocati bez razbijanja"<<endl;
    }

    return 0;
}