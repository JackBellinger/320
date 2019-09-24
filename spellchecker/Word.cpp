#include "HashTable.h"
#include <iostream>
#include <stdlib.h>

Hashable::Hashable()
{

}
Word::Word()
{

}

Word::Word(string s)
{
	str = s;
	size = str.length();
}

long int Word::strToNum()
{
	long num = 0;

	int num4 = size/4;
	int rem = size %4;

	int k = 0;
	for(int i = 0; i < num4; i++)
		for(int j = 0; j < 4; j++)
		{
			//cout << str[size-(k+1)] << endl;
			num += long(str[size-(k+1)]) * (1 << 7*i);
			k++;
		}
	
	for(int i = 0; i < rem; i++)
	{
		//cout << str[size-(k+1)] << endl;
		num += long(str[size-(k+1)]) * (1<<7*i);
		k++;
	}
	//cout << "num: " << num <<  endl;
	return num;
}


bool Word::equal_to( Hashable& h) const
{	
	Word& w = dynamic_cast<Word&>(h);
	bool same = ( str == w.str );
	return same;
}

string Word::to_string()
{
	return str;
}
