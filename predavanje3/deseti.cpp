#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string IzvrniRedoslijedRijeci(string s){
    s=s+" ";
    string rez="";
    string rijec="";
    for(int i=0;i<s.size();i++){
        if(s[i]==' ' && rijec.size()!=0){
            reverse(rijec.begin(),rijec.end());
            rez=rez+rijec+" ";
            rijec="";
        }
        if(s[i]!=' '){
            rijec.push_back(s[i]);
        }
    }
    reverse(rez.begin(),rez.end());
    if(rez[0]==' ')
    rez.erase(0,1);
    
    return rez;


}

int main(){
    string s="      Na        vrh       brda,     vrba        mrda!!!";
    cout<<IzvrniRedoslijedRijeci(s)<<endl;

    return 0;
}