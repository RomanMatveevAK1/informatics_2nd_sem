#include <iostream>
#include <string>
#include "Transport.h"

using namespace std;

void menu(bool flag);
void sort();

Transport* arrayOfTransport;
int n = 0;

int main()
{
    bool flag = false, exiting = true;
    char key;
    string s;
    int countWheels;
    double mileage;
    double volumeTank;
    double power;
    double time;
    string name;
    int distance = 0;
    while (exiting) {
        menu(flag);
        cin >> s;
        if (s.size() > 1)
            key = '5';
        else
            key = s[0];
        cout << endl;
        switch (key) {
        case '1':
            cout << "Enter the number of transports: \n";
            while (!(cin >> n) || cin.get() != '\n') {
                cout << "Write number of array elements (>0)\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            arrayOfTransport = new Transport[n];
            for (int i = 0; i < n; i++) {
                cout << "Full info for " << i + 1 << " transport\n";
                cout << "Write count of wheels\n";
                cin >> countWheels;
                cout << "Write mileage\n";
                cin >> mileage;
                cout << "Write volume of tank\n";
                cin >> volumeTank;
                cout << "Write power\n";
                cin >> power;
                cout << "Write time\n";
                cin >> time;
                cout << "Write name\n";
                cin >> name;
                arrayOfTransport[i] = Transport(countWheels,
                    mileage, volumeTank, power, time, name);
            }
            break;
        case '2':
            if (n == 0) {
                cout << "Array of transport is empty\n";
            }
            else {
                cout << "Count of wheels\tPower\tSpeed\tEngine consumption\n";
                for (int i = 0; i < n; i++) {
                    arrayOfTransport[i].printCharacter();
                }
            }
            break;
        case '3':
            cin >> distance;
            cout << "Distance writen\n";
            break;
        case '4':
            if (n == 0 || distance == 0) {
                cout << "Array of transport is empty or distance is null\n";
            }
            else {
                flag = true;
                for (int i = 0; i < n; i++) {
                    arrayOfTransport[i].calcRefills(distance);
                    arrayOfTransport[i].calcTravelTime(distance);
                }
                cout << "Calculating\n";
            }
            break;
        case '5':
            sort();
            cout << "Name\tReffils\tTravel time\n";
            for (int i = 0; i < n; i++) {
                arrayOfTransport[i].printReffilsTravelTime();
            }
            break;
        case '0':
            cout << "Are you sure? (y/n)\n";
            char k;
            cin >> k;
            if (k == 'y') {
                exiting = false;
            }
            break;
        default:
            cout << "Write number under 0 and 5\n"; 
            break;
        }
    }

    return 0;
}

void menu(bool flag) {
    cout << "Select number: \n";
    cout << "1. Entering data about several transports\n";
    cout << "2. View transports data\n";
    cout << "3. Entering route length\n";
    cout << "4. Calculate routes\n";
    if (flag) {
        cout << "5. Output of route results\n";
    }
    cout << "0. Exit\n";
    cout << "Your choice:\n";
}

void sort() {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arrayOfTransport[i].getTravelTime() >
                arrayOfTransport[j].getTravelTime()) {
                Transport tmp = arrayOfTransport[i];
                arrayOfTransport[i] = arrayOfTransport[j];
                arrayOfTransport[j] = tmp;
            }
            else if (arrayOfTransport[i].getTravelTime() ==
                arrayOfTransport[j].getTravelTime()) {
                if (arrayOfTransport[i].getReffils() >
                    arrayOfTransport[j].getReffils()) {
                    Transport tmp = arrayOfTransport[i];
                    arrayOfTransport[i] = arrayOfTransport[j];
                    arrayOfTransport[j] = tmp;
                }
            }
        }
    }
}