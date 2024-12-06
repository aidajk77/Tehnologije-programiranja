#include<iostream>
using namespace std;
int cifre(long long int n,int &c_max, int &c_min){
    int br=0;
    c_max=-1;
    c_min=10;
    do{
        int zc=n%10;
        if(zc<0) zc=-zc;
        if(zc>c_max) c_max=zc;
        if(zc<c_min) c_min=zc;
        n=n/10;
        br++;
    }while(n!=0);
    return br;
}

int main(){
    int a,b;
    cout<<cifre(-12345,a,b)<<" "<<a<<" "<<b<<endl;
    return 0;
}