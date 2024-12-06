#include<iostream>
using namespace std;

int* FibonaccijeviBrojevi(int n){
    if(n<=0) return nullptr;
    try{
        int* niz=new int[n];
        niz[0]=1;
        niz[1]=1;
        for(int i=2;i<n;i++){
            niz[i]=niz[i-1]+niz[i-2];
        }
        return niz;
    }
    catch(...){
        return nullptr;
    }
}
int main(){
      int n; 
  std::cout << "Koliko zelite Fibonaccijevih brojeva? "; 
  std::cin >> n; 
  int *fib = FibonaccijeviBrojevi(n); 
  if(!fib) std::cout << "Neuspjesna alokacija!"; 
  else { 
    for(int i = 0; i < n; i++) std::cout << fib[i] << " "; 
    delete[] fib; 
  } 
  return 0; 
}