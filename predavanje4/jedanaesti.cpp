#include<iostream>
#include<string>
using namespace std;
void IzbaciRijec(string &s,int n){
    int br=1;
    for(int i=0;i<s.size();i++){
       if(s.at(i)!=' '){
        if(br==n){
           while(i<s.size() && s.at(i)!=' '){
            s.erase(i,1);
        } 
            br++;
        }
        else{
            while(i<s.size() && s.at(i)!=' '){
                i++;
            }
            br++;
        }
       }
    }
    br--;
    if(n<1 || br<n) throw range_error("nema toliko rijeci");

}
int main(){
    string s="          ";
    try{
    IzbaciRijec(s,10);
    cout<<s<<endl;
    }
    catch(range_error &e){
        cout<<e.what()<<endl;
    }




}