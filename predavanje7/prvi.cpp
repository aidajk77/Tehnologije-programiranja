#include<iostream>
#include<cstring>
using namespace std;

void sortiranje(char** niz, int velicina){
    for(int i=0;i<velicina-1;i++){
        for(int j=0;j<velicina-i-1;j++){
            if(*niz[j] > *niz[j+1]){
                auto temp=niz[j];
                niz[j]=niz[j+1];
                niz[j+1]=temp;
            }
        }
    }
}

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
        sortiranje(niz, a);
        cout<<"sortirano"<<endl;
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