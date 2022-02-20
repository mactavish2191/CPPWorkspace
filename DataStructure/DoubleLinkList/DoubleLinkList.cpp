#include <iostream>

//Define Node
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

//Print List
void Print(Node* head)
{
    Node* current = head;
    if (current == nullptr) {
        std::cout << "List is empty...\n";
    }
    else
    {
        std::cout << "List :";
        while(current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
}

//Length
int Length(Node* head)
{
    Node* current = head;
    int cnt(0);
    while(current != nullptr)
    {
        current = current->next;
        cnt++;
    }
    return cnt;
}

//Insert at the beginning
void addBefore(Node** head, int value)
{
    if (*head == nullptr)
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        temp->prev = nullptr;
        *head = temp;
    }
    else
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = *head;
        temp->prev = nullptr;
        *head = temp;
    }
}

//Insert at the end
void addAfter(Node** head, int value)
{
    //Check if the list is empty or not
    if (*head == nullptr)
    {
        addBefore(head, value);
        return;
    }
    else
    {
        Node* current = *head;
        while(current->next != nullptr)
            current = current->next;
        
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        temp->prev = current;
        current->next = temp;
    }
}

//Insert at the middle
void addAt(Node** head, int value, int index)
{
    int size = Length(*head);
    if (index == 0)
    {
        addBefore(head, value);
        return;
    }
    else if(size == index)
    {
        addAfter(head, value);
        return;
    }
    else if(size-1 < index)
    {
        std::cout << "Index out of range. Current size of list :" << size <<"\n";
    }
    else
    {
        Node* current = *head;
        int cnt(0);
        while(cnt != index-1)
        {
            current = current->next;
            cnt++;
        }
        
        Node* temp = new Node;
        temp->data = value;
        temp->next = current->next;
        temp->prev = current;
        current->next->prev = temp;
        current->next = temp;
    }
}

//Delete list
void deleteAll(Node** head)
{
    //Check if the list is empty or not
    if (*head == nullptr)
    {
        std::cout << "The list is empty...\n";
        return;
    }
    else
    {
        Node* aux;
        Node* temp = *head;
        while (temp != nullptr) {
            aux = temp->next;
            delete temp;
            temp = aux;
        }
        *head = nullptr;
    }
}

//Delete at
void deleteAt(Node** head, int index)
{
    int size = Length(*head);
    if (index == 0) {
        if (*head == nullptr) {
            std::cout << "List is empty...\n";
            return;
        }
        else
        {
            Node* temp = *head;
            *head = temp->next;
            temp->next->prev = nullptr;
            delete temp;
        }
    }
    else if(index > size-1)
    {
        std::cout << "Index out of bound. Maximum length of list is: "<< size <<"\n";
        return;
    }
    else
    {
        int cnt(0);
        Node* previous = *head;
        while (cnt != index-1) {
            previous = previous->next;
            cnt++;
        }
        
        //Delete a node
        Node* temp = previous->next;
        if (temp->next == nullptr) {
            previous->next = nullptr;
            delete temp;
        }
        else
        {
            previous->next = temp->next;
            temp->next->prev = previous;
            delete temp;
        }
    }
}

int main()
{
    Node* var = nullptr;
    
    addBefore(&var, 300);
    addBefore(&var, 200);
    addBefore(&var, 100);
    addAfter(&var, 500);
    addAfter(&var, 600);
    addAt(&var, 400, 3);
    Print(var);
    deleteAt(&var, 6);
    Print(var);
    
    return 0;
}
