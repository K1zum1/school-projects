// Created by Jay Chong on 9/3/2023
// COMSC-210 by Professor Amato
// Program #1 - Recursive Syracuse Sequence

// include c++ libraries
#include <iostream>

#include <iomanip>

using namespace std;

// this is our function which takes in four parameters of n, countdown, highest, and abort which we pass by reference
int syracuse(int n, int countdown, int highest, bool& abort) {
  // base case: if n is 1, countdown is 0 or 1, return n because there is no syracuse calculation to be done
  if (n == 1 || countdown == 1 || countdown == 0 ) {
    cout << n << endl;
    // return the highest number between "highest" and n
    abort = true;
    return max(highest, n);
    return abort;
    
    // first base case: if n is even, divide by 2
  } else if (n % 2 == 0) {
    cout << n << endl;
    // return the function recursively by dividing n by 2, subtracting 1 from countdown, and finding the highest number between "highest" and n
    return syracuse(n / 2, countdown - 1, max(highest, n), abort);
    // second base case: if n is odd, multiply by 3 and add 1, then divide by 2
  } else if (n % 2 != 0) {
    cout << n << endl;
    // same here as line 17, return the function revursively by multiplying n by 3 and adding 1, dividing by 2, subtracting 1 from countdown, and finding the highest number between "highest" and n
    return syracuse((3 * n + 1) / 2, countdown - 1, max(highest, n), abort);
  } 
}

int main() {
  // declare variables
  int start_n;
  int lim;
  bool abort = false;
  int highest = 0;
  bool start_invalid = true;
  bool lim_invalid = true;

  // get user input for starting number while validing input
  while (start_invalid) {
    cout << "Enter a starting number: ";
    cin >> start_n;
    if (start_n > 0) {
      start_invalid = false;
    } else {
      cout << "Invalid input. Please enter a positive integer." << endl;
    }
  }
  // get user input for limit while validating input
  while (lim_invalid) {
    cout << "Enter a limit: ";
    cin >> lim;
    if (lim > 0) {
      lim_invalid = false;
    } else {
      cout << "Invalid input. Please enter a positive integer." << endl;
    }
  }

  // call the function and store the result in result
  int result = syracuse(start_n, lim, highest, abort);

  // print the highest number reached if the sequence was not aborted early
  if (abort) {
    cout << "Sequence was aborted early." << endl;
    cout << "Highest number reached " << result << "." << endl;
  } else {
    cout << "Highest number reached " << result << "." << endl;
  }
  

  return 0;
}