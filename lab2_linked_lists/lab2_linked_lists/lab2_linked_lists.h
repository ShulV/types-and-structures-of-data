#pragma once
#include "List.h"

int ReadArrayN(const std::string& filename);//������ ���������� ��������� ������� �� �����
bool SaveListInFile(List<int>& list, const std::string& filename);//���������� ������� � ����
void DisplayList(List<int>& list);
