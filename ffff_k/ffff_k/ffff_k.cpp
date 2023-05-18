#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "game.h"


#define UP 72
#define DOWN 80
#define ENTER 13


void selection_logic(int key);
void rand_word(std::map <int, std::vector<std::string>>& select_word, std::map <int, std::vector<std::string>>& hint, int key);

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    std::string str;
    Menu game_menu;
    selection_logic(game_menu.menu());
}


void selection_logic(int key)
{
    system("CLS");


    std::vector < std::string> min{ "cat", "dog", "fox", "sky" };
    std::vector < std::string> hint_min{ "Коробка? хозяин купил мне коробку!", "Гулять? Гулять!", "Так что же онаБ всё-таки говорит?", "А может ты не голубое?" };
    std::vector < std::string> mid{ "agent", "brand", "money", "anger", };
    std::vector < std::string> hint_mid{ "Мр.Андерсон, так кто же я такой?", "Ну опять переплачивать за это?!", "Только не говорите Мр.Крабсу, что мы тут!", "Моё состояние на момент написания этого кода.", };
    std::vector < std::string> max{ "alcohol", "azimuth" };
    std::vector < std::string> hint_max{ "Многих погубил этот змей", "Угол между севером и заданным направлением." };
    //std::vector < std::string> hard{}; //на будущее 
    std::map<int, std::vector<std::string>> select_word{ {1, min}, {2, mid},{3, max} };
    std::map<int, std::vector <std::string>> hint{ { 1, hint_min }, { 2, hint_mid }, { 3, hint_max } };
    rand_word(select_word, hint, key+1);

}

void rand_word(std::map <int, std::vector<std::string>> &select_word, std::map <int, std::vector<std::string>>& hint, int key)
{
    std::map <int, std::vector <std::string>>::iterator it_sel_w = select_word.find(key);
    std::map <int, std::vector <std::string>>::iterator it_hint = hint.find(key);

    std::vector <std::string> temp = it_sel_w->second;
    std::vector <std::string> hint_temp = it_hint->second;
    
    int random = rand() % temp.size();
    std::string word_hint = hint_temp.at(random);
    std::cout << word_hint;
    std::string word = temp.at(random);
    //std::cout << word << std::endl;
    Game start;
    start.play_game(word);
}