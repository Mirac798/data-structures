#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        cout << "Liste bos!" << endl;
        return;
    }

    // 1️⃣ Baştaki düğüm silinecekse
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // 2️⃣ Aradaki düğüm silinecekse
    Node* temp = head; // geçici işaretçi
    Node* prev = NULL; // önceki düğüm için işaretçi

    int count = 1;
    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // Eğer konum bulunamadıysa
    if (temp == NULL) {
        cout << "Gecersiz pozisyon!" << endl;
        return;
    }

    prev->next = temp->next; // bağlantıyı atla(lıstenin önceki düğümünü sonraki düğüme bağla)
    delete temp;             // düğümü sil
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    cout << "Silme oncesi: ";
    display();

    deleteAtPosition(3);  // 3. elemanı sil (30)
    cout << "3. eleman silindikten sonra: ";
    display();

    deleteAtPosition(1);  // baştaki elemanı sil (10)
    cout << "Bastaki eleman silindikten sonra: ";
    display();

    deleteAtPosition(10); // olmayan pozisyon
    cout << "Gecersiz silme denemesi: ";
    display();

    return 0;
}
