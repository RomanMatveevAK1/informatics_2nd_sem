#include <iostream>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif


using namespace std;

struct regular_polygon{
    int count_sides;
    double length;
    double square;
    double perimeter;
    double* x = new double[count_sides];
    double* y = new double[count_sides];
};

void CountSquare(struct regular_polygon* reg_pol, int amount);
void CountPerimeter(struct regular_polygon* reg_pol, int amount);
void SetData(regular_polygon* reg_pol, int amount);
regular_polygon* AddStruct(regular_polygon* reg_pol, int amount, int* output);
int* max_square(struct regular_polygon* reg_pol, int amount);
int* max_perimeter(struct regular_polygon* reg_pol, int amount);
int* del_struct(int* output, int choosenForDelete);
void menu(regular_polygon* OurPolygon, int PolygonAmount, int* output);
void print(regular_polygon* OurPolygon, int amount, int* output);


int main()
{
    regular_polygon* OurPolygon = 0;
    int PolygonAmount = 0;
    int YesOrNot = 0;
    int* output = new int[PolygonAmount];
    output[0] = 1;
    cout << "Hello!" << '\n';
    menu(OurPolygon, PolygonAmount, output);
    
  



    /*double ang = ((reg_pol.count_sides - 2) * M_PI) / (reg_pol.count_sides);
    double R = reg_pol.length / (2 * sin(M_PI / (reg_pol.count_sides)));*/
    
    
    /*for (int i = 0; i < reg_pol.count_sides; i++)
    {
      
    }*/
    return 0;
}



void CountSquare(struct regular_polygon* reg_pol, int amount)
{
    if (reg_pol[amount].length == 3) reg_pol[amount].square = pow(reg_pol[amount].length, 2) * sqrt(3) / 4;
    if (reg_pol[amount].length == 3) reg_pol[amount].square = pow(reg_pol[amount].length, 2);
    else
    {
        reg_pol->square = 0.25 * (double)reg_pol->count_sides * reg_pol->length * reg_pol->length * pow(tan(M_PI / ((double)reg_pol->count_sides)), -1.0);
        cout << "Square = " << reg_pol->square << '\n';
    }
}


void CountPerimeter(struct regular_polygon* reg_pol, int amount)
{
    reg_pol->perimeter = reg_pol->count_sides * reg_pol->length;
    cout << "Perimeter = " << reg_pol->perimeter << '\n';
}

regular_polygon* AddStruct(regular_polygon* reg_pol, int amount, int* output)
{
    if (amount == 0)
    {
        reg_pol = new regular_polygon[amount + 1];
    }
    else
    {
        regular_polygon* temp = new regular_polygon[amount + 1];
        int* temp2 = new int[amount + 1];
        for (int i = 0; i < amount; i++)
        {
            temp[i] = reg_pol[i];
            temp2[i] = output[i];
        }
        delete[] output;
        delete[] reg_pol;

        reg_pol = temp;
        output = temp2;
        output[amount] = 1;
    }
    return reg_pol;
}

void SetData(regular_polygon* reg_pol, int amount)
{
    cout << "Enter count of sides:" << '\n';
    cin >> reg_pol[amount].count_sides;

    cout << "Enter length of the side:" << '\n';
    cin >> reg_pol[amount].length;

    cout << "Enter vertex coordinates" << '\n';

    cout << "Enter x:" << '\n';
    cin >> reg_pol[amount].x[0];

    cout << "Enter y:" << '\n';
    cin >> reg_pol[amount].y[0];
}

int* max_square(regular_polygon* reg_pol, int amount)
{
    int i_max = 0;
    int* square_max = new int[amount];
    for (int i = 1; i < amount; i++)
    {
        if (reg_pol[i].square > reg_pol[i_max].square) i_max = i;
    }
    for (int i = i_max; i < amount; i++)
    {
        if (reg_pol[i].square == reg_pol[i_max].square) square_max[i] = i;
        else square_max[i] = 0;
    }
    return square_max;
}

int* max_perimeter(regular_polygon* reg_pol, int amount)
{
    int i_max = 0;
    int* perimeter_max = new int[amount];
    for (int i = 1; i < amount; i++)
    {
        if (reg_pol[i].perimeter > reg_pol[i_max].perimeter) i_max = i;
    }
    for (int i = i_max; i < amount; i++)
    {
        if (reg_pol[i].perimeter == reg_pol[i_max].perimeter) perimeter_max[i] = i;
        else perimeter_max[i] = 0;
    }
    return perimeter_max;
}

int* del_struct(int* output, int choosenForDelete)
{
    output[choosenForDelete - 1] = 0;
    return output;
}
/////// ОГРАНИЧЕНИЯ///////


void menu(regular_polygon* OurPolygon, int PolygonAmount, int* output)
{
    int chosenForDelete = 0;
    cout << "Choose the action" << '\n';
    cout << "1 - Add polygon         2 - Show polygons" << '\n';
    cout << "3 - Delete polygon      4 - Square/perimeter " << '\n';
    cout << "5 - Close the programm" << '\n';
    int choose;
    cin >> choose;

    switch (choose)
    {
    case 1:
        OurPolygon = AddStruct(OurPolygon, PolygonAmount, output);
        SetData(OurPolygon, PolygonAmount);
        PolygonAmount++;
    case 2:
        print(OurPolygon, PolygonAmount, output);
        menu(OurPolygon, PolygonAmount, output);
    case 3:
        cout << "Which polygon you want to delete? Input the sequence number:" << '\n';
        cin >> chosenForDelete;
        if (chosenForDelete > PolygonAmount)
        {
            cout << "There is no such polygon yet :( " << '\n';
            menu(OurPolygon, PolygonAmount, output);
        }
        else 
        {
            cout << "As you wish" << '\n';
            del_struct(output, chosenForDelete);
            menu(OurPolygon, PolygonAmount, output);
        }
    default:
        cout << "Incorrect! Try again" << '\n';
        menu(OurPolygon, PolygonAmount, output);
    }
}

void print(regular_polygon* reg_pol, int amount, int* output)
{
    for (int i = 0; i < amount; i++)
    {
        if (output[i] == 1)
        {
            cout << "Polygon number ";
            cout << i+1 << '\n';

            cout << "quontity of vertexes: ";
            cout << reg_pol[i].count_sides << '\n';

            cout << "Square: ";
            cout << reg_pol[i].square << '\n';

            cout << "Perimeter: ";
            cout << reg_pol[i].perimeter << '\n';
            cout << "Good job!";
        }
        else
        {
            for (int i = 0; i < 7; i++) cout << '\n';
        }
    }
}
