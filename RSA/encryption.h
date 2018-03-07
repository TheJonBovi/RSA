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

	big	Encrypt(big message, big other_key, big other_n);

	big	Decrypt(big message, big private_key, big other_n);
}