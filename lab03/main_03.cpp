#include <iostream>
#include "List.h"
#include "Stack.h"

int main() {
    std::cout << "Hello, Lab_03" << std::endl;
    List list;
    list.insertFirst(5);
    list.insertFirst(66);
    list.insertFirst(52);
    list.insertFirst(8);
    list.print();
    list.remove(66);
    list.print();
    list.removeFirst();
    list.print();
    list.insertFirst(45);
    list.empty();
    list.print();
    list.exists(52);

    stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }

    cout << endl;

    return 0;
}
