#include "stdafx.h"
#include "Maths_helper.h"

Maths_helper::Maths_helper()
{
}

int Maths_helper::positive_modulo(int i, int n) {
	return (i % n + n) % n;
}

int Maths_helper::mul_inv(int a, int n)
{
	int n0 = n, t, q;
	int x0 = 0, x1 = 1;
	if (n == 1) return 1;
	while (a > 1) {
		q = a / n;
		t = n, n = a % n, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += n0;
	return x1;
}