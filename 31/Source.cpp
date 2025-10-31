#include <iostream>
using namespace std;

void Init(int& size,int* arr)
{
	srand(unsigned(time(0)));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
	cout << "Your array was initialized succesfully!" << endl;
}

void Print(int& size, int* arr)
{
	cout << "Your array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void AddToEnd(int& size, int*& arr, int value)
{
	int newSize = size + 1;
	int* newarr = new int[newSize];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[size] = value;
	delete[] arr;
	arr = newarr;
	size = newSize;
}

void AddToStart(int& size, int*& arr, int value)
{
	int newSize = size + 1;
	int* newarr = new int[newSize];
	newarr[0] = value;
	for (int i = 0; i < size; i++)
	{
		newarr[i + 1] = arr[i];
	}
	delete[] arr;
	arr = newarr;
	size = newSize;
}



int main()
{
	int size;
	cout << "Enter size - > ";
	int* arr = nullptr;
	try
	{
		cin >> size;
		if (size <= 0)
		{
			throw "Size <= 0";
		}
		arr = new int[size];
		Init(size, arr);
		Print(size, arr);
		AddToEnd(size, arr, 67);
		Print(size, arr);
		AddToStart(size, arr, 11);
		Print(size, arr);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	delete[] arr;
}