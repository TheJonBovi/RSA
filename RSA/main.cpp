// main.cpp : Defines the entry point for the console application.
//

#include "keygen.h"
#include "encryption.h"
#include <iostream>

using namespace std;// /FORCE:MULTIPLE
using namespace User;

int main()
{
	big e, d;
	big valN;
	big plainText;
	big cipherText;
	int choice;
	bool programRun = true;

	while (programRun)
	{
		cout << "************RSA Multitool************\n";
		cout << endl;
		cout << " 1 - Key Generation\n";
		cout << " 2 - Encrypt\n";
		cout << " 3 - Decrypt\n";
		cout << " 4 - Exit\n";
		cout << endl;
		cout << " Enter your choice and press return: ";

		cin >> choice;

		cout << endl;

		switch (choice)
		{
		case 1:
			{
				//GenerateKey(59, 79, 1);
				const keyset keys1 = GenerateKey(59, 79);
				const keyset keys2 = GenerateKey(10067, 10159);
				const keyset keys3 = GenerateKey(10067, 10159);

				cout << " ***Keyset 1*** \n";
				cout << " N: " << keys1.n << "\n";
				cout << " e: " << keys1.e << "\n";
				cout << " d: " << keys1.d << "\n";
				cout << endl;

				cout << " ***Keyset 2*** \n";
				cout << " N: " << keys2.n << "\n";
				cout << " e: " << keys2.e << "\n";
				cout << " d: " << keys2.d << "\n";
				cout << endl;

				cout << " ***Keyset 3*** \n";
				cout << " N: " << keys3.n << "\n";
				cout << " e: " << keys3.e << "\n";
				cout << " d: " << keys3.d << "\n";
				cout << endl;

			break;
			}

		case 2:
			{
			cout << " Please input Plaintext: ";
			cin >> plainText;
			cout << endl;
			cout << " Please input N: ";
			cin >> valN;
			cout << endl;
			cout << " Please input e: ";
			cin >> e;
			cout << endl;
			cout << " The ciphertext is: ";
			cout << Encrypt(plainText, e, valN);
			cout << endl << endl;

			break;
			}

		case 3:
			{
			cout << " Please input Ciphertext: ";
			cin >> cipherText;
			cout << endl;
			cout << " Please input N: ";
			cin >> valN;
			cout << endl;
			cout << " Please input d: ";
			cin >> d;
			cout << endl;
			cout << " The plaintext is: ";
			cout << Decrypt(cipherText, d, valN);
			cout << endl << endl;

			break;
			}

		case 4: 
			cout << " End of Program.\n";
			programRun = false;

			break;

		default: 
			cout << " Not a Valid Choice. Choose again. \n";
			cin >> choice;
			cout << endl;

			break;
		}
	}

    return 0;
}
