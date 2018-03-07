#pragma once

#include "encryption.h"
#include <cmath>
#include <string>

using big = unsigned long long;

struct keyset
{	big e;
	big d;
	big n;
};

namespace User
{
	extern big n, e_key, d_key;

	extern const big DEFAULT_SIGNATURE;

	int GCD(int one, int two);

	big ModX(big base, big expo, big n);

	big	Encrypt(big plainText, big publicKey, big modN);

	big	Decrypt(big cipherText, big privateKey, big modN);
}