#pragma once
#include<string>
#include<map>
#include<iterator>
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<list>
#include"User.h"
using namespace std;

char getValue()
{
	char buff[100] = "";
	int i = 0;
	unsigned char c;
	do
	{
		cout << '\r' << buff;
		c = _getch();
		if (isdigit(c) && i == 0)
		{
			buff[i++] = c;
			buff[i] = '\0';
		}

	} while (c != '\r');
	cout << endl;
	return buff[0];
}

char getValue03()
{
	char buff[100] = "";
	int i = 0;
	unsigned char c;
	do
	{
		cout << '\r' << buff;
		c = _getch();
		if ((c == '1' || c == '2' || c == '3' || c == '0') && i == 0)
		{
			buff[i++] = c;
			buff[i] = '\0';
		}
	} while (c != '\r');
	cout << endl;
	return buff[0];
}

char getValue02()
{
	char buff[100] = "";
	int i = 0;
	unsigned char c;
	do
	{
		cout << '\r' << buff;
		c = _getch();
		if ((c == '1' || c == '2') && i == 0)
		{
			buff[i++] = c;
			buff[i] = '\0';
		}
	} while (c != '\r');
	char v = buff[0];
	cout << endl;
	return v;
}

class Quest
{
protected:
	string Ques;
	list<string> Answer; //otv
	int numAnswer;
	int Bal;
public:
	Quest() {};
	Quest(string ques, int numAnswer, int bal)
	{
		Ques = ques;
		numAnswer = numAnswer;
		Bal = bal;
	}
	void setAnswer(list<string> answer_) { Answer = answer_; }

	void print(ostream& out)
	{
		out << Ques << endl;
		int nom = 1;
		out << "  Варианты ответа:" << endl;
		for (auto& x : Answer)
			out << nom++ << ". " << x << endl;
		out << "Номер правильного ответа: " << numAnswer << " Бал за правильный ответ: " << Bal << endl; SetColor(13, 0);
		out << "------------------------------------------------------------------" << endl; SetColor(11, 0);
	}

	void printGo()
	{
		cout << Ques << endl;
		int n = 1;
		cout << "  Варианты ответа:" << endl;
		for (auto& x : Answer)
			cout << n++ << ". " << x << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "Выберите номер ответа: " << endl;
	}

	int getBal() { return Bal; }

	int getNomPravAnswer() { return numAnswer; }

	void edit(int& d)
	{
		print(cout);
		SetColor(11, 0);
		cout << "Изменить вопрос?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
		char vibor = getValue02();
		if (vibor == '1')
		{
			cout << "Введите вопрос: ";
			getline(cin, Ques);
			cout << "Вопрос изменен!" << endl;
		}
		SetColor(11, 0);
		cout << "Изменить ответы ?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
		vibor = getValue02();
		while (vibor == '1')
		{
			cout << "Введите номер ответа, который хотите изменить" << endl;
			int nom = getValue() - 48;
			while (nom <= 0 || nom > Answer.size())
			{
				cout << "Ошибка! Номер ответа должен быть от 1 до " << Answer.size() << endl;
				nom = getValue() - 48;
			}
			cout << "Введите новый ответ: ";
			string ans;
			getline(cin, ans);
			auto it = Answer.begin();
			advance(it, nom - 1);
			Answer.erase(it);
			Answer.insert(it, ans);
			cout << "Ответ изменен!" << endl;
			cout << "Изменить еще один ответ?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
			vibor = getValue02();
		}
		do {
			cout << "Добавить еще один ответ?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
			vibor = getValue02();
			if (vibor == '1')
			{
				cout << "Введите ответ: ";
				string ans;
				getline(cin, ans);
				Answer.push_back(ans);
				cout << "Ответ добавлен!" << endl;
			}
		} while (vibor == 1);
		cout << "Номер правильного ответа: " << numAnswer << " Изменить?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
		vibor = getValue02();
		if (vibor == '1')
		{
			cout << "Введите номер правильного ответа: ";
			cin >> numAnswer;
			cout << "Номер правильного ответа изменен!" << endl;
		}
		cout << "Балл за правильный ответ: " << Bal << " Изменить?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
		vibor = getValue02();
		d = 0;
		if (vibor == '1')
		{
			d = Bal;
			cout << "Введите балл: ";
			cin >> Bal;
			d = Bal - d;
			cout << "Балл изменен!" << endl;
		}
		system("pause");
	}

