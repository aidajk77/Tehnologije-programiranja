#include<iostream>
#include<vector>
using namespace std;
void TransformirajVektor(vector<int> &v){
    for(int i=0;i<v.size();i++){
        if(v.at(i)<=0){
            v.erase(v.begin()+i);
            i--;
        }else{
            for(int j=0;j<v.at(i)-1;j++){
                v.insert(v.begin()+i,v.at(i));
                i++;
            }
        }
    }
}
int main(){
    vector<int> v{3, 5, 1, 2, 0, 4, 1, -6, 2};
    TransformirajVektor(v);
    for(int x:v){
        cout<<x<<" ";
    }

    return 0;
}