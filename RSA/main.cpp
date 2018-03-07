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
				keyset keys0;
				keyset keys1;
				keyset keys2;


				//GenerateKey(59, 79, 0);
				//GenerateKey(59, 79, 1);
				keys0 = GenerateKey(10067, 10159, 2);
				keys1 = GenerateKey(10067, 10159, 2);
				keys2 = GenerateKey(10067, 10159, 2);

				User::e_key = keys0.e;
				User::d_key = keys0.d;
				User::n		= keys0.n;

			/*for(int i{}; i < 3; i++)
			{ 
				cout << " Keyset" << i + 1 << ": \n";
				cout << " N: " << keys0[i][0] << "\n";
				cout << " e: " << keys1[i][1] << "\n";
				cout << " d: " << keys2[i][2] << "\n";
			}*/

			break;
			}

		case 2:
			{
			cout << " Please input Plaintext: \n";
			cin >> plainText;
			cout << " Please input N: \n";
			cin >> valN;
			cout << " Please input e: \n";
			cin >> e;
			cout << " The ciphertext is: ";
			cout << Encrypt(plainText, e, valN);

			break;
			}

		case 3:
		{
			cout << " Please input Ciphertext: \n";
			cin >> cipherText;
			cout << " Please input N: \n";
			cin >> valN;
			cout << " Please input d: \n";
			cin >> d;
			cout << " The plaintext is: ";
			cout << Decrypt(cipherText, d, valN);
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
