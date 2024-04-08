// Jay_Chong_IntegerSet.h
#ifndef JAY_CHONG_INTEGERSET_H
#define JAY_CHONG_INTEGERSET_H

#include <vector>

class IntegerSet {
public:
    // Default constructor
    IntegerSet();
    
    // Constructor that initializes a set with an array of integers
    IntegerSet(const int arr[], int size);
    
    // Inserts a new element into the set
    void insertElement(int element);
    
    // Deletes an element from the set
    void deleteElement(int element);
    
    // Prints the elements of the set
    void printSet() const;
    
    // Determines if two sets are equal
    bool isEqualTo(const IntegerSet& other) const;
    
    // Fills the set by prompting the user for input
    void inputSet();

    // Creates a set that is the union of two existing sets
    static IntegerSet unionOfSets(const IntegerSet& set1, const IntegerSet& set2);
    
    // Creates a set that is the intersection of two existing sets
    static IntegerSet intersectionOfSets(const IntegerSet& set1, const IntegerSet& set2);

private:
    std::vector<bool> set; 
};

#endif 
