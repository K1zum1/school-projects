#include <iostream>

#include <fstream>

#include <cstring>

#include <map>

using namespace std;

int main() {
  string treeID, treeAddr;
  string tmp;
  map < string, string > idmap;
  map < string, string > addrmap;
  ifstream inFile("trees.csv");

  if (!inFile.good()) {
    cerr << "Error opening file: " << strerror(errno) << endl;
    return -1;
  }

  // Read the file and fill the maps
  while (getline(inFile, tmp, ',')) {
    treeID = tmp;
    getline(inFile, treeAddr);
    // we use the treeID as the key and the treeAddr as the value
    idmap[treeID] = treeAddr;
    // we use the treeAddr as the key and the treeID as the value
    addrmap[treeAddr] = treeID;
  }

  while (true) {
    // preset menu design from assignment
    int choice;
    cout << "Menu:" << endl;
    cout << "1. Find tree address by ID." << endl;
    cout << "2. Find tree ID by address." << endl;
    cout << "3. Exit." << endl;
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore();

    // we first check the choice and then do the appropriate action
    if (choice == 1) {
      // since choice 1 was chosen we ask for the tree ID
      cout << "Enter the tree ID: ";
      // we use getline to get the entire line
      getline(cin, treeID);
      // we check if the tree ID is in the map by using the find function which was wanted in the assignment because 
      // we want to lookup the key instead of going through all the elements in the map
      if (idmap.find(treeID) != idmap.end()) {
        cout << "The address of this tree is: " << idmap[treeID] << endl;
      } else {
        cout << "Invalid entry, not found." << endl;
      }
      // we do the same thing as choice 1 but with the address instead
    } else if (choice == 2) {
      cout << "Enter the address: ";
      // we use getline to get the entire line and set it to treeAddr
      getline(cin, treeAddr);
      // we check if the address is in the map
      if (addrmap.find(treeAddr) != addrmap.end()) {
        cout << "The ID of this tree is: " << addrmap[treeAddr] << endl;
      } else {
        cout << "Invalid entry, not found." << endl;
      }
      // if choice 3 then exit the program by breaking out of the while loop
    } else if (choice == 3) {
      cout << "Exiting..." << endl;
      break;
    } else {
      cout << "Invalid choice." << endl;
    }
  }

  return 0;
}