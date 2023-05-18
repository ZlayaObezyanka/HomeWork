//#include <iostream>
//#include <windows.h>
//#include <set>
//#include <algorithm>
#include "rendering.h"

class Game
{
public:
	Game()
	{}
	~Game()
	{}
	void play_game(std::string play_word)
	{
		char ch_temp;
		int game_over = 0;
		int j = -1, r = -1, x = -1;
		std::vector <char> word;
		std::string temp_word;
		
		
		for (int i = 0; i < play_word.size(); i++)
		{
			word.push_back(play_word[i]);
			temp_vector.push_back("|___|");
		}
		for (auto a : temp_vector)
		{
			std::cout << a;
		}

		do
		{
			std::cin >> ch_temp;
			if (std::count(word.begin(), word.end(), ch_temp))
			{
				j = -1, r = -1, x = -1;
				for (int i = 0; i < play_word.size(); i++)
				{
					if (ch_temp == play_word[i] && r == -1 && j == -1 )
					{
						r = i;
					}
					if (ch_temp == play_word[i] && r!=i && j == -1)
					{
						j = i;
					}
					if (ch_temp == play_word[i] && r != i && j != i)
					{
						x = i;
					}
				}
				send_character(r, j, x, play_word, ch_temp);

				std::cout << "true" << std::endl;
				if (temp_word.size() == play_word.size())
				{
					std::cout << "win" << std::endl;
					break;
				}
			}
			else
			{
				std::cout << "false" << std::endl;
				game_over++;
				if (game_over == 5)
				{
					open = 0;
				}
			}

		} while (open);
	}

private:

	bool open = 1;
	std::list <std::string> temp_vector;


	void go_XY(int x, int y)
	{
		COORD position{ x, y };
		SetConsoleCursorPosition(hStdOut, position);
	}

	void send_character(int a, int b, int c, std::string word, char ch_temp)
	{
		Rend draw;
		if (b == -1 && c == -1)
		{
			draw.rendering(a, word, ch_temp, temp_vector);
		}
		if (b != -1)
		{
			draw.rendering(a, b, word, ch_temp, temp_vector);
		}
		if(b != -1 && c != -1)
			draw.rendering(a, b, c, word, ch_temp, temp_vector);

	}

};
