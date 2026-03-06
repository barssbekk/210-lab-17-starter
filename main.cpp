#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addFront(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void addTail(Node *&, float);
void deleteLinkedList(Node *&);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
        // adds node at head
    }

    // addTail(head, 200); // Test
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    deleteNode(head, entry);
    // at this point, delete current and reroute pointers
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    //at this point, insert a node between prev and current
    insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteLinkedList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node *&head, const float value) {
    Node* newNode = new Node;
    if (!head) {
        head = newNode;
        newNode->value = value;
        newNode->next = nullptr;
    } else {
        newNode->value = value;
        newNode->next = head; // point to old head
        head = newNode; // move head to new node, and new node is new head
    }
}

void deleteNode(Node *&head, const int position) {
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < position - 1; ++i) {
        if (i == 0) {
            current = current->next;
        } else {
            current = current->next;
            prev = prev->next;
        }
    }
    if (current) {
        prev->next = current->next;
        delete current;
    }
}

void insertNode(Node*& head, const int position, const float value) {
    Node* current = head;
    Node* prev = head;
    for (int i = 0; i < position; ++i) {
        if (i == 0) {
            current = current->next;
        } else {
            current = current->next;
            prev = prev->next;
        }
    }
    Node* newNode = new Node;
    newNode->value = value;

    newNode->next = current;
    prev->next = newNode;
}

void addTail(Node *&head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next; // Until it reaches nullptr
        }
        current->next = newNode; // new tail
    }
}

void deleteLinkedList(Node *&head) {
    Node* current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}