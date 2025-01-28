#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>


using namespace std;

map<string,set<pair<int,int>>> KreirajIndeksPojmova(vector<string> stranice){
    map<string,set<pair<int,int>>> indeks_pojmova;
    
    for (int i = 0; i < stranice.size(); i++) {
        string rijec = "";
        for (int j = 0; j <= stranice.at(i).size(); j++) {
            if (j < stranice.at(i).size() && (isalpha(stranice.at(i)[j]) || isdigit(stranice.at(i)[j]))) {
                rijec += tolower(stranice.at(i)[j]);
            } else {
                if (!rijec.empty()) {
                    int pozicija = j - rijec.size();
                    indeks_pojmova[rijec].insert({i + 1, pozicija});
                    rijec = "";
                }
            }
        }
    }
    return indeks_pojmova;
}


set<pair<int,int>> PretraziIndeksPojmova(string rijec, map<string,set<pair<int,int>>> indeks){ 
   if(indeks.find(rijec)!=indeks.end()){
       return indeks.at(rijec);
   }
   else{
    throw logic_error("Pojam nije nadjen");
   }
}


void IspisiIndeksPojmova(map<string,set<pair<int,int>>> indeks){
    for(auto pair : indeks){
        cout<<pair.first<<": ";
        auto it = (pair.second).begin();
        while(it!=pair.second.end()){
            cout<<(*it).first<<"/"<<(*it).second;
            it++;
            if(it!=pair.second.end()) cout<<", ";
            
        }
        cout<<endl;
    }
}


int main(){
    int n; 
  std::cout << "Unesite broj stranica: "; 
  std::cin >> n; 
  std::cin.ignore(10000, '\n'); 
  std::vector<std::string> tekst(n); 
  for(int i = 0; i < n; i++) { 
    std::cout << "Unesite sadrzaj stranice " << i + 1 << ": "; 
    std::getline(std::cin, tekst[i]); 
  } 
  auto indeks = KreirajIndeksPojmova(tekst); 
  std::cout << "\nKreirani indeks pojmova:\n"; 
  IspisiIndeksPojmova(indeks);
  cout<<"Unesite rijec"<<endl;
  string rijec;
  getline(cin,rijec);
  auto trazena_rijec=PretraziIndeksPojmova(rijec, indeks);
  for(auto it : trazena_rijec){
    cout<<it.first<<"/"<<it.second<<" ";
  }

}