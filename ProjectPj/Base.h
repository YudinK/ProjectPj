#pragma once
#include"User.h"
#include"Test.h"


class BaseTest
{
	map<string, Student> stud;
	User admin;
	AllTest t;

public:
	void menu()
	{
		load();
		do {
			system("cls");
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			SetColor(11, 0);
			cout << "|    Добро пожаловать в систему тестирования   |" << endl;
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "Вход" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "Регистрация" << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "Просмотр тестов" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "Закрыть программу" << endl;

			char vibor = getValue03();
			switch (vibor)
			{
			case '1': vhod(); break;
			case '2': registr(); break;
			case '3': print(); break;
			case '0': exit(0); break;
			}
		} while (true);
	}
	void vhod()
	{
		string log, pas;
		cout << "Логин: ";
		cin >> log;
		hash<string>encrypt;
		log = to_string(encrypt(log));
		if (admin.getLogin() == log)
		{
			cout << "Пароль: ";
			cin >> pas;
			pas = to_string(encrypt(pas));
			if (admin.getPass() == pas)
				vhodAdmin();
			else {
				cout << "Неверный пароль! " << endl;
				system("pause");
			}
		}
		else {
			if (stud.count(log))
			{
				cout << "Пароль: ";
				cin >> pas;
				pas = to_string(encrypt(pas));
				if (stud[log].getPass() == pas)
					vhod(log);
				else {
					cout << "Неверный пароль! " << endl;
					system("pause");
				}
			}
			else {
				cout << "Пользователь с таким логином не найден" << endl;
				system("pause");
			}
		}

	}
	void vhod(string log)
	{
		do
		{
			system("cls");
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl;SetColor(11, 0);
			cout << "          Добро пожаловать в систему          " << endl;
			cout << "            режиме Студент имя  ";
			SetColor(10, 0);
			cout << stud[log].getFIO() << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "Статистика: пройденные и незавершенные тесты" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "Пройти тест" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "Выход" << endl;
			char vibor = getValue03();
			switch (vibor)
			{
			case '1': system("cls"); stud[log].printTResult(cout); system("pause"); break;
			case '2': goTest(log); break;
			case '0': return;
			default: break;
			}
		} while (true);
	}
	void vhodAdmin()
	{
		do
		{
			system("cls");
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			cout << "         Добро пожаловать в систему             " << endl;
			cout << "           режим Админа имя ";
			SetColor(10, 0);
			cout << admin.getFIO() << endl;
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "Статистика" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "Работа с тестами" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "Выход" << endl;;
			char vibor = getValue();
			switch (vibor)
			{
			case '1': getStat(); break;
			case '2': t.workTest(); break;
			case '0': return;
			default: break;
			}
		} while (true);
	}

	void print()
	{
		if (t.getSize())
			t.printCategoryNameT(cout);
		else cout << "Нет сохраненных тестов" << endl;
		system("pause");
	}

