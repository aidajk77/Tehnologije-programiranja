#include<iostream>
#include<string>
#include<vector>
#include<climits>

using namespace std;
long long int pretvaranje(string s, bool minus) {
    long long int a = 0;

    for (int i = 0; i < s.size(); i++) {
        // Pretvorite sljedeću cifru
        int cifra = s[i] - '0';

        // Provjera prekoračenja tijekom množenja s 10
        if (a > LLONG_MAX / 10 || (a == LLONG_MAX / 10 && cifra > LLONG_MAX % 10)) {
            throw range_error("PROBLEM: Uneseni string sadrzi prevelik broj!!!");
        }

        // Provjera prekoračenja za negativne brojeve
        if (minus && (a < LLONG_MIN / 10 || (a == LLONG_MIN / 10 && -cifra < LLONG_MIN % 10))) {
            throw range_error("PROBLEM: Uneseni string sadrzi premali broj!!!");
        }

        // Množenje s 10 i dodavanje cifre
        a = a * 10 + cifra;
    }

    // Ako se očekuje negativan broj, invertirajte `a`
    if (minus) {
        a = -a;
    }

    return a;
}

vector<long long int> BrojeviUStringu(string s){
    vector<long long int> v;
    s=s+" ";
    string rijec="";
    bool minus=false;
    long long int a;
    for(int i=0;i<s.size();i++){
        if(i==0){
            if(isdigit(s.at(i)))
            rijec=rijec+s.at(i);
            if(s.at(i)=='-')
            minus=true;
            continue;
        }
        if(isdigit(s.at(i))){
            if(s.at(i-1)=='-'){
                minus=true;
            }
            rijec=rijec+s.at(i);
        }
        if(isalpha(s.at(i))){
            if(rijec.size()!=0){
            rijec="";
            minus=false;
            }
        }
        if(!isalpha(s.at(i)) && !isdigit(s.at(i))){
            if(rijec.size()!=0){
                a=pretvaranje(rijec,minus);
                rijec="";
                v.push_back(a);
                minus=false;
            }
        }

    }
return v;

}
int main(){
    try{
    string s;
    cout<<"Unesite string: ";
    getline(cin,s);
    auto v=BrojeviUStringu(s);
    if(v.size()==0){
        cout<<"Uneseni string ne sadrzi nijedan broj!"<<endl;
        return 0;
    }
    cout<<"Brojevi unutar stringa: ";
    for(int x:v){
        cout<<x<<" ";
    }
    }
    catch(range_error e){
        cout<<e.what()<<endl;
    }
    

    return 0;
}