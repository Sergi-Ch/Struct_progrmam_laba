#include<iostream>
#include<string>

using namespace std;

class Publication {
public:
	string title;
	float price;
	void getdata();
	void putdata();
};

class Sales {
public:
	float sales[3];
	void getdata();
	void putdata();

};

class Book : public Publication, public Sales {
public:
	int pages;
	void getdata();
	void putdata();
};

class Tape : public Publication, public Sales {
public:
	int time_audio;
	void getdata();
	void putdata();
};

void Publication::getdata() {
	cout << "please enter title" << endl;
	getline(cin, title); // шоб пробел норм обработал
	cout << "please enter price" << endl;
	cin >> price;
	cin.ignore(); //очистить буфер от \n
}

void Publication::putdata() {
	cout << "title >> " << title << "\n price >> " << price << endl;

}

void Sales::getdata() {
	cout << "please enter price during last 3 months" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> sales[i];
	}
}

void Sales::putdata() {
	for (int i = 0; i < 3; i++) {
		cout << "Month " << i + 1 << " >> " << sales[i] << endl;
	}

}

void Book::getdata() {
	Publication::getdata();
	Sales::getdata();
	cout << "enter how many pages has book >> ";
	cin >> pages;
}
void Book::putdata() {
	Publication::putdata();
	Sales::putdata();
	cout << "It has " << pages << " pages" << endl;
}
void Tape::getdata() {
	Publication::getdata();
	Sales::getdata();
	cout << "enter how many minutes it has >> ";
	cin >> time_audio;
}
void Tape::putdata() {
	Publication::putdata();
	Sales::putdata();
	cout << "it has " << time_audio << " minutes of audio" << endl;
}


int main() {
	Book b;
	b.getdata();
	b.putdata();



	return 0;
}
