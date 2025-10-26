#include <iostream>
using namespace std;

// bu sistem lıstenın son elemanını siler


struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;


void insertEnd(int a) {

    Node* newNode = new Node();
    newNode->data = a;
    newNode->next = NULL;

    // 1. Düzeltme: Liste boşsa ekle ve fonksiyondan çık.
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

void disPlay() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ->";
        // 2. Düzeltme: Döngüde pointer'ı ilerlet.
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "Liste bos, silinecek eleman yok." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    /*Node* temp = head;
    while (temp->next->next != NULL) { // son düğümün bir öncesine git
        temp = temp->next;
    }
    delete temp->next; // son düğümü sil
    temp->next = NULL;*/ //son düğümün bağlantısını kes

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
    }

    // temp şu anda son düğüm
    delete temp;

    // prev artık son düğümün bir öncesi, bağlantıyı kopar
    prev->next = NULL;

}


int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    cout << "Silme oncesi: ";
    disPlay();

    deleteEnd();
    
    cout << "Silme Sonrasi: ";
    disPlay();

    return 0;
}