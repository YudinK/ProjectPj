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
			cout << "|    ����� ���������� � ������� ������������   |" << endl;
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "����" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "�����������" << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "�������� ������" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "������� ���������" << endl;

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
		cout << "�����: ";
		cin >> log;
		hash<string>encrypt;
		log = to_string(encrypt(log));
		if (admin.getLogin() == log)
		{
			cout << "������: ";
			cin >> pas;
			pas = to_string(encrypt(pas));
			if (admin.getPass() == pas)
				vhodAdmin();
			else {
				cout << "�������� ������! " << endl;
				system("pause");
			}
		}
		else {
			if (stud.count(log))
			{
				cout << "������: ";
				cin >> pas;
				pas = to_string(encrypt(pas));
				if (stud[log].getPass() == pas)
					vhod(log);
				else {
					cout << "�������� ������! " << endl;
					system("pause");
				}
			}
			else {
				cout << "������������ � ����� ������� �� ������" << endl;
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
			cout << "          ����� ���������� � �������          " << endl;
			cout << "            ������ ������� ���  ";
			SetColor(10, 0);
			cout << stud[log].getFIO() << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "����������: ���������� � ������������� �����" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "������ ����" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "�����" << endl;
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
			cout << "         ����� ���������� � �������             " << endl;
			cout << "           ����� ������ ��� ";
			SetColor(10, 0);
			cout << admin.getFIO() << endl;
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "����������" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "������ � �������" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "�����" << endl;;
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
		else cout << "��� ����������� ������" << endl;
		system("pause");
	}

	void registr()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "|       ����������� ������ ������������        |" << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);

		if (admin.getLogin() != "" && admin.getPass() != "")
		{
			cout << "|  C������                                     |" << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl << endl; SetColor(11, 0);
			Student st;
			string log, log1;
			cin.ignore();
			do {
				cout << "�����: ";
				getline(cin, log);
				if (!log.length() || isSymbol(log, ' '))
				{
					SetColor(11, 0); cout << "����� ������ ��������� ����� �������, ����� �������" << endl;
				}
				hash<string> encrypt;
				log1 = to_string(encrypt(log));
				if (stud.count(log1))
					cout << "����� �����" << endl;
			} while (isSymbol(log, ' ') || stud.count(log1));
			st.setLogin(log1);
			cin >> st;
			stud.insert(make_pair(st.getLogin(), st));
			saveUser();
			vhod(st.getLogin());
		}
		else {
			cout << "� ������� ��� ��������������, �� ������ ������������������ ��� �������������" << endl;
			cout << "����������? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "�� "; SetColor(13, 0); cout << "| 2: "; SetColor(11, 0); cout << "���" << endl;
			char vibor = getValue02();
			if (vibor == '1')
			{
				SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				cout << "|          ����������� ��������������          |" << endl; SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				string log;
				do {
					cout << "�����: ";
					getline(cin, log);
					if (!log.length() || isSymbol(log, ' '))
					{
						SetColor(11, 0); cout << "����� ������ ��������� ����� �������, ����� �������" << endl;
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
		cout << "          ����� ���������� � �������            " << endl;
		cout << "            ����� ������� ���  ";
		SetColor(10, 0);
		cout << stud[login].getFIO() << endl;
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "                 ������������                  " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		if (stud[login].getKolUnFinished())
		{
			cout << "� ��� ���� ������������� �����:" << endl;
			stud[login].printUnFinished();
			cout << "������� ���������? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "�� "; SetColor(13, 0); cout << " | 2: "; SetColor(11, 0); cout << "���" << endl;
			char vibor = getValue02();
			if (vibor == '1')
			{
				cout << "������� ����� �����, ������� ������ ����������: " << endl;
				int nom = getValue() - 48;
				if (nom > 0 && nom <= stud[login].getKolUnFinished())
					goOldTest(login, nom);
				else {
					cout << "�������� �����" << endl;
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
		cout << "                 ������������                   " << endl;
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
					cout << "������������ ���������. ���������� ���������� �������: " << kolPrav << "  ������� ���������� �������: " << p << " ������: " << m << endl;
				}
				else {
					TestUnFinished tuf(test.getName(), test.getCategory(), kolPrav, p, balTest, kolQFinished);
					stud[login].pushTUF(tuf);
					cout << "������������ ��������. ���������� ���������� �������: " << kolPrav << "  ������� ���������� �������: " << p << endl;
					cout << "�� ������ ���������� � ����� ������� ��� ��� �����" << endl;
				}
				saveUser();
				system("pause");
			}
			else {
				cout << "������ ���� ���������. �������� ������ ���� ��� �����������." << endl;
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
				cout << "������������ ���������. ���������� ���������� �������: " << kolPrav2 << "  ������� ���������� �������: " << p << " ������: " << m << endl;
			}
			else {
				TestUnFinished tuf(test.getName(), test.getCategory(), kolPrav2, p, b2, kolFin2);
				stud[login].delTUF(nomTUF);
				stud[login].pushTUF(tuf);
				cout << "������������ ��������. ���������� ���������� �������: " << kolPrav2 << "  ������� ���������� �������: " << p << endl;
				cout << "�� ������ ���������� � ����� �����" << endl;
			}
			saveUser();
			system("pause");
		}
		else {
			cout << "������ ���� �� ������ � ������ �������� ������, �������� �� ������. ���������� � ��������������" << endl;
			system("pause");
		}

	}

	void getStat()
	{
		do
		{
			system("cls"); SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			cout << "        ����� ���������� � �������              " << endl;
			cout << "          ����� ������ ���  ";
			SetColor(10, 0);
			cout << admin.getFIO() << endl;
			SetColor(13, 0);
			cout << " ����������" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "���������� ������������ ���� ���������" << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "������� ��������� / ����" << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "������� ��������" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "�����" << endl; SetColor(11, 0);
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
		cout << "        ����� ���������� � �������              " << endl;
		cout << "          ����� ������ ���  ";
		SetColor(10, 0);
		cout << admin.getFIO() << endl;
		SetColor(11, 0);
		cout << "        ����� ���������� ������������           " << endl; SetColor(13, 0);
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
		else cout << "�� ���� ������� ������������ �� ������" << endl;
		cout << endl << endl;
		cout << "��������� � ����? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "�� "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "���" << endl;
		char vibor = getValue02();
		if (vibor == '1')
		{
			cin.ignore();
			string namef;
			do {
				cout << "������� ��� �����: ";
				getline(cin, namef);
				if (namef == "test.txt" || namef == "user.txt")
					cout << "��� ��� ������, �������� ������ ��� �����" << endl;
			} while (namef == "test.txt" || namef == "user.txt");
			ofstream fout(namef); SetColor(13, 0);
			fout << "------------------------------------------------" << endl; SetColor(11, 0);
			fout << "          ����� ���������� ������������         " << endl; SetColor(13, 0);
			fout << "------------------------------------------------" << endl; SetColor(11, 0);
			for (auto& x : stud)
			{
				x.second.printTestResultStat(fout);
			}
			fout.close();
			cout << "������ ��������� � ��������� ����" << endl;
			system("pause");
		}
	}
	void printStatCatTest()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "        ����� ���������� � �������              " << endl;
		cout << "          ����� ������ ���  ";
		SetColor(10, 0);
		cout << admin.getFIO() << endl;
		SetColor(11, 0);
		cout << "      ���������� ������������ �� ����������     " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int kolT = 0;
		for (auto& x : stud)
		{
			kolT = kolT + x.second.getKolFinished() + x.second.getKolUnFinished();
		}
		if (kolT)
		{
			t.printCategoryWithoutArc();
			cout << "�������� ����� ���������:" << endl;
			int nomCat = getValue() - 48;
			if (nomCat > 0 && nomCat <= t.getSize())
			{
				string nameCat = t.getNameCatStat(nomCat);
				if (t.getKolTestCat(nameCat))
				{
					cout << "��������� " << nameCat << " �������� �����: " << endl;
					t.printNameTestStat(nameCat);
					if (t.getKolTestCat(nameCat) == 1)
					{
						string nameTest = t.getNameTest(nameCat, 0);
						system("cls");
						printStat(cout, nameCat, nameTest);
						cout << endl << endl;
						cout << "��������� � ����? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "�� "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "���" << endl;
						char vibor = getValue02();
						if (vibor == '1')
						{
							string namef;
							do {
								cout << "������� ��� �����: ";
								cin.ignore();
								getline(cin, namef);
								if (namef == "test.txt" || namef == "user.txt")
									cout << "��� ����������������� ���, �������� ������ ��� �����" << endl;
							} while (namef == "test.txt" || namef == "user.txt");
							ofstream fout(namef);
							printStat(fout, nameCat, nameTest);
							fout.close();
							cout << "������ ��������� � ��������� ����" << endl;
						}
					}
					else {
						SetColor(13, 0);
						cout << "1: "; SetColor(11, 0); cout << "���������� �� ���� ���������, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << " ������� ����" << endl;
						char vibor = getValue02();
						if (vibor == '1')
						{
							for (int i = 0; i < t.getKolTestCat(nameCat); i++)
								printStat(cout, nameCat, t.getNameTest(nameCat, i));
							cout << endl << endl;
							cout << "��������� � ����? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "�� "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "���" << endl;
							char vibor = getValue02();
							if (vibor == '1')
							{
								string namef;
								do {
									cout << "������� ��� �����: ";
									getline(cin, namef);
									if (namef == "test.txt" || namef == "user.txt")
										cout << "��� ��� ������, �������� ������ ��� �����" << endl;
								} while (namef == "test.txt" || namef == "user.txt");
								ofstream fout(namef);
								for (int i = 0; i < t.getKolTestCat(nameCat); i++)
									printStat(fout, nameCat, t.getNameTest(nameCat, i));
								fout.close();
								cout << "������ ���������" << endl;
							}
						}
						else {
							cout << "�������� ����� �����" << endl;
							int nomTest = getValue() - 48;
							if (nomTest > 0 && nomTest <= t.getKolTestCat(nameCat))
							{
								string nameTest = t.getNameTest(nameCat, nomTest - 1);
								printStat(cout, nameCat, nameTest);
								cout << endl << endl;
								cout << "��������� � ����? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "�� "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "���" << endl;
								char vibor = getValue02();
								if (vibor == '1')
								{
									string namef;
									do {
										cout << "������� ��� �����: ";
										getline(cin, namef);
										if (namef == "test.txt" || namef == "user.txt")
											cout << "��� ��� ������, �������� ������ ��� �����" << endl;
									} while (namef == "test.txt" || namef == "user.txt");
									ofstream fout(namef);
									printStat(fout, nameCat, nameTest);
									fout.close();
									cout << "������ ��������� � ��������� ����" << endl;
								}
							}
							else cout << "�������� ����� �����" << endl;
						}
					}
				}
				else cout << "������ ��������� �� �������� �� ������ �����" << endl;
			}
			else cout << "�������� ����� ���������" << endl;
		}
		else cout << "�� ���� ������� ������������ �� ������" << endl;
		system("pause");
	}
	void printStatStud()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "        ����� ���������� � �������              " << endl;
		cout << "          ����� ������ ���  ";
		SetColor(10, 0);
		cout << admin.getFIO() << endl;
		SetColor(11, 0);
		cout << "        ���������� ������������ ��������        " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int n = 1;
		for (auto& x : stud)
			cout << setw(3) << n++ << ". " << x.second.getFIO() << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "�������� ����� ��������: ";
		int nomSt;
		cin >> nomSt;
		cin.ignore();
		if (nomSt > 0 && nomSt <= stud.size())
		{
			auto it = stud.begin();
			advance(it, nomSt - 1);
			it->second.printTResult(cout);
			cout << endl << endl;
			cout << "��������� � ����? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "�� "; SetColor(13, 0); cout << " | 2 : "; SetColor(11, 0); cout << "���" << endl;
			char vibor = getValue02();
			if (vibor == '1')
			{
				string namef;
				do {
					cout << "������� ��� �����: ";
					getline(cin, namef);
					if (namef == "test.txt" || namef == "user.txt")
						cout << "��� ��� ������, �������� ������ ��� �����" << endl;
				} while (namef == "test.txt" || namef == "user.txt");
				ofstream fout(namef);
				it->second.printTResult(fout);
				fout.close();
				cout << "������ ��������� � ��������� ����" << endl;
				system("pause");
			}
		}
		else {
			cout << "�������� �����" << endl;
			system("pause");
		}
	}
	void printStat(ostream& out, string nameCat, string nameTest)
	{
		SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		out << "       ���������� ������������: ����            " << nameTest << " �� ���������:" << nameCat << endl; SetColor(13, 0);
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
		out << "             ������������� �����  :             " << endl; SetColor(13, 0);
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