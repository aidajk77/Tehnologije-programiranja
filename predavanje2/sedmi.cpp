#include<iostream>
#include<vector>
using namespace std;

vector<int> IzvodojiElemente(vector<int> v,bool a){
    vector<int> rez1;
    vector<int> rez2;
    int sum=0;
    for(int x:v){
        int temp=x;
        do{
        int zc=temp%10;
        sum+=zc;
        temp=temp/10;
        }while(temp!=0);
        if(sum%2==0) rez1.push_back(x);
        else{
            rez2.push_back(x);
        }
        sum=0;
    }
    if(a)
    return rez1;
    else
    return rez2;

}
int main(){
    cout<<"koliko zelite elemenata"<<endl;
    int a,b;
    cin>>a;
    vector<int> v;
    for(int i=0;i<a;i++){   
        cin>>b;
        v.push_back(b);
    }
    for(int x:v) cout<<x<<" ";
    cout<<endl;
    cout<<"parni brojevi su:"<<endl;
    if(IzvodojiElemente(v,true).size()!=0){
        for(int x:IzvodojiElemente(v,true)){
            cout<<x<<", ";
        }
        cout<<endl;
    }
    else
    cout<<"---"<<endl;
    cout<<"neparni brojevi su:"<<endl;
    if(IzvodojiElemente(v,false).size()!=0){
        for(int x:IzvodojiElemente(v,false)){
            cout<<x<<", ";
        }
        cout<<endl;
    }
    else
    cout<<"---"<<endl;



    return 0;
}