#include<iostream>
#include<vector>
#include<string>
using namespace std;

int brojDuplikata(const vector<string>& v){
    bool tn=false;
    vector<string> v2;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v.at(i)==v.at(j)){
                for(int k=0;k<v2.size();k++){
                    if(v.at(i)==v2.at(k)){
                        tn=true;
                    }
                }
                if(!tn){
                    v2.push_back(v.at(i));
                }
            }
        }
        tn=false;
    }
    return v2.size();

}

void duplikati(vector<string>& v){
    bool tn=false;
    vector<string> v2;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v.at(i)==v.at(j)){
                for(int k=0;k<v2.size();k++){
                    if(v.at(i)==v2.at(k)){
                        tn=true;
                    }
                }
                if(!tn){
                    v2.push_back(v.at(i));
                }
            }
        }
        tn=false;
    }
    v=v2;

}

void zadrziDuplikate(vector<string>& v){
    duplikati(v);
}

void izdvojiKrajnjeRijeci(const vector<string>& v, string &s1, string &s2){
    string max,min,temp;
    if(v.size()==0){
        s1="";
        s2="";
    }
    else{
        for(int i=0;i<v.at(0).size();i++){
            temp=temp+v.at(0).at(i);
        }
        max=temp;
        min=temp;
    }
    temp="";
    for(int i=1;i<v.size();i++){
        for(int j=0;v.at(i).size();j++){
            temp=temp+v.at(i).at(j);
        }
        if(temp>max) max=v.at(i);
        if(temp<min) min=v.at(i);
    }
    s1=min;
    s2=max;
}

int main() {
    vector<string> v;
    int size;
    string a,b,temp;
    cout<<"koliko elemenata"<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>temp;
        v.push_back(temp);
    }
    izdvojiKrajnjeRijeci(v,a,b);
    cout<<a<<" "<<b<<endl;
    if(brojDuplikata(v)){
        cout<<brojDuplikata(v)<<endl;
        zadrziDuplikate(v);
        for(int i=0;i<v.size();i++){
            cout<<v.at(i)<<" ";
        }
    }else{
        cout<<"nema duplikata"<<endl;
    }

    return 0;
}
