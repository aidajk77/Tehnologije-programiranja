#include<iostream>
#include<string>
using namespace std;
void izvrniString(string& s){
    int a=0,b=s.size()-1;
    while(b>a){
        char c=s.at(a);
        s.at(a)=s.at(b);
        s.at(b)=c;
        a++;
        b--;
    }
}
int main(){
    string s="oOvo je neki tekst...";
    izvrniString(s);
    cout<<s<<endl;


    return 0;
}