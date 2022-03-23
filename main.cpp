/********************************************
 * Name: Michael Solomon
 * File: Assignment 3 - Stacks
 * Class: COP4415.01
 * Date: 2/24/22
 * *******************************************/
/********************************************
* Sample Test Cases
* Example:
* Input: [A∗{B + (C + D)}]      Output: Balanced
* Input: [{()()}]               Output: Balanced
* Input: [A∗{B + (C + D})]      Output: Not Balanced
* Input: [{(])()}               Output: Not Balanced
* *******************************************/
// CPP program to check for balanced brackets.
#include <iostream>
using namespace std;
#define MAX 1000

class Stack {
public:
    int top;
    char exp[100];
    Stack() { top = -1; }
    bool push(int item);
    char pop();
    int isMatchingPair(char character1, char character2);
    int areParenthesisBalanced(char exp[]);
};

bool Stack::push(int item) { // push element out of stack
    if(top >= (MAX - 1 )){
        cout << "Stack Overflow";
        return false;
    }else{
        top++;
        exp[top]=item;
        return true;
    }
}

char Stack::pop() {  // pop element into stack
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }else {
        int x = exp[top];
        top--;
        return x;
    }
}

int Stack::isMatchingPair(char character1, char character2){ //checks if brackets are matching
    if (character1 == '(' && character2 == ')'){
        return 1;
    }else if (character1 == '{' && character2 == '}'){
        return 1;
    }else if (character1 == '[' && character2 == ']'){
        return 1;
    }else{
        return 0;
    }
}

int Stack::areParenthesisBalanced(char exp[]){ // function to check if brackets are balanced
    int i = 0;
     top = NULL;
    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(exp[i]);
        }
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (top == NULL) {
                return 0;
            } else if (!isMatchingPair(pop(), exp[i])) {
                return 0;
            }
        }i++;

    }
    if (top == NULL){
            return 1;
        }else{
            return 0;
        }
    }

int main() {
    class Stack s;
    char exp[100];
    cout << "enter the expression:\n";
    cin >> exp;
    if (s.areParenthesisBalanced(exp)){ //function call
    cout << "Balanced";
    } else {
    cout << "Not Balanced";
    }
    return 0;
}

