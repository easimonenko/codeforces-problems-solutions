#include <stdio.h>

int main (int argc, char *argv[])
{
	int n, m, a;
	scanf("%d %d %d", &n, &m, &a);
	printf("%lld\n", (long long)(n / a + (n % a != 0 ? 1 : 0)) * (m / a + (m % a != 0 ? 1 : 0)));
	
	return 0;
}
