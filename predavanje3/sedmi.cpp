#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

vector<string> PretvoriUBazu(vector<int> v, int baza){
    if(baza<2 || baza>36)
    throw domain_error("Nedozvoljena baza");
    vector<string> vstring;
   
    for(int i=0;i<v.size();i++){
        string rez="";
        int temp=v[i];
        int abstemp=abs(temp);

        do{
            int zc=abstemp%baza;
            if(zc<10){
                rez=rez+char('0'+zc);
            }
            if(zc>=10){
                rez=rez+char('A'+(zc-10));
            }
            abstemp/=baza;
        }while(abstemp!=0);
        reverse(rez.begin(),rez.end());
        if(temp<0){
           rez="-"+rez;
        }
        
        vstring.push_back(rez);

    }

    return vstring;

}

int main(){
    vector<string> vstring;
    vector<int> v;
    int a,b,baza;
    cout<<"koliko ce brojeva bit"<<endl;
    cin>>a;
    cout<<"unesi elemente"<<endl;
    for(int i=0;i<a;i++){
        cin>>b;
        v.push_back(b);
    }
    cout<<"unesi bazu"<<endl;
    cin>>baza;

    vstring=PretvoriUBazu(v,baza);
    cout<<"elementi u datoj bazi su:"<<endl;
    for(int i=0;i<vstring.size();i++){
        cout<<vstring[i]<<" ";
    }

    return 0;
}
