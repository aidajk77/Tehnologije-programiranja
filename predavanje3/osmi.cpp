#include<iostream>
#include<array>
#include<string>
using namespace std;

array<int,26> Prebrojoavanje(string s){
    array<int,26> niz{};

    for(int i=0;i<s.size();i++){
        switch(toupper(s[i])){
        case 'A':
            niz[0]++;
            break;
        case 'B':
            niz[1]++;
            break;    
        case 'C':
            niz[2]++;
            break;
        case 'D':
            niz[3]++;
            break;  
        case 'E':
            niz[4]++;
            break;
        case 'F':
            niz[5]++;
            break;    
        case 'G':
            niz[6]++;
            break; 
        case 'H':
            niz[7]++;
            break;
        case 'I':
            niz[8]++;
            break;    
        case 'J':
            niz[9]++;
            break; 
        case 'K':
            niz[10]++;
            break;
        case 'L':
            niz[11]++;
            break;    
        case 'M':
            niz[12]++;
            break;  
        case 'N':
            niz[13]++;
            break;
        case 'O':
            niz[14]++;
            break;    
        case 'P':
            niz[15]++;
            break;  
        case 'Q':
            niz[16]++;
            break;
        case 'R':
            niz[17]++;
            break;    
        case 'S':
            niz[18]++;
            break;  
        case 'T':
            niz[19]++;
            break;
        case 'U':
            niz[20]++;
            break;    
        case 'V':
            niz[21]++;
            break;
        case 'W':
            niz[22]++;
            break;
        case 'X':
            niz[23]++;
            break;    
        case 'Y':
            niz[24]++;
            break;   
        case 'Z':
            niz[25]++;
            break;                                                        
        }
        
    }
    return niz;

}

int main(){
    string s="The quick brown fox jumps over a lazy dog";
    array<int,26> niz=Prebrojoavanje(s);
    char c='A';
    for(int i=0;i<niz.size();i++){
        cout<<c<<":"<<niz[i]<<endl;
        c++;

    }

    return 0;
}