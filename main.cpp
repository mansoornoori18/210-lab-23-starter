#include <iostream> // 210 class OOP || Mansoor Noori
#include <fstream>  // Visual Studio Code
#include <iomanip>
#include <list>
#include "Goat.h"
#include<cstdlib>
#include<ctime>

using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    // read names form the names.txt
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    // reads colors from the color.txt
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    // list to store all the goats in the list 
    list<Goat> trip;

    while(again){
        int choice = main_menu();
        switch(choice){
            case 1: add_goat(trip, names, colors); break; // add a goat
            case 2: delete_goat(trip); break;
            case 3: display_trip(trip); break;
            case 4:
            cout << "\nGood Bye!\n";
            again = false;
            break;
            default:
            cout << "Invalid Option,Try again.\n";

        }
    }




    return 0;
}

