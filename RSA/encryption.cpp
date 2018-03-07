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
	big	Encrypt(big message, big other_key, big other_n) { return ModX(message, other_key, other_n); }

	big	Decrypt(big message, big private_key, big other_n) { return ModX(message, private_key, other_n); }

}