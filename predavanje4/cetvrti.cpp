#include<iostream>
#include<vector>
using namespace std;
void DodajSuprotne(vector<int> &v){
    for(int i=0;i<v.size();i++){
        v.insert(v.begin()+i+1,-v.at(i));
        i++;
    }
}
int main(){
    vector<int> v{3,10,-4,8};
    DodajSuprotne(v);
    for(int x:v){
        cout<<x<<endl;
    }
    return 0;
}