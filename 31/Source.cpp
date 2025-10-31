#include <iostream>
using namespace std;

void Init(int& size,int*& arr)
{
	srand(unsigned(time(0)));
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = new int[size];
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
	cout << "Function was completed succesfully!" << endl;
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
	cout << "Function was completed succesfully!" << endl;
}

void AddNewIndex(int* arr, int index, int newValue)
{
	arr[index] = newValue;
	cout << "Function was completed succesfully!" << endl;
}

void AddArrayToArray(int& size, int*& arr,int newSize,int* newArr)
{
	int totalSize = size + newSize;
	int* resultArr = new int[totalSize];

	for (int i = 0; i < size; i++)
	{
		resultArr[i] = arr[i];
	}

	for (int i = 0; i < newSize; i++)
	{
		resultArr[size + i] = newArr[i];
	}
	delete[] arr;
	arr = resultArr;
	size = totalSize;
	cout << "Function was completed succesfully!" << endl;
}

void DeleteEnd(int& size, int*& arr)
{
	int newSize = size - 1;
	int* newarr = new int[newSize];
	for (int i = 0; i < size - 1; i++)
	{
		newarr[i] = arr[i];
	}
	delete[] arr;
	arr = newarr;
	size = newSize;
	cout << "Function was completed succesfully!" << endl;
}

void DeleteStart(int& size, int*& arr)
{
	int newSize = size - 1;
	int* newarr = new int[newSize];
	for (int i = 1; i < size; i++)
	{
		newarr[i - 1] = arr[i];
	}
	delete[] arr;
	arr = newarr;
	size = newSize;
	cout << "Function was completed succesfully!" << endl;
}

void DeleteUnderArray(int& size, int*& arr,int start,int count)
{
	int newSize = size - count;
	int* newarr = new int[newSize];
	for (int i = 0; i < start; i++)
	{
		newarr[i] = arr[i];
	}
	for (int i = start + count; i < size; i++)
	{
		newarr[i - count] = arr[i];
	}
	delete[] arr;
	arr = newarr;
	size = newSize;
	cout << "Function was completed succesfully!" << endl;
}

int main()
{
	int size;
	int size2;
	cout << "Enter size - > ";
	int* arr = nullptr;
	int* arr2 = nullptr;
	try
	{
		cin >> size;
		if (size <= 0)
		{
			throw "Size <= 0";
		}
		while (true)
		{
			int choice;
			cout << "Enter the option: " << endl;
			cout << "1)Init with random numbers" << endl;
			cout << "2)Print array" << endl;
			cout << "3)Add to the end of array" << endl;
			cout << "4)Add to the start of array" << endl;
			cout << "5)Add element by index" << endl;
			cout << "6)Add array to aray" << endl;
			cout << "7)Delete last element" << endl;
			cout << "8)Delete first element" << endl;
			cout << "9)Delete under the array" << endl;
			cout << "10)Exit" << endl;
			cin >> choice;

			switch (choice)
			{
			case 1:
				Init(size, arr);
				break;
			case 2:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				Print(size, arr);
				break;
			case 3:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				int value;
				cout << "Enter the number you want to add: " << endl;
				cin >> value;
				AddToEnd(size, arr, value);
				break;
			case 4:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				int value2;
				cout << "Enter the number you want to add: " << endl;
				cin >> value2;
				AddToStart(size, arr, value2);
				break;
			case 5:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				int index;
				int value3;
				cout << "Enter the index you want to change: " << endl;
				cin >> index;
				cout << "Enter the number you want to add: " << endl;
				cin >> value3;
				if (index < 0 || index > size)
				{
					throw "Out of range";
				}
				AddNewIndex(arr, index, value3);
				break;
			case 6:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				cout << "Enter the size of the another array: " << endl;
				cin >> size2;
				if (size2 <= 0)
				{
					throw "Size <= 0";
				}
				Init(size2, arr2);
				AddArrayToArray(size, arr, size2, arr2);
				break;
			case 7:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				else if (size <= 1)
				{
					throw "Your size is to small!";
				}
				DeleteEnd(size, arr);
				break;
			case 8:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				else if (size <= 1)
				{
					throw "Your size is to small!";
				}
				DeleteStart(size, arr);
				break;
			case 9:
				if (arr == nullptr)
				{
					throw "Your array is empty!";
				}
				int startPosition;
				int countOfElement;
				cout << "Enter the start position which you want to delete: " << endl;
				cin >> startPosition;
				cout << "Enter how many indexes you want to delete: " << endl;
				cin >> countOfElement;
				if (startPosition < 0 || startPosition > size)
				{
					throw "Out of range";
				}
				else if (countOfElement >= size)
				{
					throw "Size is smaller then count of elements!";
				}
				DeleteUnderArray(size, arr, startPosition, countOfElement);
				break;
			case 10:
				cout << "Programme is done!";
				return false;
			default:
				throw "Incorrect option";
			}
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	delete[] arr;
}