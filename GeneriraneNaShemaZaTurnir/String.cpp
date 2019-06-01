#include"String.h"
#include<iostream>
#pragma warning(disable :4996)
int MyString::getSize()
{
	int counter=0;
	while (str[counter]!='\0')
	{
		counter++;
	}
	return counter;
}
MyString::MyString()
{
	this->str = new char[6];
	strcpy(this->str, "empty");
}
void MyString::print()
{
	std::cout << str<<std::endl;
}
 MyString::~MyString()
{
	 delete[] str;
}
 void MyString::CopyFrom(const MyString& other) 
 {

	 int len = strlen(other.str);
	 this->str = new char[len + 1];
	 strcpy(this->str, other.str);
}
 MyString::MyString(const MyString& other)
 {
	 CopyFrom(other);
 }
 bool::MyString::operator==( MyString& other)
 {
	 int len1 = this->getSize();
	 int len2 = other.getSize();
	 if (len1 != len2) return false;
	 for (size_t i = 0; i < len1; i++)
	 {
		 if (this->str[i] != other.str[i])
		 {
			 return false ;
		 }
	 }
	 return true;
 }
 MyString&::MyString::operator=(const MyString& other)
 {
	 if (this != &other)
	 {
		 delete[] str;
		 CopyFrom(other);
	 }
	 return *this;
 }
 MyString::MyString(const char*str)
 {
	 int len = strlen(str);
	 this->str = new char[len + 1];
	 strcpy(this->str, str);

 }
 MyString MyString::operator+(const MyString&other)
 {
	 MyString result;
	 int currLen = this->getSize();
	 int otherLen = strlen(other.str);
	 result = new char[otherLen + currLen +1];
	 for (int i = 0;i <  currLen; i++)
	 {
		 result.str[i] = this->str[i];
	 }
	 for (int i = currLen; i < otherLen+currLen; i++)
	 {
		 result.str[i] = other.str[i-currLen];
	 }
	 result.str[currLen + otherLen] = '\0';
	 //result.print();
	 return result;
 }