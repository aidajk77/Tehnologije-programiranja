#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    char a[1000]="";
    cout<<"unesi string"<<endl;
    cin.getline(a,sizeof(a));
    char* p=a;
    while(*p!='\0' && !isalpha(*p)){
        p++;
    }
    while(*p!='\0' && isalpha(*p)){
        p++;
    }
    while(*p!='\0' && !isalpha(*p)){
        p++;
    }
    while(*p!='\0'){
        cout<<*p++;
    }

    
    

    return 0;
}