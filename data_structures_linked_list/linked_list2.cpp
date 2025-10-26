#include <iostream>
using namespace std;

//program hem sondan hem bastan ekleme yapar  ve listeyi ekrana yazdirir


struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Baştan ekleme fonksiyonu
void insertFront(int value) {
    Node* newNode = new Node();  // yeni düğüm oluştur
    newNode->data = value;       // veriyi ata
    newNode->next = head;        // yeni düğümün next'i mevcut head'i göstersin
    head = newNode;              // head artık bu yeni düğümü göstersin
}

// Sondan ekleme fonksiyonu (önceden yaptığımız)
void insertEnd(int value) {
    Node* newNode = new Node(); // yeni düğüm oluştur
    newNode->data = value;  // veriyi ata
    newNode->next = NULL;   // son düğüm olduğu için next = NULL

    if (head == NULL) {
        head = newNode; // liste boşsa, yeni düğüm baş olur
    } else {
        Node* temp = head; // listenin başından başlamak üzere geçici pointer oluşturulur
        while (temp->next != NULL) { 
            temp = temp->next;   // sona kadar ilerle
        }
        temp->next = newNode;  // son düğümün next'ini yeni düğüme bağla
    }
}

// Listeyi ekrana yazdırma
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    cout << "Sondan ekleme sonucu: ";
    display();

    insertFront(5);
    insertFront(2);
    cout << "Bastan ekleme sonucu: ";
    display();

    return 0;
}
