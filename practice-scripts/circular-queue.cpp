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

    bool isFull() {
        node* temp = front;
        int i = 0;
        while (temp) {
            i++;
            temp = temp->next;
        }
        return i >= 5;
    }

    void wrap_around() {
        if (rear) rear->next = front;
    }

    void push(int data) {
        node* new_node = new node(data);
        if (isEmpty()) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
        rear->next = front;
    }

    void pop() {
        if (isEmpty()) {
            cout << "List is already empty!\n";
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = NULL;
            return;
        }
        node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }

    void print() {
        if (isEmpty()) return;
        node* temp = front;
        do {
            cout << "Data: " << temp->data << "    Address: " << temp << endl;
            temp = temp->next;
        } while (temp != front);
    }

    int size() {
        if (isEmpty()) return 0;
        node* temp = front;
        int i = 0;
        do {
            i++;
            temp = temp->next;
        } while (temp != front);
        return i;
    }
};

int main() {
    queue q;
    for (int i = 0; i < 4; i++) q.push(10);
    cout << "Inserting 4 Items: \n\n";
    q.print();
    for (int i = 0; i < 3; i++) q.pop();
    cout << "\n\nRemoving 3 Items: \n\n";
    q.print();
    for (int i = 0; i < 4; i++) q.push(10);
    cout << "\n\nInserting 4 Items: \n\n";
    q.print();
    q.wrap_around();
    cout << "\n\nInvoking Wrap-Around: \n\n";
    q.print();
    while (!q.isEmpty()) q.pop();
    return 0;
}