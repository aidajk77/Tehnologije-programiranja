#include <iostream>
#include <set>
#include<algorithm>
#include<iterator>

using namespace std;

template<typename kontejner, typename fun>
kontejner Mapiraj(kontejner const& kont,fun f){
    kontejner mapirani_kontejner;
    for(auto it=kont.begin();it!=kont.end();it++){
        mapirani_kontejner.insert(mapirani_kontejner.end(),f(*it));
    }
    return mapirani_kontejner;

    
}

int main(){

    set<int>skup;
    int a;
    cout<<"unesi elemente"<<endl;
    for(int i=0;i<3;i++){
        cin>>a;
        skup.insert(a);
    }
    auto novi_skup = Mapiraj(skup,[](int n) { 
        int suma = 0; 
        for(;n != 0; n /= 10) suma += n % 10; 
        return suma >= 0 ? suma : -suma; 
    });
    for(auto it=novi_skup.begin();it!=novi_skup.end();it++){
        cout<<*it<<" ";
    }
    


    return 0;
}