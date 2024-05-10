#include <iostream>
#include "Word.h"
#include <string>

using namespace std;

Word::Word()
{
	size = 0;
	capacity = 1;
	word = new char[capacity] {};
}

Word::Word(char* other_word)
{
	size = strlen(other_word);
	capacity = size;
	word = new char[capacity] {};

	for (int i = 0; i < size; ++i)
	{
		word[i] = other_word[i];
	}
}

Word::Word(char letter, int repeat)
{
	size = repeat;
	capacity = size;
	word = new char[capacity] {};

	for (int i = 0; i < size; ++i)
	{
		word[i] = letter;
	}
}

Word::Word(char* other_word, int n)
{
	size = 2*n;
	capacity = size;
	word = new char[capacity] {};
	for (int i = 0; i < n; ++i)
	{
		word[i] = other_word[i];
	}
	for (int i = n; i < size; ++i)
	{
		word[i] = other_word[strlen(other_word) - size + i];
	}
}

Word::Word(const Word& other_word)
{
	size = other_word.get_size();
	capacity = other_word.get_capacity();
	word = new char[capacity] {};

	for (int i = 0; i < size; ++i)
	{
		word[i] = other_word.get_symbol(i);
	}
}

Word::Word(Word&& other_word)
{
	size = other_word.get_size();
	capacity = other_word.get_capacity();
	word = new char[capacity] {};

	for (int i = 0; i < size; ++i)
	{
		word[i] = other_word.get_symbol(i);
	}
	other_word.delete_word();
}

void Word::output_word()
{
	for (int i = 0; i < size; ++i)
	{
		cout << word[i];
	}
	cout << endl;
}

Word::~Word()
{
	delete[] word;
}

int Word::get_size() const
{
	return size;
}

int Word::get_capacity() const
{
	return capacity;
}

char Word::get_symbol(int index) const
{
	return word[index];
}

void Word::delete_word()
{
	size = 0;
	capacity = 1;
	delete[] word;
	word = new char[capacity] {};
}

void Word::sort_word()
{
	char temp;
	for (int i = 1; i < size; ++i)
	{
		for (int j = size - 1; j >= i; --j)
		{
			if (word[j - 1] > word[j])
			{
				temp = word[j - 1];
				word[j - 1] = word[j];
				word[j] = temp;
			}
		}
	}
}