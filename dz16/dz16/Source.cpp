#include <iostream>
#include <windows.h>
#include <conio.h>



using namespace std;




///-------------------------��������� �������-------------------------

//--------------������ 1--------------
bool CountWords(char *str, int size_str, int index);


//--------------������ 2--------------
void ChangeOnDot(char *str, int size_str);


//--------------������ 3--------------
void CapitalsLetters(char *str, int size_str);




///-------------------------�������-------------------------

//--------------������ 1--------------
//������� ���-�� ���� � ������ 
bool CountWords(char *str, int size_str, int index)
{
	if (*(str + index) != ' ' && *(str + index+1) == ' ' || index == size_str-1)
	{
		if (*(str + index) != ' ' && *(str + index + 1) == ' ')
		{
			bool test = false;
			for (int i = index + 1; i < size_str; i++)
			{
				if (*(str + i) != ' ')
				{
					test = true;
				}
			}
			if (test == false)
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}


//--------------������ 2--------------
//������ ���� �������� �����, ������� ����� ���������� ���� �����, �� �����
void ChangeOnDot(char *str, int size_str)
{
	const char dot = '.';
	for (int i = 0, j = 0; i < size_str; i++)
	{
		if (i == 0 && *(str + i) == ' ')
		{
			continue;
		}
		if (*(str + i) != ' ' && *(str + i - 1) == ' ' || i == 0)
		{
			j = i;
			int size_word = 0;
			for (; *(str + j) != ' ' && j < size_str; j++)
			{
				size_word++;
			}
			size_word += i;
			for (int c = i; c < size_word; c++)
			{
				if (c == size_word - 1)
				{
					break;
				}
				if (*(str + c) == *(str + size_word - 1))
				{
					*(str + c) = dot;
				}
			}
		}
	}
}


//--------------������ 3--------------
//������ ������ ���� ���� �� ���������
void CapitalsLetters(char *str, int size_str)
{
	for (int i = 0; i < size_str; i++)
	{
		if (*(str + i) != ' ' && *(str + i - 1) == ' ' || i == 0)
		{
			if (i == 0 && *(str + i) == ' ')
			{
				continue;
			}
			else if (((int)*(str + i) >= 97 && (int)*(str + i) <= 122 || (int)*(str + i) >= -32 && (int)*(str + i) <= -1) && (*(str + i - 1) == ' ' || i == 0))
			{
					int code = (int)*(str + i);
					code -= 32;
					*(str + i) = (char)code;
			}
			else if ((int)*(str + i) == -72 && *(str + i - 1) == ' ')
			{
				int code = (int)*(str + i);
				code -= 16;
				*(str + i) = (char)code;
			}
		}
	}
}





///-------------------------MAIN-------------------------
void main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int max_size_str = 500;
	int choise = 0;
	do {
		cout << "1 - ������� ���-�� ���� � ������\n";
		cout << "2 - ������ ������ ������ ������, ������� ����� ����� ����������, �� �����\n";
		cout << "3 - ������ ������ ������ ����� ������ ����� �� ���������\n";
		cout << "0 - ����������� ���������� choise 0 � ������� � ����� XD\n\n";
		cout << "��� ����� ������?: ";
		cin >> choise;
		while (cin.fail() || choise < 0 || choise > 3)
		{
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			system("cls");
			cout << "1 - ������� ���-�� ���� � ������\n";
			cout << "2 - ������ ������ ������ ������, ������� ����� ����� ����������, �� �����\n";
			cout << "3 - ������ ������ ����� ������ ����� �� ���������\n";
			cout << "0 - ����������� ���������� choise 0 � ������� � ����� XD\n\n";
			if (choise > 0 || choise > 3)
			{
				cout << "������ ������� ���... ����� ������� ������ �������?: ";
			}
			else
			{
				cout << "������������ ������� �����!!! �����, ����������: ";

			}
			cin >> choise;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		switch (choise)
		{
		case 0: 
		{
			system("cls");
			cout << "��������� ����.";
			Sleep(600);
			system("cls");
			cout << "��������� ����..";
			Sleep(600);
			system("cls");
			cout << "��������� ����...";
			Sleep(600);
			system("cls");
			cout << "��������� ����.";
			Sleep(600);
			system("cls");
			cout << "��������� ����..";
			Sleep(600);
			system("cls");
		}
		break;
		//==========================������ 1==========================
		case 1:
		{
			system("cls");
			char *str = new char[max_size_str];
			cout << "������� ���� ������ (����� � ����������): ";
			cin.get();
			gets_s(str, max_size_str);
			int str_size = strlen(str);
			system("cls");
			int quantity_words = 0;
			for (int i = 0; i < str_size; i++)
			{
				bool test = CountWords(str, str_size, i);
				if (test)
				{
					quantity_words++;
				}
			}
			cout << "���� ������� - " << str << endl;
			cout << "���-�� ���� � ������ - " << quantity_words << endl;
			delete[] str;
			str = nullptr;
			cout << "\n��� �������� ���� �����";
			_getch();
			system("cls");
		}
		break;
		//==========================������ 2==========================
		case 2:
		{
			system("cls");
			char *str = new char[max_size_str];
			cout << "������� ���� ������ (����� � ����������): ";
			cin.get();
			gets_s(str, max_size_str);
			int str_size = strlen(str);
			system("cls");
			cout << "���� ������ - " << str<<endl;
			ChangeOnDot(str, str_size);
			cout << "����� ������ - " << str << endl;
			delete[] str;
			str = nullptr;
			cout << "\n��� �������� ���� �����";
			_getch();
			system("cls");
		}
		break;
		//==========================������ 3==========================
		case 3:
		{
			system("cls");
			char *str = new char[max_size_str];
			cout << "������� ���� ������ (����� � ����������): ";
			cin.get();
			gets_s(str, max_size_str);
			int str_size = strlen(str);
			system("cls");
			cout << "���� ������ - " << str << endl;
			CapitalsLetters(str, str_size);
			cout << "����� ������ - " << str << endl;
			delete[] str;
			str = nullptr;
			cout << "\n��� �������� ���� �����";
			_getch();
			system("cls");
		}
		break;
		}
	} while (choise != 0);
}