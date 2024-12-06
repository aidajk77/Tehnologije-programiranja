#include<iostream>
using namespace std;
int main(){
    double a=-1,sum=0;
    while(a!=0) {
        cin>>a;
    while(!cin || a<0 || int(a)!=a){
        cout<<"unesite fin broj"<<endl;
        cin.clear();
        cin.ignore(100000,'\n');
        cin>>a;
    }
    if(a==0) break;
   int b=a;
    for(int i=1;i<=b/2;i++){
        if(b%i==0){
            sum+=i;
        }
    }
    if(sum>a){
        cout<<"obilan"<<endl;
    }else if(sum==a){
        cout<<"savrsen"<<endl;
    }else{
        cout<<"manjkav"<<endl;
    }
    sum=0;
    cin.ignore(10000,'\n');
    cout<<"unesi novi broj"<<endl;
    }    
    cout<<"dovidjenja"<<endl;
}