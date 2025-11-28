1. Develop a menu driven program for the following operations on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values.


#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val = 0) {
        data = val;
        next = nullptr;
    }
};

class linklist {
    node* head = nullptr;
    node* temp = nullptr;

public:
    void insert_at_begin(int value) {
        node* newnode = new node(value);
        if (head == nullptr) {
            head = temp = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void del_at_begin() {
        if (head == nullptr) {
            cout << "List is already empty" << endl;
            return;
        }
        node* delnode = head;
        head = head->next;
        if (head == nullptr) temp = nullptr; // reset tail
        delete delnode;
    }

    void insert_at_end(int value) {
        node* newnode = new node(value);
        if (head == nullptr) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    void del_at_end() {
        if (head == nullptr) {
            cout << "Linked list is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = temp = nullptr;
            return;
        }
        node* prev = head;
        node* curr = head->next;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
        temp = prev; // update tail
    }

    void insert_at_pos(int value, int ele) {
        node* newnode = new node(value);
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == ele) {
            newnode->next = head;
            head = newnode;
            return;
        }
        node* prev = head;
        node* curr = head->next;
        while (curr) {
            if (curr->data == ele) {
                prev->next = newnode;
                newnode->next = curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Element " << ele << " not found\n";
    }

    void del_at_pos(int value) {
        if (head == nullptr) {
            cout << "List is Empty.\n";
            return;
        }
        node* curr = head;
        node* prev = nullptr;
        while (curr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            cout << "Element not found.\n";
            return;
        }
        if (curr == head) {
            head = head->next;
            if (head == nullptr) temp = nullptr;
        } else {
            prev->next = curr->next;
            if (curr == temp) temp = prev; // update tail if last node deleted
        }
        delete curr;
    }

    void find_pos(int ele) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        int count = 1;
        node* curr = head;
        while (curr) {
            if (curr->data == ele) {
                cout << "Element found at position " << count << endl;
                return;
            }
            count++;
            curr = curr->next;
        }
        cout << "Element " << ele << " not found\n";
    }

    void find_n_del(int ele) {
        if (head == nullptr) {
            cout << "List is Empty.\n";
            return;
        }
        int count = 0;
        // keep deleting while head matches
        while (head && head->data == ele) {
            del_at_pos(ele);
            count++;
        }
        // delete from the rest
        node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == ele) {
                del_at_pos(ele);
                count++;
            } else {
                curr = curr->next;
            }
        }
        cout << "Number of occurrences deleted: " << count << endl;
    }

    void display() {
        node* t1 = head;
        while (t1) {
            cout << t1->data << "  ";
            t1 = t1->next;
        }
        cout << endl;
    }
};

int main() {
    linklist l;
    l.insert_at_end(1);
    l.insert_at_end(2);
    l.insert_at_end(3);
    l.display();            // 1 2 3
    l.insert_at_begin(5);
    l.display();            // 5 1 2 3
    l.insert_at_pos(88, 1); // insert 88 before 1
    l.display();            // 5 88 1 2 3
    l.insert_at_pos(99, 10); // not found
    l.del_at_begin();
    l.del_at_end();
    l.display();            // 88 1 2
    l.del_at_pos(1);
    l.display();            // 88 2
    l.insert_at_begin(5);
    l.insert_at_begin(5);
    l.insert_at_begin(5);
    l.insert_at_begin(5);
    l.display();            // 5 5 5 5 88 2
    l.find_pos(88);         // position output
    l.find_n_del(5);
    l.display();            // 88 2
    return 0;
}

============================================================================================================


3. Write a program to find the middle of a linked list.
Input: 1->2->3->4->5
Output: 3

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val = 0) {
        data = val;
        next = nullptr;
    }
};

class linklist {
    node* head = nullptr;
    node* temp = nullptr;

public:
    void insert_at_begin(int value) {
        node* newnode = new node(value);
        if (head == nullptr) {
            head = temp = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void del_at_begin() {
        if (head == nullptr) {
            cout << "List is already empty" << endl;
            return;
        }
        node* delnode = head;
        head = head->next;
        if (head == nullptr) temp = nullptr; // reset tail
        delete delnode;
    }

   

    void display() {
        node* t1 = head;
        while (t1) {
            cout << t1->data << "  ";
            t1 = t1->next;
        }
        cout << endl;
    }
    void middle() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    node* slow = head;
    node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << "Middle is " << slow->data << endl;
}

};

int main() {
    linklist l;
    l.insert_at_begin(1);
    l.insert_at_begin(2);
    l.insert_at_begin(3);
    l.insert_at_begin(4);
    l.insert_at_begin(5);
    l.display();
    l.middle();
    return 0;
}

=======================================================================================================================
4. Write a program to reverse a linked list.
Input: 1->2->3->4->NULL
Output: 4->3->2->1->NULL

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val = 0) {
        data = val;
        next = nullptr;
    }
};

class linklist {
    node* head = nullptr;
    node* temp = nullptr;

public:
    void insert_at_begin(int value) {
        node* newnode = new node(value);
        if (head == nullptr) {
            head = temp = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void del_at_begin() {
        if (head == nullptr) {
            cout << "List is already empty" << endl;
            return;
        }
        node* delnode = head;
        head = head->next;
        if (head == nullptr) temp = nullptr; // reset tail
        delete delnode;
    }

   

    void display() {
        node* t1 = head;
        while (t1) {
            cout << t1->data << "  ";
            t1 = t1->next;
        }
        cout << endl;
    }
    // 5 4 3 2 1
    // 1 2 3 4 5
void reverse() {
    node* back = nullptr;
    node* curr = head;
    node* front = nullptr;

    while (curr != nullptr) {
        front = curr->next;   // save next node
        curr->next = back;    // reverse the link
        back = curr;          // move back forward
        curr = front;         // move curr forward
    }

    head = back;  // update head to new first node
}

};

int main() {
    linklist l;
    l.insert_at_begin(1);
    l.insert_at_begin(2);
    l.insert_at_begin(3);
    l.insert_at_begin(4);
    l.insert_at_begin(5);
    l.display();
    l.reverse();
    l.display();
    
    return 0;
}
===================================================================================================================

 

