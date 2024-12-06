#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

string IzvrniBezRazmaka(string const &s){
    string rez;
    remove_copy(s.rbegin(),s.rend(),inserter(rez,rez.begin()),' ');
    return rez;
}

int main(){
    cout << IzvrniBezRazmaka("Evo pada snijeg") << endl;

    return 0;
}