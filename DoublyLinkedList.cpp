#include "DoublyLinkedList.h"
#include <iomanip>
#include <sstream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int val) : head(new Node(val)), tail(new Node(val)) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node *n = head->next;
    while (n != head) {
        Node *next = n->next;
        delete n;
        n = next;
    }
    delete head;
}

void DoublyLinkedList::insert_back(int val) {
    Node *n = new Node;
    n->data = val;
    n->next = head;
    n->prev = head->prev;
    n->next->prev = n;
    n->prev->next = n;
}

void DoublyLinkedList::insert_front(int val) {
    Node* n = new Node(val);
    if (head == nullptr)
        tail = n;
    n->next = head; head = n;
    if (n->next != nullptr)
        n->next->prev = head;
}

void DoublyLinkedList::insert_at(int val, int idx) {
    Node* temp1 = new Node();
    temp1->data = val;
    temp1->next = nullptr;
    if (idx == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 0; i < idx - 2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

Node& DoublyLinkedList::find(int val) {
    // Start from the head
    Node* current = head;

    // If list is empty
    if (head == nullptr)
    {
        throw runtime_error("error");
    }

    // Traverse through list
    while (current->data != val) {

        // If it is last node
        if (current->next == nullptr) {
            throw runtime_error("error");
        }
        else {
            // Go to next node
            current = current->next;
        }
    }

    // If data found
    std::cout << "Found" << std::endl;
}

void DoublyLinkedList::delete_at(int idx) {
    Node *n = head->next;
    while (n != head) {
        Node *next = n->next;
        if (n->data == idx) {
            n->prev->next = n->next;
            n->next->prev =n->prev;
            delete n;
        }
        n = next;
    }
}

Node& DoublyLinkedList::get_head() {
    return *head;
}

Node& DoublyLinkedList::get_tail() {
    return *tail;
}

Node const& DoublyLinkedList::get_head() const {
    return *head;
}

Node const& DoublyLinkedList::get_tail() const {
    return *tail;
}

ostream& operator<<(ostream &os, DoublyLinkedList const& ll) {
    os << "Doubly Linked List" << endl;
    if (&(ll.get_head()) == nullptr)
        return (os << "Empty" << endl);
    os << "Head: " << &(ll.get_head()) << "\t Tail: " << &(ll.get_tail()) << endl;
    Node const* curr = &(ll.get_head());
    os << "Nodes (accessible from head to tail):" << endl << endl;
    os << setw(16) << setfill(' ') << ' ' << ' ' << center("prev", 15) << ' ' << center("data", 15) << ' ' << center("next", 15) << endl;
    while (curr != nullptr) {
        ostringstream oss; oss << (curr->prev); string prev = oss.str(); oss.str(""); oss << (curr->next); string next = oss.str(); oss.str(""); oss << (curr->data); string data = oss.str(); oss.str(""); oss << curr; string address = oss.str();
        os << setw(16) << setfill(' ') << ' ' << '.' << setw(16) << setfill('-') << '.' << setw(16) << '.' << setw(16) << '.' << endl;
        os << setw(16) << setfill(' ') << center(address, 15) << '|' << setw(15) << setfill(' ') << center(prev, 15) << '|' << setw(15) << center(data, 15) << '|' << setw(15) << center(next, 15) << '|' << endl;
        os << setw(16) << setfill(' ') << ' ' << '\'' << setw(16) << setfill('-') << '\'' << setw(16) << '\'' << setw(16) << '\'' << endl;
        os << endl;
        curr = curr->next;
    }
    return os;
}

string center (const string &str, const int col_width) {
    // quick and easy (but error-prone) implementation
    int padl = (col_width - str.length()) / 2;
    int padr = (col_width - str.length()) - padl;
    string strf = string(padl, ' ') + str + string(padr, ' ');
    return strf;
}
