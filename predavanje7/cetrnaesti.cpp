#include <iostream>
#include <stack>

using namespace std;

template <typename tip>
void PomnoziStek(stack<tip>& stek,tip a){
    stack<tip> pomocni;
    while(!stek.empty()){
        pomocni.push(stek.top()*a);
        stek.pop();
    }
    while(!pomocni.empty()){
        stek.push(pomocni.top());
        pomocni.pop();
    }
    
}

int main(){
    stack<double> stek;
    int a,b;
    cout<<"unesi velicinu steka"<<endl;
    cin>>a;
    cout<<"unesi elemente"<<endl;
    for(int i=0;i<a;i++){
        cin>>b;
        stek.push(b);
    }
    PomnoziStek(stek,0.5);
    while(!stek.empty()){
        cout<<stek.top()<<" ";
        stek.pop();
    }

    return 0;
}