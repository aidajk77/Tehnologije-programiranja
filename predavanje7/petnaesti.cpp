#include<iostream>
#include <stack>
#include <functional>


using namespace std;

template <typename tip1, typename tip2>
stack<tip2> TranformiraniStek(stack<tip1> stek,function<tip2(tip1)> fun){
    stack<tip2> pomocni1,pomocni2;
    while(!stek.empty()){
        pomocni1.push(fun(stek.top()));
        stek.pop();
    }
    /*while(!pomocni1.empty()){
        pomocni2.push(pomocni1.top());
        pomocni1.pop();
    }
    */
    return pomocni1;
}


int main(){
    cout<<"unesite velicinu steka"<<endl;
    int a,b;
    cin>>a;
    stack<int> stek;
    cout<<"unesite elemente"<<endl;
    for(int i=0;i<a;i++){
        cin>>b;
        stek.push(b);
    }

    stack<double> stek2 = TranformiraniStek<int, double>(stek,[](int x){ return 1./x;});
    while(!stek2.empty()){
        cout<<stek2.top()<<" ";
        stek2.pop();
    }

    return 0;
}