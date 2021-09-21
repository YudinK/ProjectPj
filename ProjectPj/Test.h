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

class Question
{
protected:
	string Ques;
	list<string> Answer; //otv
	int numAnswer;
	int Bal;
public:
	Question() {};
	Question(string ques, int numAnswer, int bal)
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
		out << "  �������� ������:" << endl;
		for (auto& x : Answer)
			out << nom++ << ". " << x << endl;
		out << "����� ����������� ������: " << numAnswer << " ��� �� ���������� �����: " << Bal << endl; SetColor(13, 0);
		out << "------------------------------------------------------------------" << endl; SetColor(11, 0);
	}

	void printGo()
	{
		cout << Ques << endl;
		int n = 1;
		cout << "  �������� ������:" << endl;
		for (auto& x : Answer)
			cout << n++ << ". " << x << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "�������� ����� ������: " << endl;
	}

	int getBal() { return Bal; }

	int getNomPravAnswer() { return numAnswer; }

	void edit(int& d)
	{
		print(cout);
		SetColor(11, 0);
		cout << "�������� ������?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
		char vibor = getValue02();
		if (vibor == '1')
		{
			cout << "������� ������: ";
			getline(cin, Ques);
			cout << "������ �������!" << endl;
		}
		SetColor(11, 0);
		cout << "�������� ������ ?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
		vibor = getValue02();
		while (vibor == '1')
		{
			cout << "������� ����� ������, ������� ������ ��������" << endl;
			int nom = getValue() - 48;
			while (nom <= 0 || nom > Answer.size())
			{
				cout << "������! ����� ������ ������ ���� �� 1 �� " << Answer.size() << endl;
				nom = getValue() - 48;
			}
			cout << "������� ����� �����: ";
			string ans;
			getline(cin, ans);
			auto it = Answer.begin();
			advance(it, nom - 1);
			Answer.erase(it);
			Answer.insert(it, ans);
			cout << "����� �������!" << endl;
			cout << "�������� ��� ���� �����?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
			vibor = getValue02();
		}
		do {
			cout << "�������� ��� ���� �����?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
			vibor = getValue02();
			if (vibor == '1')
			{
				cout << "������� �����: ";
				string ans;
				getline(cin, ans);
				Answer.push_back(ans);
				cout << "����� ��������!" << endl;
			}
		} while (vibor == 1);
		cout << "����� ����������� ������: " << numAnswer << " ��������?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
		vibor = getValue02();
		if (vibor == '1')
		{
			cout << "������� ����� ����������� ������: ";
			cin >> numAnswer;
			cout << "����� ����������� ������ �������!" << endl;
		}
		cout << "���� �� ���������� �����: " << Bal << " ��������?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
		vibor = getValue02();
		d = 0;
		if (vibor == '1')
		{
			d = Bal;
			cout << "������� ����: ";
			cin >> Bal;
			d = Bal - d;
			cout << "���� �������!" << endl;
		}
		system("pause");
	}

	friend ostream& operator<<(ostream& out, const Question& q);
};


class QuestionYesNo : public Question
{

public:
	QuestionYesNo()
	{
		Answer.push_back("�����");
		Answer.push_back("�������");
	}
	void newQues()
	{
		cout << "������: " << endl;
		getline(cin, Ques);
		cout << "�������� ������:"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "����� "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "�������" << endl;
		cout << "������� ����� ����������� ������: " << endl;
		numAnswer = getValue02() - 48;
		cout << "���������� ������ �� ���������� �����: ";
		cin >> Bal;
		cin.ignore();
	}
};

