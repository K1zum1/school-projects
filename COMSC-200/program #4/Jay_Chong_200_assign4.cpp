#include "Jay_Chong_HeartRates.h"
#include <iostream>
using namespace std;

void printHeartRateInfo(const HeartRates& heartRates);

// comment #4: this is the main function, it prompts the user for their information and then prints their heart rate information
int main() {
    string firstName, lastName;
    int birthMonth, birthDay, birthYear;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your birth month: ";
    cin >> birthMonth;
    cout << "Enter your birth day: ";
    cin >> birthDay;
    cout << "Enter your birth year: ";
    cin >> birthYear;

    HeartRates userHeartRates(firstName, lastName, birthMonth, birthDay, birthYear);
    printHeartRateInfo(userHeartRates);
    cin.get();
    return 0;
}

// comment #5 this function prints the heart rate nformation for a HeartRates object, it uses the member functions of the HeartRtes class to get the information
void printHeartRateInfo(const HeartRates& heartRates) {
    cout << "\nInformation for " << heartRates.getFirstName() << " " << heartRates.getLastName() << ":\n";
    cout << "Date of Birth: " << heartRates.getBirthMonth() << "/" << heartRates.getBirthDay() << "/" << heartRates.getBirthYear() << "\n";
    cout << "Age: " << heartRates.getAge() << " years\n";
    cout << "Maximum Heart Rate: " << heartRates.getMaximumHeartRate() << " bpm\n";
    // comment #13 this line uses the getTargetHeartRate function to get the target heart rate and then prints it
    auto [targetLow, targetHigh] = heartRates.getTargetHeartRate();
    cout << "Target Heart Rate: " << targetLow << " - " << targetHigh << " bpm\n";
}
