#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <queue> // added this for the queue data structure
#include <cstdlib>


#define IS_QUIT(s) (s == "X" || s == "x")
#define FILENAME "facebook.csv"
using namespace std;

struct Person {
    vector<string> friends;
};

void parse_line(const string &str, vector<string> &line) {
    istringstream istr(str);
    string tmp;
    while (getline(istr, tmp, ',')) {
        line.push_back(tmp);
    }
}

// this is my BFS implementation using iteration because I couldn't figure out how to do it recursively
// the purpose of this function is to check if there is a path between two
bool BFSPath(map<string, Person> &everyone, const string &start, const string &end) {
    // using a queue for BFS
    queue<string> q;
    // map to mark visited nodes
    map<string, bool> visited;
    // initialize all nodes to not visited
    q.push(start);
    // mark start as visited
    visited[start] = true;

    // while the queue is not empty
    while (!q.empty()) {
        // get the front of the queue
        string current = q.front();
        // pop the front of the queue
        q.pop();
        // if the current node is the end node, return true
        if (current == end) {
            return true; // this means path between two people has been found
        }

        // iterate through all the friends of the current node
        for (const string &friendName : everyone[current].friends) {
            // if the friend has not been visited, mark it as visited and push it to the queue
            if (!visited[friendName]) {
                // mark friend as visited
                visited[friendName] = true;
                // push friend to queue
                q.push(friendName);
            }
        }
    }

    return false; // no path found
}

int main() {
    ifstream inFile(FILENAME);
    vector<string> row;
    vector<string> names;
    map<string, Person> everyone;
    string inputLine;

    // Verify that the file open was OK
    if (!inFile.good()) {
        cerr << "Invalid file." << endl;
        return (-1);
    }

    // Read the header line of the file (first line, contains column labels).
    // We save this line (names) so we can look up the string names in the
    // below loop.
    getline(inFile, inputLine);
    parse_line(inputLine, names);

    // Read each subsequent entry
    while (getline(inFile, inputLine)) {
        if (inFile.eof())
            break;
        vector<string> row;
        Person p;
        parse_line(inputLine, row);
        // Start at 1 (0th field is the string name)
        for (size_t i = 1; i < row.size(); i++) {
            int adj_status = atoi(row[i].c_str());
            // A '1' indicates an adjacency, so skip if we get a '0'
            // If there is an adjacency to this person, push the string name
            // of that person on the adjacency list.
            if (adj_status == 1)
                p.friends.push_back(names[i]);
        }
        // Add this (new) person to the map.
        // In this map, the key is the string name of the person, and
        // the value is their Person structure (adjacency list).
        everyone.insert(make_pair(row[0], p));
    }

    for (;;) {
        cout << endl << "Enter the starting name (X to quit): ";
        getline(cin, inputLine);
        if (IS_QUIT(inputLine))
            break;

        string startName = inputLine;

        cout << "Enter the ending name (X to quit): ";
        getline(cin, inputLine);
        if (IS_QUIT(inputLine))
            break;

        string endName = inputLine;

        // this checsk for a path between the two people using BFS
        bool pathExists = BFSPath(everyone, startName, endName);

        // Output all their friends
        if (pathExists) {
            cout << "There IS a path between these two people." << endl;
        } else {
            cout << "There is NOT a path between these two people." << endl;
        }
    }

    cout << "Exiting..." << endl;
    return 0;
}
