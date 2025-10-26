#include <iostream>
using namespace std;

// Node yapısı
struct Node {
    int data;      // veriyi tutar
    Node* next;    // bir sonraki düğümün adresini tutar
};

// Listenin başını gösteren pointer
Node* head = NULL; 

// Yeni eleman ekleme (listenin sonuna)
void insert(int value) {
    Node* newNode = new Node();  // yeni düğüm oluştur
    newNode->data = value;       // veriyi ata
    newNode->next = NULL;        // son düğüm olduğu için next = NULL

    if (head == NULL) {
        head = newNode;          // liste boşsa, yeni düğüm baş olur
    } else {
        Node* temp = head;       // listenin başından başlamak üzere geçici pointer oluşturlur
        while (temp->next != NULL) {
            temp = temp->next;   // sona kadar ilerle
        }
        temp->next = newNode;    // son düğümün next'ini yeni düğüme bağla
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

// main fonksiyonu
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    cout << "Linked List: ";
    display();

    return 0;
}
