#include "Klient.h"
#include "Menu.h"

#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SEQURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;
void metod();

int  main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData) != 0) {
		cout << "������!" << endl;
		exit(1);
	}
	struct sockaddr_in peer;
	int sizeofpeer = sizeof(peer);
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	peer.sin_addr.s_addr = inet_addr("127.0.0.1");

	SOCKET s = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(s, (sockaddr*)&peer, sizeof(peer)) != 0) {
		cout << "������ �����������!\n" << endl;
		system("pause");
		return 1;
	}
	cout << "����������� ���������!\n" << endl;
	Sleep(2000);

	system("cls");

	int flag = 1, cheal = 0, ch;
	char  txt[] = ".txt";
	string st, buf;
	menu m;

	char jenia[] = "2";

	char s1[256], s2[256], b1[16384], log[] = " ", z[16384], fore[] = "4", five[] = "5", tx[5];
	int err = 0, gr, kkal;
	float price;
	while (1)
	{

		cout << "    ���� �����������    " << endl;
		m.stmenu();
		switch (m.meny())
		{
		case 1:
			strcpy(s1, "1");
			send(s, s1, sizeof(s1), NULL);
			cout << "������� �����" << endl;
			cin >> s1;
			cout << "������� ������" << endl;
			cin >> b1;
			strcat(s1, log);
			strcat(s1, b1);
			cout << s1 << endl;
			send(s, s1, sizeof(s1), NULL);
			recv(s, b1, sizeof(b1), NULL);
			flag = atoi(b1);
			system("cls");
			while (flag)
			{
				cout << "    ���� ��������������    " << endl;
				m.adminmenu();
				switch (m.meny())
				{
				case 1:
					system("cls");
					strcpy(s1, "1");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					cout << "��������: ";
					cin >> st;
					buf = st + " ";
					while (1) {
						cout << "����: ";
						cin >> price;
						if (cin.good()) {
							break;
						}
						cin.clear();
						cout << "������������ ���� ������!" << endl;
						cin.ignore(10, '\n');
					}
					st = to_string(price);
					buf = buf + st + " ";
					while (1) {
						cout << "���������: ";
						cin >> gr;
						if (cin.good()) {
							break;
						}
						cin.clear();
						cout << "������������ ���� ������!" << endl;
						cin.ignore(10, '\n');
					}
					st = to_string(gr);
					buf = buf + st + " ";
					while (1) {
						cout << "�������: ";
						cin >> kkal;
						if (cin.good()) {
							break;
						}
						cin.clear();
						cout << "������������ ���� ������!" << endl;
						cin.ignore(10, '\n');
					}
					st = to_string(kkal);
					buf = buf + st + " ";
				
						cout << "�������: ";
						cin >> st;
							buf = buf + st + " ";
							strcpy(z, buf.c_str());
							send(s, z, sizeof(z), NULL);
						
					system("pause");
					system("cls");
					break;
				case 2:
					system("cls");
					strcpy(s1, "2");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					int asd;
					char tx[5];
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "    ������ �������    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							cout << "����� �" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "��������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "���������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							cout << "\n";
						}
					}
					else cout << "������ ������� ����!" << endl;
					system("pause"); 
					system("cls");
					break;

				case 3:
					strcpy(s1, "3");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "   ������� ������� �������   " << endl;
						for (int i = 0; i < asd - 1; i++) {
							recv(s, b1, sizeof(b1), NULL);
							cout << "������������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������� ������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "����: " << b1 << endl;
							cout << "\n";
						}
						cout << "������������ ����� � �����?(��/���)" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "��" || (string)tx == "��" || (string)tx == "��") {
							strcpy(tx, "1");
							send(s, tx, sizeof(tx), NULL);
							cout << "����� ����������� � �����: �����(�������).txt" << endl;
						}
						else {
							strcpy(tx, "0");
							send(s, tx, sizeof(tx), NULL);
						}
					}
					else cout << "������� ������� �����!" << endl;
					system("pause"); 
					system("cls");
					break;
				case 4:
					strcpy(s1, "4");
					send(s, s1, sizeof(s1), NULL);
					
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "    ������ �������    " << endl;

						for (int i = 0; i < asd - 1; i++) {
							cout << "����� �" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "��������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "���������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							cout << "\n";
						}
						cout << "������� ������� ������, ������� ������ �������" << endl;
						cin >> st;
						strcpy(b1, st.c_str());
						send(s, b1, sizeof(b1), NULL);
						recv(s, b1, sizeof(b1), NULL);
						if (atoi(b1) == 1) {
							cout << "������ �������" << endl;
						}
						else cout << "������������ ���� ������!" << endl;
					}
					else cout << "������ ������� ����!" << endl;
					break;
				case 5:
					send(s, five, sizeof(five), NULL);
					system("cls");
					cout << "������� �������� ��� ������� ��� ������" << endl;
					cin >> b1;
					system("cls");
					send(s, b1, sizeof(b1), NULL);
					cout << "�� ������ �������: " << b1 << endl;
					recv(s, s1, sizeof(s1), NULL);
					if (atoi(s1) == 1) {
						cout << "���������� � ������\n" << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "��������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "����: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "���������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
					}
					else cout << "������ �� �������.";
					cout << "\n";
					system("pause"); 
					system("cls");
					break;
				case 6:
					strcpy(s1, "6");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					cout << "������ ������������� �� ��������\n" << endl;
					system("pause"); 
					system("cls");
					break;
				case 7:
					strcpy(s1, "7");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "    ������� �����������    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							recv(s, b1, sizeof(b1), NULL);
							cout << "������������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "���: " << b1 << endl;
							cout << "\n";
						}
						cout << "������������ ����� � �����?(��/���)" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "��" || (string)tx == "��" || (string)tx == "��") {
							strcpy(tx, "1");
							send(s, tx, sizeof(tx), NULL);
							cout << "����� ����������� � �����: �����(����������).txt" << endl;
						}
						else {
							strcpy(tx, "0");
							send(s, tx, sizeof(tx), NULL);
						}
					}
					else cout << "������� ������� �����!" << endl;
					system("pause");
					system("cls");
					break;
				case 8:
					strcpy(s1, "8");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "    ������ �������    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							cout << "����� �" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "��������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "���������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							cout << "\n";
						}
						int ch1;
						cout << "������� ����� ������, ������ � ������� ����� ���������������." << endl;
						while (1) {
							cin >> ch1;
							if (cin.good()) {
								if (ch1 < asd && ch1 > 0) {
									break;
								}
							}
							cin.clear();
							cout << "������������ ���� ������!" << endl;
							cin.ignore(10, '\n');
						}
						itoa(ch1, b1, 10);
						send(s, b1, sizeof(b1), NULL);
						system("cls");
						recv(s, b1, sizeof(b1), NULL);
						cout << "��������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "����: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "���������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
						cout << "\n";
						cout << "��������, ��� ����� ���������������." << endl;
						m.redmenu();
						switch (m.meny()) {
						case 1:
							strcpy(s1, "1");
							send(s, s1, sizeof(s1), NULL);
							cout << "������� ����� ��������" << endl;
							cin >> b1;
							send(s, b1, sizeof(b1), NULL);
							cout << "�������� ������� ��������!" << endl;
							break;
						case 2:
							strcpy(s1, "2");
							send(s, s1, sizeof(s1), NULL);
							while (1) {
							    cout << "������� ���e� ����" << endl;
								cin >> price;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "������������ ���� ������!" << endl;
								cin.ignore(10, '\n');
							}
							st = to_string(price);
							strcpy(b1, st.c_str());
							send(s, b1, sizeof(b1), NULL);
							cout << "���� ������� ��������!" << endl;
							break;
						case 3:
							strcpy(s1, "3");
							send(s, s1, sizeof(s1), NULL);
							while (1) {
								cout << "������� ����� ���������" << endl;
								cin >> gr;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "������������ ���� ������!" << endl;
								cin.ignore(10, '\n');
							}
							itoa(gr, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							cout << "��������� ������� ��������!" << endl;
							break;
						case 4:
							strcpy(s1, "4");
							send(s, s1, sizeof(s1), NULL);
							while (1) {
								cout << "������� ����� �������" << endl;
								cin >> kkal;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "������������ ���� ������!" << endl;
								cin.ignore(10, '\n');
							}
							itoa(kkal, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							cout << "������� ������� ��������!" << endl;
							break;
						case 5:
							strcpy(s1, "5");
							send(s, s1, sizeof(s1), NULL);
							cout << "������� ����� �������" << endl;
							cin >> b1;
							send(s, b1, sizeof(b1), NULL);
							cout << "������� ������� �������!" << endl;
							break;
						default: cout << "������� �������� ��������!";
							break;
						}
					}
					else cout << "������ ������� ����!" << endl;
					system("pause"); 
					system("cls");
					break;
				case 9:
					strcpy(s1, "9");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					cout << "���������� ������� �� ������������" << endl;
					m.trainermenu();
					switch (m.meny()) {

					case 1: 
						int age;
						system("cls");
						strcpy(s1, "1");
						send(s, s1, sizeof(s1), NULL);
						system("cls");
						cout << "�������: ";
						cin >> st;
						buf = st + " ";
						cout << "���: ";
						cin >> st;
						buf = buf + st + " ";
						while (1) {
							cout << "�������: ";
							cin >> age;
							if (cin.good()) {
								break;
							}
							cin.clear();
							cout << "������������ ���� ������!" << endl;
							cin.ignore(10, '\n');
						}
						st = to_string(age);
						buf = buf + st + " ";
						strcpy(z, buf.c_str());
						send(s, z, sizeof(z), NULL);
						system("pause");
						system("cls");
						break;

					case 2:
						send(s, jenia, sizeof(jenia), NULL);
						system("cls");
						int asd;
						char tx[5];
						recv(s, tx, sizeof(tx), NULL);
						asd = atoi(tx);
						if ((asd - 1) != 0) {
							cout << "    ������ �� ������������    " << endl;
							for (int i = 0; i < asd - 1; i++) {
								cout << "�" << i + 1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "�������: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "���: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "�������: " << b1 << endl;
								cout << "\n";
							}
						}
						else cout << "������ ������ ����!" << endl;
						system("pause");
						system("cls");
						break;

					case 3:
						strcpy(s1, "3");
						send(s, s1, sizeof(s1), NULL);
						recv(s, tx, sizeof(tx), NULL);
						asd = atoi(tx);
						if ((asd - 1) != 0) {
							cout << "    ������ �� ������������    " << endl;
							for (int i = 0; i < asd - 1; i++) {
								cout << "�" << i + 1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "�������: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "���: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "�������: " << b1 << endl;
								cout << "\n";
							}
							cout << "������� �a����� �����������, ������ � ������� ������ �������" << endl;
							cin >> st;
							strcpy(b1, st.c_str());
							send(s, b1, sizeof(b1), NULL);
							recv(s, b1, sizeof(b1), NULL);
							if (atoi(b1) == 1) {
								cout << "������ �������!" << endl;
							}
							else cout << "������������ ���� ������!" << endl;
						}
						else cout << "������ ������ ����!" << endl;
						break;
					}
					break;
				case 10: 
					strcpy(s1, "10");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					metod();
					break;
				case 11:
					strcpy(s1, "11");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					recv(s, tx, sizeof(tx), NULL);
					if ((atoi(b1)) != 0) {
						cout << "����� �� ������� �������������� ������� ����������� � �����: �����(���. �������)" << endl;
					}
					else cout << "��� �� ���� ����� �������������� �������" << endl;
					system("pause");
					system("cls");
					break;
				case 12:
					strcpy(s1, "12");
					send(s, s1, sizeof(s1), NULL);
					flag = 0;
					break;
				default: cout << "������� ������ ��������!" << endl; break;
				}
			}
			break;
		case 2:
			strcpy(s1, "2");
			send(s, s1, sizeof(s1), NULL);
			cout << "������� �����" << endl;
			cin >> s1;
			strcpy(s2, s1);
			cout << "������� ������" << endl;
			cin >> b1;
			strcat(s1, log);
			strcat(s1, b1);
			send(s, s1, sizeof(s1), NULL);
			send(s, s2, sizeof(s2), NULL);
			recv(s, b1, sizeof(b1), NULL);
			flag = atoi(b1);
			system("cls");
			while (flag)
			{
				m.Klientmenu();
				switch (m.meny())
				{
				case 1:
					strcpy(s1, "1");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					int asd;
					char tx[5];
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "    ������ �������    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							cout << "����� �" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "��������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "���������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							cout << "\n";
						}
					}
					else cout << "������ ������� ����!" << endl;
					system("pause");
					system("cls");
					break;

				case 2:
					strcpy(s1, "2");
					send(s, s1, sizeof(s1), NULL);
					recv(s, tx, sizeof(tx), NULL);
					int chch;
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "    ������ �������    " << endl;

						for (int i = 0; i < asd - 1; i++) {
							cout << "����� �" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "��������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "����: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "���������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "�������: " << b1 << endl;
							cout << "\n";
						}
						cout << "������� ����� ������, ������� �� ������ ���������" << endl;
						while (1) {
							cin >> chch;
							if (cin.good()) {
								if (chch < asd && chch > 0) {
									break;
								}
							}
							cin.clear();
							cout << "������������ ���� ������!" << endl;
							cin.ignore(10, '\n');
						}
						itoa(chch, s1, 10);
						send(s, s1, sizeof(s1), NULL);
						system("pause");
						system("cls");
						cout << "   ��� �����   " << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "��������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						strcpy(s1, b1);
						cout << "����: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "���������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
						cout << "\n";
						cout << "� ��� " << s1 << " BYN." << endl;
						system("pause");
						system("cls");
						cout << "������� �� �������!" << endl;
					}
					else cout << "������ ������� ����!" << endl;
					system("pause");
					system("cls");
					break;
				case 3:
					strcpy(s1, "3");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					while (1) {
						cout << "��������� ���������� �� ��� 230 BYN" << endl;
						cout << "������� ����������?(��/���)" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "��" || (string)tx == "��" || (string)tx == "��") {
							system("cls");
							cout << "� ��� 230 BYN." << endl;
							system("pause");
							system("cls");
							cout << "������� �� �������!" << endl;
							send(s, s1, sizeof(s1), NULL);
							break;
						}
						else {
							
							system("pause");
							system("cls");
							break;
						}
					}
					system("pause");
					system("cls");
					break;
				case 4:
					send(s, fore, sizeof(fore), NULL);
					system("cls");
					cout << "������ ������������� �� ��������\n" << endl;
					system("pause");
					system("cls");
					break;
				case 5:
					send(s, five, sizeof(five), NULL);
					system("cls");
					cout << "������� �������� ��� ������� ��� ������" << endl;
					cin >> b1;
					system("cls");
					send(s, b1, sizeof(b1), NULL);
					cout << "�� ������ �������: " << b1 << endl;
					recv(s, s1, sizeof(s1), NULL);
					if (atoi(s1) == 1) {
						cout << "���������� � ������\n" << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "��������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "����: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "���������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "�������: " << b1 << endl;
					}
					else cout << "������ �� �������.";
					cout << "\n";
					system("pause");
					system("cls");
					break;
				case 6:
					int kol;
					strcpy(s1, "6");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "��������� ������ ��������������� ������� � �������� - 50 BYN." << endl;
						cout << "������� ��������?" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "��" || (string)tx == "��" || (string)tx == "��") {
							strcpy(tx, "1");
							send(s, tx, sizeof(tx), NULL);
							system("cls");
							while (1) {
								cout << "������� ���-�� �������� �������������� �������" << endl;
								cin >> kol;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "������������ ���� ������!" << endl;
								cin.ignore(10, '\n');
							}
							cout << "�������� ������� ��� �������(������� �����)" << endl;
							for (int i = 0; i < asd - 1; i++) {
								cout << "�" << i + 1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "�������: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "���: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "�������: " << b1 << endl;
								cout << "\n";
							}
							cin >> chch;
							itoa(chch, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							system("pause");
							system("cls");
							recv(s, b1, sizeof(b1), NULL);
							recv(s, s1, sizeof(s1), NULL);
							cout << "����: " << kol << " �������(-�), ������ - " << b1 << " " << s1 << "." << endl;
							cout << "���������: " << kol * 50 << " BYN" << endl;
							itoa(kol, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							itoa(kol * 50, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							system("pause");
							system("cls");
							cout << "�������!" << endl;
							
						}
						else {
							strcpy(tx, "0");
							send(s, tx, sizeof(tx), NULL);
						}
					}
					else cout << "� ���������, ������ ��� ������� ��� �������������� �������." << endl;
					system("pause");
					system("cls");
					break;
				case 7:
					strcpy(s1, "7");
					send(s, s1, sizeof(s1), NULL);
					flag = 0;
					break;
				}
			}
			break;
		case 3:
			system("cls");
			strcpy(s1, "3");
			send(s, s1, sizeof(s1), NULL);
			cout << "������� �����" << endl;
			cin >> st;
			buf = st + " ";
			cout << "������� ������" << endl;
			cin >> st;
			buf = buf + st;
			strcpy(s1, buf.c_str());
			send(s, s1, sizeof(s1), NULL);
			recv(s, b1, sizeof(b1), NULL);

			if (atoi(b1) == 1) {
				cout << "����������� ������ �������!\n";
				system("pause"); 
				system("cls");
			}
			else {
				cout << "����� ��������� ������ ��� ������ ��� ����" << endl; 
				system("pause"); 
				system("cls");
			}

			break;
		case 4:
			strcpy(s1, "4");
			send(s, s1, sizeof(s1), NULL);
			break;
		}if (atoi(s1) == 4)
			break;

	}
	closesocket(s);
	WSACleanup();
	return 0;
}

