#include<iostream>
#include<string>
#include<vector>

using namespace std;
bool simetricnost(string s){
    if(s.size()==1) return false;
    for(int i=0;i<s.size();i++){
        if(toupper(s[i])!=toupper(s[s.size()-1-i]))
        return false;
    }
    return true;
}

vector<string> IzdvojiSimetricneRijeci(string s){
    vector<string> v;
    string rijec="";
    for(int i=0;i<s.size();i++){
        if(!isalpha(s[i]) && rijec.size()!=0){
            if(simetricnost(rijec))
            v.push_back(rijec);
            rijec="";
        }
        if(isalpha(s[i]) || isdigit(s[i])){
            rijec.push_back(s[i]);
        }
    }
    return v;



}

int main(){
    string s=" Aziza, uberi taj mirisni neven i udji u kajak!";
    vector<string> v=IzdvojiSimetricneRijeci(s);
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1){
            cout<<v[i]<<endl;
            break;
        }
        cout<<v[i]<<", ";
    }

    return 0;
}