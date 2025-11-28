1. Develop a menu driven program for the following operations of on a Circular as well
as a Doubly Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and
after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
deleted may appear as a head node, last node or a node in between.
(c) Search for a node.
--------------------------------------------------------DOUBLY LINKED LIST ------------------------------------------------------------
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int c) {
        data = c;
        next = nullptr;
        prev = nullptr;
    }
};

class dll{
    Node* head=nullptr;
    Node* temp=nullptr;
    
public:
    void insert(int val){
        Node* newnode= new Node(val);
        if(head==nullptr){
            head=newnode;
            temp=newnode;
            return;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    
    }
    void insert_b(int val){
        Node* newnode= new Node(val);
        if(head==nullptr){
            head=newnode;
            temp=newnode;
            return;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    
    }
    void insert_after(int val, int ele) {
        Node* curr = head;
        while (curr != nullptr && curr->data != ele) {
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Element " << ele << " not found!\n";
            return;
        }

        Node* newnode = new Node(val);
        newnode->next = curr->next;
        if (curr->next != nullptr) {
            curr->next->prev = newnode;
        }
        curr->next = newnode;
        newnode->prev = curr;
    }
    void del_b() {
    if (head == nullptr) {
        cout << "List already empty " << endl;
        return;
    }
    Node* del = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        temp = nullptr;  // list became empty
    }
    delete del;
}

void del_e() {
    if (head == nullptr) {
        cout << "List already empty " << endl;
        return;
    }
    if (head->next == nullptr) {  // only one element
        delete head;
        head = nullptr;
        temp = nullptr;
        return;
    }
    Node* del = temp;
    temp = temp->prev;
    temp->next = nullptr;
    delete del;
}

    void display(){
        Node* curr=head;
        while(curr){
            cout<<curr->data<<"  ";
            curr=curr->next;
        }
        cout<<endl;
    }
};

int main() {
    
    dll l;
    l.insert(2);
    l.insert(23);
    l.insert(234);
    l.insert(2345);
    l.display();
    l.insert_b(1);
    l.display();
    l.insert_after(66,23);
    l.del_b();
    l.display();
    l.del_e();
    l.display();
    return 0;
}

===========================================================================================================================================================


2. Display all the node values in a circular linked list, repeating value of head node at the
end too.
Input: 20 → 100 → 40 → 80 → 60,
Output: 20 100 40 80 60 20.



#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int c) {
        data = c;
        next = nullptr;
    }
};

class cll{
    Node* head=nullptr;
    Node* temp=nullptr;
    
public:
    void insert(int val){
        Node* newnode= new Node(val);
        if(head==nullptr){
            head=newnode;
            temp=newnode;
            newnode->next=head;
            return;
        }
        else{
            temp->next=newnode;
            newnode->next=head;
            temp=newnode;
        }
    
    }
    void insert_b(int val){
        Node* newnode= new Node(val);
        if(head==nullptr){
            head=newnode;
            temp=newnode;
            newnode->next=head;
            return;
        }
        else{
            newnode->next=head;
            temp->next=newnode;
            head=newnode;
        }
    
    }
    void insert_after(int val, int ele) {
        Node* curr = head;
        while (curr != nullptr && curr->data != ele) {
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Element " << ele << " not found!\n";
            return;
        }

        Node* newnode = new Node(val);
        newnode->next = curr->next;
        curr->next = newnode;
    }
    void del_b() {
    if (head == nullptr) {
        cout << "List already empty " << endl;
        return;
    }
    Node* del = head;
    head = head->next;
    if (head) {
        temp->next = head;
    } else {
        temp = nullptr;  // list became empty
    }
    delete del;
}

void del_e() {
    if (head == nullptr) {
        cout << "List already empty " << endl;
        return;
    }
    if (head->next == head) {  // only one element
        delete head;
        head = nullptr;
        temp = nullptr;
        return;
    }
    Node* del = temp;
    Node* curr=head;
        while(curr->next != temp){
            curr=curr->next;
        }
        
    temp = curr;
    temp->next = head;
    delete del;
}

