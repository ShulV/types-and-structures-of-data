// lab2_linked_lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "lab2_linked_lists.h"

bool SaveArrayInFile(int* A, int first, int last, const std::string& filename);//сохранения массива в файл
int ReadArrayN(const std::string& filename);//чтения количества элементов массива из файла
void DisplayArray(int* A, int first, int last);//вывод массива

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    cout << "Лаба 2. Связные списки." << endl;
    string in_filneame = "input.dat";
    string out_filneame = "output.dat";

    int i, n;

    try {
        n = ReadArrayN(in_filneame);
        cout << "N = " << n << endl;
    }
    catch (exception exc) {
        cout << "\n" << exc.what() << endl << "n = 0" << endl;
        n = 0;
    }

    int* A = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        A[i] = rand() % 131 - 50; // [-50; 80]
    }

    cout << "\nСгенерированный массив: " << endl;  //вывод упорядоченного массива
    DisplayArray(A, 1, n);
}
