#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

HashTable* dictionary;
string letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void printVector(vector<Hashable*> vector)
{
	for(Hashable* h : vector)
		cout << *h << " ";
	cout << endl;
}

void printVector(vector<Word> vector)
{
	for(Word w : vector)
		cout << w << " ";
	cout << endl;
}

HashTable* readFile(char* fileName)
{
	string line;
	int numLines = 0;
	size_t tableSize = 10000;//smallest power of 2 > 10k
	ifstream wordsFile (fileName);

	if(wordsFile.is_open()){
		cout << "opened file" << endl;
		auto start = std::chrono::system_clock::now();
		
		while(getline(wordsFile, line))
			numLines++;
		
		wordsFile.clear();
		wordsFile.seekg(0, ios::beg);
		//cout << numLines << endl;
		
		dictionary = new HashTable(tableSize);
		
		string temp = "";
		int i = 0;
		Hashable* newWord;
		
		while(wordsFile >> temp && i < numLines)
		{
			newWord = new Word(temp);
			dictionary->insert(newWord);
		}
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		dictionary->loadTime = elapsed_seconds.count();
		wordsFile.close();
	}
	return dictionary;

}

vector<Word>* check(Word* w)
{
	vector<Word>* suggestions = new vector<Word>;
	if(!dictionary->contains(w))
	{
		cout << *w << " is not a word, finding suggestions... " << endl;
		Word changed;
		//change one letter
		for(int i = 0; i < w->size; i++)
		{
			string temp = w->str;
			for(int j = 0; j < 26; j++)
			{
				string temp2 = temp.replace(i, 1, letters[j]);
				changed = Word(temp2);
				if(dictionary->contains(&changed))
					suggestions->push_back(changed);

			}
		}
	}
	else
		cout << *w << " is a word " << endl;
	return suggestions;
}
void getInput()
{
	bool quit = false;
	while(!quit)
	{
		string sentence;
		vector<Word> words;
		cout << "Please enter a sentence: " << endl;
		getline(cin, sentence);

		string temp = "";
		//cout << "sentence length " << sentence.length() << endl;
		for(int i = 0; i < sentence.length() + 1; i++)
		{
			//cout << sentence[i];
			if(sentence[i] == ' ' || sentence[i] == '\0'){
				words.push_back(Word(temp));
				//cout << "adding " + temp << endl;
				temp = "";
			}else{
				temp += sentence[i];
				//cout << " added to " + temp << endl;
			}
		}
		//cout << "all words: ";
		//printVector(words);
		cout << endl;

		vector<Word>* suggestions[words.size()];
		int x = 0;
		for(Word word : words)
			suggestions[x++] = check(&word);
		cout << "There are " << words.size() << " words with suggestions"<< endl;

		for(int i = 0; i < words.size(); i++)
		{
			//cout << "size: " << suggestions[i]->size() << endl;
			cout << "Replace " << words[i] << ": ";
			for(Word w : *suggestions[i])
				cout << w << " ";
			cout << endl;
		}
		cout << "Try another sentence? y/n: ";
		char yn;
		cin >> yn;
		cout << endl;
		if(yn == 'n')
			quit = true;
	}
}


int main(int argc, char** argv)
{
	string fileName ="output";
	fileName.append(argv[1]);
	fileName += ".txt";
	ofstream outFile(fileName);

	HashTable* dictionary = readFile(argv[1]);
	/*for(int i = 0; i < dictionary->size; i++)
	{
		//cout << "Bucket #" << i << ": ";
		//printVector(dictionary->data[i]);
		//cout << endl;
	}*/
	dictionary->stats();
	getInput();
}
