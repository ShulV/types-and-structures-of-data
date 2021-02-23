#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
//�������, ��������� �������
void Merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[last + 1];
    middle = (first + last) / 2;  //���������� �������� �������� (����������� � ������� �������)
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
void MergeSort(int* A, int first, int last) {
    if (first < last) {
        int middle = (first + last) / 2;
        MergeSort(A, first, middle);  //���������� ����� �����
        MergeSort(A, middle + 1, last);  //���������� ������ �����
        Merge(A, first, last);  //������� ���� ������
    }
}

//�������� ������������ ����� ����� �������
int GetMaxNegative(int* A, int first, int last) {
    int maxNegative=1;
    int flag = 0;
    for (int i = 1; i <= last; i++) {
        if (A[i] < 0 && (flag == 0 || maxNegative < A[i])) {
            maxNegative = A[i];
            flag = 1;

        }
    }
    if (flag == 0) throw exception("Exception: no negative numbers");
    else return maxNegative;
}

//���������� ������� � ����
bool SaveArrayInFile(int* A, int first, int last, const std::string& filename)
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

//����� �������
void DisplayArray(int* A, int first, int last) {
    for (int i = first; i <= last; i++) {
        cout << A[i] << " ";
    }
}