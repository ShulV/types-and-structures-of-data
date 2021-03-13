// lab2_linked_lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>


#include "lab2_linked_lists.h"
#include "List.h"

using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    cout << "���� 2. ������� ������." << endl;
    string in_filneame = "input.dat";
    string out_filneame = "output.dat";

    int i, n;

    //������ ������� ������ �� ����� (���������� ���������)
    try {
        n = ReadArrayN(in_filneame);
        cout << "���� ��������:\tN = " << n << endl;
    }
    catch (exception exc) {
        cout << "\n" << exc.what() << endl << "n = 0" << endl;
        n = 0;
    }
    //���������� ������ ���������� �������
    List<int> lst;
    int value;
    for (int i = 0; i < n; i++) {
        value = rand() % 500 - 250;
        lst.push_back(value);
    }
	    
    DisplayList(lst);

    cout << "\n\n\t�������� ������� �������������� � ������" << endl;
    for (int i = 0; i < n; i++) {
        if (lst[i] < 0) {
            lst.removeAt(i);
            break;
        }
    }

    DisplayList(lst);   
    try {
        SaveListInFile(lst, out_filneame);//������ �������� ������
        cout << "\n\n������ �������� � ����" << endl;
    }
    catch (exception exc) {
        cout << "\n" << exc.what() << endl;
    }
    
}

//����� ������
void DisplayList(List<int> &list) {
    if (list.GetSize()) {
        cout << "\n������: " << endl;  //����� ������
        for (int i = 0; i < list.GetSize(); i++)
            cout << list[i] << " ";
    }
    else {
        cout << "\n������ ����" << endl;
    }
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

//���������� ������� � ����
bool SaveListInFile(List<int>& list, const std::string& filename)
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

    out << list.GetSize() << "\n\n";
    for (int i = 0; i <= list.GetSize(); i++) {
        out << list[i] << endl;
    }

    out.close();

    return true;
}