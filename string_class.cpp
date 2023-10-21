#include <iostream>
#include <string.h>

class MyString {
	char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
	int string_length;     // ���ڿ� ����

public:
	// ���� �ϳ��� ����
	MyString(char c);

	// ���ڿ��� ���� ����
	MyString(const char* str);

	// ���� ������
	MyString(const MyString& str);

	~MyString();

	int length() const;

	void print() const;
	void println() const;
};
MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
}
MyString::MyString(const char* str)
{
	string_length = strlen(str);
	string_content = new char[string_length+1 ];
	for (int i = 0; i < string_length+1; i++)
	{
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str)
{
	delete[] string_content;
	string_length = strlen(str.string_content);
	string_content = new char[string_length + 1];
	for (int i = 0; i < string_length + 1; i++)
	{
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString()
{
	delete[] string_content;
}
int MyString::length() const
{
	return string_length;
}
void MyString::print() const
{
	for (int i = 0; i < string_length + 1; i++) 
	{
		std::cout << string_content[i];
	}
}
void MyString::println() const 
{
  for (int i = 0; i != string_length; i++) 
  {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}
int main() {
	MyString str1("hello world!");
	MyString str2(str1);

	str1.println();
	str2.println();
}