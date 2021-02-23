#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool SaveArrayInFile(int* A, int first, int last, const std::string& filename)
{
    /*
    Первое число в файле будет N, остальные - элементы массива
    */
    ofstream out;

    // Open the file.
    out.open(filename, std::ios::out | std::ios::binary);

    // Validate that the file is open.
    if (!out.is_open())
        return false;

    out << last << "\n\n";
    for (int i = first; i <= last; i++) {
        out << A[i] << endl;
    }

    out.close();

    return true;
}

//чтения количества элементов массива из файла
int ReadArrayN(const std::string& filename) {
    ifstream in;
    string str_n;
    int n = 0;
    // Open the file.
    in.open(filename, std::ios::in | std::ios::binary);
    if (in.is_open()) {
        getline(in, str_n);
    }
    else
    {
        throw exception("Exception: file did't open");
    }
    try {
        n = stoi(str_n);
    }
    catch (exception exc) {
        throw exception("Exception: convert failure");
    }
    return n;

}

//вывод массива
void DisplayArray(int* A, int first, int last) {
    for (int i = first; i <= last; i++) {
        cout << A[i] << " ";
    }
}