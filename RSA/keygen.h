#pragma once
#include "encryption.h"

struct keyset
{	
	big e;
	big d;
	big n;
};

keyset GenerateKey(const int p, const int q);

int InverseGCD(const int e, const int phi);
