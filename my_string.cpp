#include <iostream>
#include <string.h>
class my_string
{
	char* string_content;  // 문자열 데이터를 가리키는 포인터
	int string_length;     // 문자열 길이
	int memory_capacity;   // 현재 할당된 용량
	public:
		my_string(char c);
		my_string(const char* str);
		my_string(const my_string& str);

		~my_string();

		my_string& assign(const my_string& str);
		my_string& assign(const char* str);

		my_string& insert(int loc, const my_string& str);
		my_string& insert(int loc, const char* str);
		my_string& insert(int loc, char c);

		void reserve(int size);

		int length() const;
		int capacity() const;

		void print() const;
		void println() const;

};
my_string::my_string(char c)
{
	string_content = new char[2];
	string_content[0] = c;
	string_content[1] = '\0';
	memory_capacity = 2;
	string_length = 1;
}
my_string::my_string(const char* str)
{
	string_length = strlen(str);
	memory_capacity = string_length + 1;
	string_content = new char[string_length + 1];
	for (int i = 0; i < memory_capacity; i++)
		string_content[i] = str[i];
}
my_string::my_string(const my_string& str)
{
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
	string_content = new char[str.memory_capacity];
	for (int i = 0; i < memory_capacity; i++)
	{
		string_content[i] = str.string_content[i];
	}
}
my_string::~my_string()
{
	delete[] string_content;
}
my_string& my_string::assign(const my_string& str)
{
	if (str.string_length > memory_capacity) 
	{
		delete[]string_content;
		memory_capacity = str.memory_capacity;
		string_content = new char[memory_capacity+1];
	}
	for (int i = 0; i < str.string_length+1 ; i++)
	{
		string_content[i] = str.string_content[i];
	}
	string_length = str.string_length;

	return* this;
}
my_string& my_string::assign(const char* str)
{
	string_length = strlen(str);
	if (string_length+1 > memory_capacity)
	{
		memory_capacity = string_length + 1;
		delete[]string_content;
		string_content = new char[memory_capacity + 1];
	}
	for (int i = 0; i < string_length + 1; i++)
	{
		string_content[i] = str[i];
	}

	return*this;
}

my_string& my_string::insert(int loc, const my_string& str)
{
	int i = 0;
	int j = 0;
	if (memory_capacity < str.string_length + string_length+1)
	{
		char* pre_content = string_content;
		string_content = new char[str.string_length + string_length + 1];
		string_length = str.string_length + string_length;
		memory_capacity = string_length + 1;
		for (;i<loc;i++)
		{
			string_content[i] = pre_content[i];
		}
		for (; j < str.string_length; j++)
		{
			string_content[i+j] = str.string_content[j];
		}
		for (; i < memory_capacity; i++)
		{
			string_content[i+j] = pre_content[i];
		}
		delete pre_content;

	}
	else
	{
		string_length = str.string_length + string_length;
		memory_capacity = string_length + 1;
		for (i=loc; i < str.string_length; i++)
		{
			string_content[i + str.string_length] = string_content[i];
		}
		for (i = loc; i < str.string_length; i++)
		{
			string_content[i] = str.string_content[i];
		}
	}
	return *this;
}
my_string& my_string::insert(int loc, const char* str)
{
	my_string temp(str);
	
	return insert(loc, temp);

}
my_string& my_string::insert(int loc, char c)
{
	my_string temp(c);
	return insert(loc, temp);

}

int my_string::length()const
{
	return string_length;
}
int my_string::capacity()const
{
	return memory_capacity;
}
void my_string::reserve(int size)
{
	int i;
	if (size > memory_capacity)
	{
		char* pre_content = string_content;
		string_content = new char[size];

		for (i = 0; i < string_length; i++)
		{
			string_content[i] = pre_content[i];
		}
		string_content[i] = '\0';
		memory_capacity = size;
	}
}
void my_string::print()const
{
	std::cout << string_content;
}
void my_string::println()const
{
	std::cout << string_content<<std::endl;
}
int main()
{
	my_string s0('d');
	my_string s1("12345");
	my_string s2(s1);
	s0.println();
	s1.println();
	s2.println();
	std::cout << std::endl;
	s1.println();
	std::cout << s1.capacity() << std::endl<< s1.length()<<std::endl;
	s1.reserve(11);
	std::cout << s1.capacity() << std::endl <<  s1.length() << std::endl;
	s1.println();
	s2.assign(s1);
	std::cout << std::endl;

	s2.println();
	std::cout << std::endl;
	std::cout << std::endl;
	s2.assign("asdfg");
	s2.println();
	s2.insert(3, "kkkk");
	s2.println();
	s2.reserve(30);

	std::cout << "Capacity : " << s2.capacity() << std::endl;
	std::cout << "String length : " << s2.length() << std::endl;
	s2.println();

}