1. Develop a menu driven program demonstrating the following operations on a Stack using array: 
(i) 
push(),  (ii) pop(),  (iii) isEmpty(),  (iv) isFull(),  (v) display(), and  (vi) peek(). 

#include <iostream>
using namespace std;
//template <class T>
class stack{
	int top=-1;
	int s[10];
	public:
		void push(int ele){
			 	if(top==9){
		 cout<<"Stack full ! "<<endl;
				 }
 	   else{
		
 	        top++;
			s[top] =ele;
		}
	}
	void pop(){
		if(top ==-1){
			   	cout<<"Stack is empty already !"<<endl;
	   	        
		}
		 else{
		 	  
		 	   	top--;
    	        
		 }
	}
	void isEmpty(){
		if(top==-1){
						cout<<"yes , Stack is empty !"<<endl;
		}
		 else 
		 cout<<"noo , Stack is not empty !"<<endl;
	}
		void isFull(){
		if(top==9){
						cout<<"yes , Stack is full !"<<endl;
		}
		 else 
		 cout<<"noo , Stack is not full !"<<endl;
	}
	void display(){
		for(int i=0;i<=top;i++){
					cout<<s[i]<<"  ";
		}
		 cout<<endl;
	}
	void peek(){
		if(top ==-1){
			   	cout<<"Stack is empty already !"<<endl;
		}
		 else{
		 	   	cout<< s[top];   	        
		 }
	}
};
int  main()
{
stack s1;
s1.isEmpty();
s1.push(6);
s1.push(88);
s1.push(63);
s1.push(48);
s1.push(61);
s1.push(8);
s1.display();
s1.peek();
}
---------------------------------------------------------------------------------------------------------------------
2. Given a string, reverse it using STACK. For example “DataStructure” should be output as 
“erutcurtSataD.” 

2.#include <iostream>
#include <string>
using namespace std;
//template <class T>
class stack{
	int top=-1;
	char s[30];
	public:
		void push(char ele){
			 	if(top==29){
		 cout<<"Stack full ! "<<endl;
				 }
 	   else{
		
 	        top++;
			s[top] =ele;
		}
	}
	void pop(){
		if(top ==-1){
			   	cout<<"Stack is empty already !"<<endl;
	   	        
		}
		 else{
		 	  
		 	   	top--;
    	        
		 }
	}
	bool isEmpty(){
		if(top==-1){
					return true;
		}
		 else 
		 return false;
	}
		void isFull(){
		if(top==29){
						cout<<"yes , Stack is full !"<<endl;
		}
		 else 
		 cout<<"noo , Stack is not full !"<<endl;
	}
	void display(){
		for(int i=0;i<=top;i++){
					cout<<s[i]<<" ";
		}
		 cout<<endl;
	}
	char peek(){
		if(top ==-1){
			   	return '-';
		}
		 else{
		 	   	return s[top];   	        
		 }
	}
};
int  main()
{
stack s1;
string ds="Data structure";
cout<<ds<<endl;
for(int i=0;i<ds.length();i++){
	s1.push(ds[i]);
}
s1.display();

string dsr="";
while(!s1.isEmpty()){
	dsr+=s1.peek();
	s1.pop();
}
cout<<dsr<<endl;

}


-------------------------
using stl stacks
-------------------------

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> s1;  
    string ds = "DataStructure";  

    cout << "Original string: " << ds << endl;

    // Push characters onto stack
    for (int i = 0; i < ds.length(); i++) {
        s1.push(ds[i]);
    }

    // Pop characters to reverse
    string dsr = "";
    while (!s1.empty()) {
        dsr += s1.top();  // take top element
        s1.pop();         // remove top element
    }

    cout << "Reversed string: " << dsr << endl;

    return 0;
}

=----------------------------------------------------------------------------------------------------------------------------------
3. Write a program that checks if an expression has balanced parentheses.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> s1;  
    string peren = "[{((){})}]";  

    cout << "Parenthesis combination is: " << peren << endl;

    bool balanced = true;

    for (int i = 0; i < peren.length(); i++) {
        if (peren[i] == '[' || peren[i] == '(' || peren[i] == '{') {
            s1.push(peren[i]);
        }
        else {
            if (s1.empty()) {  
                balanced = false;
                break;
            }
            if (peren[i] == ')' && s1.top() == '(') {
                s1.pop();
            }
            else if (peren[i] == '}' && s1.top() == '{') {
                s1.pop();
            }
            else if (peren[i] == ']' && s1.top() == '[') {
                s1.pop();
            }
            else { 
                balanced = false;
                break;
            }
        }
    }

    if (balanced && s1.empty()) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
--------------------------------------------------------------------------------------------------------------------------
4. Write a program to convert an Infix expression into a Postfix expression.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    string infix = "a+b-(d*f)+(c/e)";
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand → add to output
        if (isalnum(c)) {
            postfix += c;
        }
        // If '(' → push
        else if (c == '(') {
            s.push(c);
        }
        // If ')' → pop until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        // If operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------

5. Write a program for the evaluation of a Postfix expression. 

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    cout << "Postfix is : ";
    string post = "100 200 + 2 / 5 * 7 +";
    cout << post << endl;

    stack<int> s;
    int output = 0;
    int i = 0;

    while (i < post.length()) {
        if (post[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(post[i])) {
            int num = 0;
            while (isdigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            s.push(num);
        }
        else { 
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();

            if (post[i] == '+') output = op1 + op2;
            else if (post[i] == '-') output = op1 - op2;
            else if (post[i] == '*') output = op1 * op2;
            else if (post[i] == '/') output = op1 / op2;

            s.push(output);
            i++;
        }
    }

    cout << "Final Output is : " << s.top() << endl;
    return 0;
}