#include <iostream>
using namespace std;
//1 2 3 4 5 6 7
class queue{
  
  public:
  int front;
  int rear;
  int len;
  int* q;
  queue(int size){
      len=size;
      q=new int[len];
      front=-1;
      rear=-1;
  }
  bool isempty(){
      if(front== -1 && rear==-1){
          return true;
      }
      else
      return false;
  }
  bool isfull(){
      if(rear== (len-1)){
          return true;
      }
      else
      return false;
  }
  void enqueue(int val){
      if(isfull()){
          cout<<"Q is full"<<endl;
      }
      else{
          if(isempty()){
              front=0;
          }
          rear++;
          q[rear]= val;
      }
  }
  void dequeue(){
      if(isempty()){
          cout<<"Q is empty"<<endl;
      }
else if(front==rear){
          front=rear=-1;
      }
      else{
         front++;
      }
  }
  void display(){
      for(int i=front;i<=rear;i++){
          cout<<q[i]<<"  ";
      }
      cout<<endl;
  }
};
int main() {
    queue q1(10);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    

    return 0;
}


#include <iostream>
using namespace std;
//1 2 3 4 5 6 7
class queue{
  
  public:
  int front;
  int rear;
  int len;
  int* q;
  queue(int size){
      len=size;
      q=new int[len];
      front=-1;
      rear=-1;
  }
  bool isempty(){
      if(front== -1 && rear==-1){
          return true;
      }
      else
      return false;
  }
  bool isfull(){
      if(front==(rear+1)%len){
          return true;
      }
      else
      return false;
  }
  void enqueue(int val){
      if(isfull()){
          cout<<"Q is full"<<endl;
      }
      else{
          if(isempty()){
              front=0;
          }
          rear=(rear+1)%len;
          q[rear]= val;
      }
  }
  void dequeue(){
      if(isempty()){
          cout<<"Q is empty"<<endl;
      }
      else if(front==rear){
          front=rear=-1;
      }
      else{
         front=(front+1)%len;
      }
  }
  void display(){
      int i=front ;
      while(1){
          cout<<q[i]<<"  ";
          if(i==rear){
              break;
          }
          i=(i+1)%len;
      }
      cout<<endl;
  }
};
int main() {
    queue q1(10);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.display();
    

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int>q;
    queue<int>temp;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    int originalSize = q.size();
    int i = 0;
    while (i < originalSize / 2) {
    temp.push(q.front());
    q.pop();
    i++;
    }
    i=0;
     while(i < originalSize / 2){
         q.push(temp.front());
         temp.pop();
         q.push(q.front());
         q.pop();
         i++;
     }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
   
    return 0;
}


#include <iostream>
#include <queue>

using namespace std;

void firstNonRepeatingCharacter(const string& input) {
    int freq[26] = {0};
    queue<char> q;

    for (char ch : input) {
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    getline(cin, input);
    string res = "";
    for (char ch : input) {
        if (ch != ' ') {
            res += ch;
        }
    }

    firstNonRepeatingCharacter(res);

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        // Move all elements except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the last element (stack behavior)
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        // Move elements to q2 and remember last
        int topElement;
        while (!q1.empty()) {
            topElement = q1.front();
            q2.push(topElement);
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);

        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;  // 30
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;  // 20

    return 0;
}


#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int sz = q.size();
        q.push(x);

        // Move all previous elements behind the new element
        for (int i = 0; i < sz; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;  // 30
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;  // 20

    return 0;
}