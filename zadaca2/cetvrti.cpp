#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>

using namespace std;

template<typename tip>
bool Kriterij(vector<tip> v1, vector<tip> v2){
    return *max_element(v1.begin(),v1.end())>=*max_element(v2.begin(),v2.end());
}

template<typename tip>
void SortirajPoDobrotiRedova(vector<vector<tip>> &m){
    sort(m.begin(),m.end(),[](const std::vector<tip>& v1, const std::vector<tip>& v2) {
        return Kriterij(v1, v2);
    });
}

int main(){
    cout<<"Unesite elemente (* za kraj reda, * na pocetku reda za kraj unosa):"<<endl;
    int a;
    vector<vector<int>> m;
    vector<int> temp;
    do{
        cin>>a;
        if(!cin) {
            if(temp.size()==0){
                cin.clear();
                cin.ignore(10000,'\n');
                break;
            }else{
                m.push_back(temp);
                temp.resize(0);
                cin.clear();
                cin.ignore(10000,'\n');
                continue;
            }
        }
        temp.push_back(a);
    }while(cin);
    SortirajPoDobrotiRedova(m);
    for(auto v:m){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<int> v;
    cout<<"Unesi elemente sekvence koja se trazi(* za kraj reda)"<<endl;
    do{
        cin>>a;
        if(!cin){
            cin.clear();
            cin.ignore(10000,'\n');
            break;
        }
        v.push_back(a);
    }while(cin);
    cout<<"Sekvenca se nalazi u "<<lower_bound(m.begin(),m.end(),v,[](vector<int>v1, vector<int> v2){return v1==v2;})-m.begin()+1<<" redu"<<endl;
    return 0;
}