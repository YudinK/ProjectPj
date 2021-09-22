#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"Test.h"
#include"Base.h"
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	
	BaseTest bt;
	bt.menu();
}