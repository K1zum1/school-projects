// Created by Jay Chong on 9/11/2023
// COMSC-210 by Professor Amato
// Program #3 - Queueing Simulation


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PARAMS_MAX = 5;
// given function
bool customerArrived(double prob) {
  double rv = rand() / (double(RAND_MAX) + 1);
  return (rv < prob);
}

void runSimulation(int simTime, double arrivalRate,
  int serviceTime, int maxLine,
  int & nServed, int & totalWait,
  int & totalLength, int & totalDropped) {
  queue < int > customerQueue;
  int curCustomerTime = 0;
  int curLineLength = 0; // track the current line length

  // Main simulation loop
  for (int curTime = 0; curTime < simTime; curTime++) {
    // first we can add the current line length to the total length
    totalLength += curLineLength;

    // see if the customer arrived by calling customerArrived with the arrival rate probability
    if (customerArrived(arrivalRate)) {
      // we need to check if the line is full
      if (curLineLength < maxLine) {
        // if it is not full, we can add the current customer to the queue and increment the line length
        customerQueue.push(curTime);
        curLineLength++;
      } else {
        // otherwise increment the dropped counter because the customer will leave if its full
        totalDropped++;
      }
    }

    // check if a customer is being serviced
    if (curCustomerTime > 0) {
      // if they are being serviced, decrement the time left for them to be serviced
      curCustomerTime--;
    }

    // if they are not being serviced and the line is not empty, we can get the next customer
    if (curCustomerTime == 0 && !customerQueue.empty()) {
      // calculate the wait time for the customer
      int waitTime = curTime - customerQueue.front();
      totalWait += waitTime;

      // remove the customer from the queue and set the current customer time to the service time
      customerQueue.pop();
      curCustomerTime = serviceTime;
      curLineLength--;
      nServed++;
    }
  }
}
// given function
bool readNextSimulation(ifstream & f, string & name, int & simulationTime,
  double & arrivalRate, int & serviceTime, int & lineSize) {
  string buf;
  string fileValues[5];
  int i = 0;
  while (getline(f, buf)) {
    if (f.eof()) {
      break;
    }
    fileValues[i++] = buf;
    if (i == PARAMS_MAX) {
      name = fileValues[0];
      if (!name.empty() && name.back() == '\r') {
        name.pop_back();
      }
      simulationTime = atoi(fileValues[1].c_str());
      arrivalRate = atof(fileValues[2].c_str());
      serviceTime = atoi(fileValues[3].c_str());
      lineSize = atoi(fileValues[4].c_str());
      return true;
    }
  }
  return false;
}
// given function
void printReport(string name, int simTime, double arrivalRate,
  int serviceTime, int maxLine, int nServed, int totalWait,
  int totalLength, int totalDropped) {
  cout << left;
  cout << endl;
  cout << setw(25) << "Simulation name: " << setw(12) << name << endl;
  cout << "--------------------------------------" << endl;
  cout << setw(25) << "Simulation time: " << setw(12) << simTime << endl;
  cout << setw(25) << "Arrival rate: " << setw(12) << arrivalRate << endl;
  cout << setw(25) << "Service time: " << setw(12) << serviceTime << endl;
  cout << setw(25) << "Max line size: " << setw(12) << maxLine << endl;
  cout << endl;
  cout << setw(25) << "Customers served:" << setw(12) << nServed << endl;
  cout << setw(25) << "Average wait time:" << double(totalWait) / nServed <<
    endl;
  cout << setw(25) << "Average line length:" << setw(12) <<
    double(totalLength) / simTime << endl;
  cout << setw(25) << "Total dropped customers:" << setw(12) <<
    totalDropped << endl;
}
// given function
int main() {
  int nServed;
  int totalWait = 0;
  int totalLength = 0;
  int totalDropped = 0;
  string name;
  int simTime;
  double arrivalRate;
  int serviceTime;
  int maxLine;
  string buf;
  ifstream f("simtest.txt");
  srand(int(time(NULL)));

  if (!f.good()) {
    cerr << "Invalid file, exiting." << endl;
    return -1;
  }

  while (readNextSimulation(f, name, simTime, arrivalRate, serviceTime, maxLine)) {
    runSimulation(simTime, arrivalRate, serviceTime, maxLine,
      nServed, totalWait, totalLength, totalDropped);
    printReport(name, simTime, arrivalRate,
      serviceTime, maxLine, nServed, totalWait, totalLength,
      totalDropped);
  }
  return 0;
}