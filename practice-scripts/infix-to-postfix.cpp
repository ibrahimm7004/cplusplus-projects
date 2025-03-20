#include <iostream>
using namespace std;

struct node {
    char data;
    node* next;
    node(char d) {
        data = d;
        next = NULL;
    }
};

void push(node** head, char data) {
    node* new_node = new node(data);
    new_node->next = *head;
    *head = new_node;
}

bool isEmpty(node** head) {
    return (*head == NULL);
}

char top(node** head) {
    if (!isEmpty(head)) return (*head)->data;
    return '\0';
}

void pop(node** head) {
    if (isEmpty(head)) return;
    node* temp = *head;
    *head = (*head)->next;
    cout << temp->data;
    delete temp;
}

bool check_precedence(char a, char b) {
    if (b == '(' || b == ')') return false;
    if ((a == '*' || a == '/') && (b == '+' || b == '-')) return false;
    return true;
}

void infix_to_postfix(node** head, char arr[100]) {
    int i = 0;
    while (arr[i]) {
        char a = arr[i];
        i++;
        if (isalnum(a)) cout << a;
        else if (a == '(') push(head, a);
        else if (a == ')') {
            while (!isEmpty(head) && top(head) != '(') pop(head);
            if (!isEmpty(head) && top(head) == '(') {
                node* temp = *head;
                *head = (*head)->next;
                delete temp;
            }
        } else {
            while (!isEmpty(head) && check_precedence(a, top(head))) pop(head);
            push(head, a);
        }
    }
    while (!isEmpty(head)) pop(head);
}

int main() {
    node* head = NULL;
    char input_arr[100];
    cout << "Enter expression: ";
    cin.getline(input_arr, 100);
    infix_to_postfix(&head, input_arr);
    return 0;
}
