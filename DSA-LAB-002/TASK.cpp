#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class stack {
private:
    int* arr;  // pointer for array
    int capacity;
    int top;
public:
    stack(int n)      // Constructor
    {
        capacity = n;
        arr = new int[n];
        top = -1;
    }
    ~stack()     // Destructor
    {
        delete[] arr;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    bool push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = value;
        return true;
    }
    bool isEmpty() const {
        return top == -1;
    }
    bool pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return false;
        }
        top--;
        return true;
    }
    void display() const {
        cout << "Displaying the stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // Palindrome check for the stack
    bool palindrome() {
        int start = 0;
        int end = top;
        while (start < end) {
            if (arr[start] != arr[end]) {
                return false;  // Not a palindrome
            }
            start++;
            end--;
        }
        return true;  // It is a palindrome
    }
};
bool isPalindromeString(const string& str) //palindrome for string
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return false;  // Not a palindrome
        }
        start++;
        end--;
    }
    return true;  // It is a palindrome
}
int main() {
    stack Stack(3);
    Stack.push(3);
    Stack.push(1);
    Stack.push(3);
    Stack.display(); // Display the elements in the stack
    cout << "\n";
    // Check if the current stack is a palindrome
    if (Stack.palindrome()) {
        cout << "The stack is a palindrome." << endl;
    }
    else {
        cout << "The stack is not a palindrome." << endl;
    }
    Stack.pop(); // Pop the top element
    Stack.display(); // Display the elements in the stack after popping an element
    cout << "\n";


    // Checking palindrome with string
    string str;
    cout << "INPUT A WORD TO CHECK WHETHER IT'S A PALINDROME OR NOT: ";
    getline(cin, str);

    if (isPalindromeString(str)) {
        cout << "The word is a palindrome." << endl;
    }
    else {
        cout << "The word is not a palindrome." << endl;
    }

    return 0;
}