	void registr()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "|       Регистрация нового пользователя        |" << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);

		if (admin.getLogin() != "" && admin.getPass() != "")
		{
			cout << "|  Cтудент                                     |" << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl << endl; SetColor(11, 0);
			Student st;
			string log, log1;
			cin.ignore();
			do {
				cout << "Логин: ";
				getline(cin, log);
				if (!log.length() || isSymbol(log, ' '))
				{
					SetColor(11, 0); cout << "Логин должен содержать любые символы, кроме пробела" << endl;
				}
				hash<string> encrypt;
				log1 = to_string(encrypt(log));
				if (stud.count(log1))
					cout << "Логин занят" << endl;
			} while (isSymbol(log, ' ') || stud.count(log1));
			st.setLogin(log1);
			cin >> st;
			stud.insert(make_pair(st.getLogin(), st));
			saveUser();
			vhod(st.getLogin());
		}
		else {
			cout << "В системе нет администратора, вы можете зарегистрироваться как администратор" << endl;
			cout << "Продолжить? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да "; SetColor(13, 0); cout << "| 2: "; SetColor(11, 0); cout << "нет" << endl;
			char vibor = getValue02();
			if (vibor == '1')
			{
				SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				cout << "|          Регистрация администратора          |" << endl; SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				string log;
				do {
					cout << "Логин: ";
					getline(cin, log);
					if (!log.length() || isSymbol(log, ' '))
					{
						SetColor(11, 0); cout << "Логин должен содержать любые символы, кроме пробела" << endl;
					}
				} while (isSymbol(log, ' '));
				hash<string> encrypt;
				admin.setLogin(to_string(encrypt(log)));
				cin >> admin;
				saveUser();
				vhodAdmin();
			}
			else return;
		}
		system("pause");
	}
	void load()
	{
		ifstream fin("user.txt");
		if (fin.is_open())
		{
			t.load();
			string log, pas, fi, em, t;
			getline(fin, log);
			getline(fin, pas);
			getline(fin, fi);
			getline(fin, em);
			admin.setLogin(log);
			admin.setPas(pas);
			admin.setFIO(fi);
			admin.setEmail(em);
			int kolStud;
			fin >> kolStud;
			for (size_t i = 0; i < kolStud; i++)
			{
				fin.get();
				Student st;
				getline(fin, log);
				getline(fin, pas);
				getline(fin, fi);
				getline(fin, em);
				st.setLogin(log);
				st.setPas(pas);
				st.setEmail(em);
				st.setFIO(fi);
				int kolFin;
				fin >> kolFin;
				if (kolFin)
				{
					string nam, cat;
					int kP, p, b, m;
					for (size_t i = 0; i < kolFin; i++)
					{
						fin.get();
						getline(fin, nam);
						getline(fin, cat);
						fin >> kP;
						fin >> p;
						fin >> b;
						fin >> m;
						TestFinished tf(nam, cat, kP, p, b, m);
						st.pushTF(tf);
					}
				}
				fin >> kolFin;
				if (kolFin)
				{
					string nam, cat;
					int kP, p, b, kQ;
					for (size_t i = 0; i < kolFin; i++)
					{
						fin.get();
						getline(fin, nam);
						getline(fin, cat);
						fin >> kP;
						fin >> p;
						fin >> b;
						fin >> kQ;
						TestUnFinished tuf(nam, cat, kP, p, b, kQ);
						st.pushTUF(tuf);
					}
				}
				stud.insert(make_pair(log, st));
			}
		}
		fin.close();
	}
	void saveAll() { t.save(); saveUser(); }
	void saveUser()
	{
		ofstream fout("user.txt");
		fout << admin;
		fout << stud.size() << endl;
		for (auto& x : stud)
			fout << x.second;
		fout.close();
	}

	void goTest(string login)
	{
		system("cls"); SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "          Добро пожаловать в систему            " << endl;
		cout << "            режим Студент имя  ";
		SetColor(10, 0);
		cout << stud[login].getFIO() << endl;
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "                 Тестирование                  " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		if (stud[login].getKolUnFinished())
		{
			cout << "У вас есть незавершенные тесты:" << endl;
			stud[login].printUnFinished();
			cout << "Желаете завершить? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да "; SetColor(13, 0); cout << " | 2: "; SetColor(11, 0); cout << "нет" << endl;
			char vibor = getValue02();
			if (vibor == '1')
			{
				cout << "Введите номер теста, который хотите продолжить: " << endl;
				int nom = getValue() - 48;
				if (nom > 0 && nom <= stud[login].getKolUnFinished())
					goOldTest(login, nom);
				else {
					cout << "Неверный номер" << endl;
					system("pause");
				}
			}
			else goNewTest(login);
		}
		else goNewTest(login);
	}

	void goNewTest(string login)
	{
		system("cls"); SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "                 Тестирование                   " << endl;
		bool uspeh;
		Test test;
		int kolQFinished, kolPrav, balTest;
		t.getTest(test, uspeh);
		if (uspeh)
		{
			if (test.getActive())
			{
				test.go(kolQFinished, kolPrav, balTest);
				int p = round(kolPrav * 100. / test.getKolQ());
				if (kolQFinished == test.getKolQ())
				{
					int m = round(12. * balTest / test.getBal());
					TestFinished tf(test.getName(), test.getCategory(), kolPrav, p, balTest, m);
					stud[login].pushTF(tf);
					cout << "Тестирование закончено. Количество правильных ответов: " << kolPrav << "  Процент правильных ответов: " << p << " Оценка: " << m << endl;
				}
				else {
					TestUnFinished tuf(test.getName(), test.getCategory(), kolPrav, p, balTest, kolQFinished);
					stud[login].pushTUF(tuf);
					cout << "Тестирование прервано. Количество правильных ответов: " << kolPrav << "  Процент правильных ответов: " << p << endl;
					cout << "Вы можете продолжить в любое удобное для вас время" << endl;
				}
				saveUser();
				system("pause");
			}
			else {
				cout << "Данный тест неактивен. Выберите другой тест для прохождения." << endl;
				system("pause");
			}
		}
	}
	void goOldTest(string login, int nomTUF)
	{
		TestUnFinished tuf;
		stud[login].getTUF(nomTUF, tuf);
		string nameTest = tuf.getName();
		string nameCat = tuf.getCategory();
		Test test;
		bool uspeh = false;
		t.getOldTest(nameTest, nameCat, test, uspeh);
		if (uspeh == true && test.getActive())
		{
			int kolFin1 = tuf.getKolQFinished();
			int kolPrav1 = tuf.getKolPrav();
			int b1 = tuf.getBalTest();
			int kolFin2, kolPrav2, b2;
			test.goOld(kolFin1, kolPrav1, b1, kolFin2, kolPrav2, b2);
			int p = round(kolPrav2 * 100. / test.getKolQ());
			if (kolFin2 == test.getKolQ())
			{
				int m = round(12. * b2 / test.getBal());
				TestFinished tf(test.getName(), test.getCategory(), kolPrav2, p, b2, m);
				stud[login].pushTF(tf);
				stud[login].delTUF(nomTUF);
				cout << "Тестирование закончено. Количество правильных ответов: " << kolPrav2 << "  Процент правильных ответов: " << p << " Оценка: " << m << endl;
			}
			else {
				TestUnFinished tuf(test.getName(), test.getCategory(), kolPrav2, p, b2, kolFin2);
				stud[login].delTUF(nomTUF);
				stud[login].pushTUF(tuf);
				cout << "Тестирование прервано. Количество правильных ответов: " << kolPrav2 << "  Процент правильных ответов: " << p << endl;
				cout << "Вы можете продолжить в любое время" << endl;
			}
			saveUser();
			system("pause");
		}
		else {
			cout << "Данный тест не найден в списке активных тестов, возможно он удален. Обратитесь к администратору" << endl;
			system("pause");
		}

	}

	void getStat()
	{
		do
		{
			system("cls"); SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			cout << "        Добро пожаловать в систему              " << endl;
			cout << "          режим Админа имя  ";
			SetColor(10, 0);
			cout << admin.getFIO() << endl;
			SetColor(13, 0);
			cout << " Статистика" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "Результаты тестирования всех студентов" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "Выбрать категорию / тест" << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "Выбрать студента" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "Выход" << endl; SetColor(11, 0);
			char vibor = getValue03();
			switch (vibor)
			{
			case '1': printStatAll(); break;
			case '2': printStatCatTest(); break;
			case '3': printStatStud(); break;
			case '0': return;
			}
		} while (true);
	}

	void printStatAll()
	{
		system("cls"); SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "        Добро пожаловать в систему              " << endl;
		cout << "          режим Админа имя  ";
		SetColor(10, 0);
		cout << admin.getFIO() << endl;
		SetColor(11, 0);
		cout << "        Общие результаты тестирования           " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int kolT = 0;
		for (auto& x : stud)
		{
			kolT = kolT + x.second.getKolFinished() + x.second.getKolUnFinished();
		}
		if (kolT)
		{
			for (auto& x : stud)
			{
				x.second.printTestResultStat(cout);
			}
		}
		else cout << "Ни один студент тестирование не прошел" << endl;
		cout << endl << endl;
		cout << "Сохранить в файл? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "нет" << endl;
		char vibor = getValue02();
		if (vibor == '1')
		{
			cin.ignore();
			string namef;
			do {
				cout << "Введите имя файла: ";
				getline(cin, namef);
				if (namef == "test.txt" || namef == "user.txt")
					cout << "Это имя занято, выберите другое имя файла" << endl;
			} while (namef == "test.txt" || namef == "user.txt");
			ofstream fout(namef); SetColor(13, 0);
			fout << "------------------------------------------------" << endl; SetColor(11, 0);
			fout << "          Общие результаты тестирования         " << endl; SetColor(13, 0);
			fout << "------------------------------------------------" << endl; SetColor(11, 0);
			for (auto& x : stud)
			{
				x.second.printTestResultStat(fout);
			}
			fout.close();
			cout << "Данные сохранены в указанный файл" << endl;
			system("pause");
		}
	}
	void printStatCatTest()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "        Добро пожаловать в систему              " << endl;
		cout << "          режим Админа имя  ";
		SetColor(10, 0);
		cout << admin.getFIO() << endl;
		SetColor(11, 0);
		cout << "      Результаты тестирования по категориям     " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int kolT = 0;
		for (auto& x : stud)
		{
			kolT = kolT + x.second.getKolFinished() + x.second.getKolUnFinished();
		}
		if (kolT)
		{
			t.printCategoryWithoutArc();
			cout << "Выберите номер категории:" << endl;
			int nomCat = getValue() - 48;
			if (nomCat > 0 && nomCat <= t.getSize())
			{
				string nameCat = t.getNameCatStat(nomCat);
				if (t.getKolTestCat(nameCat))
				{
					cout << "Категория " << nameCat << " содержит тесты: " << endl;
					t.printNameTestStat(nameCat);
					if (t.getKolTestCat(nameCat) == 1)
					{
						string nameTest = t.getNameTest(nameCat, 0);
						system("cls");
						printStat(cout, nameCat, nameTest);
						cout << endl << endl;
						cout << "Сохранить в файл? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "нет" << endl;
						char vibor = getValue02();
						if (vibor == '1')
						{
							string namef;
							do {
								cout << "Введите имя файла: ";
								cin.ignore();
								getline(cin, namef);
								if (namef == "test.txt" || namef == "user.txt")
									cout << "Это зарезервированное имя, выберите другое имя файла" << endl;
							} while (namef == "test.txt" || namef == "user.txt");
							ofstream fout(namef);
							printStat(fout, nameCat, nameTest);
							fout.close();
							cout << "Данные сохранены в указанный файл" << endl;
						}
					}
					else {
						SetColor(13, 0);
						cout << "1: "; SetColor(11, 0); cout << "статистика по всей категории, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << " выбрать тест" << endl;
						char vibor = getValue02();
						if (vibor == '1')
						{
							for (int i = 0; i < t.getKolTestCat(nameCat); i++)
								printStat(cout, nameCat, t.getNameTest(nameCat, i));
							cout << endl << endl;
							cout << "Сохранить в файл? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "нет" << endl;
							char vibor = getValue02();
							if (vibor == '1')
							{
								string namef;
								do {
									cout << "Введите имя файла: ";
									getline(cin, namef);
									if (namef == "test.txt" || namef == "user.txt")
										cout << "Это имя занято, выберите другое имя файла" << endl;
								} while (namef == "test.txt" || namef == "user.txt");
								ofstream fout(namef);
								for (int i = 0; i < t.getKolTestCat(nameCat); i++)
									printStat(fout, nameCat, t.getNameTest(nameCat, i));
								fout.close();
								cout << "Данные сохранены" << endl;
							}
						}
						else {
							cout << "Выберите номер теста" << endl;
							int nomTest = getValue() - 48;
							if (nomTest > 0 && nomTest <= t.getKolTestCat(nameCat))
							{
								string nameTest = t.getNameTest(nameCat, nomTest - 1);
								printStat(cout, nameCat, nameTest);
								cout << endl << endl;
								cout << "Сохранить в файл? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "нет" << endl;
								char vibor = getValue02();
								if (vibor == '1')
								{
									string namef;
									do {
										cout << "Введите имя файла: ";
										getline(cin, namef);
										if (namef == "test.txt" || namef == "user.txt")
											cout << "Это имя занято, выберите другое имя файла" << endl;
									} while (namef == "test.txt" || namef == "user.txt");
									ofstream fout(namef);
									printStat(fout, nameCat, nameTest);
									fout.close();
									cout << "Данные сохранены в указанный файл" << endl;
								}
							}
							else cout << "Неверный номер теста" << endl;
						}
					}
				}
				else cout << "Данная категория не содержит ни одного теста" << endl;
			}
			else cout << "Неверный номер категории" << endl;
		}
		else cout << "Ни один студент тестирование не прошел" << endl;
		system("pause");
	}
	void printStatStud()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "        Добро пожаловать в систему              " << endl;
		cout << "          режим Админа имя  ";
		SetColor(10, 0);
		cout << admin.getFIO() << endl;
		SetColor(11, 0);
		cout << "        Результаты тестирования студента        " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int n = 1;
		for (auto& x : stud)
			cout << setw(3) << n++ << ". " << x.second.getFIO() << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "Выберите номер студента: ";
		int nomSt;
		cin >> nomSt;
		cin.ignore();
		if (nomSt > 0 && nomSt <= stud.size())
		{
			auto it = stud.begin();
			advance(it, nomSt - 1);
			it->second.printTResult(cout);
			cout << endl << endl;
			cout << "Сохранить в файл? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "нет" << endl;
			char vibor = getValue02();
			if (vibor == '1')
			{
				string namef;
				do {
					cout << "Введите имя файла: ";
					getline(cin, namef);
					if (namef == "test.txt" || namef == "user.txt")
						cout << "Это имя занято, выберите другое имя файла" << endl;
				} while (namef == "test.txt" || namef == "user.txt");
				ofstream fout(namef);
				it->second.printTResult(fout);
				fout.close();
				cout << "Данные сохранены в указанный файл" << endl;
				system("pause");
			}
		}
		else {
			cout << "Неверный номер" << endl;
			system("pause");
		}
	}
	void printStat(ostream& out, string nameCat, string nameTest)
	{
		SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		out << "       Результаты тестирования: тест            " << nameTest << " из категории:" << nameCat << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl;
		for (auto& x : stud)
		{
			if (x.second.getKolFinished())
			{
				x.second.printStatTF(out, nameCat, nameTest);
				out << endl;
			}
		};
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		out << "             Незавершенные тесты  :             " << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl;
		for (auto& x : stud)
		{
			if (x.second.getKolUnFinished())
			{
				x.second.printStatTUF(out, nameCat, nameTest);
				out << endl;
			}
		};
		out << "------------------------------------------------" << endl;
	}
};