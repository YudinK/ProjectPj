#pragma once
#include<string>
#include<map>
#include<iostream>
#include<iomanip>
#include<list>
#include"Test.h"
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>

using namespace std;

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6,
	LightGray = 7, DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11,
	LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));

}
bool isSymbol(string s, char c)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == c)
			return true;
	return false;
}

class User
{
protected:
	string login;
	string password;
	string fio;
	string email;

public:
	User() {};
	User(const User& us)
	{
		this->login = us.login;
		this->password = us.password;
		this->fio = us.fio;
		this->email = us.email;
	}

	User operator=(const User& us)
	{
		this->login = us.login;
		this->password = us.password;
		this->fio = us.fio;
		this->email = us.email;
		return *this;
	}

	void setLogin(string log) { login = log; }
	void setPas(string pas) { password = pas; }
	void setFIO(string fi) { fio = fi; }
	void setEmail(string em) { email = em; }
	string getLogin() { return login; }

	string getPass() { return password; }
	string getFIO() { return fio; }
	string getEmail() { return email; }
	friend istream& operator>>(istream& in, User& us)
	{
		string pas, fio, em;

		do {
			SetColor(11, 0);
			cout << "Пароль: ";
			getline(in, pas);
			if (!pas.length() || isSymbol(pas, ' '))
				cout << "Пароль должен содержать любые символы, кроме пробела" << endl;
		} while (isSymbol(pas, ' '));
		cout << "Фамилия, имя, отчество: ";
		getline(in, fio);
		do {
			cout << "e-mail: ";
			getline(in, em);
			if (!isSymbol(em, '@'))
				cout << "e-mail должен иметь вид name@service" << endl;
		} while (!isSymbol(em, '@'));
		hash<string> encrypt;
		us.password = to_string(encrypt(pas));
		us.fio = fio;
		us.email = em;
		return in;
	}
	friend ostream& operator<<(ostream& out, const User& us)
	{
		out << us.login << endl;
		out << us.password << endl;
		out << us.fio << endl;
		out << us.email << endl;
		return out;
	}
};

class TestFinished
{
protected:
	string name;
	string category;
	int kolPOt; 
	int procPOt; 
	int bal;
private:
	int mark;
public:
	TestFinished() {};
	TestFinished(string nam, string cat, int k, int p, int b, int m)
	{
		name = nam;
		category = cat;
		kolPOt = k;
		procPOt = p;
		bal = b;
		mark = m;
	}
	TestFinished(const TestFinished& tf)
	{
		this->name = tf.name;
		this->category = tf.category;
		this->kolPOt = tf.kolPOt;
		this->procPOt = tf.procPOt;
		this->bal = tf.bal;
		this->mark = tf.mark;
	}
	TestFinished operator=(const TestFinished& tf)
	{
		this->name = tf.name;
		this->category = tf.category;
		this->kolPOt = tf.kolPOt;
		this->procPOt = tf.procPOt;
		this->bal = tf.bal;
		this->mark = tf.mark;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const TestFinished& t)
	{
		out << t.name << endl;
		out << t.category << endl;
		out << t.kolPOt << endl;
		out << t.procPOt << endl;
		out << t.bal << endl;
		out << t.mark << endl;
		return out;
	}
	void print(ostream& out)
	{
		SetColor(11, 0);
		out << name << " Категория: " << category << "  Оценка: " << mark << endl;
		out << "Правильных ответов: " << kolPOt << "  "<< procPOt << " %   Количество набранных баллов: " << bal << endl;
	}
	string getName() { return name; }
	string getCategory() { return category; }
	int getKolPrav() { return kolPOt; }
	int getPer() { return procPOt; }
	int getBalTest() { return bal; }
	int getMark() { return mark; }
};

class TestUnFinished :public TestFinished
{
	int kolQFinished;
public:
	TestUnFinished() {};
	TestUnFinished(string nam, string cat, int k, int p, int b, int kQ)
	{
		name = nam;
		category = cat;
		kolPOt = k;
		procPOt = p;
		bal = b;
		kolQFinished = kQ;
	}

	TestUnFinished(const TestUnFinished& tf)
	{
		this->name = tf.name;
		this->category = tf.category;
		this->kolPOt = tf.kolPOt;
		this->procPOt = tf.procPOt;
		this->bal = tf.bal;
		this->kolQFinished = tf.kolQFinished;
	}
	TestUnFinished operator=(const TestUnFinished& tf)
	{
		this->name = tf.name;
		this->category = tf.category;
		this->kolPOt = tf.kolPOt;
		this->procPOt = tf.procPOt;
		this->bal = tf.bal;
		this->kolQFinished = tf.kolQFinished;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const TestUnFinished& t)
	{
		out << t.name << endl;
		out << t.category << endl;
		out << t.kolPOt << endl;
		out << t.procPOt << endl;
		out << t.bal << endl;
		out << t.kolQFinished << endl;
		return out;
	}

	void print(ostream& out)
	{
		SetColor(11, 0);
		out << name << " Категория: " << category << "  Количество пройденных вопросов: " << kolQFinished << endl;
		out << "Правильных ответов: " << kolPOt << "  " << procPOt << " %   Количество набранных баллов: " << bal << endl;
	}
	int getKolQFinished() { return kolQFinished; }
};

