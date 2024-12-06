#include<iostream>

using namespace std;

enum class NacinAlokacije{Fragmentirano, Kontinualno};

int** TablicaMnozenja(int n,NacinAlokacije nacin){
    if(n<=0) return nullptr;
    int** pok_mat{};
    if(nacin==NacinAlokacije::Fragmentirano){
        try{
            auto pok_mat=new int*[n]{};
            for(int i=1;i<n+1;i++){
                pok_mat[i-1]=new int[n];
                for(int j=1;j<n+1;j++){
                    pok_mat[i-1][j-1]=i*j;
                }
            }
            return pok_mat;
        }
        catch(...){
            for(int i=0;i<n;i++){
                delete[] pok_mat[i];
            }
            delete[] pok_mat;
            throw;
        }
    }
    if(nacin==NacinAlokacije::Kontinualno){
        try{
            auto pok_mat=new int*[n*n]{};
            for(int i=1;i<n;i++){
                pok_mat[i]=pok_mat[i-1]+n;
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<n+1;j++){
                    pok_mat[i-1][j-1]=i*j;
                }
            }
            return pok_mat;
        }
        catch(...){
            delete[] pok_mat;
            throw;
        }
    }
}

int main(){
    int n;
    cout<<"unesi broj"<<endl;
    cin>>n;
    try{
    auto tablica=TablicaMnozenja(n,NacinAlokacije::Fragmentirano);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<tablica[i][j]<<" ";
        }
        cout<<endl;
    }
    }catch(...){
        cout<<"neuspjela alokacija"<<endl;
    }

    return 0;
}