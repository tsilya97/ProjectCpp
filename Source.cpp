#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;
//#include <stdafx.h>
int key=0;
//char mem[255];
vector <string> memory;
void decryption();

void print() {
	ifstream fin;
	fin.open("text.txt");
	if (!fin.is_open()) // если файл небыл открыт
	{
		cout << "‘айл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		 // выполнить выход из программы
	}
	string buff;
	while (!getline(fin, buff).eof()) {
		cout << buff << endl;
	}
	fin.close();
}
void encryption(bool crypt) {
	if (crypt) {
	cout << "¬ведите ключ";
	cin >> key;
	decryption();
	} 
	else{
		key = -key;
		decryption();
	}
	
	
}
void decryption() {
	ifstream fin;
	fin.open("text.txt");
	ofstream fout;
	
	if (!fin.is_open()) // если файл небыл открыт
	{
		cout << "‘айл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		 // выполнить выход из программы
	}
	string buff;

	while (!getline(fin, buff).eof()) {

		for (int i = 0;i < (buff.length());i++) {

			buff[i] += key;
			
		}
		buff += '\n';

		memory.push_back(buff); // запись строки в вектор
	}
	fout.open("text.txt");
	fin.close();
	for (int i = 0;i < memory.size();i++) {
		
		fout << memory[i]; // запись строки в файл

	}
	memory.clear();
	fout.close(); // закрываем файл
}
void selected() {
	
	int s = 1;
	while (s!=0) {
		cout << "Enter choice:\n 1-Print file \n 2-encryption \n 3-decryption \n 4-exit \n";
		cin >> s;
		switch (s)
		{
		case 1:
			print();
			break;
		case 2:
			encryption(1);
			break;
		case 3:
			encryption(0);
			break;
		case 4:
			s = 0;
			break;

		default:
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	selected();
	
}