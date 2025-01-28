#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef map<string,set<tuple<string,int,int>>> Indeks; 
vector<string> RijeciIzStranice(string s){
    vector<string> rijeci;
    string rijec = "";
    for (int i = 0; i < s.size(); i++) {
            if (isalpha(s.at(i)) || isdigit(s.at(i))) {
                rijec += tolower(s.at(i));
            } else {
                if (!rijec.empty()) {
                    rijeci.push_back(rijec);
                    rijec = "";
                }
            }
    }
    if (!rijec.empty()) {
        rijeci.push_back(rijec);
        rijec = "";
    }
    return rijeci;
}

string PretvoriUMala(string s){
    string rez;
    for(auto x : s){
        if(isalpha(x)){
            rez+=tolower(x);
        }else{
            rez+=x;
        }
    }
    return rez;
}

Indeks KreirajIndeksPojmova (Knjiga k){
    Indeks index;
    int counter=1;
    for(auto poglavlje : k){
        for(string stranica_u_poglavlju : poglavlje.second){
            auto stranica = PretvoriUMala(stranica_u_poglavlju);
            auto rijeci = RijeciIzStranice(stranica);
            for(string rijec : rijeci){
                int pos=0;
                while(stranica.find(rijec,pos)!=string::npos){
                    pos=stranica.find(rijec,pos);
                    index[rijec].insert({poglavlje.first,counter,pos+1});
                    pos+=rijec.size();
                    
                }
            }
            counter++;
        }
    }
    return index;
}

bool SamiZnakovi(string s){
    for(auto x : s){
        if(!isalpha(x) && !isdigit(x)) return false;
    }
    return true;
}

set<tuple<string,int,int>> PretraziIndeksPojmova(string rijec, Indeks index){
    if(!SamiZnakovi(rijec)) throw domain_error("Neispravna rijec");
    set<tuple<string,int,int>> rez;
    rez = index[PretvoriUMala(rijec)];
    return rez;
}

void IspisiIndeksPojmova(Indeks index){
    int counter = 0;
    for(auto x : index){
        cout<<x.first<<": ";
        for(auto y : x.second){
            counter++;
            cout<<get<0>(y)<<"/"<<get<1>(y)<<"/"<<get<2>(y);
            if(counter<x.second.size()){
                cout<<", ";
            }
        }
        counter=0;
        cout<<endl;
    }
}

int main(){
    vector<string> v;
    v.push_back("ABC QWE STSDA ABC ABC DHI QWE HRKW DHI");
    Knjiga k = {{"I",v}};
    auto index = KreirajIndeksPojmova(k);
    auto find = PretraziIndeksPojmova("ABC",index);
    for(auto x : find){
        cout<<get<0>(x)<<"/"<<get<1>(x)<<"/"<<get<2>(x)<<endl;
    }
    cout<<"______________"<<endl;

   IspisiIndeksPojmova(index);


    return 0;
}