#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

enum class Type_of_book {
	fiction,
	technical
};

class book {
private:
	Type_of_book type;
	string author;
	string title;

public:
	book(string tm_author, string tm_title, Type_of_book tm_type) {
		if (tm_author == "" || tm_title == "") {
			throw invalid_argument("invalid author or titile");
		}

		author = tm_author;
		title = tm_title;
		type = tm_type;

	}
	string Get_Author() {
		return author;
	}
	string Get_Title() {
		return title;
	}
	Type_of_book Get_Type() {
		return type;
	}
};


class library {
private:
	vector<unique_ptr<book>> list_books;

public:
	void add_book(const string& author, const string& title, Type_of_book type) {
		list_books.push_back(make_unique <book>(author, title, type));
		cout << "added book " << title << " author " << author << endl;
	}

	void show_list_books() {
		for (const auto& obj : list_books) {

			string type;
			if (obj->Get_Type() == Type_of_book::fiction) {
				type = "fiction";
			}
			else {
				type = "techical";
			}
			cout << "title " << obj->Get_Title() << " author " << obj->Get_Author() << " type " << type << endl;

		}
	}

	void count_books_without_switch() {
		cout << "count of books without switch" << endl;
		int fiction_count = 0;
		int technical_count = 0;

		for (const auto& book_ptr : list_books) {
			if (book_ptr->Get_Type() == Type_of_book::fiction) {
				fiction_count++;
			}
			else {
				technical_count++;
			}

		}
		cout << "technical >> " << technical_count << " fiction >> " << fiction_count << endl << endl;
	}

	void count_books_with_switch() {
		cout << "count of books with switch" << endl;
		int fiction_сount = 0;
		int technical_count = 0;
		for (auto const& obj : list_books) {
			switch (obj->Get_Type())
			{
			case Type_of_book::fiction:
				fiction_сount++;
				break;

			case Type_of_book::technical:
				technical_count++;
				break;

			}
		}
		cout << "technical >> " << technical_count << " fiction >> " << fiction_сount << endl << endl;
	}
};



int main() {
	setlocale(LC_ALL, "RU");
	library my_lib;

	my_lib.add_book("Лев Толстой", "Война и мир", Type_of_book::fiction);
	my_lib.add_book("Федор Достоевский", "Преступление и наказание", Type_of_book::fiction);
	my_lib.add_book("Антон Чехов", "Вишневый сад", Type_of_book::fiction);
	my_lib.add_book("Александр Пушкин", "Евгений Онегин", Type_of_book::fiction);
	my_lib.add_book("Михаил Булгаков", "Мастер и Маргарита", Type_of_book::fiction);

	my_lib.add_book("Бьярне Страуструп", "Язык программирования C++", Type_of_book::technical);
	my_lib.add_book("Роберт Мартин", "Чистый код", Type_of_book::technical);
	my_lib.add_book("Стив Макконнелл", "Совершенный код", Type_of_book::technical);
	my_lib.add_book("Дональд Кнут", "Искусство программирования", Type_of_book::technical);
	cout << endl << endl;
	// Вывод всех книг
	my_lib.show_list_books();
	cout << endl << endl;

	my_lib.count_books_with_switch();

	my_lib.count_books_without_switch();




	int n;
	cin >> n;


	int* first_array{ new int[n] };
	double second_array[10];
	short third_array[10];

	cout << "first_array (int)" << endl;
	for (int i = 0; i < n; i++) {
		cin >> first_array[i];
	}

	cout << "second_array (double)" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> second_array[i];
	}

	cout << "third_array (short)" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> third_array[i];
	}


	cout << "first >>> ";
	for (int i = 0; i < n; i++) {
		cout << first_array[i] << "( " << &first_array[i] << " ) ";
	}
	cout << endl;
	cout << "second >>> ";
	for (int i = 0; i < 10; i++) {
		cout << second_array[i] << "( " << &second_array[i] << " ) ";
	}
	cout << endl;
	cout << "third >>> ";
	for (int i = 0; i < 10; i++) {
		cout << third_array[i] << "( " << &third_array[i] << " ) ";
	}
	delete[] first_array;
	delete[] second_array;
	delete[] third_array;

	return 0;
}