	friend ostream& operator<<(ostream& out, const Quest& q);
};


class QuestionYesNo : public Quest
{

public:
	QuestionYesNo()
	{
		Answer.push_back("Верно");
		Answer.push_back("Неверно");
	}
	void newQues()
	{
		cout << "Вопрос: " << endl;
		getline(cin, Ques);
		cout << "Варианты ответа:"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "верно "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "неверно" << endl;
		cout << "Введите номер правильного ответа: " << endl;
		numAnswer = getValue02() - 48;
		cout << "Количество баллов за правильный ответ: ";
		cin >> Bal;
		cin.ignore();
	}
};

class QuestionOneOfMany : public Quest
{

public:
	void newQues()
	{
		cout << "Вопрос: " << endl;
		getline(cin, this->Ques);
		cout << "Варианты ответа: " << endl;
		string ans;
		char c = 0, vibor = '1';
		int nom = 1;
		do {
			cout << nom++ << ". ";
			getline(cin, ans);
			Answer.push_back(ans);
			cout << "Добавить еще вариант ответа:"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
			vibor = getValue02();
		} while (vibor == '1');
		cout << "Введите номер правильного ответа: " << endl;
		numAnswer = getValue() - 48;
		while (numAnswer <= 0 || numAnswer >= nom)
		{
			cout << "Ошибка! Номер правильного ответа должен быть от 1 до " << nom - 1 << endl;
			numAnswer = getValue() - 48;
		}
		cout << "Количество баллов за правильный ответ: ";
		cin >> Bal;
		cin.ignore();
	}
};

class Test
{
	string Name;
	string Category;
	bool Active = 0;
	list<Quest> questions;
	int Bal = 0;
	bool unFinished = 0;

public:
	Test() {};
	Test(string name, string category, string comment, bool active, int bal, bool unfinished)
	{
		Name = name;
		Category = category;
		Active = active;
		Bal = bal;
		unFinished = unfinished;
	}
	Test(const Test& obj)
	{
		this->Name = obj.Name;
		this->Category = obj.Category;
		this->Active = obj.Active;
		this->Bal = obj.Bal;
		this->unFinished = obj.unFinished;
		list<Quest> q = obj.questions;
		this->questions = q;
	}

	Test operator=(const Test& obj)
	{
		this->Name = obj.Name;
		this->Category = obj.Category;
		this->Active = obj.Active;
		this->Bal = obj.Bal;
		this->unFinished = obj.unFinished;
		list<Quest> q = obj.questions;
		this->questions = q;
		return *this;
	}

	string getName() { return Name; }
	string getCategory() { return Category; }
	bool getActive() { return Active; }
	int getBal() { return Bal; }
	int getKolQ() { return questions.size(); }
	bool getUnFinished() { return unFinished; }
	int getSizeName() { return Name.length(); }

	void changeActive()
	{
		if (Active)
			cout << "Тест активен";
		else cout << "Тест неактивен";
		cout << "  Изменить ?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
		char vibor = getValue02();
		if (vibor == '1')
			Active = !Active;
	}
	void setCategory(string cat) { Category = cat; }
	void setQuestions(list<Quest> q) { questions = q; }

	void addQuest()
	{
		char vibor = '1';
		do {
			cout << "Выберите тип:"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "верно | неверно "; SetColor(13, 0); cout << "2 : "; SetColor(11, 0); cout << "один из нескольких" << endl;
			char type = getValue02();
			if (type == '1')
			{
				QuestionYesNo q;
				q.newQues();
				questions.push_back(q);
				Bal += q.getBal();
			}
			else
			{
				QuestionOneOfMany q;
				q.newQues();
				questions.push_back(q);
				Bal += q.getBal();
			}
			cout << "Добавить еще вопрос?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
			vibor = getValue02();
		} while (vibor == '1');
	}

