//Удаление комментариев
//Дан текст программы на С++.Комментарии начинаются с "//" и продолжаются до конца текущей строки
//или начинаются с "/*" и заканчиваются "*/".
//Написать функцию, удаляющую комментарии.

#include <iostream>
#include <algorithm>
 

int main()
{
	setlocale(LC_ALL, "Rus");

	std::string str1{ "Штиль — ветер молчит /*упал. белой чайкой на дно*/ ШТИЛЬ — наш корабль забыт. //Штиль — наш корабль забыт. \n Жажда жить сушит сердца до дна" };

	std::cout << str1 << std::endl;
	int temp = str1.find("*/") - str1.find("/*");
	str1.erase(str1.find("/*"), temp + 2);
	std::cout << str1 << std::endl;
		
	temp = str1.find('\n') - str1.find("//");
	str1.erase(str1.find("//"), temp);
	std::cout << str1 << std::endl;

}