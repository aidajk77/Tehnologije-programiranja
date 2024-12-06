#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using namespace std;
typedef vector<int> IntVector;
typedef vector<IntVector> IntMatrica;
int MaxSirina(IntMatrica m){
    int  max=0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            int temp=m[i][j];
            int br=0;
            if(temp<0 || temp==0) br++;
            while(temp!=0){
                br++;
                temp/=10;
            }
            if(br>max)
            max=br;
            
        }
    }
    return max;
}
IntMatrica PaskalovTrougao(int n){
    if(n<0){
        throw domain_error("Broj redova ne smije biti negativan");
    }
    IntMatrica m(n);
    if(n==0)
    return m;
    for(int i=0;i<m.size();i++){
        m.at(i).resize(i+1);
    }
    m[0][0]=1;
    for(int i=1;i<m.size();i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                m.at(i).at(j)=1;
            }
            else{
                m.at(i).at(j)=m.at(i-1).at(j)+m.at(i-1).at(j-1);
            }
        }
    }
    return m;
}
int main(){
    try{
    int a;
    cout<<"unesi broj redova"<<endl;
    cin>>a;
    auto m=PaskalovTrougao(a);
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout<<setw(MaxSirina(m))<<m.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
    return 0;
    }
    catch(domain_error e){
        cout<<e.what()<<endl;
    }
}