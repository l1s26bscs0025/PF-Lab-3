# include<iostream>
# include<fstream>
using namespace std;
int main() {
	int a, b, ans = 0;
	char op;
	char ch;
	int score = 0;
	float div = 0;

	int question = 0;
	ifstream infile("quiz.txt");
	ofstream outfile("correction.txt");

	if (!infile || !outfile)
	{
		cout << "files not exist ";
		return 0;
	}
	while (infile >> a >> op >> b >> ch >> ans)
	{
	int 	sum = 0;
		if (op == '+')
		{
			sum = a + b;
			if (ans == sum)
			{
				cout << a << "+" << b << "=" << ans << "= correct" << endl;
				score++;
			}
			else
			{
				cout << a << "+" << b << "=" << ans << "= wrong" << endl;

				outfile << a << op << b << ch << a + b << "you wrote=" << ans << endl;
			}
		}
		if (op == '-')
		{
			sum = a - b;
			if (ans == sum)
			{
				cout << a << "-" << b << "=" << ans << "= correct" << endl;
				score++;
			}
			else
			{
				cout << a << "-" << b << "=" << ans << "= wrong" << endl;

				outfile << a << op << b << ch << a - b << "you wrote=" << ans << endl;
			}
		}
		if (op == '*')
		{
			sum = a * b;
			if (ans == sum)
			{
				cout << a << "*" << b << "=" << ans << "= correct" << endl;
				score++;
			}
			else
			{
				cout << a << "*" << b << "=" << ans << "= wrong" << endl;

				outfile << a << op << b << ch << a * b << "you wrote=" << ans << endl;
			}
		}
		if (op == '/')
		{
			
		
			 if (b == 0 || a == 0)
			 {
				 cout << "invalid input" << endl;
				 break;
			 }
			 else
			 {
				 div = a / b;


				 if (ans == div)
				 {
					 cout << a << "/" << b << "=" << ans << "= correct" << endl;
					 score++;
				 }
				 else
				 {
					 cout << a << "/" << b << "=" << ans << "= wrong" << endl;

					 outfile << a << op << b << ch << a / b << "you wrote=" << ans << endl;
				 }
			 }
		}
		question++;
	}
	infile.close();
	outfile.close();

	cout << "score=" << score << "/" << question << endl;



	return 0;
}