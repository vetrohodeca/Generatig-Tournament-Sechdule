#include<iostream>
#include"Date.cpp"
#include"String.h"
using namespace std;
int main()
{
	Date d(31, 12, 1999, 23, 45);
	d.addMinutes(25);
	d.printDate();

	system("pause");
	return 0;
}