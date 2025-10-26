#include <iostream>
#include <stack>
using namespace std;

//bu program girilen sayiyi binary (ikilik) sisteme cevirir

void yazdir(std::stack<int> st){
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}


int binary(int number){
    stack<int> St;
    while(number>0){
        int temp=int(number%2);
        
        St.push(temp);
        number/=2;
    }
    yazdir(St);
}

int main(){
    int number;
    cout<<"Bir sayi giriniz--> ";
    cin>>number;

    binary(number);




    return 0;
}