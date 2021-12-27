#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

//Print the list
void Print(Node* head)
{
    Node* temp = head;
    cout << "List :";
    while (temp != nullptr) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << "\n";
}

//Count the elements
int Length(Node* head)
{
    Node* temp = head;
    int cnt(0);
    while (temp != nullptr) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void addAfter(Node** head, int value)
{
    //check if the list is empty
    if (*head == nullptr)
    {
        //create a new node
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        *head = temp;
    }
    else
    {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }

        //create a new node
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        current->next = temp;
    }
}

void addBefore(Node** head, int value)
{
    //check if the list is empty
    if (*head == nullptr)
    {
        //create a new node
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        *head = temp;
    }
    else
    {
        //create a new node and assign to head
        Node* temp = new Node;
        temp->data = value;
        temp->next = *head;
        *head = temp;
    }
}

void addAt(Node** head, int value, int index)
{
    int length = Length(*head);

    if (index == 0)
    {
        addBefore(head, value);
    }
    else if (index == length)
    {
        addAfter(head, value);
    }
    else if (index > length-1)
    {
        cout << "Index out of bound. Maximum length of list is: "<< length <<"\n";
        return;
    }
    else
    {
        //get to the previous node before index node
        int cnt(0);
        Node* previous = *head;
        while (cnt != index-1) {
            previous = previous->next;
            cnt++;
        }

        //create a new node
        Node* temp = new Node;
        temp->data = value;
        temp->next = previous->next;
        previous->next = temp;

    }
}

void deleteList(Node** head)
{
    Node* temp = *head;
    Node* aux = nullptr;
    while (temp != nullptr) {
        aux = temp->next;
        delete temp;
        temp = aux;
    }
    *head = nullptr;
}

void deleteAt(Node** head, int index)
{
    int length = Length(*head);

    if (index == 0)
    {
        if (*head == nullptr) {
            cout << "List is empty...\n";
            return;
        }
        else
        {
            Node* temp = *head;
            *head = temp->next;
            delete temp;
        }
    }
    else if (index > length-1)
    {
        cout << "Index out of bound. Maximum length of list is: "<< length <<"\n";
        return;
    }
    else
    {
        //get to the previous node before index node
        int cnt(0);
        Node* previous = *head;
        while (cnt != index-1) {
            previous = previous->next;
            cnt++;
        }

        //delete a node
        Node* temp = previous->next;
        if (temp->next == nullptr) {
            previous->next = nullptr;
            delete temp;
        }
        else
        {
            previous->next = temp->next;
            delete temp;
        }
    }
}

void ReveresePairIterative(Node* head)
{
    int temp(0);
    int step(0);
    Node* current = head;
    while (current->next != nullptr) {
        if (step%2 == 0) {
            temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
        }
        step++;
        current = current->next;
    }
}

int main() {
    Node* head1 = nullptr;

    addAfter(&head1, 100);
    addAfter(&head1, 200);
    addAfter(&head1, 300);
    addAfter(&head1, 400);
    addAfter(&head1, 500);
    addAfter(&head1, 600);
    addAfter(&head1, 700);
    Print(head1);
    ReveresePairIterative(head1);
    Print(head1);

    return 0;
}
