#include <iostream>
using namespace std;

//program sondan ve bastan ekleme yapar ardından bastaki elemani siler ve listeyi ekrana yazdirir


struct Node{
    int data;
    Node* next;


};
Node* head =NULL;
void insertFront(int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}

void deleteFront(){
    if(head==NULL){
        cout<<"liste bos!"<<endl;
    }
    Node*temp=head;
    head=head->next;
    delete temp;
    cout<<"bastaki eleman silindi!!"<<endl;

}

void display(){
    Node*temp=head;
    while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        
    }
    cout<<"NULL"<<endl;
    
}

int main(){
   
    insertFront(30);
    insertFront(20);
    insertFront(10);

    cout << "Baslangic listesi: ";
    display();

    deleteFront();

    cout << "Silme sonrasi: ";
    display();



    return 0;
}