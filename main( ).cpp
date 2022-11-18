#include<iostream>
#include<fstream>
using namespace std;
void Menu()
{
	cout << "Press 1. to insert new test result\n"
		<< "Press 2. to display total number of results\n"
		<< "Press 3. to delete any test value from table\n"
		<< "Press 4. to display the 2 most frequent values in table\n"
		<< "Press 5. to display the average scores of each field\n"
		<< "Press 6. to display field having maximum success score\n"
		<< "Press 7. to exit the program\n";
}
double** read_file(int& row,int& col)// file reading....
{
	double** array = nullptr;
	ifstream fin("Pestcouts.txt");
	if (fin.is_open())
	{
		fin >> row;
		fin >> col;
		array = new double* [row] {0};
		for (int i = 0; i < row; i++)// 2d array creation here
		{
			array[i] = new double[col] {0};
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fin >> array[i][j];
				
			}
		}
		cout << "Data Readed Successfully\n";
		cout << "================================\n\n";
		return array;
	}
	else
	{
		cout << "Pestcouts.txt file is not available\n\n";
	}
	return nullptr;
}
void Insert_NewTestValue(double**&array,int row,int col)
{
	double value = 0.0;
	int field = 0, c = 0;
	bool flage = false;
	cout << "Enter the field in which you want to enter a test value : ";
	cin >> field;
	cout << "Enter new test value : ";
	cin >> value;
	for (int i = 0; i < row; i++)
	{
		if (field==i+1)
		{
			for (int j = 0; j < col; j++)
			{
				if (array[i][j] == -1)
				{
					array[i][j] = value;
					c= j ;
					flage = true;
					break;
					
				}
			}
		}
		if (flage)
		{
			cout << value << " is entered in field " << field << " at location " << c << endl;
			break;
		}
		
	}
	if (!flage)
	{
		cout << "Sorry dear!!! No location is free in this field\n";
	}
		
}
void Display_TotalNumberOfResults(double**& array, int row, int col)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (array[i][j] != -1)
			{
				count++;
			}
		}
	}
	cout << "There are " << count << " test score values entered in table\n";
}
void Delete_AnyTestValue(double**& array, int row, int col)
{
	int count = 0; bool flage = false;
	double value = 0.0;
	cout << "Enter test value you want to delete from table : ";
	cin >> value;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (array[i][j]==value)
			{
				
				array[i][j] = -1;
				break;
				flage = true;
			}
		}
		if (flage)
		{
			cout << "Test value " << value << "deleted successfully\n";
			break;
		}
	}
	if (!flage)
	{
		cout << "Sorry dear!!! This test value not found in table\n";
	}
}
void Average_ScoreOfEachField(double**& array, int row, int col)
{
	double average = 0.0;
	double sum = 0.0;
	for (int i = 0; i < row; i++)
	{
		average = 0.0; sum = 0.0;
		for (int j = 0; j < col; j++)
		{
			sum = sum + array[i][j];
		}
		average = sum / col;
		if (average > 0)
		{
			cout << "Field " << i + 1 << "average : " << average << endl;
		}
		else
		{
			cout << "Field " << i + 1 << "average : Empty" << endl;
		}
	}
}
void Maximum_SuccessScore(double**& array, int row, int col)
{
	double sum = 0;
	double max = 0;
	int j = 0, r = 0;
	for (int i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			sum = sum + array[i][j];
		}
		if (i == 0 && j == 0)
		{
			max = sum;
		}
		if (sum > max)
		{
			max = sum;
			r = i;
		}
	}
	cout << "Field " << r << " has the maximum success score\n";
}
	void Two_MostFrequentValues(double**& array, int row, int col)
	{

		double most_fr1 = -1, most_fr2 = -1;
		double* arr = new double[row * col];
		int count = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (array[i][j] == -1)
					continue;
				arr[count++] = array[i][j];
			}
		}
		bool* check = new bool[count];
		for (int i = 0; i < count; i++)
		{
			check[i] = 0;
		}

		int max = -1, min = -1;
		for (int i = 0; i < count; i++) 
		{
			if (check[i] == 1) {
				continue;
			}
			int counter = 1;
			for (int j = i + 1; j < count; j++) {
				if (arr[i] == arr[j]) {
					check[j] = 1;
					counter++;
				}
			}
			if (counter > max) {
				min = max;
				max = counter;
				most_fr2 = most_fr1;
				most_fr1 = arr[i];
			}
			else if (counter > min && counter <= max) {
				min = counter;
				most_fr2 = arr[i];
			}

		}

		if (most_fr1 == -1 && most_fr2 == -1)
			cout << "There is no most frequent\n";
		if (most_fr1 != -1)
			cout << "Most Frequent 1 : " << most_fr1 << endl;
		else if (most_fr1 == -1)
			cout << "Most frequent 1 not found\n";
		if (most_fr2 != -1)
			cout << "Most Frequent 2 : " << most_fr2 << endl;
		else if (most_fr2 == -1)
			cout << "Most frequent 2 not found\n";
		delete[] check;
		check = nullptr;
		delete[] arr;
		arr = nullptr;
	}

void write_in_file(double**array,int row,int col)// writing in file...
{
	ofstream fout("Pestcouts.txt");
	fout << row << " " << col << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fout << array[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

int main()
{
	int choice = 0, loop_terminator = 0, row = 0, col = 0;
	double** array = read_file(row, col);
	if (array != nullptr)
	{
		while (loop_terminator == 0)
		{
			Menu();
			cout << "Enter Choice : ";
			cin >> choice;
			if (choice == 1)
			{
				Insert_NewTestValue(array,row,col);
			}
			else if (choice == 2)
			{
				Display_TotalNumberOfResults(array, row, col);
			}
			else if (choice == 3)
			{
				Delete_AnyTestValue(array, row, col);
			}
			else if (choice == 4)
			{
				Two_MostFrequentValues(array, row, col);
			}
			else if (choice == 5)
			{
				Average_ScoreOfEachField(array, row, col);
			}
			else if (choice == 6)
			{
				Maximum_SuccessScore(array, row, col);
			}
			else if (choice == 7)
			{
				write_in_file(array,row,col);
				cout << "Program has been exit successfully\n\n";
				loop_terminator++;
			}
			else
			{
				cout << "Invalid input!!!Try Again\n";
			}

		}
	}
	


	return 0;
}