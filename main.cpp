#include <iostream>

using namespace std;

class Car{
    public:
        int cnt_wheels;
        double mileage;
        double V;
        double speed;
        double power;
        double consump;
        double time;
        char name;

};

int main()
{
    Car car;
    Car *ptr = &car;

    cout << "Enter power: " << endl;
    cin << ptr->power << endl;

    cout << "Enter mileage: " << endl;
    cin << ptr->mileage << endl;

    cout << "Enter engine capacity: " << endl;
    cin << ptr->V << endl;

    cout << "Enter the distance: " << endl;
    cin << distance << endl;

    ptr->consump = 100 * ptr->V / ptr->mileage;

    cout << ptr->consump << endl;

    cout << "time:"
    time_calc(distance, strong);

    return 0;
}

void time_calc(double distance, double strong){
    double mass = 1250, mu = 0,02,
    strong = mu * mass * 10;
    speed = ptr->power / strong;
    time = distance / speed;
    cout << speed << endl;
}

void t