     void display(){
        if(head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while(curr != head);
        cout << head->data << endl; 
    }
};

int main() {
    
    cll l;
    l.insert(2);
    l.insert(23);
    l.insert(234);
    l.insert(2345);
    l.display();
    l.insert_b(1);
    l.display();
    l.insert_after(66,23);
    l.del_b();
    l.display();
    l.del_e();
    l.display();
    return 0;
}

=====================================================================================================================================

3. Write a program to find size of
i. Doubly Linked List.
ii. Circular Linked List.

i.    void size(){
        int len=0;
        Node* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        cout<<"Size of list is "<<len<<endl;
       }

ii.   void size(){
        int len=0;
        Node* curr=head;
        do {
            len++;
            curr = curr->next;
        } while(curr != head);
        cout<<"Size of list is "<<len<<endl;
    }

==========================================================================================================================================

4. Write a program to check if a doubly linked list of characters is palindrome or not.

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char c) {
        data = c;
        next = nullptr;
        prev = nullptr;
    }
};

class dll{
    Node* head=nullptr;
    Node* temp=nullptr;
    
public:
    void insert(char val){
        Node* newnode= new Node(val);
        if(head==nullptr){
            head=newnode;
            temp=newnode;
            return;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    
    }
    void display(){
        Node* curr=head;
        while(curr){
            cout<<curr->data<<"  ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void size(){
        int len=0;
        Node* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        cout<<"Size of list is "<<len<<endl;
    }
   void palindrome(){
        Node* start = head;
        Node* end = temp;
        if (head == nullptr) {
            cout << "List is empty (considered a palindrome)." << endl;
            return;
        }
        bool flag = true;
        while(start != end && start->prev != end) { 
            if(start->data != end->data){
                flag = false;
                break;
            }
            start = start->next;
            end = end->prev;
        }
        
        if(flag){
            cout << "It is a palindrome" << endl;
        }
        else{
            cout << "Not a palindrome" << endl;
        }
    }
};

int main() {
    
    dll l;
    l.insert('l');
    l.insert('e');
    l.insert('v');
    l.insert('e');
    //l.insert('l');
    l.display();
    l.palindrome();
    
    return 0;
}

=================================================================================================================================================
                                                                 ADDITIONAL QUESTIONS
=================================================================================================================================================

1. Given a Circular linked list. The task is split into two Circular Linked lists. If there are an
odd number of nodes in the given circular linked list then out of the resulting two halved
lists, the first list should have one node more than the second list.
https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
Input: 10->4->9
Output: 10->4 , 9


// C++ Program to split a circular linked list
// into two halves 
#include <bits/stdc++.h>
using namespace std;

class Node { 
    public:
    int data; 
    Node *next; 
    Node (int new_value){
        data = new_value;
        next = nullptr;
    }
}; 

pair<Node*, Node*> splitList(Node *head) { 
    Node *slow = head; 
    Node *fast = head; 
    
    if(head == nullptr) 
        return {nullptr, nullptr}; 
        
    while(fast->next != head && 
          fast->next->next != head) { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    
    // If there are even elements in list
    // then move fast
    if(fast->next->next == head) 
        fast = fast->next; 
        
    // Set the head pointer of first half
    Node* head1 = head; 
        
    // Set the head pointer of second half
    Node* head2 = slow->next; 
        
    // Make second half circular
    fast->next = slow->next; 
        
    // Make first half circular
    slow->next = head; 
    
    return {head1, head2};
} 

void printList(Node *head) { 
    Node *curr = head; 
    if(head != nullptr) { 
        do { 
        cout << curr->data << " "; 
        curr = curr->next; 
        } while(curr != head); 
      	cout << endl; 
    } 
} 

int main() { 
    
    Node *head = new Node(1); 
    Node *head1 = nullptr; 
    Node *head2 = nullptr; 

    // Created linked list will be 1->2->3->4
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    pair<Node*, Node*> result = splitList(head); 
    head1 = result.first;
    head2 = result.second;
    
    printList(head1); 
    printList(head2);
    
    return 0; 
}

==========================================================================================================================================