class Student :public User
{
	list<TestFinished> testFinished;
	list<TestUnFinished> testUnFinished;

public:
	Student() {};
	Student(const Student& st)
	{
		this->login = st.login;
		this->password = st.password;
		this->fio = st.fio;
		this->email = st.email;
		list<TestFinished> tf;
		tf = st.testFinished;
		this->testFinished = tf;
		list<TestUnFinished> tuf;
		tuf = st.testUnFinished;
		this->testUnFinished = tuf;
	}
	Student operator=(const Student& st)
	{
		this->login = st.login;
		this->password = st.password;
		this->fio = st.fio;
		this->email = st.email;
		list<TestFinished> tf;
		tf = st.testFinished;
		this->testFinished = tf;
		list<TestUnFinished> tuf;
		tuf = st.testUnFinished;
		this->testUnFinished = tuf;
		return *this;
	}

	void pushTF(TestFinished t) { testFinished.push_back(t); }
	void pushTUF(TestUnFinished t) { testUnFinished.push_back(t); }
	friend ostream& operator<<(ostream& out, const Student& us)
	{
		out << us.login << endl;
		out << us.password << endl;
		out << us.fio << endl;
		out << us.email << endl;
		out << us.testFinished.size() << endl;
		if (us.testFinished.size() != 0)
		{
			for (auto& x : us.testFinished)
				out << x;
		}
		out << us.testUnFinished.size() << endl;

		if (us.testUnFinished.size() != 0)
		{
			for (auto& x : us.testUnFinished)
				out << x;
		}
		return out;
	}

	void printTResult(ostream& out)
	{
		SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		out << "      Результаты тестирования: "; SetColor(10, 0);out << fio << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		if (testFinished.size())
		{
			int nom = 1; 
			for (auto& x : testFinished)
			{
				out << nom++ << ". ";
				x.print(out);
				SetColor(13, 0);
				out << "------------------------------------------------" << endl; SetColor(11, 0);
			}
		}
		else {
			SetColor(11, 0);
			out << "          нет пройденных тестов                 " << endl; SetColor(13, 0);
			out << "------------------------------------------------" << endl; SetColor(11, 0);
		}
		out << "          Незавершенные тесты:                  " << endl; SetColor(13, 0);
		out << "------------------------------------------------" << endl; SetColor(11, 0);
		if (testUnFinished.size())
		{
			int nom = 1;
			SetColor(13, 0);
			for (auto& x : testUnFinished)
			{
				out << nom++ << ". ";
				x.print(out);
				SetColor(13, 0);
				out << "------------------------------------------------" << endl; SetColor(11, 0);
			}
		}
		else {
			SetColor(11, 0);
			out << "          нет незавершенных тестов             " << endl; SetColor(13, 0);
			out << "------------------------------------------------" << endl; SetColor(11, 0);
		}
	}
	void printTestResultStat(ostream& out)
	{
		if (testFinished.size() || testUnFinished.size())
		{
			SetColor(13, 0);
			out << "------------------------------------------------" << endl; SetColor(11, 0);
			out << "       Результаты тестирования:                 " << fio << endl; SetColor(13, 0);
			out << "------------------------------------------------" << endl; SetColor(11, 0);
			if (testFinished.size())
			{
				int nom = 1;
				SetColor(13, 0);
				for (auto& x : testFinished)
				{
					out << nom++ << ". ";
					x.print(out);
					out << "------------------------------------------------" << endl;
				}
			}
			if (testUnFinished.size())
			{
				SetColor(11, 0);
				out << "              Незавершенные тесты:              " << endl; SetColor(13, 0);
				out << "------------------------------------------------" << endl; SetColor(11, 0);
				int nom = 1;
				SetColor(13, 0);
				for (auto& x : testUnFinished)
				{
					out << nom++ << ". ";
					x.print(out);
					out << "------------------------------------------------" << endl;
				}
			}
		}
	}

	void printUnFinished()
	{
		int nom = 1;
		SetColor(13, 0);
		for (auto& x : testUnFinished)
		{
			cout << nom++ << ". ";
			x.print(cout);
			SetColor(13, 0);
			cout << "------------------------------------------------" << endl; SetColor(11, 0);
		}
	}

	int getKolFinished() { return testFinished.size(); }
	int getKolUnFinished() { return testUnFinished.size(); }

	void getTUF(int nomTUF, TestUnFinished& tuf)
	{
		auto it = testUnFinished.begin();
		advance(it, nomTUF - 1);
		tuf = *it;
	}

	void delTUF(int nom)
	{
		auto it = testUnFinished.begin();
		advance(it, nom - 1);
		testUnFinished.erase(it);
	}
	void printStatTF(ostream& out, string nameCat, string nameTest)
	{
		SetColor(11, 0);
		for (auto& x : testFinished)
			if (x.getName() == nameTest && x.getCategory() == nameCat)
				out << fio << "  Оценка: " << x.getMark() << "   Правильных ответов: " << x.getPer()
				<< " %" << "Количество набранных баллов: " << x.getBalTest() << endl;
	}

	void printStatTUF(ostream& out, string nameCat, string nameTest)
	{
		SetColor(11, 0);
		for (auto& x : testUnFinished)
			if (x.getName() == nameTest && x.getCategory() == nameCat)
				out << fio << "  Количество пройденных вопросов: " << x.getKolQFinished() << "   Правильных ответов: " << x.getPer()
				<< " %" << "Количество набранных баллов: " << x.getBalTest() << endl;
	}
};