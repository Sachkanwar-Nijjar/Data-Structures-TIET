//   QUES 1) Implement the Binary search algorithm regarded as a fast search algorithm with run-time
// complexity of Ο(log n) in comparison to the Linear Search. 

#include<iostream>
using namespace std;

void binary_search(int arr[], int length, int number){
    int s = 0;
    int e = length - 1;

    int mid = s + ((e-s)/2);
    bool check = false;

        while(s<=e){
        if(arr[mid]==number){
            check = true;
            break;
        }

        if(arr[mid]>number){
            e = mid - 1;
            mid = s + ((e-s)/2);
        }

         if(arr[mid]<number){
            s = mid + 1;
            mid = s + ((e-s)/2);
        }
        }
    
    if(check){
        cout<<"your element is present"<<endl;
    }

    else{
        cout<<"your element is not present "<<endl;
    }
    
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  cout<<"enter the element you want to find "<<endl;
    int n;
     cin>>n;

     binary_search(arr,10,n);
 }




/*
Q2) Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent
elements if they are in wrong order. Code the Bubble sort with the following elements:
64 34 25 12 22 11 90
*/

#include<iostream>
using namespace std;

void printarr(int arr[],int length){
    for(int i = 0; i<length; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubblesort(int arr[],int n){

    for(int i = 0; i<n; i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){
    int arr[7] = {64,34,25,12,22,11,90};

    cout<<"before bubble sort"<<endl;;
    printarr(arr,7);
    
    bubblesort(arr,7);

    cout<<"after bubble sort"<<endl;
    printarr(arr,7);
}




//Q3
#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return low + 1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6, 7, 8}; 
    cout << "Missing number: " << findMissing(arr) << endl;
    return 0;
}




// Q4 a
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    str1 += str2; // concatenation
    cout << "Concatenated String: " << str1 << endl;

    return 0;
}


//Q4 b
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Reversed String: ";
    for (int i = str.length() - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;

    return 0;
}



//Q4 c
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";
    for (char c : str) {
        if (!isVowel(c)) {
            result += c;
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}



//Q4 d
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    string arr[50];
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}


//Q4 e
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character in uppercase: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;  // ASCII conversion: 'A' (65) → 'a' (97)
    }

    cout << "Lowercase character: " << ch << endl;

    return 0;
}



//Q8 
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // Check if this element appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            distinctCount++;
        }
    }

    cout << "Total number of distinct elements: " << distinctCount << endl;
    return 0;
}