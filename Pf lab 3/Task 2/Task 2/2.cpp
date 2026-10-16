# include<iostream>
# include<fstream>
using namespace std;
int main() {

	int day, month, year = 0;
	int inhour, inmin, outhour, outmin = 0;
	char slash;
	int start, finish = 0;
	int work ,late=0;
	int total = 0;
	ifstream infile("attandence.txt");
	if (!infile)
	{
		cout << "file doesnot exist" << endl;
		return 0;
	}
	while (infile >> day >> slash >> month >> slash >> year >> inhour)
	{
		infile.ignore(1, ':');
		infile >> inmin;

		infile >> outhour;
		infile.ignore(1, ':');
		infile >> outmin;

		start = inhour * 60 + inmin;
		finish = outhour * 60 + outmin;
		work = finish - start;
		total = total + work;
		cout << day << "/" << month << "/" << year << endl;
		cout << " worked " << work / 60 << " h ";
		cout << work % 60 << " min"<<endl;

		if (inhour > 9 || (inhour == 9 && inmin > 0))
		{
			cout << " (LATE)";
			late++;
		}
	}
	return 0;
}