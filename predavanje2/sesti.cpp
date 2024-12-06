#include<iostream>
#include<vector>
using namespace std;

bool TestPerioda(vector<double> v,int p){
    for(int i=0;i<v.size()-p;i++){
        if(v.at(i)!=v.at(i+p)) return false;
    }
    return true;
}
int OdrediOsnovniPeriod(vector<double> v){
    int br=1;
    do{
        if(TestPerioda(v,br)){
                return br;
            }
        br++;
    }while(br!=v.size());
    return 0;
}
int main(){
    cout<<"unesite brojeve"<<endl;
    double a;
    vector<double> v;
    do{
        cin>>a;
        if(a!=0)
        v.push_back(a);
    }while(a!=0);
    int b=OdrediOsnovniPeriod(v);
    for(double x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    if(b!=0){
        cout<<"Osnovni period je "<<b<<endl;
    }
    else{
        cout<<"nema perioda"<<endl;
    }



    return 0;
}