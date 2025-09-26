/*
 Write a program that records and displays league standings for a baseball league. The program will ask the user to enter five team names, and five win amounts. It will store the data in memory, and print it back out sorted by wins from highest to lowest.

 The sample output from your program should look something like this (user input in bold orange):

 Enter team #1: Padres
 Enter the wins for team #1: 75
 Enter team #2: Dodgers
 Enter the wins for team #2: 91
 Enter team #3: Giants
 Enter the wins for team #3: 92
 Enter team #4: Rockies
 Enter the wins for team #4: 65
 Enter team #5: Diamondbacks
 Enter the wins for team #5: 70

 League Standings:
 Giants: 92
 Dodgers: 91
 Padres: 75
 Diamondbacks: 70
 Rockies: 65
 Requirements
 The data must be stored in two parallel arrays: an array of strings named teams, and an array of ints named wins.  These arrays must be declared in the main() function.  You can assume that the league has five teams, so each of the arrays should have five elements.

 As usual, you may not use any global arrays or global variables.

 All of the user input must be done in a function named initializeArrays.  It must have the following signature:

 void initializeArrays(string names[], int wins[], int size)
 You must also write two more functions: one to sort both arrays, and one to display the final (sorted) list of team names and scores. They must have the following signatures:

 void sortData(string names[], int wins[], int size)
 void displayData(string names[], int wins[], int size)
 The main function should be very short. It should just declare the arrays and then call these three functions.
 */

//
//  main.cpp
//  Assignment 5 - The League
//
//  Created by Kristian Mitchell on 9/25/25.
//

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void initializeArrays(string [], int [], int );
void sortData(string [], int [], int );
void displayData(string [], int [], int );

const int SIZE = 5;

int main()
{
    string names[SIZE];                 // Array of the team names
    int wins[SIZE];                     // Array of the team scores
    
    initializeArrays(names, wins, SIZE);
    sortData(names, wins, SIZE);
    displayData(names, wins, SIZE);
   
    
    return 0;
}

void initializeArrays(string names[], int wins[], int size)
{
    cin.ignore();
    for (int i = 0; i < size; i++)
    {
        cout << "Enter team #" << i + 1 << ": ";
        getline(cin, names[i]);
        
        cout << "Enter the wins for team #" << i + 1 << ": ";
        while (!(cin >> wins[i]) || wins[i] < 0) {
            cout << "Invalid input. Please enter a non-negative number: ";
            cin.clear();
            cin.ignore();
        }
        cin.ignore();
    }
    cout << endl;
}

void sortData(string names[], int wins[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            // Sort the wins, if the wins are the same, then list the team names alphabetically
            if (wins[j] > wins[i] || (wins[j] == wins[i] && names[j] < names[i]))
            {
                // Swap the values
                int tempInt = wins[i];
                string tempString = names[i];
                
                wins[i] = wins[j];
                names[i] = names[j];
                
                wins[j] = tempInt;
                names[j] = tempString;
            }
        }
    }
}

void displayData(string names[], int wins[], int size)
{
    cout << "League Standings:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << names[i] << ": " << wins[i] << endl;
    }
    
}
