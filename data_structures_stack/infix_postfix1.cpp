#include <iostream>
#include <stack>
#include <string>
using namespace std;

int oncelik(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // diğer karakterler için 0 döner
}

string swp(string input){
    stack<char> St;
    string output="";

    for(int i=0; i<input.length(); i++){
        char c;
        c=input[i];

        if (c == ' ')
            continue;
        
        if(isalnum(c))
            output+=c;
        
        else{
            // HATA BURADAYDI: Parantez düzeltildi
            while(!St.empty() && oncelik(St.top()) >= oncelik(c)){ 
                output+=St.top();
                St.pop();
            }
            St.push(c);
        }
    }
    
    while(!St.empty()){
        output+=St.top();
        St.pop();
    }
    return output;
}

int main(){
    string input;
    cout << "Infix ifade giriniz: "; // Ekrana ne girileceğini yazmak iyi bir pratiktir
    getline(cin,input);
    string output=swp(input);
    cout<<"Postfix ifade : "<<output<<endl;

    return 0;
}