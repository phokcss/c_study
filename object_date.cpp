#include <iostream>
class Date {
private:
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int day)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	void AddDay(int inc)
	{
		if ((month_ == 1) or (month_ == 3) or (month_ == 5) or (month_ == 7) or (month_ == 8) or (month_ == 10) or (month_ == 12))
		{
			day_ += inc;
			if (day_ > 31)
			{
				day_ -= 31;
				month_ += 1;
			}
			if (month_ == 13)
			{
				year_ += 1;
				month_ = 1;
			}
		}
		if ((month_ == 6) or (month_ == 9) or (month_ == 11))
		{
			day_ += inc;
			if (day_ > 30)
			{
				day_ -= 30;
				month_ += 1;
			}
			if (month_ == 2)
			{
				if (year_ % 4 == 0)
				{
					day_ += inc;
					if (day_ > 29)
					{
						day_ -= 29;
						month_ += 1;
					}
				}
				else
				{
					day_ += inc;
					if (day_ > 28)
					{
						day_ -= 28;
						month_ += 1;
					}
				}
			}
		}
	}
	void AddMonth(int inc)
	{
		month_ += inc;
		if (month_ > 12)
		{
			month_ =- 12;
			year_ += 1;
		}

	}
	void AddYear(int inc)
	{
		year_ += inc;
	}
	void ShowDate()
	{
		std::cout << "year_" << year_ << std::endl;
		std::cout << "month_" << month_ << std::endl;
		std::cout << "day_" << day_ << std::endl;
	}
};
int main()
{
	Date date;
	int set_year, set_month, set_day;
	int year, month, day, end = 1;
	int swit;
	std::cout << "set_year" << std::endl;
	std::cin >> year;

	std::cout << "set_month" << std::endl;
	std::cin >> month;

	std::cout << "set_day" << std::endl;
	std::cin >> day;
	date.SetDate(year, month, day);
	date.ShowDate();
	while (end)
	{
		std::cout << "0:set_year" << std::endl;
		std::cout << "1:set_month" << std::endl;
		std::cout << "2:set_day" << std::endl;
		std::cout << "3:end" << std::endl;
		std::cin >> swit;
		switch (swit)
		{
			case 0:
			{
				std::cin >> set_year;
				date.AddYear(set_year);
				break;
			}
			case 1:
			{
				std::cin >> set_month;
				date.AddMonth(set_month);
				break;
			}
			case 2:
			{
				std::cin >> set_day;
				date.AddDay(set_day);
				break;
			}
			case 3:
			{
				end = 0;
			}
		}
		std::cout<<std::endl;
		date.ShowDate();

	}
}