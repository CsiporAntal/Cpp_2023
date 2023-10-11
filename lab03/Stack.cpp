//
// Created by Toni on 2023. 10. 11..
//

#include "Stack.h"

using namespace std;

List list;
void stack::push(int e) {
    list.insertFirst(e);
}

int stack::pop() {
    if (list.empty()) {
        throw domain_error("Empty stack");
    }
    return list.removeFirst();
}

bool stack::isEmpty() const{
    return list.empty();
}