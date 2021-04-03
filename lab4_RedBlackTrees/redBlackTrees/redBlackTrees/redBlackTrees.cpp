#include "redBlackTrees.h"
int numcmp(int a, int b);// ��������� �����
struct tnode* addNode(struct tnode* p, int key);// ������� ���������� ���� � ������
void randomAdd_N_Nodes(struct tnode** node, int quantity);// ���������� N ����� � ������ � ��������� ���������
void deleteSubTree(tnode* tree);// ������� �������� ���������
tnode* deleteRootSubTree(tnode* node);// �������� ��������� ����
void deleteNode(tnode* node, tnode* del_node, int level);// �������� ����
tnode* findNode(tnode* node, int key, int level);// ����� � �������� ������ �� ��������
void printTree(struct tnode* p);// ������� ������ ������
int readArrayN(const std::string& filename);// ������ ���������� ��������� ������� �� �����
void SaveTreeInFile(struct tnode* node, const std::string& filename);// ��������� ������ � ����
bool SaveNumberInFile(const std::string& filename, int key);// ���������� ����� � ����
void clearFile(const std::string& filename);// �������� ����


int main(int argc, char* argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    string in_filneame = "input.dat";
    string out_filneame = "output.dat";

    int n = 0;// ���-�� ����� ��� ������ �� �����
    int key = 0; // ����
    int level = 0; // �������
    char choice; // �����
    struct tnode* root;
    root = NULL;

    do
    {
        cout << "Lab 4. Red-black trees." << endl;
        printf("\n\t1 - Read file and fill tree;\n\t2 - Save tree in file;\n\t3 - Add element;\n\t4 - Delete tree;\n\t5 - Print tree;\n\t6 - Find and delete node;\n\t0 - Exit:\nYour choice:\t");
        fflush(stdin);
        choice = _getch();
        printf("\n");



        switch (choice)
        {
        case '1':
            n = readArrayN(in_filneame);
            cout << "N = " << n << endl;
            randomAdd_N_Nodes(&root, n);
            _getch();
            break;
        case '2':
            clearFile(out_filneame);
            SaveTreeInFile(root, out_filneame);
            cout << "file is written" << endl;
            _getch();
            break;
        case '3':
            while (!(fflush(stdin)) && !(printf("Enter key ") && scanf_s("%d", &key)));//���� �����
            root = addNode(root, key);
            _getch();
            break;
        case '4':
            cout << "\nTree will be deleted" << endl;
            deleteSubTree(root);
            root = NULL;
            _getch();
            break;
        case '5':
            if (root) {
                cout << "\nTree:\n";//����� � ������ �������
                printTree(root);
            }
            else cout << "\nTree is empty:\n";
            _getch();
            break;
        case '6':
            /*
            tnode *node2;
            while (!(fflush(stdin)) && !(printf("Enter key to search: ") && scanf_s("%d", &key)));//���� �����
            while (!(fflush(stdin)) && !(printf("Enter level to search: ") && scanf_s("%d", &level)));//���� ������
            node2=findNode(root, key, level);
            if (node2!=NULL)
            {
                cout << "Was found" << endl;
                cout << node2->key << " level: " << node2->level << endl;

            }

            else cout << "Was not found" << endl;
            */


            root = deleteRootSubTree(root);
            cout << "Root is deleted" << endl;
            _getch();
            break;
        }

        system("cls");

    } while (choice != '0');



    system("pause");
    return 0;
}