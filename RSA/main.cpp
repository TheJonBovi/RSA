// main.cpp : Defines the entry point for the console application.
//

#include "keygen.h"
#include "encryption.h"
#include "signature.h"
#include <iostream>

using namespace std;// /FORCE:MULTIPLE

int main()
{
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

			GenerateKey(59, 79);

			break;
			}

		case 2:
			{

			break;
			}

		case 3: 
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
