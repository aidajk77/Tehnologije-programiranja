#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <cmath>

using namespace std;

bool prime(int a){
    if(abs(a)==2) return true;
    int counter=0;
    for(int i=2;i<abs(a)/2+1;i++){
        if(a%i==0) return false;
    }
    return true;
}

int nzd(int a, int b){
    a=abs(a);
    b=abs(b);
    int nzd=1;
    int temp;
    if(abs(a)>abs(b)) {
        temp=b;
    }
    else {
        temp=a;
    }
    int i=2;
    do{
        if(prime(i)){
            if(a%i==0 && b%i==0){
                nzd*=i;
                a/=i;
                b/=i;
                temp/=i;
                continue;
            }      
        }
        i++;

    }while(temp>=i);
    return nzd;
}

int NajveciZajednickiDjelilac(list<int> const & lista){
    if(lista.size()==0) return 0;
    auto it1 = lista.begin();
    bool sve_nule=true;
    int nzd_varijabla=1;
    for(auto it = next(it1); it!=lista.end();it++){
        if(*it!=0) sve_nule=false;
        if(*it1==0 || *it==0){
            it1++;
            continue;
        }
        if(nzd_varijabla==1 || nzd(*it1,*it)<nzd_varijabla){
            nzd_varijabla=nzd(*it1,*it);
            if(nzd_varijabla==1) return 1;
        }
        it1++;
    }
    if(sve_nule) return 0;
    return nzd_varijabla;
}

int main(){
    int n; 
    cout << "Koliko ima brojeva: "; 
    cin >> n; 
    list<int> v(n); 
    cout << "Unesite brojeve: "; 
    for(int &e : v) cin >> e; 
    cout << "Njihov najveci zajednicki djelilac je "<<NajveciZajednickiDjelilac(v)<<endl;

    return 0;
}