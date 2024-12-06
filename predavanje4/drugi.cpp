#include<iostream>
using namespace std;
/*
void OdstraniParneCifre(int &n){
    int temp=0;
    bool minus;
    do{
       int zc=n%10;
       cout<<zc<<endl;
        if(zc%2!=0) {
            temp=temp*10+zc;
        }    
        n/=10;
    }while(n!=0);
    cout<<temp<<endl;
    if(temp!=0){
        do{
            int zc=temp%10;
            if(zc%2!=0) n=n*10+zc;
            temp/=10;
        }while(temp!=0);
    }
    else{
        n=temp;
    }
    cout<<n<<endl;
}    
*/

void OdstraniParneCifre(int &n) {
 int novi = 0, tezina = 1;
 while(n != 0) {
 int cifra = n % 10;
 if(cifra % 2 != 0) {
 novi += cifra * tezina; tezina *= 10; 
 }
 n /= 10;
 }
 n = novi;
}


int main(){
    int a=-12345;
    OdstraniParneCifre(a);
    cout<<a<<endl;

    return 0;
}