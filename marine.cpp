#include <iostream>
class Marine {
	static int total_marine_num;
	
	int hp;
	int coord_x, coord_y;
	int damage;
	bool is_dead;

	const int default_damage;

public:
	Marine();
	Marine(int x, int y);  // x, y 좌표에 마린 생성
	Marine(int x, int y,int default_damage);

	int attack();                       // 데미지를 리턴한다.
	void be_attacked(int damage_earn);  // 입는 데미지
	void move(int x, int y);            // 새로운 위치

	void show_status();  // 상태를 보여준다.
};
int Marine::total_marine_num = 0;
Marine::Marine() :hp(50), coord_x(0), coord_y(0), damage(5), default_damage(5), is_dead(false) { total_marine_num++; }
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), damage(5), default_damage(5), is_dead(false){ total_marine_num++; }
Marine::Marine(int x, int y,int default_damage) : hp(50), coord_x(x), coord_y(y), damage(5),default_damage(default_damage), is_dead(false) { total_marine_num++; }

int Marine::attack()
{
	return damage;
}
void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp < 1)
		is_dead = true;
}
void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}
void Marine::show_status()
{
	std::cout<<"hp:" << hp << std::endl;
	std::cout<<"x=" << coord_x << std::endl;
	std::cout<<"y:" << coord_y << std::endl;
	std::cout<<"dead:" << is_dead << std::endl;
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;

}
int main()
{
	Marine marine1(2, 3, 10);
	Marine marine2(3, 5, 10);

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}