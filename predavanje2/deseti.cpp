#include<iostream>
#include<vector>
using namespace std;

int BrojPrijateljskihParova(vector<int> v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        int SumaDjelioca1=0,SumaDjelioca2=0;
        for(int k=1;k<=v[i]/2;k++){
            if(v[i]%k==0) 
            SumaDjelioca1+=k;
        }
        for(int j=i+1;j<v.size();j++){
            for(int k=1;k<=v[j]/2;k++){
            if(v[j]%k==0) SumaDjelioca2+=k;
        }
        if(SumaDjelioca1==v[j] || SumaDjelioca2==v[i])
        sum++;
        }
        SumaDjelioca1=0;
        SumaDjelioca2=0;
    }
    return sum;
}

int main(){
    cout<<"koliko ima brojeva"<<endl;
    int a,b;
    cin>>a;
    vector<int> v;
    for(int i=0;i<a;i++){
        cin>> b;
        v.push_back(b);
    }
    cout<<"broj prijateljskih parova je "<<BrojPrijateljskihParova(v)<<endl;

    return 0;
}