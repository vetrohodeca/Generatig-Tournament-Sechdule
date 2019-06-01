#pragma once
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
	MyString operator+(const MyString&other);
	~MyString();
	void CopyFrom(const MyString& other);
	void print();
	int getSize();
};