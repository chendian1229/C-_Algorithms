#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	char data[100];

	ofstream outfile;
	outfile.open("test.csv");

	if(!outfile)
	{
		cout << "The file opend failed !" << endl;
		return 0;
	}

	for(int i = 1; i <=100; i++ )
	{
		if( i % 10 != 0)	outfile << i << "," ;
		else outfile << i << "," <<endl ;
	}

	outfile.close();
	cout << "Write the file successful!"<<endl;

	fstream infile;  //read the file test.csv
	infile.open("test.csv",ios::in);

	if(!infile)
	{
		cout << "Open the file failed! " << endl;
		return 0;
	}
	cout << "start read the file !" << endl;

	string date;

	while ( !infile.eof() )
	{
		getline( infile, date , '\n');
		//infile.getline( data,256,'\n');
		// infile >> date;
		 cout << date.c_str() << endl;
	}

	infile.close();


	//cout << infile.getline() << endl;



	return 0;


}