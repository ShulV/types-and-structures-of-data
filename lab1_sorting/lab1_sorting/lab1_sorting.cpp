

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>


//TODO сделать тесты!


using namespace std;
//функция, сливающая массивы
void merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[last+1];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (j = first; j <= last; j++)  //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};
//рекурсивная процедура сортировки
void mergeSort(int* A, int first, int last) {
    if (first < last) {
        mergeSort(A, first, (first + last) / 2);  //сортировка левой части
        mergeSort(A, (first + last) / 2 + 1, last);  //сортировка правой части
        merge(A, first, last);  //слияние двух частей
    }
}

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

//сохранения массива в файл
bool saveArrayInFile(int* A, int first, int last, const std::string& filename)
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

void displayArray(int* A, int first, int last) {
    for (int i = first; i <= last; i++) {
        cout << A[i] << " ";
    }
}
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