class QuestionOneOfMany : public Question
{

public:
	void newQues()
	{
		cout << "������: " << endl;
		getline(cin, this->Ques);
		cout << "�������� ������: " << endl;
		string ans;
		char c = 0, vibor = '1';
		int nom = 1;
		do {
			cout << nom++ << ". ";
			getline(cin, ans);
			Answer.push_back(ans);
			cout << "�������� ��� ������� ������:"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
			vibor = getValue02();
		} while (vibor == '1');
		cout << "������� ����� ����������� ������: " << endl;
		numAnswer = getValue() - 48;
		while (numAnswer <= 0 || numAnswer >= nom)
		{
			cout << "������! ����� ����������� ������ ������ ���� �� 1 �� " << nom - 1 << endl;
			numAnswer = getValue() - 48;
		}
		cout << "���������� ������ �� ���������� �����: ";
		cin >> Bal;
		cin.ignore();
	}
};

class Test
{
	string Name;
	string Category;
	bool Active = 0;
	list<Question> questions;
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
		list<Question> q = obj.questions;
		this->questions = q;
	}

	Test operator=(const Test& obj)
	{
		this->Name = obj.Name;
		this->Category = obj.Category;
		this->Active = obj.Active;
		this->Bal = obj.Bal;
		this->unFinished = obj.unFinished;
		list<Question> q = obj.questions;
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
			cout << "���� �������";
		else cout << "���� ���������";
		cout << "  �������� ?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
		char vibor = getValue02();
		if (vibor == '1')
			Active = !Active;
	}
	void setCategory(string cat) { Category = cat; }
	void setQuestions(list<Question> q) { questions = q; }

	void edit()
	{
		do
		{
			system("cls");
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			cout << "              �������������� �����              " << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "�������� ������ " << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "������� ������ " << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "������������� ������ " << endl; SetColor(13, 0);
			cout << "4: "; SetColor(11, 0); cout << "�������� �������� �����" << endl; SetColor(13, 0);
			cout << "5: "; SetColor(11, 0); cout << "�������� ���������� �����" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "�����" << endl;
			char vibor = getValue();
			switch (vibor)
			{
			case '1': addQuest(); break;
			case '2': delQuest(); break;
			case '3': editQuest(); break;
			case '4':
				cout << "�������� �����: " << Name << endl;
				cout << "������� ����� ��������: ";
				getline(cin, Name);
				cout << "�������� ����� ��������" << endl;
				break;
			case '5': changeActive(); break;
			case '0': return;
			default: break;
			}
		} while (true);
	}

	void addQuest()
	{
		char vibor = '1';
		do {
			cout << "�������� ���:"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "����� | ������� "; SetColor(13, 0); cout << "2 : "; SetColor(11, 0); cout << "���� �� ����������" << endl;
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
			cout << "�������� ��� ������?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
			vibor = getValue02();
		} while (vibor == '1');
	}

	void delQuest()
	{
		int nom = 1;
		for (auto& x : questions)
		{
			cout << "������ �" << nom++ << ".  ";
			x.print(cout);
		}
		cout << "������� ����� ������� ��� ��������: " << endl;
		int nomQ = getValue() - 48;
		if (nomQ > 0 && nomQ < nom)
		{
			auto it = questions.begin();
			advance(it, nomQ - 1);
			questions.erase(it);
			cout << "������ ������ �� �����!" << endl;
		}
		else cout << "�������� �����" << endl;
		system("pause");
	}

	void editQuest()
	{
		int nom = 1;
		for (auto& x : questions)
		{
			cout << "������ �" << nom++ << ".  ";
			x.print(cout);
		}
		cout << "������� ����� ������� ��� ��������������: " << endl;
		int nomQ = getValue() - 48;
		if (nomQ > 0 && nomQ < nom)
		{
			auto it = questions.begin();
			advance(it, nomQ - 1);
			int d;
			it->edit(d);
			Bal += d;
			cout << "������ �������!" << endl;
		}
		else cout << "�������� �����" << endl;
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
			cout << "(���� �� �������)" << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		out << "���������: " << Category << endl;
		out << "��������� �������� � �����: " << questions.size() << endl;
		out << "������������ ���������� ������: " << Bal << endl;
		out << "������������ ������:  12" << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		int nm = 1;
		for (auto& x : questions)
		{
			out << "������ �" << nm++ << ":   ";
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
		cout << "������� �������� �����: ";
		getline(cin, this->Name);
		this->Active = true;
		int b = 0;
		list < Question> quest;
		char vibor = 1;
		do {
			SetColor(13, 0);
			cout << "1: "; SetColor(11, 0); cout << "�������� ����� ������ � �����, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "��������� �������� �����" << endl;
			vibor = getValue02();
			if (vibor == '1')
			{
				cout << "�������� ���: "; SetColor(13, 0); cout << "1: ";  SetColor(11, 0); cout << "����� / �������"; SetColor(13, 0); cout << " 2: "; SetColor(11, 0); cout << "���� �� ����������" << endl;
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
		cout << "����: " << Name << " �� ���������: " << Category << endl;
		cout << "���� �������� " << questions.size() << " ��������, ������������ ���: " << Bal << endl;
		cout << "�� ������ � ����� ������ �������� ������������ � ���������� " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		int nom = 1;
		b = 0;
		kolPrav = 0;
		kolQFinished = 0;
		for (auto& x : questions)
		{
			system("cls");
			cout << endl;
			cout << "����: " << Name << " �� ���������: " << Category << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
			cout << " ������ �" << nom++ << ". ";
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
				cout << "����������? "; SetColor(13, 0); cout << "1: "; SetColor(11, 0); cout << "��"; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "�������� ������������" << endl;
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
		cout << "����: " << Name << " �� ���������: " << Category << endl;
		cout << "���� �������� ����� " << questions.size() << " ��������, ������������ ���: " << Bal << endl;
		cout << "�� �������� �� " << kolQFin1 << " ��������, �� ��� " << kolPrav1 << " ���������� ������� � ������� " << b1 << " ������" << endl; SetColor(13, 0);
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
				cout << "����: " << Name << " �� ���������: " << Category << endl; SetColor(13, 0);
				cout << "------------------------------------------------" << endl; SetColor(11, 0);
				cout << " ������ �" << nom++ << ". ";
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
					cout << "����������?"; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2: "; SetColor(11, 0); cout << "���" << endl;
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
		cout << "             �������� ������ �����              " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		Test t;
		if (!allTest.size())
		{
			cout << "������� �������� ��������� �����:";
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
		cout << "                   �������� �����               " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		printCategoryNameT(cout);
		cout << "�������� ���������" << endl;
		int nomCat = getValue() - 48;
		if (nomCat > 0 && nomCat <= allTest.size())
		{
			auto it = allTest.begin();
			advance(it, nomCat - 1);
			string nameCat = it->first;
			cout << "���������: " << nameCat << " �������� �����:" << endl;
			int nom = 1;
			for (auto& x : allTest[nameCat])
				cout << nom++ << ". " << x.getName() << endl;
			cout << "�������� ����� �����: " << endl;
			int nomT = getValue() - 48;
			if (nomT > 0 && nomT < nom)
			{
				if (nameCat == "�����")
				{
					cout << "�� �������, ��� ������ ������� ���� �" << nomT << " �� ���������: " << nameCat; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2 : "; SetColor(11, 0); cout << "���" << endl;
					char uver = getValue02();
					if (uver == '1')
					{
						auto it = allTest[nameCat].begin();
						advance(it, nomT - 1);
						allTest[nameCat].erase(it);
						cout << "���� ������" << endl;
					}
					else cout << "�������� ��������" << endl;
				}
				else {
					SetColor(13, 0);
					cout << "1: "; SetColor(11, 0); cout << "������� ����" << endl;
					char ud = getValue02();
					if (ud == '1')
					{
						cout << "�� �������, ��� ������ ������� ���� �" << nomT << " �� ���������: " << nameCat; SetColor(13, 0); cout << " 1: "; SetColor(11, 0); cout << "��, "; SetColor(13, 0); cout << "2 : "; SetColor(11, 0); cout << "���" << endl;
						char uver = getValue02();
						if (uver == '1')
						{
							auto it = allTest[nameCat].begin();
							advance(it, nomT - 1);
							allTest[nameCat].erase(it);
							cout << "���� ������" << endl;
						}
						else cout << "�������� ��������" << endl;
					}
				}
			}
			else cout << "�������� ����� �����" << endl;
		}
		else cout << "�������� ����� ���������" << endl;
		system("pause");
		save();
	}
	void editTest()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "             �������������� �����               " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		printCategoryNameT(cout);
		cout << "�������� ���������" << endl;
		int nomCat = getValue() - 48;
		if (nomCat > 0 && nomCat <= allTest.size())
		{
			auto it = allTest.begin();
			advance(it, nomCat - 1);
			string nameCat = it->first;
			cout << "���������: " << nameCat << " �������� �����:" << endl;
			int nom = 1;
			for (auto& x : allTest[nameCat])
				cout << nom++ << ". " << x.getName() << endl;
			cout << "�������� ����� �����: " << endl;
			int nomT = getValue() - 48;
			if (nomT > 0 && nomT < nom)
			{
				auto it = allTest[nameCat].begin();
				advance(it, nomT - 1);
				it->edit();
				cout << "��������� � ���� �������" << endl;
			}
			else cout << "�������� ����� �����" << endl;
		}
		else cout << "�������� ����� ���������" << endl;
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
				int bal_, kolQ;
				string name_, category_, comment_;
				bool active_, unFinished_;
				getline(fin, name_);
				getline(fin, category_);
				getline(fin, comment_);
				fin >> active_;
				fin >> bal_;
				fin >> unFinished_;
				fin >> kolQ;
				fin.get();
				Test t(name_, category_, comment_, active_, bal_, unFinished_);
				list<Question> lq;
				for (int i = 0; i < kolQ; i++)
				{
					string ques_, ans_;
					int numAnswer_, bal_, kolAns;
					getline(fin, ques_);
					fin >> numAnswer_;
					fin >> bal_;
					Question q(ques_, numAnswer_, bal_);
					fin >> kolAns;
					fin.get();
					list<string> answer_;
					for (int i = 0; i < kolAns; i++)
					{
						getline(fin, ans_);
						answer_.push_back(ans_);
					}
					q.setAnswer(answer_);
					lq.push_back(q);
				}
				t.setQuestions(lq);
				if (allTest.count(category_))
				{
					auto it = allTest.find(category_);
					it->second.push_back(t);
				}
				else
				{
					list<Test> lt;
					lt.push_back(t);
					allTest.insert(make_pair(category_, lt));
				}
			}
			cout << "����� ���������" << endl;
		}
		else  cout << "���� � ������� ������ �� ������" << endl;
	}

	void menu()
	{
		do
		{
			system("cls");
			SetColor(13, 0);
			cout << "1: "; SetColor(11, 0); cout << "������ � ������� " << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "���������" << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "���������" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "�����" << endl; SetColor(11, 0);
			char vibor = getValue();
			switch (vibor)
			{
			case '1': workTest(); break;
			case '2': save(); break;
			case '3': load(); system("pause"); break;
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
				cout << x.first << " -  " << x.second.size() << " ������" << endl; SetColor(13, 0);
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
			cout << "��� ����������� ������" << endl;
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
				cout << nom++ << "." << x.first << " -  " << x.second.size() << " ����." << endl;
			}
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
		}
		else cout << "��� ����������� ���������!" << endl;
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
				if (x.first != "�����")
					cout << nom++ << "." << x.first << " -  " << x.second.size() << " ����." << endl;
			}
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
		}
		else cout << "��� ����������� ���������!" << endl;
	}

	void print()
	{
		system("cls");
		SetColor(13, 0);
		cout << "1: "; SetColor(11, 0); cout << "������ ���� ������" << endl; SetColor(13, 0);
		cout << "2: "; SetColor(11, 0); cout << "������� ���������" << endl;
		char vibor = getValue02();
		if (vibor == '1')
			printAllTest();
		else {
			printCategory();
			cout << "�������� ���������:" << endl;
			int nomCat = getValue() - 48;
			if (nomCat > 0 && nomCat <= allTest.size())
			{
				auto it = allTest.begin();
				advance(it, nomCat - 1);
				string nameCat = it->first;
				SetColor(13, 0);
				cout << "------------------------------------------------" << endl;
				cout << "1: "; SetColor(11, 0); cout << "������ ���� ������ ��������� ���������" << endl; SetColor(13, 0);
				cout << "2: "; SetColor(11, 0); cout << "������� ����" << endl;
				char kolT = getValue02();
				if (kolT == '1')
					printAllTestFromCateg(nameCat);
				else
				{
					SetColor(13, 0);
					cout << "------------------------------------------------" << endl; SetColor(11, 0);
					cout << "���������: " << nameCat << " �������� " << allTest[nameCat].size() << " �����(��)" << endl;
					int nom = 1;
					for (auto& x : allTest[nameCat])
						cout << nom++ << ". " << x.getName() << endl;
					cout << "�������� ����� �����: " << endl;
					int nomT = getValue() - 48;
					if (nomT > 0 && nomT < nom)
					{
						auto it = allTest[nameCat].begin();
						advance(it, nomT - 1);
						system("cls");
						it->print(cout);
					}
					else cout << "������������ �����" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "�������� ����� ���������" << endl;
				system("pause");
			}
		}
	}

	void printCategoryNameT(ostream& out)
	{
		int nom = 1;
		for (auto& x : allTest)
		{
			out << nom++ << ".  " << x.first << " - " << x.second.size() << " �����(��)" << endl;
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
		cout << "���������: " << nameCat << " - " << allTest[nameCat].size() << " ������" << endl;
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		for (auto& x : allTest[nameCat])
		{
			x.print(cout);
			system("pause");
			system("cls");
		}
	}

	void printFile()
	{
		system("cls");
		SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "             ������ ������ � ����               " << endl; SetColor(13, 0);
		cout << "------------------------------------------------" << endl; SetColor(11, 0);
		cout << "������� ��� �����: ";
		string namef;
		do
		{
			cin >> namef;
			if (namef == "test.txt" || namef == "user.txt")
				cout << "��� ��������� ����� ������, ������� ������ ���: ";
		} while (namef == "test.txt" || namef == "user.txt");
		SetColor(13, 0);
		cout << "1: "; SetColor(11, 0); cout << "������ � ���� ���� ������" << endl; SetColor(13, 0);
		cout << "2: "; SetColor(11, 0); cout << "������� ���������" << endl;
		char vibor = getValue02();
		if (vibor == '1')
			printFileAllTest(namef);
		else {
			printCategory();
			cout << "�������� ���������:" << endl;
			int nomCat = getValue() - 48;
			if (nomCat > 0 && nomCat <= allTest.size())
			{
				auto it = allTest.begin();
				advance(it, nomCat - 1);
				string nameCat = it->first;
				SetColor(13, 0);
				cout << "------------------------------------------------" << endl;
				cout << "1: "; SetColor(11, 0); cout << "������ � ���� ���� ������ ��������� ���������" << endl; SetColor(13, 0);
				cout << "2: "; SetColor(11, 0); cout << "������� ����" << endl;
				char kolT = getValue02();
				if (kolT == '1')
					printFileAllTestFromCateg(namef, nameCat);
				else
				{
					SetColor(13, 0);
					cout << "------------------------------------------------" << endl; SetColor(11, 0);
					cout << "���������: " << nameCat << " �������� " << allTest[nameCat].size() << " �����(��)" << endl;
					int nom = 1;
					for (auto& x : allTest[nameCat])
						cout << nom++ << ". " << x.getName() << endl;
					cout << "�������� ����� �����: " << endl;
					int nomT = getValue() - 48;
					if (nomT > 0 && nomT < nom)
					{
						printFileOneTest(namef, nameCat, nomT);
					}
					else cout << "������������ �����" << endl;
				}
			}
			else	cout << "�������� ����� ���������" << endl;
		}
		system("pause");
	}
	void printFileAllTest(string namef)
	{
		if (allTest.size())
		{
			ofstream fout(namef);
			SetColor(13, 0);
			fout << "------------------------------------------------" << endl; SetColor(11, 0);
			for (auto& x : allTest)
			{
				fout << x.first << " -  " << x.second.size() << " ������" << endl; SetColor(13, 0);
				fout << "------------------------------------------------" << endl; SetColor(11, 0);
				for (auto& it : x.second)
				{
					it.print(fout);
				}
			}
			fout.close();
			cout << "����� ������� �������� � ��������� ����!" << endl;
		}
		else {
			cout << "��� ����������� ������" << endl;
		}
	}
	void printFileAllTestFromCateg(string namef, string nameCat)
	{
		ofstream fout(namef);
		SetColor(13, 0);
		fout << "------------------------------------------------" << endl; SetColor(11, 0);
		fout << "���������: " << nameCat << " - " << allTest[nameCat].size() << " ������" << endl; SetColor(13, 0);
		fout << "------------------------------------------------" << endl; SetColor(11, 0);
		for (auto& it : allTest[nameCat])
			it.print(fout);
		fout.close();
		cout << "��� ����� ���������: " << nameCat << " �������� � ��������� ����" << endl;
	}
	void printFileOneTest(string namef, string nameCat, int nom)
	{
		ofstream fout(namef);
		auto it = allTest[nameCat].begin();
		advance(it, nom - 1);
		it->print(fout);
		fout.close();
		cout << "���� ������� � ��������� ����" << endl;
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
			cout << "               ������ � �������                 " << endl; SetColor(13, 0);
			cout << "------------------------------------------------" << endl;
			cout << "1: "; SetColor(11, 0); cout << "�������� ���� " << endl; SetColor(13, 0);
			cout << "2: "; SetColor(11, 0); cout << "������� ���� " << endl; SetColor(13, 0);
			cout << "3: "; SetColor(11, 0); cout << "������������� ���� " << endl; SetColor(13, 0);
			cout << "4: "; SetColor(11, 0); cout << "������ �� �����" << endl; SetColor(13, 0);
			cout << "5: "; SetColor(11, 0); cout << "��������� � ����" << endl; SetColor(13, 0);
			cout << "0: "; SetColor(11, 0); cout << "�����" << endl;
			char vibor = getValue();
			switch (vibor)
			{
			case '1':addTest(); break;
			case '2': delTest(); break;
			case '3': editTest(); break;
			case '4': print(); break;
			case '5': printFile(); break;
			case '0': return;
			default: break;
			}
		} while (true);
	}

	void getTest(Test& t, bool& uspeh)
	{
		printCategoryWithoutArc();
		cout << "�������� ����� ���������" << endl;
		int nomCat = getValue() - 48;
		int kolCat = getSize();
		if (allTest.count("�����"))
			kolCat--;
		if (nomCat > 0 && nomCat <= kolCat)
		{
			auto it = allTest.begin();
			if (allTest.count("�����"))
				advance(it, nomCat);
			else advance(it, nomCat - 1);
			string nameCat = it->first;
			cout << "���������: " << nameCat << " �������� �����:" << endl;
			int nom = 1;
			for (auto& x : allTest[nameCat])
				cout << nom++ << ". " << x.getName() << endl;
			cout << "�������� ����� �����: " << endl;
			int nomT = getValue() - 48;
			if (nomT > 0 && nomT < nom)
			{
				auto it = allTest[nameCat].begin();
				advance(it, nomT - 1);
				t = *it;
				uspeh = true;
			}
			else {
				cout << "�������� ����� �����" << endl;
				uspeh = false;
				system("pause");
			}
		}
		else {
			cout << "�������� ����� ���������" << endl;
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
		if (allTest.count("�����"))
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

ostream& operator<<(ostream& out, const Question& q)
{
	out << q.Ques << endl;
	out << q.numAnswer << endl;
	out << q.Bal << endl;
	out << q.Answer.size() << endl;
	for (auto& x : q.Answer)
		out << x << endl;
	return out;
}