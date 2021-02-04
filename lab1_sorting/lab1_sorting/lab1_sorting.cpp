// lab1_sorting.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <array>
#include <ctime>

using namespace std;

const int elemQuantity = 1000; // кол-во элементов массива

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лаба 1. Внутренная сортировка." << endl;
    array<int, elemQuantity> someArray;
    srand(time(NULL));
    for (int i = 0; i < elemQuantity; i++) {
        someArray[i] = rand() % 81 - 30;
        cout << someArray[i] << endl;
        /*
        if (someArray[i] <= -30 || someArray[i] >= 50) {
            cout << "NO!\n\n\n\n\n\n" << endl;
        }
        */
        
    }
}

