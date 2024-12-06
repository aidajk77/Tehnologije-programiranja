#include<iostream>
using namespace std;
template <typename iterTip>
void AnalizaBloka(iterTip start, iterTip kraj,int& a, int& b){
    auto max=*start;
    auto min=*start;
    int maxbroj=0;
    int minbroj=0;
    while(start!=kraj){
        if(*start==max){
            maxbroj++;
        }
        if(*start==min){
            minbroj++;
        }
        if(*start>max){
            max=*start;
            maxbroj=1;
        }
        if(*start<min){
            min=*start;
            minbroj=1;
        }
       
        start++;
    }
    b=maxbroj;
    a=minbroj;
}



int main() { 
  double niz[]{3, 5.12, 2.4, 7.8, 4, 3, 7.8, 5.723, 7.8, 6.21}; 
  int br_min, br_max; 
  AnalizaBloka(std::begin(niz), std::end(niz), br_min, br_max); 
  std::cout << "Najmanji element niza se javlja " << br_min  
    << "puta, a najveći element niza " << br_max << " puta.\n"; 
   return 0; 
 } 
