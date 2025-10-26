#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool sorgu2(char open,char close){
    if(open=='(' && close==')')
        return true;
    else if(open=='[' && close==']')
        return true;
    
    else if(open=='{' && close=='}')
        return true;
 
    return false;
}

bool sorgu1(string ch){
    stack<char> St;
    for(int i=0;i<ch.length();i++){
        if(ch[i]=='(' || ch[i]=='[' || ch[i]=='{')
            St.push(ch[i]);

        else if(ch[i]==')' || ch[i]==']' || ch[i]=='}'){
            if(St.empty() || !sorgu2(St.top(),ch[i]))
                return false;
            else
                St.pop();
        }
        
    }
    bool b;
    if(St.empty())
        return true;
    else
        return false;

}

int main(){
    string ch;
    cout<<"Bir karakter giriniz--> ";
    cin>>ch;

    if(sorgu1(ch))
        cout<<"Dengede";
    else
        cout<<"Dengede Degil!!";


    return 0;
}