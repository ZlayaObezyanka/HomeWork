#include <string.h>
#include <algorithm>


class Rend
{
public:

	void rendering(int letter_position, std::string &word, char &ch, std::list <std::string> & temp_vector)// letter_position -- ������� ����� � �����; word -- �����, � ������� ��������; ch -- ������������ ������.
	{
		std::string temp ("|_");
		temp += ch;
		temp += "_|";
		std::string temp2("|___|");
		
		std::list <std::string>::iterator it_temp_vector = temp_vector.begin();
		for (int i = 0; i < word.size();  i++)
		{
			if (letter_position == i)
			{
				*it_temp_vector = temp;
			}
			++it_temp_vector;
		}
		for (auto a : temp_vector)
		{
			std::cout << a;
		}
	}

	void rendering(int first_letter_position, int second_letter_position, std::string& word, char& ch, std::list <std::string>& temp_vector)// letter_position -- ������� ����� � �����; second_letter_position -- ������� ����� � �����;
																												//word -- �����, � ������� ��������; ch -- ������������ ������.
	{
		std::string temp("|_");
		temp += ch;
		temp += "_|";
		std::string temp2("|___|");

		std::list <std::string>::iterator it_temp_vector = temp_vector.begin();
		for (int i = 0; i < word.size(); i++)
		{
			if (first_letter_position == i)
			{
				*it_temp_vector = temp;


			}
			if (second_letter_position == i) {
				*it_temp_vector = temp;

			}
			++it_temp_vector;
		}
		std::cout << std::endl;
		for (auto a : temp_vector)
		{
			std::cout << a;
		}
	}

	void rendering(int first_letter_position, int second_letter_position, int third_letter_position, std::string& word, char& ch, std::list <std::string>& temp_vector)// letter_position -- ������� ����� � �����; second_letter_position -- ������� ����� � �����;
																																		//third_letter_position -- ������� ����� � �����; word -- �����, � ������� ��������; 
																																								//ch -- ������������ ������.
	{
		std::string temp("|_");
		temp += ch;
		temp += "_|";
		std::string temp2("|___|");

		for (int i = 0; i < word.size(); i++)
		{
			if (first_letter_position == i)
			{
				std::cout << "|_" << ch << "_|";
			}
			else if (second_letter_position == i)
				std::cout << "|_" << ch << "_|";
			else if (third_letter_position == i)
				std::cout << "|_" << ch << "_|";
			else if (temp2 != "2") {}

			else {
				temp_vector;

			}
			
				
		}
		for (auto a : temp_vector)
		{
			std::cout << a;
		}
	}

	Rend() {}
	~Rend()
	{}
};
