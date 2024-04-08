#include <iostream>
#include <ctime>
using namespace std;

int main() {
    // declare the array and the variables
    int list[10] = {};
    int even = 0;
    int odd = 0;

    // had to look up how to seed the random number generator
    srand(time(0));
    for (int i = 0; i < 10; i++) {
            list[i] = rand() % 100 + 1;
    };

    //simple for loop to count even and odd numbers, if even, add to even, if odd, add to odd
    for (int i = 0; i < 10; i++) {
        if (list[i] % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    };

    cout << "Array contents: ";
    // simple for loop to print out the array contents
    for (int i = 0; i < 10; i++) {
        cout << list[i] << " ";
    };

    cout << endl;
    // print out the final result
    cout << "This array has a total of " << even << " even numbers and " << odd << " odd numbers." << endl;

}