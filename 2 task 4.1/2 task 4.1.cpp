//

#include <iostream>
#include "Word.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	char w[100]{};
	cout << "Введите слово: ";
	cin.getline(w,sizeof w);
	Word word_1(w);
	word_1.output_word();
	Word word_2('o', 4);
	word_2.output_word();
	Word word_3(w, 3);
	word_3.output_word();
	Word word_4(word_2);
	word_4.output_word();
	Word word_5(move(word_1));
	word_5.output_word();
	cout << "w1 = ";
	word_1.output_word();
	cout << endl;
	word_5.sort_word();
	word_5.output_word();
}