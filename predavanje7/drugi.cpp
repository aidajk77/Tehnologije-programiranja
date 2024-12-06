#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int main(){
    int a;
    cout<<"unesi koliko elemenata"<<endl;
    cin>>a;
    cin.ignore(10000,'\n');
    char** niz{};
    try{
        niz = new char*[a]{};
        for(int i=0;i<a;i++){
            char temp[1000];
            cin.getline(temp,sizeof temp);
            niz[i] = new char[strlen(temp)+1];
            strcpy(niz[i], temp);
        }
        
        cout<<"sortirano"<<endl;
        sort(niz,niz+a,[](char* a, char* b){return *a<*b;});
        for(int i=0; i<a; i++){
            cout<<niz[i]<<endl;
        }
        for(int i=0;i<a;i++){
            delete[] niz[i];
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