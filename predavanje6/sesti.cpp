#include<iostream>
#include <exception>
using namespace std;

  int **KreirajTrokut(int n) { 
  if(n <= 0) throw std::domain_error("Broj redova mora biti pozitivan"); 
  int **pok_mat = new int*[n]; 
  try { 
    pok_mat[0] = new int[n * n]; 
  } 
  catch(...) { 
    delete[] pok_mat; 
    throw; 
  } 
  for(int i = 1; i < n; i++) pok_mat[i] = pok_mat[i - 1] + 2 * i - 1; 
  for(int i = 0; i < n; i++) { 
    for(int j = 0; j < i; j++) pok_mat[i][j] = i + 1 - j; 
    for(int j = i; j <= 2 * i + 1; j++) pok_mat[i][j] = j + 1 - i; 
  } 
  return pok_mat;
  }

int main(){

    int n; 
  std::cout << "Koliko zelite redova: "; 
  std::cin >> n; 
  try { 
    int **mat = KreirajTrokut(n); 
    for(int i = 0; i < n; i++) { 
      for(int j = 0; j < 2 * i + 1; j++) std::cout << mat[i][j] << " "; 
      std::cout << std::endl; 
    } 
    for(int i = 0; i < n; i++) delete[] mat[i]; 
    delete[] mat; 
  } 
  catch(std::domain_error e) { 
    std::cout << "Izuzetak: " << e.what(); 
  } 
  catch(std::bad_alloc) { 
    std::cout << "Izuzetak: Nedovoljno memorije!"; 
  } 
  return 0;

}