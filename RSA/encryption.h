#pragma once

#include "encryption.h"
#include <cmath>
#include <string>

using big = unsigned long long;

namespace User
{	
	extern big n, e_key, d_key;

	extern const big DEFAULT_SIGNATURE;

	int GCD(int one, int two);

	big ModX(big base, big expo, big n);

	//std::string	Encrypt(std::string message, big other_key, big other_n);//Call big Encrypt foreach chunk of data in our message.
	big			Encrypt(big plainText, big publicKey, big modN);
	//std::string	Decrypt(std::string message);							//Call big Decrypt foreach chunk of data in our message
	big			Decrypt(big cipherText, big publicKey, big modN);
	big			SendSignature(big signiture);		
	big			TestSignature(big e_signature, big other_key, big other_n, big d_signature);
}