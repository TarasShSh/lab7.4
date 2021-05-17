// ����������-�����������
// ������ 23
// ��-11 �������� �����
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <Windows.h> // ��������� ��������, ��� ��������� ����������� ��������
using namespace std;
struct Contacts
{
	string surname, name, number;
	int bdate[3];
};
void add(map<int, Contacts>& c)
{
	int pos = c.size();
		int tmp2;
	Contacts tmp;
	cout << "������� ��������: ";
	cin >> tmp.surname;
	cout << "��� ��������: ";
	cin >> tmp.name;
	cout << "����� ��������: ";
	cin >> tmp.number;
	cout << "���� ����������: ";
	do
	{
		cin >> tmp2;
	} while (tmp2 < 1 || tmp2 > 31);
	tmp.bdate[0] = tmp2;
	cout << "̳���� ����������: ";
	do
	{
		cin >> tmp2;
	} while (tmp2 < 1 || tmp2 > 12);
	tmp.bdate[1] = tmp2;
	cout << "г� ����������: ";
	do
	{
		cin >> tmp2;
	} while (tmp2 < 1 || tmp2 > 2003);
	tmp.bdate[2] = tmp2;
	c.insert({ pos, tmp });
}
void display(map<int, Contacts> c)
{
	for (int i = 0; i < c.size(); i++)
	{
		cout << "������� ��������: " << c[i].surname << endl;
		cout << "��� ��������: " << c[i].name << endl;
		cout << "����� ��������: " << c[i].number << endl;
		cout << "���� ����������: " << c[i].bdate[0] << endl;
		cout << "̳���� ����������: " << c[i].bdate[1] << endl;
		cout << "г� ����������: " << c[i].bdate[2] << endl;
	}
}
void display(map<int, Contacts> c, int j)
{
	for (int i = j; i < c.size(); i++)
	{
		cout << "������� ��������: " << c[i].surname << endl;
		cout << "��� ��������: " << c[i].name << endl;
		cout << "����� ��������: " << c[i].number << endl;
		cout << "���� ����������: " << c[i].bdate[0] << endl;
		cout << "̳���� ����������: " << c[i].bdate[1] << endl;
		cout << "г� ����������: " << c[i].bdate[2] << endl;
	}
}
bool display(map<int, Contacts> c, int d, int m, int y)
{
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i].bdate[0] == d && 
			c[i].bdate[1] == m && 
			c[i].bdate[2] == y)
		{
			display(c, i);
			return true;
		}
		else
		{
			cout << "�������� � ����� ����� ���������� �� ��������." << endl;
			return false;
		}
	}
}
void sort(map<int, Contacts>& c)
{
	for (int i = 0; i < c.size() - 1; i++)
		for (int j = i; j < c.size(); j++)
		{
			if (c[i].bdate[0] == c[j].bdate[0] && 
				c[i].bdate[1] == c[j].bdate[1] && 
				c[i].bdate[2] == c[j].bdate[2] )
			{
				Contacts tmp;
				tmp = c[i];
				c.erase(i);
				c.insert({ i, c[j] });
				c.erase(j);
				c.insert({ j, tmp });
			}
		}
}
int main()
{
	// ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������ ������� win-cp1251
	// (��������) � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������ ������� win-cp1251
	// (��������) � ���� ������
	map<int, Contacts> contact;
	int tmp2, tmp3, tmp4, tmp5;
	do
	{
		cout << "[1] ������ �������" << endl;
		cout << "[2] ������� �������� �� ��� ����������" << endl;
		cout << "[0] �����" << endl;
		do
		{
			cin >> tmp2;
		} while (tmp2 < 0 || tmp2 > 2);
		switch (tmp2)
		{
		case 1:
			add(contact);
			sort(contact);
			break;
		case 2:
			cout << "���� ����������: ";
			do
			{
				cin >> tmp3;
			} while (tmp3 < 1 || tmp3 > 31);
			cout << "̳���� ����������: ";
			do
			{
				cin >> tmp4;
			} while (tmp4 < 1 || tmp4 > 12);
			cout << "г� ����������: ";
			do
			{
				cin >> tmp5;
			} while (tmp5 < 1 || tmp5 > 2003);
			display(contact, tmp3, tmp4, tmp5);
			break;
		default:
			break;
		}
	} while (tmp2 != 0);
	return 0;
}
