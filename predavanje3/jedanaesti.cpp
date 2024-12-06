#include<iostream>
#include<array>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int SaberiCifre(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum;

    
}
int DigitalniKorijen(int n){
    
    while(abs(n)>9){
        n=SaberiCifre(abs(n));
    }
    return n;
    
    
}
array< vector<int> ,10 > Razvrstaj(vector<int> v){
    array<vector<int>, 10> niz;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<niz.size();j++){
            if(DigitalniKorijen(v[i])==j)
            niz[j].push_back(v[i]);
        }
    }
    return niz;


}

int main(){
    vector<int> v{5, 19, -332, 65413, 29, 788, -6, 0, 4219, 99, -100};
    auto niz=Razvrstaj(v);
    for(int i=0;i<niz.size();i++){
        cout<<"digitalni korijen "<<i<<": ";
        for(int j=0;j<niz[i].size();j++){
            cout<<niz[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}