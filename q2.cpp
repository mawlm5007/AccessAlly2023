/*
Problem 2: Blood Distribution
Problem Description

At the Cardiac Center there are four types of blood available: O, A, B, and AB. Each of these types of blood has an Rh factor, which is either “positive” or “negative”. There are many patients who each require 1 unit of blood. Each patient’s blood type determines the type of blood s/he may receive:

Each Type O patient requires Type O blood.
Each Type A patient may receive blood of Type A or Type O.
Each Type B patient may receive blood of Type B or Type O.
The Type AB patients may receive blood of any type.
Patients who have Rh-negative blood can accept Rh-negative blood only, but patients with Rh-positive blood can accept either Rh-positive or Rh-negative types of blood.

We want as many patients as possible to receive a unit of blood. What is the maximum number of patients that can receive blood?

Input Specification

The first line of input contains 8 integers: the number of units of blood of Type O negative, O positive, A negative, A positive, B negative, B positive, AB negative and AB positive. This is followed by a line containing eight numbers: the number of patients whose blood type is O negative, O positive, A negative, A positive, B negative, B positive, and AB negative and AB positive. Each of these integers will be at least 0 and less than 107.

Output Specification

The output of your program should be a single number: the maximum number of patients that can receive blood.

Sample Input

5 5 3 1 2 11 5 12

2 4 9 2 3 9 7 3

Output for Sample Input

33

An Explanation

2 Type O- patients receive Type O- blood 9
4 Type O+ patients receive Type O+ blood
3 Type A- patients receive Type A- blood
3 Type A- patients receive Type 0- blood
1 Type A+ patients receive Type A+ blood
1 Type A+ patients receive Type O+ blood
2 Type B- patients receive Type B- blood
9 Type B+ patients receive Type B+ blood
5 Type AB- patient receives Type AB- blood
3 Type AB+ patients receive Type AB+ blood
*/


#include <iostream>
#include <sstream>
#include <map>

