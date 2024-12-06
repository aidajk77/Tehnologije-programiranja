#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef vector<vector<int>> matrica;
void minimaxAndMaximin(const matrica& m,int& minimax, int& maximin){
    if(m.size()==0){
        throw domain_error("Neispravna matrica");
    }
    minimax=INT_MAX;
    maximin=INT_MIN;
    int max=INT_MIN;
    int min=INT_MAX;
    int size=m.at(0).size();
    for(int i=0;i<m.size();i++){
        if(m.at(i).size()!=size){
            throw domain_error("Parametar nema formu matrice");
        }
        for(int j=0;j<m.at(i).size();j++){
            if(m.at(i).at(j)>max){
                max=m.at(i).at(j);
            }
            if(m.at(i).at(j)<min){
                min=m.at(i).at(j);
            }

        }
        if(max<minimax) minimax=max;
        if(min>maximin) maximin=min;
        max=INT_MIN;
        min=INT_MAX;
    }

}
int main(){
    matrica m;
    int a,b,c,minimax,maximin;
    cout<<"unesite dimenzije"<<endl;
    cin>>a>>b;
    cout<<"unesite elemente"<<endl;
    m.resize(a);
    for(int i=0;i<a;i++){
        m.at(i).resize(b);
        for(int j=0;j<m.at(i).size();j++){
            cin>>c;
            m.at(i).at(j)=c;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<m.at(i).size();j++){
            cout<<m.at(i).at(j)<<" ";
        }
        cout<<endl;
         
    }
    cout<<"__________"<<endl;
    try{
    minimaxAndMaximin(m,minimax,maximin);
    cout<<minimax<<" "<<maximin<<endl;
    return 0;
    }
    catch(domain_error& e){
        cout<<e.what()<<endl;
    }
}