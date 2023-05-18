//Создайте приложение «Телефонная книга».Необходимо
//хранить данные об абоненте(ФИО, домашний телефон,
//	рабочий телефон, мобильный телефон, дополнительная
//	информация о контакте) внутри соответствующего класса.
//	Наполните класс переменными - членами, функциямичленами, конструкторами, inline - функциями - членами,
//	используйте инициализаторы, реализуйте деструктор.
//	Обязательно необходимо выделять динамически память под
//	ФИО.Предоставьте пользователю возможность добавлять
//	новых абонентов, удалять абонентов, искать абонентов
//	по ФИО, показывать всех абонентов

//не сделал. не хватило дней и головы, походу. не реализованы: поиск, удаление, показ всех, добавление новых (не очень понял задачу). В процессе реализации: ввод мобильного номера (157стр).


#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype> 

class Phone_book

	{
	public:
		Phone_book(std::string full_name, const int SIZE, int home_phone, int work_phone, int mobile_phone[11], std::string add_inform);

		~Phone_book();
		void setHome_phone();
		void setFull_name();
		void setWork_phone();
		void setMobile_phone();
		void print() {
			std::cout << home_phone << std::endl;
		}
		void getMobile_phone();

		Phone_book()
		{
		}
		~Phone_book()
		{
		}

	private:
		std::string full_name;
		static const int SIZE = 11;
		int home_phone;
		int work_phone;
		int mobile_phone[SIZE] = {};
		std::string add_inform;
		inline int temp_phone(std::string temp);
		inline int temp_phone(std::string temp, int arr[SIZE]);

	};

	


int main()
{
	Phone_book first_subscriber;
	first_subscriber.setMobile_phone();
	first_subscriber.getMobile_phone();


}

void Phone_book::getMobile_phone()
{

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << mobile_phone[i];
	}
}

inline int Phone_book::temp_phone(std::string temp) {
	std::string temp_num;
	int num = 0;
	for (auto i : temp)
	{
		if (isdigit(i)) temp_num.push_back(i);
	}
	/*for (int i = 0; i < temp.size() +1 ; i++)
	{
		if (temp[i] >= 48 && temp[i] <= 57)
		{
			temp_num.push_back(temp[i]);
		}
	}*/
	num = stoi(temp_num); //Имеет проблему с нулем в начале (незначимый 0). В int не присваевается значение, начинающееся с 0 ( вместо 01234 будет 1234). 2 путя решения: геморойный(очень) и вернуть стринг, вместо инт.
	return num;
}

inline int Phone_book::temp_phone(std::string temp, int arr[SIZE])
{
	
	std::string temp_num;
	char crutch[SIZE+1] = {};
	bool open = 1;
	do
	{
		for (auto i : temp)
		{
			if (isdigit(i)) temp_num.push_back(i);
		}

		if (temp_num.size() != 11)
		{
			std::cout << "You entered short mobile number." << std::endl;
			std::cout << "Enter subscriber's mobile phone: \t";
			std::cin >> temp;
			continue;
		}
		else {
			for (int i = 0; i < SIZE; i++)
			{
				crutch[i] = temp_num[i];
			}
			int t;
			t = atoi(crutch);
			for (int i = 0; i < SIZE; i++)
			{
				arr[i] = t%10;
				t /= 10;
				open = 0;
			}
		}

	} while (open);
		
	return arr[SIZE];
}

void Phone_book::setFull_name() //А как чаровый динамический массив то сделать? Я таких не знаю, из-за этого использовал стринг. Фактически, он динамический. 
{
	std::cout << "Enter subscriber's full name\t ";
	std::cin >> full_name;
}

void Phone_book::setHome_phone() {
	std::string temp;
	std::cout << "Enter the subscriber's Home phone number \t ";
	std::cin >> temp;
	home_phone = temp_phone(temp);
}

void Phone_book::setWork_phone() {
	std::string temp;
	std::cout << "Enter the subscriber's work phone number \t ";
	std::cin >> temp;
	work_phone = temp_phone(temp);
}

void Phone_book::setMobile_phone() //тут не работает. (возвращаемое число отличается от введенного. Возможно в какой-то кодировке, но маловероятно.
{
	std::string temp;
	std::cout << "Enter the subscriber's work phone number \t ";
	std::cin >> temp;
	
	mobile_phone[SIZE] = temp_phone(temp, mobile_phone);
}