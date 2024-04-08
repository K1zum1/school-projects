#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;


const int HASH_SIZE = 1051;
const string INFILE = "nflix.csv";
const int NFIELDS = 6;
const char DELIMITER = ',';


struct netflixEntry {
    string type;
    string title;
    string director;
    string country;
    int year;
    string duration;
    netflixEntry *next; // this will be the pointer to the next entry in the list
};


netflixEntry *entryHash[HASH_SIZE] = { 0 };

// function to generate a hash key, given a string
    unsigned int getHashIndex(string hashInput) {
        unsigned int sum = 0; // have to use an unsigned int here because array indices must be not negative
        for (char c : hashInput) { // we can loop through the string and add the ascii values of each character
            sum += c; // add the ascii value of the character to the sum
        }
        return (sum % HASH_SIZE); // return the sum mod the hash size to get the index
        // important to note that this hash function i made is not really efficient 
    }


netflixEntry *readSingleEntry(const string &lineFromFile) {
    istringstream istr(lineFromFile);
    string fields[NFIELDS];
    string tmp, dstr;
    netflixEntry *np = nullptr;
    int i = 0;

    while (getline(istr, tmp, DELIMITER) && i < NFIELDS) {
        fields[i++] = tmp;
    }
    if (i < NFIELDS) {
        return 0;
    }

    np = new netflixEntry;
    np->type = fields[0];
    np->title = fields[1];
    np->director = fields[2];
    np->country = fields[3];
    np->year = atoi(fields[4].c_str());
    dstr = fields[5];

    if (dstr.size() != 0 && dstr[dstr.size() - 1] == '\r')
        dstr.erase(dstr.size() - 1);
    np->duration = dstr;

    return np;   

    
}

// function to be completed
void entryInsert(netflixEntry *newEnt, unsigned int hashIndex) {
    if (entryHash[hashIndex] == nullptr) { // first we can check if the hash index is empty
        entryHash[hashIndex] = newEnt; // if it is then place the new entry in
    } else {
        newEnt->next = entryHash[hashIndex]; // if its not empty then we can set the next pointer to the first entry
        entryHash[hashIndex] = newEnt; // then place the new entry inside which makes it the first index
    }
}

// function to be completed
netflixEntry *entryFind(const string &title, unsigned int hashIndex, int &ncmp) {
    // Start with the first entry in the bucket at the hash index
    netflixEntry *current = entryHash[hashIndex]; // Initialize current to the head of the list at hashIndex
    while (current != nullptr) { // then loop through the linked list until we find the title or reach the end
        ncmp++; // increment the comparison count
        if (current->title == title) { // check if the title entry matches the title we are looking for
            return current; // return if it is a successful match
        }
        current = current->next; // move to the next entry in the list
    }
    return nullptr; // if we reach here, the title was not found in the hash table
}

// Main function
// Main function
int main() {
    ifstream inFile(INFILE);
    string inputLine, inputStr;
    netflixEntry *np = nullptr;
    int linesRead = 0;

    if (!inFile.good()) {
        cerr << "Cannot open the input file!" << endl;
        return -1;
    }

    while (getline(inFile, inputLine)) {
        linesRead++;
        np = readSingleEntry(inputLine);
        if (!np) continue;
        entryInsert(np, getHashIndex(np->title));
    }

    if (linesRead == 0) {
        cerr << "Nothing was read from the file!" << endl;
        return -1;
    } else {
        cout << "Read " << linesRead << " entries.\n"; // Added line break here
        if (np) {
            cout << "Last entry added: " << np->title << " (" << np->director << ", " << np->year << ")\n\n"; 
        }
    }

    // Input loop
    while (true) {
        cout << "Enter a movie: "; 
        getline(cin, inputStr);
        if (inputStr.empty()) {
            break;
        }
        // call the hashindex function 
        unsigned int hashIndex = getHashIndex(inputStr);
        int ncmp = 0;
        // call the entryFind function
        netflixEntry *foundEntry = entryFind(inputStr, hashIndex, ncmp);

        if (foundEntry) { // if the entry is found then print out the information in the given format 
            cout << "Entry found after " << ncmp << " comparisons:" << endl;
            cout << "Type: " << foundEntry->type << endl;
            cout << "Movie: " << foundEntry->title << endl;
            cout << "Director: " << foundEntry->director << endl;
            cout << "Country: " << foundEntry->country << endl;
            cout << "Year: " << foundEntry->year << endl;
            cout << "Duration: " << foundEntry->duration << endl;
            cout << "\n";
        } else {
            cout << "Entry not found after " << ncmp << " comparisons." << endl;
        }
    }

    cout << "Exiting...\n"; 

    return 0;
}

