#include "keygen.h"
#include "encryption.h"

using namespace User;

keyset GenerateKey(const big p,const big q, const big inite)
{
	big const n = p * q;
	big const phi = (p - 1) * (q - 1);
	big e = inite;

	bool foundE{};
	while(!foundE)
	{
		if(User::GCD(e, phi) == 1) foundE = true;
		else e++;
	}

	big d = 2;
	//d = InverseGCD(e, phi);

	bool foundD{};
	while(!foundD && d < phi)
	{
		if((e * d) % phi == 1) foundD = true;
		else d++;
	}

	keyset retset;
	retset.e = e;
	retset.d = d;
	retset.n = n;

	return retset;
}

// TODO: This doesnt work 
int InverseGCD(const int e, const int phi)
{
	int g[100];
	int u[100];
	int v[100];

	auto i{ 1 };
	int d;
	int y;

	g[0] = phi;
	g[1] = e;
	u[0] = v[1] = 1;
	u[1] = v[0] = 0;

	while (g[i])
	{
		g[i] = u[i] * phi + v[i] * e;
		y = g[i - 1] / g[i];
		g[i + 1] = g[i - 1] - y * g[i];
		u[i + 1] = u[i - 1] - y * u[i];
		v[i + 1] = v[i - 1] - y * v[i];
		i++;
	}
	
	if (v[i - 1] <= 0)
	{
		d = v[i - 1] + n;
	}
	else
	{
		d = v[i - 1] + 2 * n;
	}

	return d;
}