	void delQuest()
	{
		int nom = 1;
		for (auto& x : questions)
		{
			cout << "Вопрос №" << nom++ << ".  ";
			x.print(cout);
		}
		cout << "Введите номер вопроса для удаления: " << endl;
		int nomQ = getValue() - 48;
		if (nomQ > 0 && nomQ < nom)
		{
			auto it = questions.begin();
			advance(it, nomQ - 1);
			questions.erase(it);
			cout << "Вопрос удален из теста!" << endl;
		}
		else cout << "Неверный номер" << endl;
		system("pause");
	}

	void editQuest()
	{
		int nom = 1;
		for (auto& x : questions)
		{
			cout << "Вопрос №" << nom++ << ".  ";
			x.print(cout);
		}
		cout << "Введите номер вопроса для редактирования: " << endl;
		int nomQ = getValue() - 48;
		if (nomQ > 0 && nomQ < nom)
		{
			auto it = questions.begin();
			advance(it, nomQ - 1);
			int d;
			it->edit(d);
			Bal += d;
			cout << "Вопрос изменен!" << endl;
		}
		else cout << "Неверный номер" << endl;
		system("pause");
	}
	void print(ostream& out)
	{
		SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		int vir;
		if (getSizeName() < 80)
			vir = 80 - (80 - getSizeName()) / 2 - 1;
		else vir = 79;
		out << setw(vir) << Name << endl;
		if (!Active)
			cout << "(Тест не активен)" << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		out << "Категория: " << Category << endl;
		out << "Количесто вопросов в тесте: " << questions.size() << endl;
		out << "Максимальное количество баллов: " << Bal << endl;
		out << "Максимальная оценка:  12" << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		int nm = 1;
		for (auto& x : questions)
		{
			out << "Вопрос №" << nm++ << ":   ";
			x.print(out);
		}
	}
	friend ostream& operator<<(ostream& out, const Test& t)
	{
		out << t.Name << endl;
		out << t.Category << endl;
		out << t.Active << endl;
		out << t.Bal << endl;
		out << t.unFinished << endl;
		out << t.questions.size() << endl;
		for (auto& x : t.questions)
			out << x;
		return out;
	}
	void create()
	{
		cout << "Введите название теста: ";
		getline(cin, this->Name);
		this->Active = true;
		int b = 0;
		list < Quest> quest;
		char vibor = 1;
		do {
			SetColor(13, 0);
			cout << "1: "; SetColor(11, 0); cout << "добавить новый вопрос к тесту, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "завершить создание теста" << endl;
			vibor = getValue02();
			if (vibor == '1')
			{
				cout << "Выберите тип: "; SetColor(13, 0); cout << "1: ";  SetColor(11, 0); cout << "верно / неверно"; SetColor(13, 0); cout << " 2: "; SetColor(11, 0); cout << "один из нескольких" << endl;
				char type = getValue02();
				if (type == '1')
				{
					QuestionYesNo q;
					q.newQues();
					quest.push_back(q);
					b += q.getBal();
				}
				else
				{
					QuestionOneOfMany q;
					q.newQues();
					quest.push_back(q);
					b += q.getBal();
				}
			}
		} while (vibor == '1');
		this->questions = quest;
		this->Bal = b;
		this->unFinished = false;
	}

