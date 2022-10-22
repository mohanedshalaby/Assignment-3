#pragma once

#include <iostream>

using namespace std;

struct Node
{
    int number;
    int counter;
    Node* nxt;

    Node();

    Node(int number);

    Node(int number, int counter);
};

class LinkedList
{
    Node* head;
    Node* tail;
public:
    LinkedList();

    void insert(int number, int counter);

    void print();
    int getSum();
    void remove(int x);
};