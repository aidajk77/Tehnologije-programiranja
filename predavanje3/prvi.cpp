#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
typedef vector<int> IntVector;
typedef vector<IntVector> IntMatrica;
IntMatrica KroneckerovProizvod(IntVector v1,IntVector v2){
    IntMatrica m(v1.size(),IntVector(v2.size()));
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            m[i][j]=v1[i]*v2[j];
        }
    }
    return m;
    
}
int main(){
    cout<<"unesite koliko ce elemenata biti u prvom vektoru"<<endl;
    int a,b,c,max=0;
    cin>>a;
    cout<<"unesite koliko ce elemenata biti u drugom vektoru"<<endl;
    cin>>b;
    IntVector v1,v2;
    for(int i=0;i<a;i++){
        cout<<"unesite element"<<endl;
        cin>>c;
        v1.push_back(c);
    }
    /*for(int i=0;i<b;i++){
        cout<<"unesite element"<<endl;
        cin>>c;
        v2.push_back(c);
    }*/
    auto m=KroneckerovProizvod(v1,v2);
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            int temp=m[i][j];
            int br=0;
            if(temp<0) br++;
            while(temp!=0){
                br++;
                temp/=10;
            }
            if(br>max)
            max=br;
            
        }
    }
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            cout<<setw(max+1)<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}