// main.cpp : Defines the entry point for the console application.
//

#include "keygen.h"
#include "encryption.h"
#include "signature.h"
#include <iostream>

using namespace std;// /FORCE:MULTIPLE
using namespace User;

int main()
{
	int choice;
	big keyP, keyQ;
	big key;
	big valN;
	big plainText;
	big cipherText;
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

			cout << "Please input 1st prime number\n";
			cin >> keyP;
			cout << "Please input 2nd prime number\n";
			cin >> keyQ;

			key = GenerateKey(59, 79);

			break;
			}

		case 2:
			{

			cout << "Please input Plaintext \n";
			cin >> plainText;
			cout << "Please input N \n";
			cin >> valN;
			cout << Encrypt(plainText, key, valN);

			break;
			}

		case 3:
		{
			cout << "Please input Ciphertext \n";
			cin >> cipherText;
			cout << "Please input N \n";
			cin >> valN;
			cout << Decrypt(cipherText, key, valN);
			break;
		}

		case 4: 
			cout << " End of Program.\n";
			programRun = false;
			return 0;

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
