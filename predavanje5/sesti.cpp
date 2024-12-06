#include<iostream>
#include <algorithm>
#include<vector> 
using namespace std;
int bc(int a){
    a=abs(a);
    if(a==0)
        return 0;
    return 1+bc(a/10);
}

bool kriterij(int a, int b){
    if(bc(a)!=bc(b)) return bc(a)<bc(b);
    return a<b;
}
int main(){
    int n,a,b;
    vector<int> v;
    cout<<"unesi broj elemenata"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"unesi element"<<endl;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),kriterij);
    cout<<"unesi broj"<<endl;
    cin>>b;
    cout<<lower_bound(v.begin(),v.end(),b)-v.begin()<<endl;
    for(int i=0;i<10;i++){
        cout<<v.at(i)<<" ";
    }

    return 0;
}