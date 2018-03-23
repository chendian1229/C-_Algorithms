#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <fstream>

using namespace std;

set<string> dict;

int main()
{
	fstream infile;
	infile.open("test.txt", ios::in);

	if(!infile)
	{
		cout << "Open file failed!" << endl;
		return 0;
	}

	string s, buf;


	while ( !infile.eof() )
	{
		getline( infile , s , '\n');
		for (int i = 0; i < s.length(); i++ )
		{
			if(isalpha(s[i]))	s[i] = tolower(s[i]); 
			else s[i] = ' ';
		}

		stringstream ss(s);
		while (ss >> buf)	dict.insert(buf);

	}

	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
	{
		cout << *it << "\n";
	}

	infile.close();

	return 0;
}