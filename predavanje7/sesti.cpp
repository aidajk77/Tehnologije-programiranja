#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template <typename TipElemenata> 
  void SortirajListu(list<TipElemenata> &lista) { 
    for(auto it1 = lista.begin(); it1 != lista.end(); it1++) { 
      auto gdje_je_min = it1; 
      for(auto it2 = it1; it2 != lista.end(); it2++) 
        if(*it2 < *gdje_je_min) gdje_je_min = it2; 
      if(*gdje_je_min != *it1) swap(*it1, *gdje_je_min); 
  } 
  }


int main(){
    cout<<"koliko ima elemenata"<<endl;
    int a,b;
    cin>>a;
    list<int> l;
    cout<<"unesi elemente"<<endl;
    for(int i=0;i<a;i++){
        cin>>b;
        l.push_back(b);
    }
    SortirajListu(l);
    for(int i:l){
        cout<<i<<" ,";
    }

    return 0;
}