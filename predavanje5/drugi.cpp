#include <iostream>
#include <string>

using namespace std;

template <typename iterator>
void funkcija(iterator start1, iterator end1, iterator start2){
    while(start1!=end1){
        auto temp=*start1;
        *start1=*start2;
        *start2=temp;
        start1++;
        start2++;
    }
}

int main(){
    int niz1[5]={1,2,3,4,5};
    int niz2[]={5,4,3,2,1};
    string a="abc";
    string b="cba";
    funkcija(niz1,niz1+5,niz2);
    funkcija(a.begin(),a.end(),b.begin());
    cout<<a<<endl;
    for(int i=0;i<5;i++){
        cout<<niz1[i]<<endl;
    }

    return 0;
}