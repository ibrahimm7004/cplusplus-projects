#include <iostream>
using namespace std;

struct node {
    node* next;
    int data;
    node(int d) {
        data = d;
        next = NULL;
    }
};

class queue {
public:
    node* front;
    node* rear;

    queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void push(int data) {
        node* new_node = new node(data);
        if (isEmpty()) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "List is already empty!\n";
            return;
        }
        node* temp = front;
        front = front->next;
        delete temp;
        if (front == NULL) rear = NULL;
    }

    node* peek() {
        return front;
    }

    void print() {
        node* temp = front;
        while (temp) {
            cout << "Data: " << temp->data << "    Address: " << temp << endl;
            temp = temp->next;
        }
    }
};

class stack {
public:
    node* head;

    stack() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int data) {
        node* new_node = new node(data);
        new_node->next = head;
        head = new_node;
    }

    void pop() {
        if (isEmpty()) {
            cout << "List is already empty! \n";
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    node* peek() {
        return head;
    }

    void print() {
        node* temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

void push_to_stack(queue& q, stack& s) {
    while (!q.isEmpty()) {
        s.push(q.peek()->data);
        q.pop();
    }
}

void pop_to_queue(queue& q, stack& s) {
    while (!s.isEmpty()) {
        q.push(s.peek()->data);
        s.pop();
    }
}

int main() {
    queue q;
    stack s;

    q.push(10);
    q.push(28);
    q.push(9);
    q.push(43);
    q.print();
    
    push_to_stack(q, s);
    s.print();
    
    pop_to_queue(q, s);
    q.print();
    
    for (int i = 0; i < 4; i++) {
        cout << "\nPeek: " << q.peek()->data << endl;
        q.pop();
        q.print();
    }
    
    return 0;
}