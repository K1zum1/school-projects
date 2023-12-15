// Created by Jay Chong on 9/11/2023
// COMSC-210 by Professor Amato
// Program #2 - Stack or No Stack?

#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

#define INPUT_FILE "test.txt"

int main() {
    ifstream f(INPUT_FILE); 
    string tmp;

    if (!f.good()) {
        cout << "Error opening file " << endl;
        exit(-1);
    }

    while (true) {
        getline(f, tmp); 
        if (f.eof()) 
            return 0;
        
        int nl = atoi(tmp.c_str()); 
        stack<string> wordStack; // create a stack to simulate the operations 
        bool failed = false; // initialize a boolean data type to track if the test case failed

        while (nl--) { 
            getline(f, tmp); 
            char op = tmp[0]; 
            string word = tmp.substr(2); 

            if (op == 'i') { // if the operation pulled is an "i" then push the word onto the stack
                wordStack.push(word); // using the member function push 
            } else if (op == 'r') { // if the operation pulled is an "r" then pop the word off the stack
                if (wordStack.empty() || wordStack.top() != word) { // check if the stack is empty or the retrieved value doesn't match the word 
                    while (nl--) {
                        getline(f, tmp); //  advance to any remaining lines for this test case
                    }
                    failed = true; // set the failed flag
                    break; // exit the loop
                }
                wordStack.pop(); // pop the string from the stack using the LIFO principle
            }
        }

        if (!failed && wordStack.empty()) { // if the test case didn't fail and the stack is empty
            cout << "stack" << endl; 
        } else { // if the test case didn't fail but the stack is not empty
            cout << "not stack" << endl; 
        }
    }

    return 0;
}
