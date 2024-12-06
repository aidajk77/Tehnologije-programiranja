#include<iostream>
#include<cstring>
#include<algorithm>
#include<memory>
using namespace std;
typedef shared_ptr<string> pok_str;

int main(){
    int a;
    cout<<"unesi koliko elemenata"<<endl;
    cin>>a;
    cin.ignore(10000,'\n');
    unique_ptr<pok_str[]> niz = make_unique<pok_str[]>(a);
        for(int i=0;i<a;i++){
            string temp="";
            getline(cin,temp);
            niz[i] = make_shared<string>(temp);
        }
        
        cout<<"sortirano"<<endl;
        sort(niz.get(),niz.get()+a,[](pok_str a, pok_str b){return *a<*b;});
        for(int i=0; i<a; i++){
            cout<<*niz[i]<<endl;
        }
        
        


    



    return 0;
}