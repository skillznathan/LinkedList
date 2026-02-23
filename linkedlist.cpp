#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

// Inserts a new node with the given value at the front of the list.
// Returns a pointer to the new head.
Node* push_front(Node* head, int value) {
    Node* node = new Node;
    node->value = value;
    node->next = head;
    return node;
}

// Removes the first node in the list and returns the new head.
// If the list is empty, returns nullptr.
Node* remove_head(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
    return head;
}

// Prints every value in the list on one line, separated by spaces.
void print_list(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->value << " ";
    }
    cout << endl;
}

// Part 2: Count the Nodes
int count_nodes(Node* head) {
    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        count++;
    }
    return count;
}

// Part 4: Find a Value
bool contains(Node* head, int target) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->value == target) {
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = nullptr;

    // Part 1: Build and Print a List
    // To get 10, 20, 30, 40, 50, we must push in reverse order.
    head = push_front(head, 50);
    head = push_front(head, 40);
    head = push_front(head, 30);
    head = push_front(head, 20);
    head = push_front(head, 10);
    print_list(head);

    // Part 2: Count the Nodes
    cout << "Count: " << count_nodes(head) << endl;

    // Part 3: Remove from the Front
    head = remove_head(head); // Removes 10
    print_list(head);
    head = remove_head(head); // Removes 20
    print_list(head);
    cout << "Count: " << count_nodes(head) << endl;

    // Part 4: Find a Value
    cout << "Contains 40? " << contains(head, 40) << endl;
    cout << "Contains 99? " << contains(head, 99) << endl;

    // Optional: Clean up remaining nodes to avoid memory leaks
    while (head != nullptr) {
        head = remove_head(head);
    }

    return 0;
}