#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
    }
};

void push(node** head, int data) {
    node* new_node = new node(data);
    new_node->next = *head;
    *head = new_node;
}

bool isEmpty(node** head) {
    return (*head == NULL);
}

int top(node** head) {
    if (!isEmpty(head)) return (*head)->data;
    return 0;
}

void pop(node** head) {
    if (isEmpty(head)) return;
    node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void postfix_calculator(node** head, char input_arr[]) {
    int i = 0;
    while (input_arr[i]) {
        char a = input_arr[i];
        i++;
        if (isdigit(a)) {
            push(head, a - '0');
        } else {
            int temp1 = top(head);
            pop(head);
            int temp2 = top(head);
            pop(head);
            int result;
            if (a == '*') result = temp2 * temp1;
            else if (a == '+') result = temp2 + temp1;
            else if (a == '-') result = temp2 - temp1;
            else result = temp2 / temp1;
            push(head, result);
        }
    }
    cout << top(head);
}

int main() {
    node* head = NULL;
    char input_arr[100];
    cout << "Enter expression: ";
    cin.getline(input_arr, 100);
    postfix_calculator(&head, input_arr);
    return 0;
}
