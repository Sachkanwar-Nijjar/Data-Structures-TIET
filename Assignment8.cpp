1. Write program using functions for binary tree traversals: Pre-order, In-order and Postorder using recursive approach.

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
void preorder(Node* root){
    if(root!=nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void postorder(Node* root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    return;
}
void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node(16);
    root->left = new Node(8);
    root->right = new Node(25);
    root->right->right = new Node(42);
    root->right->right->right = new Node(62);
    root->right->right->right->left = new Node(49);
    root->right->right->right->left->right = new Node(58);
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    deleteTree(root);
    
    return 0;
}

=============================================================================================================================

2. Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)

Node* search_rec(Node* root, int val) {
    if (root == nullptr || root->data == val) {
        if (root) {
            cout << "Element " << val << " found in the BST." << endl;
        } else {
            cout << "Element " << val << " not found in the BST." << endl;
        }
        return root;
    }

    else if (val < root->data) {
        return search_rec(root->left, val);
    }
    else { 
        return search_rec(root->right, val);
    }
}


Node* search_loop(Node* root, int val) {
    Node* temp=root;
    while(temp!=nullptr){
    if (temp->data == val) {
    cout << "Element " << val << " found in the BST." << endl;
        return temp;
    }
    else if (val < temp->data) {
       temp=temp->left;
    }
    else { 
       temp=temp->right;
        }
    }
    cout<<"Element not found:("<<endl;
    return nullptr;
}


(b) Maximum element of the BST

   Node* Max(Node* root){
    if (root == nullptr) {
        cout << "The tree is empty. Max element not found." << endl;
        return nullptr;
    }
    Node* temp = root;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    
    cout << "Max element is " << temp->data << endl;
    return temp;
}

(c) Minimum element of the BST
    
Node* Min(Node* root){
    if (root == nullptr) {
        cout << "The tree is empty. Min element not found." << endl;
        return nullptr;
    }
    Node* temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    
    cout << "Min element is " << temp->data << endl;
    return temp;
}

(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST 

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
Node* Min(Node* root){
    if (root == nullptr) {
        cout << "The tree is empty. Min element not found." << endl;
        return nullptr;
    }
    Node* temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    
    cout << "Min element is " << temp->data << endl;
    return temp;
}
Node* Max(Node* root){
    if (root == nullptr) {
        cout << "The tree is empty. Max element not found." << endl;
        return nullptr;
    }
    Node* temp = root;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    
    cout << "Max element is " << temp->data << endl;
    return temp;
}

Node* succ(Node* root, int ele){
    Node* successor = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (ele < current->data) {
            successor = current;  // potential successor
            current = current->left;
        } else if (ele > current->data) {
            current = current->right;
        } else {
            // Found the node
            if (current->right != nullptr) {
                successor = Min(current->right);
            }
            break;
        }
    }

    return successor;
}

Node* prede(Node* root, int ele){
    Node* predeccessor = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (ele < current->data) {
            current = current->left;
        } else if (ele > current->data) {
            predeccessor=current;
            current = current->right;
        } else {
            // Found the node
            if (current->left != nullptr) {
                predeccessor = Max(current->left);
            }
            break;
        }
    }

    return predeccessor;
}
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node(16);
    root->left = new Node(8);
    root->right = new Node(25);
    root->right->right = new Node(42);
    root->right->right->right = new Node(62);
    root->right->right->right->left = new Node(49);
    root->right->right->right->left->right = new Node(58);
    inorder(root);
    cout<<endl<<succ(root,58)->data<<endl;
    cout<<endl<<prede(root,58)->data<<endl;
    deleteTree(root);
    
    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert node into BST (iterative)
