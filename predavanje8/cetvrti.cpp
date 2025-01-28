#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

string ZamijeniPremaRjecniku(string s,map<string,string> const& rjecnik){

    string rezultat;
    string rijec=""; 
    bool traje_rijec = false;
    for(int i=0;i<s.size();i++){
        if(isalpha(s.at(i))) traje_rijec=true;
        else {
            traje_rijec=false;
        }
        if(traje_rijec) rijec+=s.at(i);
        else {
            if(rjecnik.find(rijec)!=rjecnik.end()){
                rijec=rjecnik.at(rijec);
                rezultat+=rijec;
                rijec="";
            }else{
                rezultat+=rijec;
                rijec="";
            }
        }
        if(!traje_rijec && rijec=="") rezultat+=s.at(i);
        if(i==s.size()-1){
            if(rjecnik.find(rijec)!=rjecnik.end()){
                rijec=rjecnik.at(rijec);
                rezultat+=rijec;
                rijec="";
            }else{
                rezultat+=rijec;
                rijec="";
            }
        }
    }
    return rezultat;
}

int main(){
    std::map<std::string, std::string> rjecnik{{"jabuka", "apple"}, {"da", "yes"}, 
    {"kako", "how"}, {"ne", "no"}, {"majmun", "monkey"}, {"mart", "ozujak"}, 
    {"maj", "svibanj"}, {"jul", "srpanj"}}; 
  std::cout << ZamijeniPremaRjecniku("  kako   da   ne   ", rjecnik) << std::endl 
    << ZamijeniPremaRjecniku("danas je 8. mart a 1. maj je praznik rada", rjecnik)  
    << std::endl 
    << ZamijeniPremaRjecniku("davor martic ima sestre maju i juliju", rjecnik)  
    << std::endl; 
  return 0; 
}
