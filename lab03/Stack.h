//
// Created by Toni on 2023. 10. 11..
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include "List.h"

class stack {
private:
    List list;

public:
    void push(int e);
    int pop();
    bool isEmpty() const;
};


#endif //CPP_2022_STACK_H
