#include<iostream>
#include<string>
using namespace std;
bool TestKljuca(string s){
    for(int i=0;i<s.size();i++){
        if(s.at(i)<65 || s.at(i)>90){
            return false;
        }
    }
    return true;
}
string ViginereSifriranje(string s, string kljuc){
    string final="";
    int br=0;
    if(!TestKljuca(kljuc)) throw domain_error("Neispravan kljuc");
    for(int i=0;i<s.size();i++){
        if(isalpha(s.at(i))){ 
            if(s.at(i)>64 && s.at(i)<91){   
                if(s.at(i)+kljuc.at(br)-65>90){
                    final=final+char(s.at(i)+kljuc.at(br)-65-26);
                    br++;
                    if(br==kljuc.size())  br=0;
                    continue;
            }
            final=final+char(s.at(i)+kljuc.at(br)-65);
            br++;

            }
            if(s.at(i)>96 && s.at(i)<123){
                if(s.at(i)+kljuc.at(br)-65>122){
                    final=final+char(s.at(i)+kljuc.at(br)-65-26);
                    br++;
                    if(br==kljuc.size())  br=0;
                    continue;
                }
                final=final+char(s.at(i)+kljuc.at(br)-65);
                br++;
            }

        }
        else
            final=final+s.at(i);  
        if(br==kljuc.size())  br=0;     
    }
    return final;


}

string ViginereDesifriranje(string s, string kljuc){
    string final="";
    int br=0;
    if(!TestKljuca(kljuc)) throw domain_error("Neispravan kljuc");
    for(int i=0;i<s.size();i++){
        if(isalpha(s.at(i))){ 
            if(s.at(i)>64 && s.at(i)<91){   
                if(s.at(i)-(kljuc.at(br)-65)<65){
                    final=final+char(s.at(i)-(kljuc.at(br)-65)+26);
                    br++;
                    if(br==kljuc.size())  br=0;
                    continue;
            }
            final=final+char(s.at(i)-(kljuc.at(br)-65));
            br++;

            }
            if(s.at(i)>96 && s.at(i)<123){
                if(s.at(i)-(kljuc.at(br)-65)<97){
                    final=final+char(s.at(i)-(kljuc.at(br)-65)+26);
                    br++;
                    if(br==kljuc.size())  br=0;
                    continue;
                }
                final=final+char(s.at(i)-(kljuc.at(br)-65));
                br++;
            }

        }
        else
            final=final+s.at(i);  
        if(br==kljuc.size())  br=0;     
    }
    return final;


}
int main(){
    string kljuc1,kljuc2;
    string recenica;
    cout<<"Unesite kljuc: ";
    getline(cin,kljuc1);
    while(!TestKljuca(kljuc1)){
        cout<<"Neispravan kljuc, ponovite unos:"<<endl;
        cout<<"Unesite kljuc: ";
        getline(cin,kljuc1);
    }
    cout<<"Kljuc prihvacen. Unesite poruku: ";
    getline(cin,recenica);
    auto poruka=ViginereSifriranje(recenica,kljuc1);
    cout<<"Sifrirana poruka: "<<ViginereSifriranje(recenica,kljuc1)<<endl;
    cout<<endl;
    cout<<"Pokusajte pogoditi kljuc: ";
    getline(cin,kljuc2);
    while(kljuc1!=kljuc2){
        if(!TestKljuca(kljuc2)){
            cout<<"Niste pogodili kljuc, probajte ponovo!"<<endl;
            cout<<"Pokusajte pogoditi kljuc: ";
            getline(cin,kljuc2);
        }
        else{
            cout<<"Pokusaj desifriranja: "<<ViginereDesifriranje(poruka,kljuc2)<<endl;
            cout<<"Niste pogodili kljuc, probajte ponovo!"<<endl;
            cout<<"Pokusajte pogoditi kljuc: ";
            getline(cin,kljuc2);
        }
    }
    cout<<"Pokusaj desifriranja: "<<ViginereDesifriranje(poruka,kljuc2)<<endl;
    cout<<"Bravo, pogodili ste kljuc!"<<endl;
    
    return 0;
}