#include<iostream>
#include<deque>
using namespace std;

template<typename iterTip>
void KumulativnaSuma(iterTip a, iterTip b, iterTip c){
    decltype(c) d=c;
    if(a==b) throw range_error("prazan blok");
    *d=*a++;
    d++;
    while(a!=b){
        *d=*(d-1)+*a;
        a++;
        d++;
    }

}
int main(){

    int n; 
    std::cout << "Koliko ima brojeva: "; 
    std::cin >> n; 
    std::deque<int> d(n),d2(n); 
    std::cout << "Unesite brojeve: "; 
    for(int &e : d) std::cin >> e; 
    KumulativnaSuma(d.begin(), d.end(), d2.begin()); 
    for(int &e : d2) std::cout << e << " ";
    return 0;

}