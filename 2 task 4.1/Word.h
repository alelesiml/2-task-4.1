#pragma once

class Word
{
	char* word;
	int size;
	int capacity;
public:
	Word();
	Word(char*);
	Word(char, int);
	Word(char*, int);
	Word(const Word&);
	Word(Word&&);
	~Word();
	void output_word();
	int get_size() const;
	int get_capacity() const;
	char get_symbol(int) const;
	void delete_word();
	void sort_word();


};