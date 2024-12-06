#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<double>> matrica;
void AnalizaMatrice(const matrica& m,vector<int> &v1,vector<int> &v2){
    v1.resize(0);
    v2.resize(0);
    if(m.size()==0) throw domain_error("prazna matrica");
    for(int i=0;i<m.size();i++){
        if(m.at(i).size()!=m.at(i).size()) throw domain_error("grbava matrica");
        bool nula=true;
        for(int j=0;j<m.at(i).size() && nula;j++){
            if(m.at(i).at(j)!=0) nula=false;
        }
        if(nula) v1.push_back(i);
    }
    for(int i=0;i<m.at(0).size();i++){
        bool nula=true;
        for(int j=0;j<m.size() && nula;j++){
            if(m.at(j).at(i)!=0) nula=false;
        }
        if(nula) v2.push_back(i);
    }


}
int main(){
    cout<<"unesite dimenzije"<<endl;
    int a,b,c;
    cin>>a>>b;
    cout<<"unesite elemente"<<endl;
    matrica m;
    m.resize(a);
    for(int i=0;i<m.size();i++){
        m.at(i).resize(b);
        for(int j=0;j<m.at(i).size();j++){
            cin>>c;
            m.at(i).at(j)=c;
        }
    }
    vector<int> red,kolona;
    AnalizaMatrice(m,red,kolona);
    for(auto x:red){
        cout<<x<<" ";
    }
    cout<<endl;
      for(auto x:kolona){
        cout<<x<<" ";
    }
}