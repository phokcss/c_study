#include <iostream>
class string {
	char* str;
	int len;

public:
	string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
	string(const char* s);
	string(const string& s);
	void add_string(const string& s);
	~string();
	void print_string();
	void copy_string(const string& s);
	int strlen();
};
string::string(char c, int n)
{
	str = new char[n + 1];
	for (int i = 0; i < n; i++)
	{
		str[i] = c;
	}
	str[n] = '\0';
	len = n;
}
string::string(const char* s)
{
	len = 0;
	while (s[len] != '\0') len++;
	str = new char[len + 1];
	for (int i = 0; i < len+1; i++)
	{
		str[i] = s[i];
	}
}
string::string(const string& s)
{
	str = new char[s.len + 1];
	for (int i = 0; i < s.len + 1; i++)
	{
		str[i] = s.str[i];
	}
	len = s.len;
}
void string::add_string(const string& s)
{

	char* new_str = new char[len + s.len + 1];

	for (int i = 0; i < len; i++)
	{
		new_str[i] = str[i];
		std::cout << new_str[i] << std::endl;
	}

	for (int i = len; i < len + s.len + 1; i++)
	{
		std::cout << s.str[i-len]<< std::endl;

		new_str[i] = s.str[i - len];
	}
	len += s.len;
	delete str;
	str = new_str;
}
void string::copy_string(const string& s)
{
	delete str;
	str = new char[s.len + 1];
	for (int i = 0; i < s.len+1; i++)
	{
		str[i] = s.str[i];
	}
	len = s.len;
}
int string::strlen()
{
	return len;
}
string::~string()
{
	delete str;
}

void string::print_string()
{
	std::cout << str << std::endl;
}
int main()
{
	string s1('h', 3);
	string s2("gfdashasd");
	string s3(s2);
	std::cout << "s1" << std::endl;
	s1.print_string();
	std::cout << "s2" << std::endl;
	s2.print_string();
	std::cout << "s3" << std::endl;
	s3.print_string();
	std::cout << "s2" << std::endl;
	s2.add_string("1234");
	s2.print_string();
	s1.copy_string(s2);
	std::cout << "s1" << std::endl;
	s1.print_string();
	std::cout << s1.strlen() << std::endl;
	std::cout << s2.strlen() << std::endl;
	std::cout << s3.strlen() << std::endl;
}