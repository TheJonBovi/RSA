
#include "stdafx.h"

#include "keygen.h"
#include "encryption.h"

void generateKey(int p, int q)
{
	auto const n = p * q;
	auto const phi = (p - 1) * (q - 1);
	int e = phi - 1;
	bool foundE{};

	while(!foundE)
	{
		if(User::GCD(e, phi) == 1) foundE = true;
		else e--;
	}
}
