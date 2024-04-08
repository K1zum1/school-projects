// Jay_Chong_IntegerSet.cpp
#include "Jay_Chong_IntegerSet.h"
#include <iostream>

// Implement the default constructor
IntegerSet::IntegerSet() : set(101, false) {}

// Implement the constructor that initializes a set with an array of integers
IntegerSet::IntegerSet(const int arr[], int size) : IntegerSet() {
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0 && arr[i] <= 100) {
            set[arr[i]] = true;
        }
    }
}

// Implement the insertElement function
void IntegerSet::insertElement(int element) {
    if (element >= 0 && element <= 100) {
        set[element] = true;
    }
}

// Implement the deleteElement function
void IntegerSet::deleteElement(int element) {
    if (element >= 0 && element <= 100) {
        set[element] = false;
    }
}

// Implement the printSet function
void IntegerSet::printSet() const {
    bool isEmpty = true;
    for (size_t i = 0; i < set.size(); ++i) {
        if (set[i]) {
            std::cout << i << ' ';
            isEmpty = false;
        }
    }
    if (isEmpty) {
        std::cout << "--";
    }
    std::cout << std::endl;
}

// Implement the isEqualTo function
bool IntegerSet::isEqualTo(const IntegerSet& other) const {
    return set == other.set;
}

// Implement the inputSet function
void IntegerSet::inputSet() {
    int num;
    std::cout << "Enter elements (-1 to end): ";
    while (std::cin >> num && num != -1) {
        if (num >= 0 && num <= 100) {
            set[num] = true;
        }
    }
}

// Implement the static function unionOfSets
IntegerSet IntegerSet::unionOfSets(const IntegerSet& set1, const IntegerSet& set2) {
    IntegerSet unionSet;
    for (size_t i = 0; i < unionSet.set.size(); ++i) {
        unionSet.set[i] = set1.set[i] || set2.set[i];
    }
    return unionSet;
}

// Implement the static function intersectionOfSets
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& set1, const IntegerSet& set2) {
    IntegerSet intersectionSet;
    for (size_t i = 0; i < intersectionSet.set.size(); ++i) {
        intersectionSet.set[i] = set1.set[i] && set2.set[i];
    }
    return intersectionSet;
}
