#include "binaryTree1.h"
int numcmp(int a, int b);// Сравнение чисел
struct tnode* addNode(struct tnode* p, int key);// Функция добавления узла к дереву
void randomAdd_N_Nodes(struct tnode* node, int quantity);// Добавление N узлов к дереву с рандомным значением
void deleteNode(tnode* tree);// Функция удаления поддерева
void printTree(struct tnode* p);// Функция вывода дерева
int readArrayN(const std::string& filename);// Чтения количества элементов массива из файла
void SaveTreeInFile(struct tnode* node, const std::string& filename);//сохранить дерево в файл
bool SaveNumberInFile(const std::string& filename, int key);//сохранения числа в файл
void clearFile(const std::string& filename);//очистить файл

int main(int argc, char* argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    string in_filneame = "input.dat";
    string out_filneame = "output.dat";

    int n = 0;// Кол-во узлов для записи из файла
    int key; // Ключ
    char choice; // Выбор
    struct tnode* root;
    root = NULL;

    key = 10;
    
    do {
        key--;
        cout << "key =" << key << endl;
         root = addNode(root, key);
    } while (key);   


    do
    {
        cout << "Лаба 3. Бинарные деревья." << endl;
        printf("\n\t1 - Read file and fill tree;\n\t2 - Save tree in file;\n\t3-Add element;\n\t4-Delete element;\n\t5 - Print tree;\n\t0-Exit:\nYour choice:\t");
        fflush(stdin);
        choice = _getch();
        printf("\n");

        

        switch (choice)
        {
        case '1':
            n = readArrayN(in_filneame);
            cout << "N = " << n << endl;
            randomAdd_N_Nodes(root, n);
            _getch();
            break;
        case '2':
            clearFile(out_filneame);
            SaveTreeInFile(root, out_filneame);
            cout << "file is written" << endl;
            _getch();
            break;
        case '3':
            while (!(fflush(stdin)) && !(printf("Enter key ") && scanf_s("%d", &key)));//ввод ключа
            root = addNode(root, key);
            _getch();
            break;
        case '4':
            while (!(fflush(stdin)) && !(printf("Enter key to delete ") && scanf_s("%d", &key)));//ввод ключа
            deleteNode(root);
            root = NULL;
            _getch();
            break;
        case '5':
            printf("List view:\n");//вывод в прямом порядке
            printTree(root);
            _getch();
            break;
        }

        system("cls");

    } while (choice != '0');



    system("pause");
    return 0;
}