#pragma once
#include "encryption.h"

struct keyset
{	
	big e;
	big d;
	big n;
};

keyset GenerateKey(const big p, const big q, const big inite);

int InverseGCD(const int e, const int phi);
