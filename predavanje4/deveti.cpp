#include<iostream>
#include<string>
using namespace std;

void ruraliziraj(string &s){
    for(int i=0;i<s.size();i++){
        if(tolower(s.at(i))=='a' || tolower(s.at(i))=='e' || tolower(s.at(i))=='i' || tolower(s.at(i))=='o' || tolower(s.at(i))=='u' ){
            if(islower(s.at(i))){
                s.insert(s.begin()+i,s.at(i));
                i++;
            }
            else{
                s.insert(s.begin()+i+1,tolower(s.at(i)));
                i++;
            }
        }
    }

} 

int main(){
    string s= "Johan Straus je iz Austrije";
    ruraliziraj(s);
    cout<<s<<endl;
    cout<<"Joohaan Straauus jee iiz Aauustriijee"<<endl;
}