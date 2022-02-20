#include <iostream>
#include <climits>
#include <string>
struct DynamicStack{
    int top;
    int capacity;
    char *array;
};

DynamicStack* CreateStack()
{
    DynamicStack *S = (DynamicStack*)malloc(sizeof(DynamicStack));
    if (S == nullptr) { //fail check for memory allocation
        return nullptr;
    }
    S->capacity = 2;
    S->top = -1;
    S->array = (char*)malloc(S->capacity*sizeof(char));
    if (S->array == nullptr) { //fail check for memory allocation
        return nullptr;
    }
    
    return S; //return stack object
}

int isFullStack(DynamicStack *S){
    return (S->top == S->capacity-1);
}

void DoubleStack(DynamicStack *S){
    S->capacity *= 2;
    S->array = (char*)realloc(S->array, S->capacity);
}

void Push(DynamicStack *S, char x){
    if (isFullStack(S)) {
        DoubleStack(S);
    }
    S->array[++S->top] = x;
}

int isEmptyStack(DynamicStack *S){
    return S->top == -1;
}

char Top(DynamicStack *S)
{
    if (isEmptyStack(S)) {
        return CHAR_MIN;
    }
    return S->array[S->top];
}
char Pop(DynamicStack *S){
    if (isEmptyStack(S)) {
        return CHAR_MIN;
    }
    return S->array[S->top--];
}

void DeleteStack(DynamicStack *S){
    if (S != nullptr) {
        if (S->array != nullptr) {
            free(S->array);
        }
        free(S);
        std::cout << "Deleted successfully...\n";
    }
}

void PrintStack(DynamicStack *S){
    if (S != nullptr) {
        if (S->array != nullptr) {
            for (int i = S->top; i >=0; i--) {
                if (i == S->top) {
                    std::cout << S->array[i] << "<--Top\n";
                }
                else{
                    std::cout << S->array[i] <<"\n";
                }
            }
        }
        else{
            std::cout << "No elements in Stack\n";
        }
    }
    else{
        std::cout << "Stack Underflow\n";
    }
}

bool isMatchingPair(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    else if(a == '{' && b == '}')
        return true;
    else if(a == '[' && b == ']')
        return true;
    else
        return false;
}

void BalanceSymbol(DynamicStack *S, std::string str)
{
    if (str == "" || S == nullptr) {
        std::cout << "Either string is empty or Stack is empty \n";
        return;
    }
    else{
        char openSymbol[] = {'(','{','['};
        char closeSymbol[] = {']','}',')'};
        bool flag = false;
        for (size_t i=0; i < str.size(); i++) {
            for (size_t j=0; j<3; j++) {
                if (str[i] == openSymbol[j]) {
                    Push(S, str[i]);
                    break;
                }
                if (str[i] == closeSymbol[j]) {
                    if (isMatchingPair(S->array[S->top], str[i])) {
                        Pop(S);
                        continue;
                    }
                    else{
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == true)
                break;
        }
        if (isEmptyStack(S) && flag == false) {
            std::cout << "Expression " << str << " is balanced.\n";
        }
        else{
            std::cout << "Expression " << str << " is unbalanced.\n";
        }
        
    }
}

int main() {
    DynamicStack *var = CreateStack();
    std::string str = "((a+b)+[c-d])";
    BalanceSymbol(var, str);
    
    //PrintStack(var);
    DeleteStack(var);
    return 0;
}
