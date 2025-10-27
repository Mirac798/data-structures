#include <iostream>
#include <stack>
#include <string>
using namespace std;
void sorgu(string str){
    stack<char> St;
    bool control=true;
    int i=0;
    while(control && i<str.length()){
        char ch=str[i++];
        if(ch=='{')
            St.push(ch);

        else if(ch=='}'){
            if(!St.empty())
                St.pop();
            else
                control=false;
        }
    }
    if(control && St.empty())
        cout<<"Dengede";
    else
        cout<<"Dengede Degil";
}


int main(){
    string str="{a{b}c}";
    sorgu(str);

    return 0;
}