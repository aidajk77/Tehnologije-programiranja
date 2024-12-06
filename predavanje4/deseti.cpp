#include<iostream>
#include<string>
using namespace std;
void transformiraj(string& s){
    for(int i=0;i<s.size()-1;i++){
        if(isalpha(s.at(i))){
            s.at(i)=toupper(s.at(i));
        }
        if(s.at(i)==' ' && !isalpha(s.at(i+1))){
            s.erase(i,1);
            i--;
        }
    }
    cout<<s<<endl;
    if(s.at(0)==' ')
        s.erase(0,1);
    if(isalpha(s.at(s.size()-1))){
        s.at(s.size()-1)=toupper(s.at(s.size()-1));   
    }          
    if(s.at(s.size()-1)==' '){
        s.erase(s.size()-1,1);
    }

}
int main(){
    string s="          AId      samed  s";
    transformiraj(s);
    cout<<s<<endl;
}