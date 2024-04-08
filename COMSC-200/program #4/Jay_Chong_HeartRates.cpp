 #include "Jay_Chong_HeartRates.h"
#include <iostream>
#include <ctime>
using namespace std;

// comment #14 this is the constructor for the HeartRtes class, it initializes the member variables for the object with the values passed in as arguments
HeartRates::HeartRates(string firstName, string lastName, int birthMonth, int birthDay, int birthYear)
    : firstName(firstName), lastName(lastName), birthMonth(birthMonth), birthDay(birthDay), birthYear(birthYear) {}

// comment #6: these are the member functions of the HeartRates class
string HeartRates::getFirstName() const { return firstName; }
string HeartRates::getLastName() const { return lastName; }
int HeartRates::getBirthMonth() const { return birthMonth; }
int HeartRates::getBirthDay() const { return birthDay; }
int HeartRates::getBirthYear() const { return birthYear; }
void HeartRates::setFirstName(string firstName) { this->firstName = firstName; }
void HeartRates::setLastName(string lastName) { this->lastName = lastName; }
void HeartRates::setBirthMonth(int birthMonth) { this->birthMonth = birthMonth; }
void HeartRates::setBirthDay(int birthDay) { this->birthDay = birthDay; }
void HeartRates::setBirthYear(int birthYear) { this->birthYear = birthYear; }

// comment #7: this function calculates the age of the person based on the current date and the bith date, it uses the ctime library to get the current date and time instead of prompting the user for it
int HeartRates::getAge() const {
    time_t theTime = time(NULL);
    // comment #14: the localtime function converts the time_t value to a tm struct, which has members for the year, month, and day
    tm *aTime = localtime(&theTime);

    // comment #8: the tm struct has a member for the current year, month, and day, so we can use those to calculate the age
    int currentYear = aTime->tm_year + 1900; 
    int currentMonth = aTime->tm_mon + 1; 
    int currentDay = aTime->tm_mday;

    // comment #9: this is the clculation for the age, it subtacts the birth year from the current year, and then checks if the birth month and day have passed this year
    int age = currentYear - birthYear;
    if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay)) {
        // if the birth month and day have not passed this year, then the age is one less
        age--;
    }
    return age;
}
// comment #10: this function calculates the maximum heart rate based on the age of the person
int HeartRates::getMaximumHeartRate() const {
    return 220 - getAge();
}

// comment #11: this function calculates the target heart rate based on the maximum heart rate
pair<int, int> HeartRates::getTargetHeartRate() const {
    int maxHR = getMaximumHeartRate();
    // comment #12: the target heart rate is 50-85% of the maximum heart rate as stated in the assingment
    return {static_cast<int>(maxHR * 0.50), static_cast<int>(maxHR * 0.85)};
}
