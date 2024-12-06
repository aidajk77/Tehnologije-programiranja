#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
string IzdvojiRijec(string s,int n){
    if(n<1)
        throw range_error("pogresan redni broj rijeci");
    string rijec="";
    int br=0;
    s=" "+s+" ";
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==' ' && s[i+1]!=' '){
            br++;
            continue;
        }
        if(br==n){
            if(s[i]==' '){
            break;
            }
            rijec=rijec+s[i];

        }
        
    }
    if(br<n)
        throw range_error("pogresan redni broj rijeci");
    return rijec;
}
int main(){
    int n;
    string s;
    cout<<"unesi recenicu pa zatim redni broj rijeci"<<endl;
    getline(cin,s);
    cin>>n;
    try{
        string rez=IzdvojiRijec(s,n);
        cout<<"rijec na toj poziciji je:"<<endl;
        cout<<rez<<endl;
    }
    catch(range_error e){
        cout<<e.what()<<endl;
    }
    


    return 0;
}