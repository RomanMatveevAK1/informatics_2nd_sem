#include <iostream>
#include <string>
using namespace std;

void Print_Menu();
void Input(int cnt);


class transport 
{
public:
    int cnt_wheels;
    double mileage;
    double eng_capacity;
    double speed;
    double power;
    double consump;
    double massa;
    double time;
    string name;
};

void Print_Menu()
{
    cout << "--------------------------МЕНЮ--------------------------\n 1. Ввести и посмотреть данные о ТС\n 2. Ввести протяженность трассы\n 3. Произвести расчет прохождения трассы\n 4. Осуществить вывод результатов прохождения трассы\n 5. Выход\n" << endl;
}

void Input(int cnt)
{
    transport* ptr = new transport[cnt];
    for (int i = 0; i < cnt; i++)
    {
        transport TS;
        cout << "Транспорт №" << i + 1 << endl;
        cout << "Название ТС: " << endl;
        cin >> TS.name;
        cout << "Количество колёс (шт.):" << endl;
        cin >> TS.cnt_wheels;
        cout << "Мощность двигателя (л. с.):" << endl;
        cin >> TS.power;
        cout << "Объём двигателя (л):" << endl;
        cin >> TS.eng_capacity;
        cout << "Пробег (км):" << endl;
        cin >> TS.mileage;
        TS.consump = 100 * TS.eng_capacity / TS.mileage;
        cout << "Потребление двигателя (л/км):" << TS.consump << endl;
        cout << "Масса (кг):" << TS.massa << endl;
        cin >> TS.massa;
        TS.speed = TS.power * 735.5 / (0.02 * TS.massa);
        cout << "Скорость транспортного средства (м/c):" << TS.speed;

        ptr[i] = TS;
    }
    for (int i = 0; i < cnt; i++)
    {
        cout << "Transport №" << i + 1 << "\t\t";
        cout << ptr[i].name << "\t\t";
        cout << ptr[i].cnt_wheels << "\t\t";
        cout << ptr[i].power << "\t\t";
        cout << ptr[i].consump << "\n";
        cout << ptr[i].speed << endl;
    }
}


int main()
{

    setlocale(LC_ALL, "ru");
    Print_Menu();

    int choose, cnt;

    cout << "Выберите номер пункта меню" << endl;
    cin >> choose;


    switch (choose)
    {
        case 1:
            cout << "Ввод данных о транспортных средствах\n" << endl;
            cout << "Введите количество транспортных средств:" << endl;
            cin >> cnt;
            Input(cnt);
            break;
        case 2:


        /*case 4:
        case 5:
        case 6:*/
        default:
            cout << "Ошибка! Попробуйте сделать выбор еще раз.";

    }
}



