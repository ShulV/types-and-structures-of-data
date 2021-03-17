#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>


using namespace std;


/*
* ����������� ���������� ������ � �������
* ����������
*/

template<typename T>
class List
{
public:
	List();
	~List();
	//���������� �������� � ����� ������
	void push_back(T data);
	//�������� �������� � ������ �� ���������� �������
	void removeAt(int index);
	// �������� ���������� ��������� � ������
	int GetSize() { return Size; }
	// ������������� �������� [] 
	T& operator[](const int index);
private:
	template<typename T>
	class Node
	{
	public:
		Node *pNext, *pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			if (pNext == nullptr)
				this->pNext = this;
			else
				this->pNext = pNext;
			if (pPrev == nullptr)
				this->pPrev = this;
			else 
				this->pPrev = pPrev;
		}
	};
	int Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);//�������� ������� ��������
	}
	else
	{
		//���������� �������� � ����� ������
		Node<T>* before_last = this->head->pPrev;//�������� �������� ��������� Node (����� - �������������)
		Node<T>* last = new Node<T>(data);//������� ����� ��������� Node
		last->pNext = this->head;//��������� �� ��������� - ������ ������
		before_last->pNext = last;//��������� �� ������������� - ���������
		last->pPrev = before_last;//���������� ����� ��������� - ������ �������������
		head->pPrev = last;//���������� ����� ������� - ���������
	}

	Size++;
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (this->GetSize() < index || index < 0) {
		throw exception("Wrong function using");
	}
	else {
		if (index == 0)
		{
			Node<T>* previous = head->pPrev;
			//cout << "prev = " << previous->data << endl;
			Node<T>* next = head->pNext;
			previous->pNext = next;
			next->pPrev = previous;
			if (Size > 0) this->head = this->head->pNext;
			else head = nullptr;//���� ������ ���� ������
			Size--;
			
		}
		else
		{
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node<T>* toDelete = previous->pNext;
			Node<T>* next = toDelete->pNext;
			previous->pNext = next;
			next->pPrev = previous;
			delete toDelete;
			Size--;
		}
	}
	
	
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}








