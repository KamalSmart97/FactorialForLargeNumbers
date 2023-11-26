#include<iostream>

using namespace std;

int factorial(int num, int * FactorialValue)
{
	int j = 0;
	unsigned long long int multiplication = 0;

	const  unsigned int size = 4500000;
	memset(reinterpret_cast<void*>(FactorialValue),-1, size);

	FactorialValue[0] = 1;

	for (int i = 1; i <= num; i++)
	{
		j = 0;
		int carryOver = 0, residue = 0, tempNum = 0;

		while (FactorialValue[j] != -1)
		{
			multiplication = (FactorialValue[j]) * i;

			multiplication += carryOver;

			residue = multiplication % 10;

			carryOver = multiplication / 10;

			FactorialValue[j] = residue;

			j++;
		}
		while (carryOver > 0)
		{
			FactorialValue[j] = carryOver % 10;

			carryOver = carryOver / 10;

			j++;
		}
	}
	return j;

}


int main()
{
	int nFactorial = 0, nNoOfDigit =0;

	int* FactorialValue = new int[4500000]();

	cout << "enter the number to find the factorial ";

	cin >> nFactorial;

	cout << "\n";

	nNoOfDigit = factorial(nFactorial, FactorialValue);

	for (int i = (nNoOfDigit-1); i >= 0; i--)
		cout << FactorialValue[i];

	return 0;

}
