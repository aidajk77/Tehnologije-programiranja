#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
typedef vector<int> IntVector;
typedef vector<IntVector> IntMatrica;


/*int BrojStacionarnih(IntMatrica m){
    if(m.size()==0) return 0;
    int br=0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            if(i==0 && j==0){
                if(m.at(i).size()>1){
                if(m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
                }
            }
            if(i==0 && j==m.at(i).size()-1){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(i==0){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(i==m.size()-1 && j==0){
                if(m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i-1).at(j))
                br++;
                continue;
            }
            if(i==m.size()-1 && j==m.at(i).size()-1){
                if(m.at(i).at(j)==m.at(i-1).at(j) && m.at(i).at(j)==m.at(i).at(j-1))
                br++;
                continue;
            }
            if(i==m.size()-1){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i-1).at(j))
                br++;
                continue;
            }
            if(j==0){
                if(m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i-1).at(j) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(j==m.at(i).size()-1){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i-1).at(j) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i+1).at(j) && m.at(i).at(j)==m.at(i-1).at(j))
            br++;

           
        }
    }
    return br;
}


*/
int BrojStacionarnih(IntMatrica m){
    if(m.size()==0) return 0;
    int br=0;
    int brojElemenata=m.at(0).size();
    for(int i=0;i<m.size();i++){
        if(m.at(i).size()!=brojElemenata){
            throw domain_error("grbava matrica");
        }
        for(int j=0;j<m[i].size();j++){
            if(i==0 && j==0){
                if(m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(i==0 && j==m.at(i).size()-1){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(i==0){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(i==m.size()-1 && j==0){
                if(m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i-1).at(j))
                br++;
                continue;
            }
            if(i==m.size()-1 && j==m.at(i).size()-1){
                if(m.at(i).at(j)==m.at(i-1).at(j) && m.at(i).at(j)==m.at(i).at(j-1))
                br++;
                continue;
            }
            if(i==m.size()-1){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i-1).at(j))
                br++;
                continue;
            }
            if(j==0){
                if(m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i-1).at(j) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(j==m.at(i).size()-1){
                if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i-1).at(j) && m.at(i).at(j)==m.at(i+1).at(j))
                br++;
                continue;
            }
            if(m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i+1).at(j) && m.at(i).at(j)==m.at(i-1).at(j))
            br++;

           
        }
    }
    return br;
}



int main(){
    cout<<"unesite dimenzije matrice"<<endl;
    int a,b,c;
    cin>>a>>b;
    IntMatrica m{{1,1,1}};
   /* for(int i=0;i<m.size();i++){
        m[i].resize(b);
    }
    cout<<"unesite matricu"<<endl;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m.at(i).size();j++){
            cin>>c;
            m.at(i).at(j)=c;
        }
    }
    */
    cout<<"broj stacionarnih elemenata je "<<BrojStacionarnih(m)<<endl;


    return 0;
}