	void go(int& kolQFinished, int& kolPrav, int& b)
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "Тест: " << Name << " из категории: " << Category << endl;
		cout << "Тест содержит " << questions.size() << " вопросов, максимальный бал: " << Bal << endl;
		cout << "Вы можете в любой момент прервать тестирование и продолжить " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int nom = 1;
		b = 0;
		kolPrav = 0;
		kolQFinished = 0;
		for (auto& x : questions)
		{
			system("cls");
			cout << endl;
			cout << "Тест: " << Name << " из категории: " << Category << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			cout << " Вопрос №" << nom++ << ". ";
			x.printGo();
			int nomAns = getValue() - 48;
			if (nomAns == x.getNomPravAnswer())
			{
				b += x.getBal();
				kolPrav++;
			}
			kolQFinished++;
			if (nom - 1 < questions.size())
			{
				SetColor(11, 0);
				cout << "Продолжить? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "да"; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "прервать тестирование" << endl;
				char vibor = getValue02();
				if (vibor == '2') 	break;
			}
		}
	}
	void goOld(int kolQFin1, int kolPrav1, int b1, int& kolQFin2, int& kolPrav2, int& b2)
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "Тест: " << Name << " из категории: " << Category << endl;
		cout << "Тест содержит всего " << questions.size() << " вопросов, максимальный бал: " << Bal << endl;
		cout << "Вы ответили на " << kolQFin1 << " вопросов, из них " << kolPrav1 << " правильных ответов и набрали " << b1 << " баллов" << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int nom = 1;
		b2 = b1;
		kolPrav2 = kolPrav1;
		kolQFin2 = kolQFin1;
		for (auto& x : questions)
		{
			if (nom > kolQFin1)
			{
				system("cls");
				cout << endl;
				cout << "Тест: " << Name << " из категории: " << Category << endl; SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				cout << " Вопрос №" << nom++ << ". ";
				x.printGo();
				int nomAns = getValue() - 48;
				if (nomAns == x.getNomPravAnswer())
				{
					b2 += x.getBal();
					kolPrav2++;
				}
				kolQFin2++;
				if (nom - 1 < questions.size())
				{
					cout << "Продолжить?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "нет" << endl;
					char vibor = getValue02();
					if (vibor == '2')
						break;
				}
			}
			else nom++;
		}
	}
};