int Oneg(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 0; 
    int output = 0; 
    // Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}

int Opos(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 1; 
    int output = 0; 
    // Opos
    if (bloodRecord[1] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[1] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[1];
            output += bloodRecord[1];
            bloodRecord[1] = 0; 
        }
        else {
            bloodRecord[1] = bloodRecord[1] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    //Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}

int Aneg(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 2; 
    int output = 0; 
    // Aneg
    if (bloodRecord[2] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[2] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[2];
            output += bloodRecord[2];
            bloodRecord[2] = 0; 
        }
        else {
            bloodRecord[2] = bloodRecord[2] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    //Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}

int Apos(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 3; 
    int output = 0; 
    // Apos
    if (bloodRecord[3] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[3] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[3];
            output += bloodRecord[3];
            bloodRecord[3] = 0; 
        }
        else {
            bloodRecord[3] = bloodRecord[3] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Opos
    if (bloodRecord[1] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[1] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[1];
            output += bloodRecord[1];
            bloodRecord[1] = 0; 
        }
        else {
            bloodRecord[1] = bloodRecord[1] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Aneg
    if (bloodRecord[2] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[2] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[2];
            output += bloodRecord[2];
            bloodRecord[2] = 0; 
        }
        else {
            bloodRecord[2] = bloodRecord[2] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    //Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}

int Bneg(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 4; 
    int output = 0; 
    // Bneg
    if (bloodRecord[4] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[4] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[4];
            output += bloodRecord[4];
            bloodRecord[4] = 0; 
        }
        else {
            bloodRecord[4] = bloodRecord[4] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    //Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}

int Bpos(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 5; 
    int output = 0; 
    // Bpos
    if (bloodRecord[5] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[5] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[5];
            output += bloodRecord[5];
            bloodRecord[5] = 0; 
        }
        else {
            bloodRecord[5] = bloodRecord[5] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Opos
    if (bloodRecord[1] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[1] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[1];
            output += bloodRecord[1];
            bloodRecord[1] = 0; 
        }
        else {
            bloodRecord[1] = bloodRecord[1] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Bneg
    if (bloodRecord[4] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[4] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[4];
            output += bloodRecord[4];
            bloodRecord[4] = 0; 
        }
        else {
            bloodRecord[4] = bloodRecord[4] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    //Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}

int ABneg(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 6; 
    int output = 0; 
    // ABneg
    if (bloodRecord[6] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[6] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[6];
            output += bloodRecord[6];
            bloodRecord[6] = 0; 
        }
        else {
            bloodRecord[6] = bloodRecord[6] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Aneg
    if (bloodRecord[2] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[2] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[2];
            output += bloodRecord[2];
            bloodRecord[2] = 0; 
        }
        else {
            bloodRecord[2] = bloodRecord[2] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Bneg
    if (bloodRecord[4] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[4] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[4];
            output += bloodRecord[4];
            bloodRecord[4] = 0; 
        }
        else {
            bloodRecord[4] = bloodRecord[4] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    //Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}

int ABpos(std::map<int, int> &patientRecord, std::map<int, int> &bloodRecord) {
    int blood = 7; 
    int output = 0; 
    // ABpos
    if (bloodRecord[7] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[7] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[7];
            output += bloodRecord[7];
            bloodRecord[7] = 0; 
        }
        else {
            bloodRecord[7] = bloodRecord[7] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Apos
    if (bloodRecord[3] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[3] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[3];
            output += bloodRecord[3];
            bloodRecord[3] = 0; 
        }
        else {
            bloodRecord[3] = bloodRecord[3] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Bpos
    if (bloodRecord[5] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[5] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[5];
            output += bloodRecord[5];
            bloodRecord[5] = 0; 
        }
        else {
            bloodRecord[5] = bloodRecord[5] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Opos
    if (bloodRecord[1] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[1] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[1];
            output += bloodRecord[1];
            bloodRecord[1] = 0; 
        }
        else {
            bloodRecord[1] = bloodRecord[1] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // ABneg
    if (bloodRecord[6] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[6] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[6];
            output += bloodRecord[6];
            bloodRecord[6] = 0; 
        }
        else {
            bloodRecord[6] = bloodRecord[6] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Aneg
    if (bloodRecord[2] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[2] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[2];
            output += bloodRecord[2];
            bloodRecord[2] = 0; 
        }
        else {
            bloodRecord[2] = bloodRecord[2] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    // Bneg
    if (bloodRecord[4] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[4] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[4];
            output += bloodRecord[4];
            bloodRecord[4] = 0; 
        }
        else {
            bloodRecord[4] = bloodRecord[4] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    //Oneg
    if (bloodRecord[0] != 0 && patientRecord[blood] != 0) {
        if (bloodRecord[0] <= patientRecord[blood]) {
            patientRecord[blood] = patientRecord[blood] - bloodRecord[0];
            output += bloodRecord[0];
            bloodRecord[0] = 0; 
        }
        else {
            bloodRecord[0] = bloodRecord[0] - patientRecord[blood]; 
            output += patientRecord[blood]; 
            patientRecord[blood] = 0; 
        }
    }
    return output; 
}


int main() {
    std::string unitsBlood = ""; 
    std::getline(std::cin, unitsBlood); 
    std::istringstream unit(unitsBlood);

    int number = 0; 
    int output = 0; 

    //define map for units of blood and map for patients 
    std::map<int, int> patientRecord; 
    std::map<int, int> bloodRecord;
    // 0 - Opos, 1 - Oneg, 2 - Aneg, 3 - Apos, 4 - Bneg, etc 
    int patientIndex = 0; 
    int bloodIndex = 0; 

    while (unit >> number) {
        //std::cout << number << std::endl;
        bloodRecord[bloodIndex] = number; 
        bloodIndex++;
    }

    std::string patients = ""; 
    std::getline(std::cin, patients); 
    std::istringstream need(patients); 

    while (need >> number) {
        //std::cout << number << std::endl;
        patientRecord[patientIndex] = number; 
        patientIndex++;
    }

    // Iterate over the map
    /*
    for (std::map<int, int>::iterator it = bloodRecord.begin(); it != bloodRecord.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
    for (std::map<int, int>::iterator it = patientRecord.begin(); it != patientRecord.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }*/

    // checking Oneg 
    //std::cout << Oneg(patientRecord, bloodRecord) << std::endl;

    output += Oneg(patientRecord, bloodRecord); 

    // checking Opos
    //std::cout << Opos(patientRecord, bloodRecord) << std::endl;

    output += Opos(patientRecord, bloodRecord); 

    // checking Aneg 
    //std::cout << Aneg(patientRecord, bloodRecord) << std::endl;

    output += Aneg(patientRecord, bloodRecord); 

    // checking Apos 
    //std::cout << Apos(patientRecord, bloodRecord) << std::endl;

    output += Apos(patientRecord, bloodRecord); 

    // checking Bneg 
    //std::cout << Bneg(patientRecord, bloodRecord) << std::endl;

    output += Bneg(patientRecord, bloodRecord); 

    // checking Bpos 
    //std::cout << Bpos(patientRecord, bloodRecord) << std::endl;

    output += Bpos(patientRecord, bloodRecord); 

    // checking ABneg
    //std::cout << ABneg(patientRecord, bloodRecord) << std::endl;

    output += ABneg(patientRecord, bloodRecord); 

    // checking ABpos
    //std::cout << ABpos(patientRecord, bloodRecord) << std::endl;

    output += ABpos(patientRecord, bloodRecord); 

    std::cout << output << std::endl;

    return 0; 
}