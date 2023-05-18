#define UP 72
#define DOWN 80
#define ENTER 13

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

class Menu
{
public:
    Menu() {}
    ~Menu() {}
    int menu()
    {
        char menu_navigation = 0;
        int activ_menu = 0;

        std::string Menu[] = { "Новая игра", "Правила", "Об игре", "Выход" };

        while (true)
        {
            //int x = 40;
            //int y = 12;
            for (int i = 0; i < size(Menu); i++)
            {
                if (activ_menu == i)
                    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
                else SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << Menu[i] << std::endl;
            }

            menu_navigation = _getch();
            if (menu_navigation == -32)
                menu_navigation = _getch();

            switch (menu_navigation)
            {
            case UP:
            {   if (activ_menu > 0)
                --activ_menu;
            system("CLS");
            break;
            }
            case DOWN:
            {   if (activ_menu < size(Menu) - 1)
                ++activ_menu;
            system("CLS");
            break;
            }
            case ENTER:
            {
                if (activ_menu == 0)
                {
                    system("CLS");

                    return menu_complexity();
                }
                else if (activ_menu == 1)
                {
                    rules();

                }
                else if (activ_menu == 2)
                {
                    About_the_game();
                }
                else if (activ_menu == 3)
                    exit(0);

                system("CLS");

                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);

                break;
            }
            default:
            {
                std::cout << (int)menu_navigation << std::endl;
                break;
            }
            }
        }
    }
private:

    void rules()
    {
        system("CLS");
        std::cout << "Тут будут правила. Мне было лень писать их, но они в разработке. ctrl+c -- ctrl+v не интересно." << std::endl;
        Sleep(5000);
        
    }

    void About_the_game()
    {
        std::cout << "Игра создавалась путем насилования своих извилин, и терпеливого Коллектива. \n Искренне хочу поблагодарить преподавательский состав, а так же остатки нашей группы. \n Вы лучшие! ";
        Sleep(5000);
    }

    int menu_complexity()
    {
        char menu_navigation;
        int activ_menu = 0;
        std::string choice_menu_item[] = { "Легкий", "Средний", "Сложный" };

        do
        {

            for (int i = 0; i < size(choice_menu_item); i++)
            {
                if (activ_menu == i)
                    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
                else SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << choice_menu_item[i] << std::endl;

            }

            menu_navigation = _getch();
            if (menu_navigation == -32)
                menu_navigation = _getch();
            switch (menu_navigation)
            {
            case UP:
            {
                if (activ_menu > 0)
                    --activ_menu;
                system("CLS");
                break;
            }
            case DOWN:
            {
                if (activ_menu < size(choice_menu_item) - 1)
                    ++activ_menu;
                system("CLS");
                break;
            }
            case ENTER:
            {
                return activ_menu;
            }
            default:
                break;
            }

        } while (true);
    }
};