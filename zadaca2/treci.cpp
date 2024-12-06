#include <iostream>
#include <deque>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename reztip, typename tip1, typename tip2>
reztip UnijaBlokova(tip1 p1,tip1 p2, tip2 p3, tip2 p4, reztip p5){
    reztip start=p5;
    *p5=*p1;
    p5++;
    auto temp=p1;
    temp++;
   for(tip1 i=temp;i!=p2;i++){
    int cnt=count(p1,i,*i);
    if(cnt==0){
        *p5=*i;
        p5++;
    }
   }
   for(tip2 i=p3;i!=p4;i++){
    int cnt=count(start,p5,*i);
    if(cnt==0){
        *p5=*i;
        p5++;
    }
   }
   return p5;
}


int main(){
    cout<<"unesi broj elemenata niza"<<endl;
    int ben,a,bed;
    cin>>ben;
    int niz[ben];
    cout<<"unesi elemente niza"<<endl;
    for(int i=0;i<ben;i++){
        cin>>a;
        niz[i]=a;
    }
    cout<<"unesi broj elemenata deka"<<endl;
    cin>>bed;
    deque<int> d;
    cout<<"unesi elemente deka"<<endl;
    for(int i=0;i<bed;i++){
        cin>>a;
        d.push_back(a);
    }
    vector<int> v(ben+bed);
    auto v_end=UnijaBlokova(niz,niz+ben,d.begin(),d.end(),v.begin());
    auto v_start=v.begin();
    cout<<"unija glasi: "<<endl;
    while(v_start!=v_end){
        cout<<*v_start<<" ";
        v_start++;
    }
    cout<<endl;
    return 0;
}