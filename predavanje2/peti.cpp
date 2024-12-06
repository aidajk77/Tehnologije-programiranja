#include<iostream>
#include<vector>
using namespace std;
bool prost(int n){
    if(n==2 || n==3) return true;
    for(int i=2;i<=n/2;i++){
        if(n%i==0)
        return false;
    }
    return true;
}
vector<int> ProstiFaktori(int a){
    vector<int> v;
    for(int i=2;i<a/2;i++){
        if(a%i==0){
            if(prost(i)){
                v.push_back(i);
            }
        }
    }
    return v;
}
vector<int> ProstiFaktoriSPonavljanjem(int a){
    vector<int> v1=ProstiFaktori(a);
    vector<int> v2;
    for(int i=0;i<v1.size();i++){
        while(a%v1[i]==0){
            v2.push_back(v1[i]);
            a=a/v1[i];
        }

    }
    return v2;
}
int main(){
    cout<<"unesite broj"<<endl;
    int a;
    cin>>a;
    cout<<"prosti faktori su:"<<endl;
    vector<int>v1=ProstiFaktori(a);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<", ";
    }
    cout<<endl;
    cout<<"prosti faktori s ponavljanjem su:"<<endl;
    vector<int>v2=ProstiFaktoriSPonavljanjem(a);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<", ";
    }
    

    return 0;
}