//
// Created by Toni on 2023. 10. 11.
//

#include "List.h"



bool List::exists(int d) const {
    for (auto n{first}; n != nullptr; n = n->next) {
        if (n->value == d) {
            return true;
        }
    }
    return false;
}

bool List::empty() const {
    return first == nullptr;
}

void List::insertFirst(int d) {
    this->first = new Node(d, this->first);
    this->nodeCounter++;
}


int List::removeFirst() {
    if (first == nullptr) {
        throw domain_error("Empty list");
    }
    Node* tmp = first;
    first = first->next;
    int result = tmp->value;
    delete tmp;
    return result;
}

void List::remove(int d, DeleteFlag df) {
    Node* prev = nullptr;
    Node* current = first;

    while (current != nullptr) {
        if ((df == DeleteFlag::LESS && current->value < d) ||
            (df == DeleteFlag::EQUAL && current->value == d) ||
            (df == DeleteFlag::GREATER && current->value > d)) {
            if (prev == nullptr) {
                first = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void List::print() const {
    for (Node* n = first; n != nullptr; n = n->next) {
        cout << n->value << " ";
    }
    cout << endl;
}