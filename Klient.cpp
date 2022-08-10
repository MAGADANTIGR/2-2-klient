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
		cout << "Ошибка!" << endl;
		exit(1);
	}
	struct sockaddr_in peer;
	int sizeofpeer = sizeof(peer);
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	peer.sin_addr.s_addr = inet_addr("127.0.0.1");

	SOCKET s = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(s, (sockaddr*)&peer, sizeof(peer)) != 0) {
		cout << "Ошибка подключения!\n" << endl;
		system("pause");
		return 1;
	}
	cout << "Подключение выполнено!\n" << endl;
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

		cout << "    Меню авторизации    " << endl;
		m.stmenu();
		switch (m.meny())
		{
		case 1:
			strcpy(s1, "1");
			send(s, s1, sizeof(s1), NULL);
			cout << "Введите логин" << endl;
			cin >> s1;
			cout << "Введите пароль" << endl;
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
				cout << "    Меню администратора    " << endl;
				m.adminmenu();
				switch (m.meny())
				{
				case 1:
					system("cls");
					strcpy(s1, "1");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					cout << "Название: ";
					cin >> st;
					buf = st + " ";
					while (1) {
						cout << "Цена: ";
						cin >> price;
						if (cin.good()) {
							break;
						}
						cin.clear();
						cout << "Неправильный ввод данных!" << endl;
						cin.ignore(10, '\n');
					}
					st = to_string(price);
					buf = buf + st + " ";
					while (1) {
						cout << "Граммовка: ";
						cin >> gr;
						if (cin.good()) {
							break;
						}
						cin.clear();
						cout << "Неправильный ввод данных!" << endl;
						cin.ignore(10, '\n');
					}
					st = to_string(gr);
					buf = buf + st + " ";
					while (1) {
						cout << "Калории: ";
						cin >> kkal;
						if (cin.good()) {
							break;
						}
						cin.clear();
						cout << "Неправильный ввод данных!" << endl;
						cin.ignore(10, '\n');
					}
					st = to_string(kkal);
					buf = buf + st + " ";
				
						cout << "Артикул: ";
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
						cout << "    Список товаров    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							cout << "Товар №" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Название: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Цена: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Граммовка: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Калории: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Артикул: " << b1 << endl;
							cout << "\n";
						}
					}
					else cout << "Список товаров пуст!" << endl;
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
						cout << "   История покупок товаров   " << endl;
						for (int i = 0; i < asd - 1; i++) {
							recv(s, b1, sizeof(b1), NULL);
							cout << "Пользователь: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Название товара: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Цена: " << b1 << endl;
							cout << "\n";
						}
						cout << "Сформировать отчет в файле?(Да/Нет)" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "Да" || (string)tx == "да" || (string)tx == "ДА") {
							strcpy(tx, "1");
							send(s, tx, sizeof(tx), NULL);
							cout << "Отчет сформирован в файле: Отчет(покупки).txt" << endl;
						}
						else {
							strcpy(tx, "0");
							send(s, tx, sizeof(tx), NULL);
						}
					}
					else cout << "История покупок пуста!" << endl;
					system("pause"); 
					system("cls");
					break;
				case 4:
					strcpy(s1, "4");
					send(s, s1, sizeof(s1), NULL);
					
					recv(s, tx, sizeof(tx), NULL);
					asd = atoi(tx);
					if ((asd - 1) != 0) {
						cout << "    Список товаров    " << endl;

						for (int i = 0; i < asd - 1; i++) {
							cout << "Товар №" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Название: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Цена: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Граммовка: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Калории: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Артикул: " << b1 << endl;
							cout << "\n";
						}
						cout << "Введите артикул товара, который хотите удалить" << endl;
						cin >> st;
						strcpy(b1, st.c_str());
						send(s, b1, sizeof(b1), NULL);
						recv(s, b1, sizeof(b1), NULL);
						if (atoi(b1) == 1) {
							cout << "Данные удалены" << endl;
						}
						else cout << "Неправильный ввод данных!" << endl;
					}
					else cout << "Список товаров пуст!" << endl;
					break;
				case 5:
					send(s, five, sizeof(five), NULL);
					system("cls");
					cout << "Введите название или артикул для поиска" << endl;
					cin >> b1;
					system("cls");
					send(s, b1, sizeof(b1), NULL);
					cout << "По вашему запросу: " << b1 << endl;
					recv(s, s1, sizeof(s1), NULL);
					if (atoi(s1) == 1) {
						cout << "Информация о товаре\n" << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Название: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Цена: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Граммовка: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Калории: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Артикул: " << b1 << endl;
					}
					else cout << "Ничего не найдено.";
					cout << "\n";
					system("pause"); 
					system("cls");
					break;
				case 6:
					strcpy(s1, "6");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					cout << "Данные отсортированы по алфавиту\n" << endl;
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
						cout << "    Покупки абонементов    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							recv(s, b1, sizeof(b1), NULL);
							cout << "Пользователь: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "День: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Месяц: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Число: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Время: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Год: " << b1 << endl;
							cout << "\n";
						}
						cout << "Сформировать отчет в файле?(Да/Нет)" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "Да" || (string)tx == "да" || (string)tx == "ДА") {
							strcpy(tx, "1");
							send(s, tx, sizeof(tx), NULL);
							cout << "Отчет сформирован в файле: Отчет(абонементы).txt" << endl;
						}
						else {
							strcpy(tx, "0");
							send(s, tx, sizeof(tx), NULL);
						}
					}
					else cout << "История покупок пуста!" << endl;
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
						cout << "    Список товаров    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							cout << "Товар №" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Название: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Цена: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Граммовка: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Калории: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Артикул: " << b1 << endl;
							cout << "\n";
						}
						int ch1;
						cout << "Введите номер товара, данные о котором нужно отредактировать." << endl;
						while (1) {
							cin >> ch1;
							if (cin.good()) {
								if (ch1 < asd && ch1 > 0) {
									break;
								}
							}
							cin.clear();
							cout << "Неправильный ввод данных!" << endl;
							cin.ignore(10, '\n');
						}
						itoa(ch1, b1, 10);
						send(s, b1, sizeof(b1), NULL);
						system("cls");
						recv(s, b1, sizeof(b1), NULL);
						cout << "Название: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Цена: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Граммовка: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Калории: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Артикул: " << b1 << endl;
						cout << "\n";
						cout << "Выберите, что нужно отредактировать." << endl;
						m.redmenu();
						switch (m.meny()) {
						case 1:
							strcpy(s1, "1");
							send(s, s1, sizeof(s1), NULL);
							cout << "Введите новое название" << endl;
							cin >> b1;
							send(s, b1, sizeof(b1), NULL);
							cout << "Название успешно изменено!" << endl;
							break;
						case 2:
							strcpy(s1, "2");
							send(s, s1, sizeof(s1), NULL);
							while (1) {
							    cout << "Введите новeю цену" << endl;
								cin >> price;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "Неправильный ввод данных!" << endl;
								cin.ignore(10, '\n');
							}
							st = to_string(price);
							strcpy(b1, st.c_str());
							send(s, b1, sizeof(b1), NULL);
							cout << "Цена успешно изменена!" << endl;
							break;
						case 3:
							strcpy(s1, "3");
							send(s, s1, sizeof(s1), NULL);
							while (1) {
								cout << "Введите новое граммовку" << endl;
								cin >> gr;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "Неправильный ввод данных!" << endl;
								cin.ignore(10, '\n');
							}
							itoa(gr, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							cout << "Граммовка успешно изменена!" << endl;
							break;
						case 4:
							strcpy(s1, "4");
							send(s, s1, sizeof(s1), NULL);
							while (1) {
								cout << "Введите новые калории" << endl;
								cin >> kkal;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "Неправильный ввод данных!" << endl;
								cin.ignore(10, '\n');
							}
							itoa(kkal, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							cout << "Калории успешно изменены!" << endl;
							break;
						case 5:
							strcpy(s1, "5");
							send(s, s1, sizeof(s1), NULL);
							cout << "Введите новый артикул" << endl;
							cin >> b1;
							send(s, b1, sizeof(b1), NULL);
							cout << "Артикул успешно изменен!" << endl;
							break;
						default: cout << "Введено неверное значение!";
							break;
						}
					}
					else cout << "Список товаров пуст!" << endl;
					system("pause"); 
					system("cls");
					break;
				case 9:
					strcpy(s1, "9");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					cout << "Управление данными об инструкторах" << endl;
					m.trainermenu();
					switch (m.meny()) {

					case 1: 
						int age;
						system("cls");
						strcpy(s1, "1");
						send(s, s1, sizeof(s1), NULL);
						system("cls");
						cout << "Фамилия: ";
						cin >> st;
						buf = st + " ";
						cout << "Имя: ";
						cin >> st;
						buf = buf + st + " ";
						while (1) {
							cout << "Возраст: ";
							cin >> age;
							if (cin.good()) {
								break;
							}
							cin.clear();
							cout << "Неправильный ввод данных!" << endl;
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
							cout << "    Данные об инструкторах    " << endl;
							for (int i = 0; i < asd - 1; i++) {
								cout << "№" << i + 1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Фамилия: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Имя: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Возраст: " << b1 << endl;
								cout << "\n";
							}
						}
						else cout << "Список данных пуст!" << endl;
						system("pause");
						system("cls");
						break;

					case 3:
						strcpy(s1, "3");
						send(s, s1, sizeof(s1), NULL);
						recv(s, tx, sizeof(tx), NULL);
						asd = atoi(tx);
						if ((asd - 1) != 0) {
							cout << "    Данные об инструкторах    " << endl;
							for (int i = 0; i < asd - 1; i++) {
								cout << "№" << i + 1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Фамилия: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Имя: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Возраст: " << b1 << endl;
								cout << "\n";
							}
							cout << "Введите фaмилию инструктора, данные о котором хотите удалить" << endl;
							cin >> st;
							strcpy(b1, st.c_str());
							send(s, b1, sizeof(b1), NULL);
							recv(s, b1, sizeof(b1), NULL);
							if (atoi(b1) == 1) {
								cout << "Данные удалены!" << endl;
							}
							else cout << "Неправильный ввод данных!" << endl;
						}
						else cout << "Список данных пуст!" << endl;
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
						cout << "Отчет об оплатах индивидуальных занятий сформирован в файле: Отчет(инд. занятия)" << endl;
					}
					else cout << "Еще не было оплат индивидуальных занятий" << endl;
					system("pause");
					system("cls");
					break;
				case 12:
					strcpy(s1, "12");
					send(s, s1, sizeof(s1), NULL);
					flag = 0;
					break;
				default: cout << "Введите верное значение!" << endl; break;
				}
			}
			break;
		case 2:
			strcpy(s1, "2");
			send(s, s1, sizeof(s1), NULL);
			cout << "Введите логин" << endl;
			cin >> s1;
			strcpy(s2, s1);
			cout << "Введите пароль" << endl;
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
						cout << "    Список товаров    " << endl;
						for (int i = 0; i < asd - 1; i++) {
							cout << "Товар №" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Название: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Цена: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Граммовка: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Калории: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Артикул: " << b1 << endl;
							cout << "\n";
						}
					}
					else cout << "Список товаров пуст!" << endl;
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
						cout << "    Список товаров    " << endl;

						for (int i = 0; i < asd - 1; i++) {
							cout << "Товар №" << i + 1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Название: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Цена: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Граммовка: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Калории: " << b1 << endl;
							recv(s, b1, sizeof(b1), NULL);
							cout << "Артикул: " << b1 << endl;
							cout << "\n";
						}
						cout << "Введите номер товара, который Вы хотите прибрести" << endl;
						while (1) {
							cin >> chch;
							if (cin.good()) {
								if (chch < asd && chch > 0) {
									break;
								}
							}
							cin.clear();
							cout << "Неправильный ввод данных!" << endl;
							cin.ignore(10, '\n');
						}
						itoa(chch, s1, 10);
						send(s, s1, sizeof(s1), NULL);
						system("pause");
						system("cls");
						cout << "   Ваш товар   " << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Название: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						strcpy(s1, b1);
						cout << "Цена: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Граммовка: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Калории: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Артикул: " << b1 << endl;
						cout << "\n";
						cout << "С Вас " << s1 << " BYN." << endl;
						system("pause");
						system("cls");
						cout << "Спасибо за покупку!" << endl;
					}
					else cout << "Список товаров пуст!" << endl;
					system("pause");
					system("cls");
					break;
				case 3:
					strcpy(s1, "3");
					send(s, s1, sizeof(s1), NULL);
					system("cls");
					while (1) {
						cout << "Стоимость абонемента на год 230 BYN" << endl;
						cout << "Желаете приобрести?(Да/Нет)" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "Да" || (string)tx == "да" || (string)tx == "ДА") {
							system("cls");
							cout << "С Вас 230 BYN." << endl;
							system("pause");
							system("cls");
							cout << "Спасибо за покупку!" << endl;
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
					cout << "Товары отсортированы по алфавиту\n" << endl;
					system("pause");
					system("cls");
					break;
				case 5:
					send(s, five, sizeof(five), NULL);
					system("cls");
					cout << "Введите название или артикул для поиска" << endl;
					cin >> b1;
					system("cls");
					send(s, b1, sizeof(b1), NULL);
					cout << "По вашему запросу: " << b1 << endl;
					recv(s, s1, sizeof(s1), NULL);
					if (atoi(s1) == 1) {
						cout << "Информация о товаре\n" << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Название: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Цена: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Граммовка: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Калории: " << b1 << endl;
						recv(s, b1, sizeof(b1), NULL);
						cout << "Артикул: " << b1 << endl;
					}
					else cout << "Ничего не найдено.";
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
						cout << "Стоимость одного индивидуального занятия с тренером - 50 BYN." << endl;
						cout << "Желаете оплатить?" << endl;
						cin.ignore();
						cin.getline(tx, 3);
						if ((string)tx == "Да" || (string)tx == "да" || (string)tx == "ДА") {
							strcpy(tx, "1");
							send(s, tx, sizeof(tx), NULL);
							system("cls");
							while (1) {
								cout << "Введите кол-во желаемых индивидуальный занятий" << endl;
								cin >> kol;
								if (cin.good()) {
									break;
								}
								cin.clear();
								cout << "Неправильный ввод данных!" << endl;
								cin.ignore(10, '\n');
							}
							cout << "Выберите тренера для занятий(введите номер)" << endl;
							for (int i = 0; i < asd - 1; i++) {
								cout << "№" << i + 1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Фамилия: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Имя: " << b1 << endl;
								recv(s, b1, sizeof(b1), NULL);
								cout << "Возраст: " << b1 << endl;
								cout << "\n";
							}
							cin >> chch;
							itoa(chch, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							system("pause");
							system("cls");
							recv(s, b1, sizeof(b1), NULL);
							recv(s, s1, sizeof(s1), NULL);
							cout << "Итог: " << kol << " занятий(-я), тренер - " << b1 << " " << s1 << "." << endl;
							cout << "Стоимость: " << kol * 50 << " BYN" << endl;
							itoa(kol, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							itoa(kol * 50, b1, 10);
							send(s, b1, sizeof(b1), NULL);
							system("pause");
							system("cls");
							cout << "Спасибо!" << endl;
							
						}
						else {
							strcpy(tx, "0");
							send(s, tx, sizeof(tx), NULL);
						}
					}
					else cout << "К сожалению, сейчас нет тренера для индивидуальных занятий." << endl;
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
			cout << "Введите логин" << endl;
			cin >> st;
			buf = st + " ";
			cout << "Введите пароль" << endl;
			cin >> st;
			buf = buf + st;
			strcpy(s1, buf.c_str());
			send(s, s1, sizeof(s1), NULL);
			recv(s, b1, sizeof(b1), NULL);

			if (atoi(b1) == 1) {
				cout << "Регистрация прошла успешно!\n";
				system("pause"); 
				system("cls");
			}
			else {
				cout << "Такое сочетание логина или пароля уже есть" << endl; 
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
	cout << "Вы решили добавить новую услугу в фитнес-центре, выбирая из следующих: бассейн, SPA-комплекс,"
		"йога и пилатес. Введите значения, которые описывают прибыль каждой услуги при благоприятных условиях и"
		"убыток при неблагоприятных условиях. На основе расчетов будет выведен результат, какую услугу стоит добавить." << endl;
	cout << "\nВведите прибыль бассейна: ";
	cin >> swim1;
	cout << "\nВведите убыток бассейна: ";
	cin >> swim2;
	swim3 = (swim1 - swim2) * 0.5;
	cout << "\nВведите прибыль SPA-комплекса: ";
	cin >> spa1;
	cout << "\nВведите убыток SPA-комплекса: ";
	cin >> spa2;
	spa3 = (spa1 - spa2) * 0.5;
	cout << "\nВведите прибыль йоги: ";
	cin >> yoga1;
	cout << "\nВведите убыток йоги: ";
	cin >> yoga2;
	yoga3 = (yoga1 - yoga2) * 0.5;
	cout << "\nВведите прибыль пилатеса: ";
	cin >> pil1;
	cout << "\nВведите убыток пилатеса: ";
	cin >> pil2;
	pil3 = (pil1 - pil2) * 0.5;
	cout << "Вероятность как благоприятных, так и неблагоприятных условий равно 0,5.";
	cout << "\nСледовательно, средний ожидаемый выигрыш для бассейна равен " << swim3 << ", для SPA-комплекса - " << spa3 << ", для йоги - " << yoga3 << ", для пилатеса - " << pil3 << endl;
	if (swim3 > spa3 && swim3 > yoga3 && swim3 > pil3) {
		cout << "Наиболее целесообразно выбрать услугу: бассейн." << endl;
	}
	else if (spa3 > swim3 && spa3 > yoga3 && spa3 > pil3) {
		cout << "Наиболее целесообразно выбрать услугу: SPA-комплекс." << endl;
	}
	else if (yoga3 > swim3 && yoga3 > spa3 && yoga3 > pil3) {
		cout << "Наиболее целесообразно выбрать услугу: йога." << endl;
	}
	else {
		cout << "Наиболее целесообразно выбрать услугу: пилатес." << endl;
	}
}