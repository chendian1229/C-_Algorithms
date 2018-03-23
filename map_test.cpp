#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

map<string,int> cnt;
vector<string> words;

template <typename T>
string repr(const T &s)
{
	stringstream ss;

	ss << s;
	string ans;
	ss >> ans;
	for (int i = 0; i < ans.length(); i++)
	{
		ans[i] = tolower(ans[i]);
	}

	sort(ans.begin(),ans.end());
	return ans;

}

int main()
{

	int n = 0;
	string s, buf;

	fstream infile;
	infile.open("test.txt",ios::in);
	if(!infile) 
	{
		cerr<<"Open file failed!"<<endl;
		return 0;
	}

	while(!infile.eof())
	{
		getline(infile,s,'\n');
		
		stringstream ss(s);
		while (ss >> buf)
		{
			if( buf == "#") 	break;   
			words.push_back(buf);
			string r = repr(buf);

			if(!cnt.count(r))	cnt[r] = 0;
			cnt[r]++;
		}

	}

	vector<string> ans;
	for (int i = 0; i< words.size(); i++)
	{
		if(cnt[repr(words[i])] == 1)	ans.push_back(words[i]);
	}

/*******************************************************************************
		//By quick sort output map

	// sort(ans.begin(),ans.end());
	// for (int i = 0; i < ans.size(); i++)
	// 	cout << ans[i] << endl;
******************************************************************************/
	set<string> dict;
	for(vector<string>::iterator it = ans.begin(); it != ans.end(); it++)  			//(int j = 0; j < ans.size(); j++)
	{
		dict.insert(*it);
	}

	for(set<string>::iterator it = dict.begin(); it != dict.end(); it++)
	{
		cout<< *it <<endl;
	}

	return 0;
}
