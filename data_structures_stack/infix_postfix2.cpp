#include <iostream>
#include <stack>
#include <string>
using namespace std;

int oncelik(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // Parantezler ve diğerleri için 0
}

string swp(string input){
    stack<char> St;
    string output="";

    for(int i=0; i<input.length(); i++){
        char c = input[i];

        if (c == ' ')
            continue;
        
        // 1. Durum: Operand (harf veya rakam)
        if(isalnum(c)) {
            output += c;
        }
        // 2. Durum: Açma Parantezi '('
        else if (c == '(') {
            St.push('(');
        }
        // 3. Durum: Kapatma Parantezi ')'
        else if (c == ')') {
            // '(' bulana kadar stack'ten pop et ve output'a ekle
            while(!St.empty() && St.top() != '('){
                output += St.top();
                St.pop();
            }
            St.pop(); // '(' karakterini stack'ten at (output'a eklemeden)
        }
        // 4. Durum: Operatör (+, -, *, /)
        else {
            // Stack'in tepesindeki '(' DEĞİLSE ve öncelik >= c ise pop et
            while(!St.empty() && St.top() != '(' && oncelik(St.top()) >= oncelik(c)){ 
                output += St.top();
                St.pop();
            }
            St.push(c); // Yeni operatörü stack'e ekle
        }
    }
    
    // Döngü bittikten sonra stack'te kalanları boşalt
    while(!St.empty()){
        output += St.top();
        St.pop();
    }
    return output;
}

int main(){
    string input;
    cout << "Parantezli infix ifade giriniz: ";
    getline(cin,input);
    string output=swp(input);
    cout << "Postfix ifade : " << output << endl;

    return 0;
}