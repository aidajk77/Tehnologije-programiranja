#include<iostream>
#include <exception>
using namespace std;

  int** KreirajTrokut(int n) {
    if (n <= 0) {
        throw domain_error("Broj redova mora biti pozitivan");
    }
    
    int** niz = nullptr;  // Pointer to pointer to int
    try {
        niz = new int*[n]();  // Allocate memory for 'n' rows, initialize pointers to nullptr
        for (int i = 0; i < n; i++) {
            niz[i] = new int[2 * i + 1];  // Allocate memory for each row
            
            // Fill the left half of the triangle
            for (int j = 0; j < i; j++) {
                niz[i][j] = i - j + 1;
            }
            
            // Fill the right half of the triangle
            for (int j = i; j < 2 * i + 1; j++) {
                niz[i][j] = j - i + 1;
            }
        }
    }
    catch (bad_alloc&) {
        // In case of an allocation failure, clean up previously allocated rows
        for (int i = 0; i < n; i++) {
            delete[] niz[i];  // Only delete if memory was allocated
        }
        delete[] niz;  // Delete the outer array of pointers
        throw;  // Rethrow the exception
    }
    
    return niz;  // Return the pointer to the array of arrays
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