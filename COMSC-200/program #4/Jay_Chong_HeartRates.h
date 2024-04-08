#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <string>
#include <utility>
using namespace std;

// comment #1: these are the private member variables of th HeartRates class
class HeartRates {
private:
    string firstName;
    string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

// comment #2: these are the public member functions of the HeartRates class
public:
    HeartRates(string firstName, string lastName, int birthMonth, int birthDay, int birthYear);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setBirthMonth(int birthMonth);
    void setBirthDay(int birthDay);
    void setBirthYear(int birthYear);
    string getFirstName() const;
    string getLastName() const;
    int getBirthMonth() const;
    int getBirthDay() const;
    int getBirthYear() const;
    int getAge() const;
    int getMaximumHeartRate() const;
    // comment #3: this function returns a pair of integers, which is a way to return two values from a function
    pair<int, int> getTargetHeartRate() const;
};

#endif 
