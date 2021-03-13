#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

struct tnode {// ���� ������
    int key;// ����
    int count;// ����� ���������
    int level;//�������
    struct tnode* left;// ����� �������
    struct tnode* right;// ������ �������
    struct tnode* parent;// ��������
    
};
int numcmp(int a, int b)
{
    if (a > b) return 1;
    if (a < b) return -1;
    if (a == b) return 0;
}
// ������� ���������� ���� � ������
struct tnode* addNode(struct tnode* node, int key) {
    int cond;
    if (node == NULL) {
        node = new tnode();
        node->key = key;
        node->level = 0;
        node->left = node->right = node->parent = NULL;

    }
    else 
        if((cond = numcmp(key, node->key)) != 0){
            if (cond < 0) {
                node->left = addNode(node->left, key);
                node->left->parent = node;
                node->left->level = node->level + 1;
            }
            else {
                node->right = addNode(node->right, key);
                node->right->parent = node;
                node->right->level = node->level + 1;
            }
                
        }
    return node;
}
//���������� N ����� � ������ � ��������� ���������
void randomAdd_N_Nodes(struct tnode* node, int quantity) {
    int number;
    for (int i = 0; i < quantity; i++) {
        number = rand() % 100 - 50;
        addNode(node, number);
    }
}
// ������� �������� ���������
void deleteNode(tnode* node) {
    if (node != NULL) {
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }
}
// ������� ������ ������
void printTree(struct tnode* node) {
    if (node != NULL) {
        printTree(node->left);
        cout << "����: " << node->key << "\t\t�������: " << node->level << endl;
        printTree(node->right);
    }
}

int readArrayN(const std::string& filename)//������ ���������� ��������� ������� �� �����
{
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
//���������� ����� � ����
bool SaveNumberInFile(const std::string& filename, int key)
{
    ofstream out;
    // Open the file.
    out.open(filename, ios::app | std::ios::binary);
    // Validate that the file is open.
    if (!out.is_open())
        return false;
    out << key << endl;
    out.close();
    return true;
}

//��������� ������ � ����
void SaveTreeInFile(struct tnode* node, const std::string& filename)
{
    if (node != NULL) {
        SaveTreeInFile(node->left, filename);
        SaveNumberInFile(filename, node->key);//��������� 1 �������� � ����
        SaveTreeInFile(node->right, filename);
    }
}

//�������� ����
void clearFile(const std::string& filename) {
    ofstream out;
    // Open the file.
    out.open(filename, ios::trunc);//����������� ���� (������� ������)
    out.close();
}