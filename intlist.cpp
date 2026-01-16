// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
//Owen Kirchner, 1/15/26

#include "intlist.h"

#include <iostream>
#include <utility>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if(!source.head) return;

    head = new Node{source.head->info, nullptr};
    tail=head;

    Node* curr = source.head->next;
    while(curr){
        tail->next = new Node{curr->info, nullptr};
        tail=tail->next;
        curr=curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr=head;
    while(curr){
        Node* next = curr->next;
        delete curr;
        curr=next;
    }
    head = tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int sum=0;
    Node* curr = head;
    while(curr){
        sum+=curr->info;
        curr=curr->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr=head;
    while(curr){
        if(curr->info==value){
            return true;
        }
        curr=curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head) return 0;
    Node* curr=head;
    int max=curr->info;
    while(curr){
        if(curr->info>max){
            max=curr->info;
        }
        curr=curr->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!head) return 0.0;
    int size=0;
    double sum=0.0;
    Node* curr=head;
    while(curr){
        sum+=curr->info;
        size++;
        curr=curr->next;
    }
    return sum/size;
}


// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* x = new Node{value,head};
    head=x;
    if(!tail) tail=head;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* x = new Node{value,nullptr};
    if(!head){
        head = tail = x;
    } else {
        tail->next=x;
        tail=x;
    }
 
}

// return count of values
int IntList::count() const {
   int c=0;
   Node* curr=head;
   while(curr){
    c++;
    curr=curr->next;
   }
   return c;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this == &source) return *this;

    Node* curr = head;
    while(curr){
        Node* next = curr->next;
        delete curr;
        curr=next;
    }
    head = tail = nullptr;

    if(source.head == nullptr) return *this;

    head = new Node {source.head->info, nullptr};
    tail = head;
    for(Node* s = source.head->next; s!= nullptr; s = s->next){
        tail->next = new Node {s->info, nullptr};
        tail=tail->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

