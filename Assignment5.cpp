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

/*
SAMPLE OUTPUT
[kmitch79@hills ~]$ ./a.out 
Enter team #1: Padres
Enter the wins for team #1: 75
Enter team #2: Dogers
Enter the wins for team #2: 91
Enter team #3: Giants
Enter the wins for team #3: 92
Enter team #4: Rockies
Enter the wins for team #4: 65
Enter team #5: Diamondbacks
Enter the wins for team #5: 70

League Standings:
Giants: 92
Dogers: 91
Padres: 75
Diamondbacks: 70
Rockies: 65
[kmitch79@hills ~]$ ./a.out 
Enter team #1: Team 1
Enter the wins for team #1: 40
Enter team #2: Team 2
Enter the wins for team #2: 55
Enter team #3: Team 3
Enter the wins for team #3: 85
Enter team #4: Team 4
Enter the wins for team #4: 55
Enter team #5: Team 5
Enter the wins for team #5: 100

League Standings:
Team 5: 100
Team 3: 85
Team 2: 55
Team 4: 55
Team 1: 40
*/