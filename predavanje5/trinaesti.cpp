#include<iostream>
#include<cmath>
using namespace std;

template <typename iterTip, typename funRez, typename funPar>
iterTip maksfun(iterTip start, iterTip kraj, funRez f(funPar)) {
    iterTip poz = start;
    auto max = f(*start);
    while (start != kraj) {
        if (f(*start) > max) {
            max = f(*start);  // Correctly assign the function result
            poz = start;
        }
        start++;  // Increment the iterator here
    }
    return poz;
}

int main() { 
    double niz[] {3.7, 2.15, 4.741, 3.19, 5.2}; 
    std::cout << "Najveci sinus ima element " << *maksfun(std::begin(niz), std::end(niz), std::sin); 
    return 0; 
}


// ne radi 