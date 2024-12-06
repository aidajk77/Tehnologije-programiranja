#include <iostream>
#include <set>
using namespace std;

template <typename t>
set<t> unija(set<t> a, set<t> b){
    set<t> rez;
    for(auto x : a){
        rez.insert(x);
    }
    for(auto y : b){
        rez.insert(y);
    }
    return rez;
}

template <typename t>
set<t> presjek(set<t> const &a, set<t> const &b){
    set<t> rez;
    for(auto x : a){
        for(auto y : b){
            if(x==y){
                rez.insert(x);
            }
        }
    }
    
    return rez;
}


int main(){
    int a,b;
    set<int> s1,s2,s3;
    cout<<"koliko elemenata u prvom skupu"<<endl;
    cin>>a;
    for(int i=0;i<a;i++){
        cout<<"unesi element"<<endl;
        cin>>b;
        s1.insert(b);
    }
    cin.ignore(10000,'\n');
    cout<<"koliko elemenata u drugom skupu"<<endl;
    cin>>a;
    for(int i=0;i<a;i++){
        cout<<"unesi element"<<endl;
        cin>>b;
        s2.insert(b);
    }
    s3=presjek(s1,s2);
    for(int i : s3){
        cout<<i<<" ";
    }




    return 0;
}