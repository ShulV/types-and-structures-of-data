#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab1_sorting\lab1_sorting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1UnitTest1
{
	TEST_CLASS(Lab1UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMerge)
		{
			//���� 1 (8 ���������, ������� �� ���� �������������)
			{
				int inA[] = { 0, 8, 9, 6, 7, 8, 12, 3, 4 };
				Merge(inA, 1, 8);
				int outA[] = { 0,8,8,9,6,7,12,3,4 };
				Assert::IsTrue(compareArray(inA, outA));
			}
			
			//���� 2 (6 ���������, ������� �������������)
			{
				int inA[] = { 0, 22, 33, 44, 2, 3, 4 };
				Merge(inA, 1, 6);
				int outA[] = { 0,2,3,4,22,33,44 };
				Assert::IsTrue(compareArray(inA, outA)); 
			}
			//���� 3 (5 ���������, ������� �������������)
			{
				int inA[] = { 0, 22, 33, 44, 2, 3 };
				Merge(inA, 1, 5);
				int outA[] = { 0,2,3,22,33,44 };
				Assert::IsTrue(compareArray(inA, outA));
			}
			//���� 4 (5 ���������, ������� �� ���� �������������)
			{
				int inA[] = { 0, 5, 4, 3, 2, 1 };
				Merge(inA, 1, 5);
				int outA[] = { 0,3,2,1,5,4,3 };
				Assert::IsTrue(compareArray(inA, outA));
			}
			//���� 5 (1 �������)
			{
				int inA[] = { 0, 55 };
				Merge(inA, 1, 1);
				int outA[] = { 0,55 };
				Assert::IsTrue(compareArray(inA, outA));
			}
			//���� 6 (2 ��������)
			{
				int inA[] = { 0, 55, 66 };
				Merge(inA, 1, 2);
				int outA[] = { 0,55,66};
				Assert::IsTrue(compareArray(inA, outA));
			}

		}
		
		TEST_METHOD(TestSortMerge)
		{
			//���� 1 (���������� ������������������ 8 ����)
			{
				int inA[] = { 0, 8,7,6,5,4,3,2,1 };
				Merge(inA, 1, 8);
				int outA[] = { 0,1,2,3,4,5,6,7,8 };
				Assert::IsTrue(compareArray(inA, outA));
			}
			//���� 2 (���������� ���������������� 8 ����)
			{
				int inA[] = { 0,1,2,3,4,5,6,7,8 };
				Merge(inA, 1, 8);
				int outA[] = { 0,1,2,3,4,5,6,7,8 };
				Assert::IsTrue(compareArray(inA, outA));
			}
			//���� 3 (���������� ���������������� 3 ����)
			{
				int inA[] = { 0,1,2,3};
				Merge(inA, 1, 3);
				int outA[] = { 0,1,2,3};
				Assert::IsTrue(compareArray(inA, outA));
			}
			//���� 4 (���������� ������������������ 3 ����)
			{
				int inA[] = { 0,3,2,1 };
				Merge(inA, 1, 3);
				int outA[] = { 0,1,2,3 };
				Assert::IsTrue(compareArray(inA, outA));
			}
			//���� 5 (���������� ������� ���������� ���������)
			{
				int inA[] = { 0,1,1,2,1,2};
				Merge(inA, 1, 5);
				int outA[] = { 0,1,1,1,2,2 };
				Assert::IsTrue(compareArray(inA, outA));
			}
		}
		TEST_METHOD(TestGetMaxNegative)
		{
			//���� 1 
			{
				int inA[] = { 0,1,1,2,3,-1 };
				Assert::IsTrue(GetMaxNegative(inA, 1, 5) == -1); 

			}
			//���� 2 (�� ����� � �����)
			{
				int inA[] = { 0,-1,1,-0,-1,0 };
				Assert::IsTrue(GetMaxNegative(inA, 1, 5) == -1);
			}
			//���� 3 
			{
				int inA[] = { 0,-1,-1,-2,-3,-99 };
				Assert::IsTrue(GetMaxNegative(inA, 1, 5) == -1);
			}

		}

		void throwException()
		{
			throw 1;
		}
		
		bool compareArray(int* mas_a, int* mas_b) {
			//����� ��������� �������� �� ������������
			bool flag;
			for (int i = 0; i < sizeof(mas_a) / sizeof(mas_a[0]) - 1; i++) {
				flag = false;
				for (int j = 0; j < sizeof(mas_b) / sizeof(mas_b[0]) - 1; j++) {
					if (mas_a[i] == mas_b[j]) { flag = true; break; }
					if (flag == false)  return false;
				}
				
			}
			return true;
		}

	};
}