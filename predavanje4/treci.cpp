#include<iostream>
#include<vector>
using namespace std;

void ModificirajVector(vector<int> &v){

    for(int i=0;i<v.size();i++){
        int temp=v.at(i);
        int zc=temp%10;
        int ostatak=zc%2;
        do{
            zc=temp%10;
            if(zc%2!=ostatak){
                v.erase(v.begin()+i);
                i=0;
                break;
            }
            temp/=10;
        }while(temp!=0);
    }
}
int main(){
    vector<int> v{351, 452, 736, 2806, 912};

    ModificirajVector(v);
    for(int x: v){
        cout<<x<<endl;
    }
    return 0;
}