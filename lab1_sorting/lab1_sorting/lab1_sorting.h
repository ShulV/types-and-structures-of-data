#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
//�������, ��������� �������
void merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[last + 1];
    middle = (first + last) / 2;  //���������� �������� ��������
    start = first;                //������ ����� �����
    final = middle + 1;           //������ ������ �����
    for (j = first; j <= last; j++)  //��������� �� ������ �� �����
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    //����������� ���������� � ������
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};

//����������� ��������� ����������
void mergeSort(int* A, int first, int last) {
    if (first < last) {
        mergeSort(A, first, (first + last) / 2);  //���������� ����� �����
        mergeSort(A, (first + last) / 2 + 1, last);  //���������� ������ �����
        merge(A, first, last);  //������� ���� ������
    }
}

//�������� ������������ ����� ����� �������
int getMaxNegative(int* A, int first, int last) {
    int maxNegative = 0;
    for (int i = 1; i <= last; i++) {
        if (A[i] < 0 && (A[i] > maxNegative || maxNegative == 0)) {
            maxNegative = A[i];
        }
    }
    if (maxNegative == 0) throw exception("Exception: no negative numbers");
    return maxNegative;
}

//���������� ������� � ����
bool saveArrayInFile(int* A, int first, int last, const std::string& filename)
{
    /*
    ������ ����� � ����� ����� N, ��������� - �������� �������
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

//������ ���������� ��������� ������� �� �����
int readArrayN(const std::string& filename) {
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

//����� �������
void displayArray(int* A, int first, int last) {
    for (int i = first; i <= last; i++) {
        cout << A[i] << " ";
    }
}