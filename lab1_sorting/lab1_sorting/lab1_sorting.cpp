﻿
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

#include "lab1_sorting.h"
//TODO сделать тесты!


using namespace std;

void merge(int* A, int first, int last);//функция, сливающая массивы
void mergeSort(int* A, int first, int last);//рекурсивная процедура сортировки
int getMaxNegative(int* A, int first, int last);//получить максимальное отриц число массива
bool saveArrayInFile(int* A, int first, int last, const std::string& filename);//сохранения массива в файл
int readArrayN(const std::string& filename);//чтения количества элементов массива из файла
void displayArray(int* A, int first, int last);//вывод массива

//главная функция
void main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    cout << "Лаба 1. Внутренная сортировка." << endl;
    string in_filneame = "input.dat";
    string out_filneame = "output.dat";

    int i, n;
    int maxNegative;


    try{
        n = readArrayN(in_filneame);
        cout << "N = " << n << endl;
    }
    catch (exception exc){
        cout << "\n" << exc.what() << endl;
    }
    
    int* A = new int[n+1];
    for (int i = 1; i <= n; i++) {
        A[i] = rand() % 131-50; // [-50; 80]
    }

    cout << "\nСгенерированный массив: " << endl;  //вывод упорядоченного массива
    displayArray(A, 1, n);
    try{ 
        maxNegative = getMaxNegative(A, 1, n);
        for (int i = 1; i <= n; i++) {
            A[i] += maxNegative;
        }
        cout << "\nМассив с добавлением максимального отрицательного:" << maxNegative << endl;  //вывод массива с добавлением максимального отрицательного
        displayArray(A, 1, n);
    }
    catch(exception ex){
        cout << "\n" << ex.what() << endl;
    }
  
    mergeSort(A, 1, n);  //вызов сортирующей процедуры
    cout << "\nУпорядоченный массив: " << endl;  //вывод упорядоченного массива
    displayArray(A, 1, n);


    saveArrayInFile(A, 1, n, out_filneame);
    delete[] A;
    system("pause>>void");
}