class AllTest
{
	map<string, list<Test>> allTest;
public:
	void addTest()
	{
		system("cls");
		cout << endl;
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "             Создание нового теста              " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		Test t;
		if (!allTest.size())
		{
			cout << "Введите название категории теста:";
			string cat;
			cin.ignore();
			getline(cin, cat);
			list<Test> l;
			allTest.insert(make_pair(cat, l));
			t.setCategory(cat);
			t.create();
			auto it = allTest.begin();
			allTest[it->first].push_back(t);
		}
		save();
	}
	void delTest()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "                   Удаление теста               " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		printCategoryNameT(cout);
		cout << "Выберите категорию" << endl;
		int nomCat = getValue() - 48;
		if (nomCat > 0 && nomCat <= allTest.size())
		{
			auto it = allTest.begin();
			advance(it, nomCat - 1);
			string nameCat = it->first;
			cout << "Категория: " << nameCat << " содержит тесты:" << endl;
			int nom = 1;
			for (auto& x : allTest[nameCat])
				cout << nom++ << ". " << x.getName() << endl;
			cout << "Выберите номер теста: " << endl;
			int nomT = getValue() - 48;
			if (nomT > 0 && nomT < nom)
			{
				if (nameCat == "Архив")
				{
					cout << "Вы уверены, что хотите удалить тест №" << nomT << " из категории: " << nameCat; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2 : "; SetColor(11, 0); cout << "нет" << endl;
					char uver = getValue02();
					if (uver == '1')
					{
						auto it = allTest[nameCat].begin();
						advance(it, nomT - 1);
						allTest[nameCat].erase(it);
						cout << "Тест удален" << endl;
					}
					else cout << "Удаление отменено" << endl;
				}
				else {
					SetColor(13, 0);
					cout << "1: "; SetColor(11, 0); cout << "удалить тест" << endl;
					char ud = getValue02();
					if (ud == '1')
					{
						cout << "Вы уверены, что хотите удалить тест №" << nomT << " из категории: " << nameCat; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "да, "; SetColor(13, 0); cout << "2 : "; SetColor(11, 0); cout << "нет" << endl;
						char uver = getValue02();
						if (uver == '1')
						{
							auto it = allTest[nameCat].begin();
							advance(it, nomT - 1);
							allTest[nameCat].erase(it);
							cout << "Тест удален" << endl;
						}
						else cout << "Удаление отменено" << endl;
					}
				}
			}
			else cout << "Неверный номер теста" << endl;
		}
		else cout << "Неверный номер категории" << endl;
		system("pause");
		save();
	}
	
	void save()
	{
		ofstream fout("test.txt");
		fout << getKolTest() << endl;
		for (auto& x : allTest)
		{
			for (auto& it : x.second)
			{
				fout << it;
			}
		}
		fout.close();

	}

	void load()
	{
		ifstream fin("test.txt");
		if (fin.is_open())
		{
			int k;
			fin >> k;
			fin.get();
			for (int i = 0; i < k; i++)
			{
				int bal, kolQ;
				string name, category, comment;
				bool active, unfinished;
				getline(fin, name);
				getline(fin, category);
				getline(fin, comment);
				fin >> active;
				fin >> bal;
				fin >> unfinished;
				fin >> kolQ;
				fin.get();
				Test t(name, category, comment, active, bal, unfinished);
				list<Quest> lq;
				for (int i = 0; i < kolQ; i++)
				{
					string ques, ans;
					int numAnswer, bal, kolAns;
					getline(fin, ques);
					fin >> numAnswer;
					fin >> bal;
					Quest q(ques, numAnswer, bal);
					fin >> kolAns;
					fin.get();
					list<string> answer;
					for (int i = 0; i < kolAns; i++)
					{
						getline(fin, ans);
						answer.push_back(ans);
					}
					q.setAnswer(answer);
					lq.push_back(q);
				}
				t.setQuestions(lq);
				if (allTest.count(category))
				{
					auto it = allTest.find(category);
					it->second.push_back(t);
				}
				else
				{
					list<Test> lt;
					lt.push_back(t);
					allTest.insert(make_pair(category, lt));
				}
			}
			cout << "Тесты загружены" << endl;
		}
		else  cout << "Файл с данными тестов не найден" << endl;
	}

	void menu()
	{
		do
		{
			system("cls");
			SetColor(13, 0);
			cout << "1: "; SetColor(11, 0); cout << "работа с тестами " << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "сохранить" << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "загрузить" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "выход" << endl; SetColor(11, 0);
			char vibor = getValue();
			switch (vibor)
			{
			case '1': workTest(); break;
			case '2': save(); break;
			//case '3': load(); system("pause"); break;
			case '0': exit(0); break;
			default: break;
			}
		} while (true);
	}

	void printAllTest()
	{
		if (allTest.size())
		{
			for (auto& x : allTest)
			{
				system("cls");
				SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				cout << x.first << " -  " << x.second.size() << " тестов" << endl; SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				system("pause");
				for (auto& it : x.second)
				{
					system("cls");
					it.print(cout);
					system("pause");
				}
			}
		}
		else {
			cout << "Нет сохраненных тестов" << endl;
			system("pause");
		}
	}
	void printCategory()
	{
		if (allTest.size())
		{
			int nom = 1;
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			for (auto& x : allTest)
			{
				cout << nom++ << "." << x.first << " -  " << x.second.size() << " тест." << endl;
			}
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
		}
		else cout << "Нет сохраненных категорий!" << endl;
	}
	void printCategoryWithoutArc()
	{
		if (allTest.size())
		{
			int nom = 1;
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			for (auto& x : allTest)
			{
				if (x.first != "Архив")
					cout << nom++ << "." << x.first << " -  " << x.second.size() << " тест." << endl;
			}
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
		}
		else cout << "Нет сохраненных категорий!" << endl;
	}

	void print()
	{
		system("cls");
		SetColor(13, 0);
		cout << "1: "; SetColor(11, 0); cout << "печать всех тестов" << endl; SetColor(13, 0);
		cout << "2: "; SetColor(11, 0); cout << "выбрать категорию" << endl;
		char vibor = getValue02();
		if (vibor == '1')
			printAllTest();
		else {
			printCategory();
			cout << "Выберите категорию:" << endl;
			int nomCat = getValue() - 48;
			if (nomCat > 0 && nomCat <= allTest.size())
			{
				auto it = allTest.begin();
				advance(it, nomCat - 1);
				string nameCat = it->first;
				SetColor(13, 0);
				cout << "------------------------------------------------" << endl;
				cout << "1: "; SetColor(11, 0); cout << "печать всех тестов выбранной категории" << endl; SetColor(13, 0);
				cout << "2: "; SetColor(11, 0); cout << "выбрать тест" << endl;
				char kolT = getValue02();
				if (kolT == '1')
					printAllTestFromCateg(nameCat);
				else
				{
					SetColor(13, 0);
					cout << "------------------------------------------------" << endl; SetColor(11, 0);
					cout << "Категория: " << nameCat << " содержит " << allTest[nameCat].size() << " теста(ов)" << endl;
					int nom = 1;
					for (auto& x : allTest[nameCat])
						cout << nom++ << ". " << x.getName() << endl;
					cout << "Выберите номер теста: " << endl;
					int nomT = getValue() - 48;
					if (nomT > 0 && nomT < nom)
					{
						auto it = allTest[nameCat].begin();
						advance(it, nomT - 1);
						system("cls");
						it->print(cout);
					}
					else cout << "Неправильный номер" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "Неверный номер категории" << endl;
				system("pause");
			}
		}
	}

	void printCategoryNameT(ostream& out)
	{
		int nom = 1;
		for (auto& x : allTest)
		{
			out << nom++ << ".  " << x.first << " - " << x.second.size() << " теста(ов)" << endl;
			for (auto& it : x.second)
				out << "            " << it.getName() << endl;
			SetColor(13, 0);
			out << "------------------------------------------------" << endl; SetColor(11, 0);
		}
	}
	void printAllTestFromCateg(string nameCat)
	{
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "Категория: " << nameCat << " - " << allTest[nameCat].size() << " тестов" << endl;
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		for (auto& x : allTest[nameCat])
		{
			x.print(cout);
			system("pause");
			system("cls");
		}
	}

	int getKolTest()
	{
		int kol = 0;;
		for (auto& x : allTest)
		{
			kol += x.second.size();
		}
		return kol;
	}

	int getSize() { return allTest.size(); }

	void workTest()
	{
		do
		{
			system("cls");
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			cout << "               Работа с тестами                 " << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "добавить тест " << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "удалить тест " << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "печать на экран" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "выход" << endl;
			char vibor = getValue();
			switch (vibor)
			{
			case '1':addTest(); break;
			case '2': delTest(); break;
			case '3': print(); break;
			case '0': return;
			default: break;
			}
		} while (true);
	}

	void getTest(Test& t, bool& uspeh)
	{
		printCategoryWithoutArc();
		cout << "Выберите номер категории" << endl;
		int nomCat = getValue() - 48;
		int kolCat = getSize();
		if (allTest.count("Архив"))
			kolCat--;
		if (nomCat > 0 && nomCat <= kolCat)
		{
			auto it = allTest.begin();
			if (allTest.count("Архив"))
				advance(it, nomCat);
			else advance(it, nomCat - 1);
			string nameCat = it->first;
			cout << "Категория: " << nameCat << " содержит тесты:" << endl;
			int nom = 1;
			for (auto& x : allTest[nameCat])
				cout << nom++ << ". " << x.getName() << endl;
			cout << "Выберите номер теста: " << endl;
			int nomT = getValue() - 48;
			if (nomT > 0 && nomT < nom)
			{
				auto it = allTest[nameCat].begin();
				advance(it, nomT - 1);
				t = *it;
				uspeh = true;
			}
			else {
				cout << "Неверный номер теста" << endl;
				uspeh = false;
				system("pause");
			}
		}
		else {
			cout << "Неверный номер категории" << endl;
			uspeh = false;
			system("pause");
		}
	}
	void getOldTest(string nameTest, string nameCat, Test& t, bool& uspeh)
	{
		uspeh = false;
		for (auto& x : allTest[nameCat])
			if (x.getName() == nameTest)
			{
				t = x;
				uspeh = true;
			}
	}

	string getNameCatStat(int nomCat)
	{
		auto it = allTest.begin();
		if (allTest.count("Архив"))
			advance(it, nomCat);
		else advance(it, nomCat - 1);
		return it->first;
	}

	string getNameTest(string nameCat, int nomTest)
	{
		auto it = allTest[nameCat].begin();
		advance(it, nomTest);
		return it->getName();
	}

	void printNameTestStat(string nameCat)
	{
		int n = 1;
		for (auto& x : allTest[nameCat])
			cout << n++ << ". " << x.getName() << endl;
	}
	int getKolTestCat(string nameCat)
	{
		return allTest[nameCat].size();
	}
};

ostream& operator<<(ostream& out, const Quest& q)
{
	out << q.Ques << endl;
	out << q.numAnswer << endl;
	out << q.Bal << endl;
	out << q.Answer.size() << endl;
	for (auto& x : q.Answer)
		out << x << endl;
	return out;
}