void metod() {
	float swim1, spa1, yoga1, pil1, swim2, spa2, yoga2, pil2, swim3, spa3, yoga3, pil3;
	cout << "�� ������ �������� ����� ������ � ������-������, ������� �� ���������: �������, SPA-��������,"
		"���� � �������. ������� ��������, ������� ��������� ������� ������ ������ ��� ������������� �������� �"
		"������ ��� ��������������� ��������. �� ������ �������� ����� ������� ���������, ����� ������ ����� ��������." << endl;
	cout << "\n������� ������� ��������: ";
	cin >> swim1;
	cout << "\n������� ������ ��������: ";
	cin >> swim2;
	swim3 = (swim1 - swim2) * 0.5;
	cout << "\n������� ������� SPA-���������: ";
	cin >> spa1;
	cout << "\n������� ������ SPA-���������: ";
	cin >> spa2;
	spa3 = (spa1 - spa2) * 0.5;
	cout << "\n������� ������� ����: ";
	cin >> yoga1;
	cout << "\n������� ������ ����: ";
	cin >> yoga2;
	yoga3 = (yoga1 - yoga2) * 0.5;
	cout << "\n������� ������� ��������: ";
	cin >> pil1;
	cout << "\n������� ������ ��������: ";
	cin >> pil2;
	pil3 = (pil1 - pil2) * 0.5;
	cout << "����������� ��� �������������, ��� � ��������������� ������� ����� 0,5.";
	cout << "\n�������������, ������� ��������� ������� ��� �������� ����� " << swim3 << ", ��� SPA-��������� - " << spa3 << ", ��� ���� - " << yoga3 << ", ��� �������� - " << pil3 << endl;
	if (swim3 > spa3 && swim3 > yoga3 && swim3 > pil3) {
		cout << "�������� ������������� ������� ������: �������." << endl;
	}
	else if (spa3 > swim3 && spa3 > yoga3 && spa3 > pil3) {
		cout << "�������� ������������� ������� ������: SPA-��������." << endl;
	}
	else if (yoga3 > swim3 && yoga3 > spa3 && yoga3 > pil3) {
		cout << "�������� ������������� ������� ������: ����." << endl;
	}
	else {
		cout << "�������� ������������� ������� ������: �������." << endl;
	}
}