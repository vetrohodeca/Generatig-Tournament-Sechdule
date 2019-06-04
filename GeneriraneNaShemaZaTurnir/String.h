#pragma once
#include<fstream>
using namespace std;
class MyString
{
private:
	char* str;
public: 
	MyString();
	MyString(const char*);
	MyString(const MyString&other);
	MyString& operator=(const MyString&other);
	bool operator==( MyString&other);
	bool operator==(const char* other)const;
	MyString operator+(const MyString&other);
	~MyString();
	void CopyFrom(const MyString& other);
	void print();
	int getSize()const;
	friend istream& operator >> (istream& IN, MyString& mystring);
};