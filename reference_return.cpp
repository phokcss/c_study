#include <iostream>
class A {
	int x;
public:
	A(int c);

	int& access_x();
	int get_x();
	void show_x();
};
A::A(int c): x(c){}
int& A::access_x(){return x;}
int A::get_x() { return x; }
void A::show_x(){ std::cout << x << std::endl;}
int main() {
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	// �Ʒ��� ����
	// int& e = a.get_x();
	// e = 2;
	// a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();
}