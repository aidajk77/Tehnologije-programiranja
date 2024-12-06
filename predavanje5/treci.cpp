#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool potpun_kv(int a){
    if(double(sqrt(a))==int(sqrt(a)))
        return true;
    else
        return false;
}

int BrojCifara(int n) { 
if(n >= -9 && n <= 9) return 1; 
return 1 + BrojCifara(n / 10); 
}

bool KriterijPoBrojuCifara(int m, int n) { 
  return BrojCifara(m) < BrojCifara(n); 
}

int main(){
    int niz[]={1,2,3,4,5,8,7,6};
    cout<<"najveci elem: "<<*max_element(niz,niz+10)<<endl;
    cout<<"broj najmanjeg elem: "<<count(niz,niz+10,*min_element(niz,niz+10))<<endl;
    cout<<"potpunih kvadrata ima: "<<count_if(niz,niz+10,potpun_kv)<<endl;



    return 0;
}