void createnode(Node* root, int ele) {
    Node* parent = nullptr;
    Node* curr = root;

    while (curr != nullptr) {
        parent = curr;
        if (ele < curr->data)
            curr = curr->left;
        else if (ele > curr->data)
            curr = curr->right;
        else
            return; // duplicate
    }

    Node* newNode = new Node(ele);
    if (ele < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* delnode(Node* root, int ele) {
    if (root == nullptr)
        return root;

    if (ele < root->data)
        root->left = delnode(root->left, ele);
    else if (ele > root->data)
        root->right = delnode(root->right, ele);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delnode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = new Node(15);
    createnode(root, 6);
    createnode(root, 18);
    createnode(root, 3);
    createnode(root, 7);
    createnode(root, 17);
    createnode(root, 20);
    createnode(root, 2);
    createnode(root, 4);
    createnode(root, 13);
    createnode(root, 9);

    cout << "Inorder before deletion:\n";
    inorder(root);

    root = delnode(root, 2); // deleting leaf node
    cout << "\n\nInorder after deleting 2:\n";
    inorder(root);

    return 0;
}
--------------------------------------------------------------------------------------------------

(c) Maximum depth of BST

(d) Minimum depth of BST

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void createnode(Node* root, int ele) {
    Node* parent = nullptr;
    Node* curr = root;
    while (curr != nullptr) {
        parent = curr;
        if (ele < curr->data)
            curr = curr->left;
        else if (ele > curr->data)
            curr = curr->right;
        else
            return;
    }
    Node* newNode = new Node(ele);
    if (ele < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = new Node(15);
    createnode(root, 6);
    createnode(root, 18);
    createnode(root, 3);
    createnode(root, 7);
    createnode(root, 17);
    createnode(root, 20);
    createnode(root, 2);
    createnode(root, 4);
    createnode(root, 13);
    createnode(root, 9);

    cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}

--------------------------------------------------------------------------------------------------------------------------------------------
# LEVEL ORDER TRAVERSAL/// BREADTH FIRST

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    // Create BST manually
    Node* root = new Node(15);
    root->left = new Node(6);
    root->right = new Node(18);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(17);
    root->right->right = new Node(20);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right->right = new Node(13);
    root->left->right->right->left = new Node(9);

    cout << "Level Order Traversal: ";
    levelOrder(root);
    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------

4. Write a program to determine whether a given binary tree is a BST or not.

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
bool isBST(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(6);
    root->right = new Node(18);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "It is a BST\n";
    else
        cout << "Not a BST\n";
}
=======================================================================================================================================================

##. Write a non-recursive function to traverse a BST in in-order traversal using stack.

#include <iostream>
#include <stack>
using namespace std;

// BST Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Iterative In-order Traversal using Stack
void inorderIterative(Node* root) {
    stack<Node*> st;       // Stack to store nodes
    Node* current = root;  // Start from root

    cout << "In-order Traversal: ";
    
    while (current != nullptr || !st.empty()) {
        // Go to the leftmost node
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // Process the node at the top of the stack
        current = st.top();
        st.pop();
        cout << current->data << " ";  // Visit node

        // Go to the right subtree
        current = current->right;
    }
    cout << endl;
}

// Main function
int main() {
    /*
            10
           /  \
          5    20
         / \
        3   7
    */
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(7);

    inorderIterative(root);

    return 0;
}
========================================================================================================================================================

##. Given preorder and in-order traversals, write a program to construct the Binary Tree.

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Function to find index of current root in inorder array
int searchInorder(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; // should not happen if inputs are valid
}

// Function to build the tree from preorder and inorder
Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex) {
    // Base condition
    if (inStart > inEnd)
        return nullptr;

    // Pick current node from preorder using preIndex
    int curr = preorder[preIndex++];
    Node* node = newNode(curr);

    // If this node has no children (leaf node)
    if (inStart == inEnd)
        return node;

    // Find the position of this node in inorder traversal
    int inIndex = searchInorder(inorder, inStart, inEnd, curr);

    // Build left and right subtrees
    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Inorder traversal (to verify)
void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Preorder traversal (to verify)
void printPreorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int inorder[]  = {3, 5, 7, 10, 20};
    int preorder[] = {10, 5, 3, 7, 20};
    int n = 5;

    int preIndex = 0;

    Node* root = buildTree(inorder, preorder, 0, n - 1, preIndex);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder Traversal of Constructed Tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
================================================================================================================================

##. Given in-order and post-order traversals, write a program to construct the Binary Tree.

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Function to find index of current root in inorder array
int searchInorder(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; // should not happen if inputs are valid
}

// Function to build the tree from postorder and inorder
Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex) {
    // Base condition
    if (inStart > inEnd)
        return nullptr;

    // Pick current node from preorder using postIndex
    int curr = postorder[postIndex--];
    Node* node = newNode(curr);

    // If this node has no children (leaf node)
    if (inStart == inEnd)
        return node;

    // Find the position of this node in inorder traversal
    int inIndex = searchInorder(inorder, inStart, inEnd, curr);

    // Build left and right subtrees
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Inorder traversal (to verify)
void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Postorder traversal (to verify)
void printPostorder(Node* root) {
    if (root == nullptr) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    int inorder[]  = {3, 5, 7, 10, 20};
    int postorder[] = {3,7,5,20,10};
    int n = 5;

    int postIndex = n-1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    cout << "Postorder Traversal of Constructed Tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}

==================================================================================================================================================

5. Implement Heapsort (Increasing/Decreasing order).
   #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HeapSort {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Max-heap property
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Heap Sort function
    void sort(vector<int>& arr, bool increasing = true) {
        int n = arr.size();

        // Build max-heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Extract elements
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }

        // For decreasing order, just reverse the array
        if (!increasing)
            reverse(arr.begin(), arr.end());
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    HeapSort hs;

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    hs.sort(arr, true);
    cout << "Sorted (increasing): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    hs.sort(arr, false);
    cout << "Sorted (decreasing): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
================================================================================================================================

6. Implement priority queues using heaps.
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap; 
    
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
  
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }
    void increase_key(int x, int k){
        int parent= ciel(x/2)-1;
        if(heap[x]<k){
                swap(heap[x], k);
                while(parent>=0){
                    if(k> heap[parent]){
                        swap(heap[parent], k);
                    }
                    parent=(parent/2)-1;
                }
            }
            
        
    }
    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(50);
    pq.push(40);
    pq.push(33);
    cout << "Priority Queue: ";
    pq.display();
    cout << pq.top() << endl;
   // pq.pop();
   pq.increase_key(2, 60);
    pq.display();
   // pq.pop();
   // pq.pop();
   // pq.display();

    return 0;
}
===========================================================================================================================================
