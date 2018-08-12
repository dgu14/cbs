#include <bits/stdc++.h>
using namespace std;

int divisors[100005];

void precalc()
{
	for (int i = 1;i <= 100000;i++)
	{
		for (int j = i;j <= 100000;j += i)
		{
			divisors[j] ++;
		}
	}
}

int gcd(int a, int b)
{
	if (a < b) swap(a, b);

	if (b == 0) return a;
	return gcd(b, a%b);
}

int solve(int A, int B, int C)
{
	int a = divisors[A], b = divisors[B], c = divisors[C], g = divisors[gcd(gcd(A, B), C)],
		p = divisors[gcd(A, B)], q = divisors[gcd(B, C)], r = divisors[gcd(A, C)];


	return a * b*c - g * (g - 1)*(g - 2) - 2 * g*(g - 1) + g * (g - 1)*(g - 2) / 6 // g g g
		- g * (p + q + r - 3 * g) - 3 * g*(g - 1) / 2 * (p + q + r - 3 * g)  // g g x
		- g * (g - 1) / 2 * (a + b + c - 2 * (p + q + r) + 3 * g) // g g ?
		- 2 * g*(p - g)*(q - g) - 2 * g*(p - g)*(r - g) - 2 * g*(q - g)*(r - g) // g xd xd
		- (p - g)*(p - g - 1) / 2 * (c) - (q - g)*(q - g - 1) / 2 * (a) - (r - g)*(r - g - 1) / 2 * (b) // xs xs g,?,x
		- g * (p - g)*(c - q - r + g) - g * (q - g)*(a - p - r + g) - g * (r - g)*(b - p - q + g) // g x ?
		- (p - g)*(q - g)*(r - g); // x x x
}

int main()
{
	precalc();
	int tt, a, b, c;
	scanf("%d", &tt);

	while (tt--)
	{
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", solve(a, b, c));
	}

	return 0;
}
