#include<iostream>
#include<vector>
using namespace std;
bool prost(int n){
    for(int i=2;i<n/2;i++){
        if(n%i==0)
        return false;
    }
    return true;
}

vector<int> OpsegProstih(int a,int b){
    vector<int> v;
    for(int i=a;i<b;i++){
        if(prost(i))
        v.push_back(i);
    }
    return v;
}

int main(){
    vector<int> v;
    int a,b;
    cout<<"unesi dva broja"<<endl;
    cin>>a>>b;
    v=OpsegProstih(a,b);
    if(v.size()==0)
    cout<<"prazno"<<endl;
    else{
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
    }
}