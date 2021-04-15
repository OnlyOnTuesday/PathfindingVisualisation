#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Windows.h"

using namespace std;

int main(){

    int selection = 0;
    char cont;

    cout << "\nWelcome to Pathfinding Visualisation" << endl;
    cout << "Produced by: Team C++ 1\n" << endl;
    cout << "You can use this program to select an alogirthm to solve mazes.\n";

    do {
        cout << "Enter a number 1-5 to select an algorithm:" <<endl
             << "1: Basic Solve" << endl
             << "2: Prim Algorithm" << endl
             << "3: Djikstra" << endl
             << "4: Compare time between algorithms" << endl
             << "5: Exit" << endl;
        cin >> selection;

        switch(selection){
            case 1:
            //run the Basic Solve
            cout << "Moving to Basic Solve..." << endl;
            //system("basicSolve.exe");
            system("sample.exe");
            break;
            case 2:
            //run the Prim Algorithm
            cout << "Moving to Prim..." << endl;
            //system("primAlg.exe");
            break;
            case 3:
            //run Djikstra
            cout << "Moving to Djikstra..." << endl;
            //system("djikstra.exe");
            break;
            case 4:
            //compare the time the algorithms take
            cout << "Moving to compare the times..." << endl;
            //system("timeComparison.exe");
            break;
            case 5:
            //exit the program
            cont = 'N';
            break;
            default: 
            cout << "Please choose a menu option.";
        }

        if (selection != 5){
            cout << "Would you like to choose another algorithm? Y/N:" << endl;
            cin >> cont;
        }

        while (cont!='y' && cont!='Y' && cont!='N' && cont!='n'){
            cout << "Please enter Y for Yes or N for No: " << endl;
            cin >> cont;
        }

    } while (cont == 'Y' || cont == 'y');

    cout << "\nThank you for using Pathfinder Visualization as presented by Team C++ 1. \nGoodbye." <<endl;

    return 0;
}