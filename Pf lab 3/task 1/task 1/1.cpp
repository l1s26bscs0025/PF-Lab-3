# include<iostream>
# include<fstream>
using namespace std;
int main() {
	const int size = 7;
	double arr[size];
	float average = 0;
float 	sum = 0;

	ifstream infile("rainfall.txt");

	if (!infile)
	{
		cout << "file doesnot exist ";
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		infile >> arr[i];
		infile.ignore(100, ',');

	}
	infile.close();
	ofstream write("rainy-days.txt");

	if (!write)
	{
		cout << "rainy days file does not exits ";
		return 0;
	}
	
	for (int i = 0; i < size; i++)
	{
		cout << "day" << i + 1 << " " << arr[i] << "mm" << endl;;
		sum = sum + arr[i];
		if (arr[i]>0)
		{
			write << arr[i];

		}

	}
	average = sum / size;
	cout << "average rainafll =" << average <<"mm"<< endl;
	cout << "total ranifall =" << sum<<"mm"<<endl;
	cout << "total days =" << size << endl;

	return 0;
 }