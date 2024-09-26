#include <iostream>

struct Node
{
    int data;
    Node *next;
};

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

//Print the list
void Print(Node* head)
{
    Node* temp = head;
    std::cout << "List :";
    while (temp != nullptr) {
        std::cout << temp->data <<" ";
        temp = temp->next;
    }
    std::cout << "\n";
}

void PrintCycle(Node* head)
{
    Node* temp = head;
    std::cout << "List :";
    int cnt(0);
    while (cnt != 15) {
        std::cout << temp->data <<" ";
        temp = temp->next;
        cnt++;
    }
    std::cout << "\n";
}

bool detectLoop(Node* head)
{
    Node* slowptr = head;
    Node* fastptr = head;
    
    while(slowptr != nullptr && fastptr != nullptr)
    {
        fastptr = fastptr->next;
        
        if(fastptr == slowptr)
            return true;
        
        if(fastptr == nullptr)
            return false;
        
        fastptr = fastptr->next;
        
        if(fastptr == slowptr)
            return true;
        
        slowptr = slowptr->next;
    }
    return false;
}

int main()
{
    Node* var = nullptr;
    addAfter(&var, 100);
    addAfter(&var, 200);
    addAfter(&var, 300);
    addAfter(&var, 400);
    addAfter(&var, 500);
    addAfter(&var, 600);
    addAfter(&var, 700);
    addAfter(&var, 800);
    addAfter(&var, 900);
    Print(var);
    std::cout << "Loop found :" << std::boolalpha << detectLoop(var) << "\n";
    
    Node* temp = var->next->next->next;
    Node* current = var;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = temp;
    
    PrintCycle(var);
    std::cout << "Loop found :" << std::boolalpha << detectLoop(var) << "\n";
    
    return 0;
}

