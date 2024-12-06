#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int main(){
    int a;
    cout<<"unesi koliko elemenata"<<endl;
    cin>>a;
    cin.ignore(10000,'\n');
    string** niz{};
    try{
        niz = new string*[a]{};
        for(int i=0;i<a;i++){
            niz[i] = new string;
            getline(cin,*niz[i]);
        }
        
        cout<<"sortirano"<<endl;
        sort(niz,niz+a,[](string* a, string* b){return *a<*b;});
        for(int i=0; i<a; i++){
            cout<<*niz[i]<<endl;
        }
        for(int i=0;i<a;i++){
            delete niz[i];
        }
        delete[] niz;
        


    }catch(...){
        for(int i=0;i<a;i++){
            delete[] niz[i];
        }
        delete[] niz;

    }



    return 0;
}