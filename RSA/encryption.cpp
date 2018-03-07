#include "encryption.h"

namespace User
{	
		big n,		//The number to modulate messages sent to us
			e_key,	//Our public  encryption key
			d_key;	//Our private decryption key
//		message,	//A large piece of the message
//		other_n,	//The number to modulate messages we send
//		other_key:	//The other's public encryption key
//	string message:	//The whole message we are sending or recieving at this time, not including the signiture.

	const big DEFAULT_SIGNATURE = 0b1010101010101010101010101010101010101010101010101010101010101010;

	int GCD(int one, int two)
	{	
		if(0 == one) return two;
		if(0 == two) return one;
		return GCD(two, one % two);
	}

	big ModX(big base, big expo, big n)
	{	
		big ans = 1;
		while(expo--){ ans = ans*base % n; }
		return ans;
	}

	//std::string	Encrypt(std::string message, big other_key, big other_n){ return message; }//Call big Encrypt foreach chunk of data in our message.

	big			Encrypt(big message, big other_key, big other_n)		{ return ModX(message, other_key, other_n); }

	//std::string	Decrypt(std::string message)							{ return message; }//Call big Decrypt foreach chunk of data in our message

	

	big			SendSignature(big signiture = DEFAULT_SIGNATURE)		{ return Decrypt(signiture); }

	big			TestSignature(big e_signature, big other_key, big other_n, big d_signature = DEFAULT_SIGNATURE)
					{ return d_signature == ModX(e_signature, other_key, other_n); }

	big	Encrypt(big plainText, big publicKey, big modN)
	{

		big cipherText;

		cipherText = plainText = pow(cipherText, publicKey);
		plainText = plainText % modN;  //this weirdness is split into 2 lines because POW was being difficult

		return plainText;



	}

	big	Decrypt(big cipherText, big privateKey, big modN) 
	{ 
	
		big plainText;

		plainText = pow(cipherText, privateKey);
		plainText = plainText % modN;  //this weirdness is split into 2 lines because POW was being difficult

		return plainText;
	
	}

}