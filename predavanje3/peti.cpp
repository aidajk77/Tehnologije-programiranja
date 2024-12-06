#include<iostream>
#include<string>
using namespace std;

string satrovacki(string s){

    string samoglasnici="aeiou";
    string rez="";
    for(int i=0;i<s.size();i++){
        int velicina=rez.size();
        for(int j=0;j<samoglasnici.size();j++){
            if(s[i]==samoglasnici[j]){
                rez=rez+s[i]+"p"+s[i];
                break;
            }
            if(s[i]==toupper(samoglasnici[j])){
                    rez=rez+s[i]+"p"+char(tolower(s[i]));
                    break;
            }
        }
        if(velicina!=rez.size()){
            continue;
        }
        rez+=s[i];
    }
    return rez;
}
int main(){
    cout<<"unesite recenicu"<<endl;
    string s="";
    getline(cin,s);
    cout<<"data recenica na satrovackom je:"<<endl<<satrovacki(s)<<endl;

    return 0;
}