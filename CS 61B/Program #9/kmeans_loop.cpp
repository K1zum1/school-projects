#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// COMSC 210
// k-Means Algorithm Starter File

// ---------
// Constants
// ---------

const int NUM_CENTROIDS = 3;        // The value 'k' number of clusters/centroids
const int NUM_ITERATIONS = 10;       // Number of iterations to run
const int NUM_PEOPLE = 10;          // Number of people data points below

// -------------
// Individual Data
// -------------
struct Individual {
    double height;          // Height of this person in inches
    double weight;          // Weight in pounds
};

Individual allPeople[NUM_PEOPLE] = {
     { 63, 144 },
     { 73, 180 },
     { 62, 133 },
     { 70, 175 },
     { 72, 200 },
     { 73, 205 },
     { 74, 208 },
     { 64, 148 },
     { 61, 129 },
     { 71, 178 },
};

// This function computes the Euclidean Distance between
// two Individual points.
double distance(Individual a, Individual b) {
    double d1 = pow(a.height - b.height, 2);
    double d2 = pow(a.weight - b.weight, 2);

    return sqrt(d1 + d2);
}

// This function performs 1 iteration of the kmeans algorithm.
// Upon completion, the 'centroids' array is updated with the current
// centroid values.
//
// Parameters:
// pData - Array of Individual data points
// np - Number of elements in 'pData'
// centroids - Array of centroid values 
// int ncent - Number of elements in 'centroids'
void kmeans(Individual pData[], int np, Individual centroids[], int ncent) {
    double d = 0, mind = -1;       // Temporary variables
    double s1 = 0, s2 = 0;
    int midx = 0;
    vector<Individual> clusters[ncent];  // The set of people for each centroid

    // For each person, calculate which centroid is nearest to it
    for (int i = 0; i < np; i++) {

        // For each centroid, find our distance.  Select the min. distance.
        mind = -1;
        for (int c = 0; c < ncent; c++) {
            d = distance(pData[i], centroids[c]);
            if (mind == -1 || d < mind) {
                midx = c;
                mind = d;
            }
        }

        // Add this person to the cluster associated with
        // the closest centroid.
        clusters[midx].push_back(pData[i]);
    }

    // For each cluster, update the centroid value (for each of
    // height and weight, find the average values).
    for (int c = 0; c < ncent; c++) {
        s1 = s2 = 0;
        // Reset any empty centroids/clusters
        if (clusters[c].size() == 0) {
            centroids[c] = { 0, 0 };
            continue;
        }

        // Find the average
        for (int i = 0; i < clusters[c].size(); i++) {
            s1 += clusters[c][i].height;
            s2 += clusters[c][i].weight;
        }
        centroids[c].height = s1 / clusters[c].size();
        centroids[c].weight = s2 / clusters[c].size();
    }    
}

int main() {
    Individual centroids[NUM_CENTROIDS];

    // Seed RNG
    srand(time(0));
    cout << fixed << setprecision(2);

    // Initialize the centroids from random points in the data set
     for (int c = 0; c < NUM_CENTROIDS; c++) {
        int r = rand() % NUM_PEOPLE;
        centroids[c] = allPeople[r];
    }
    // Run the k-means algorithm in a loop
    kmeans(allPeople, NUM_PEOPLE, centroids, NUM_CENTROIDS);
    // Print the centroid values
    for (int c = 0; c < NUM_CENTROIDS; c++) {
        cout << "\t"
             << "#" << c + 1 << ": "
             << "Height: "
             << centroids[c].height << " Weight: " << centroids[c].weight << endl;
    }
    return 0;
}
