#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("char = %ld octet(s)\n", sizeof(char));
	printf("unsigned char = %ld octet(s)\n", sizeof(unsigned char));
	printf("int = %ld octet(s)\n", sizeof(int));
	printf("unsigned int = %ld octet(s)\n", sizeof(unsigned int));
	printf("long = %ld octet(s)\n", sizeof(long));
	printf("unsigned long = %ld octet(s)\n", sizeof(unsigned long));
	printf("long long= %ld octet(s)\n", sizeof(long long));
	printf("unsigned long long = %ld octet(s)\n", sizeof(unsigned long long));
	printf("double = %ld octet(s)\n", sizeof(double));
	printf("\nint max value = %i octet(s)\n", INT_MAX);
	printf("u int max value = %u octet(s)\n", UINT_MAX);
	printf("long max value = %ld octet(s)\n", LONG_MAX);
	printf("u long max value = %lu octet(s)\n", ULONG_MAX);
	printf("long long max value = %lld octet(s)\n", LLONG_MAX);
	printf("u long max value = %llu octet(s)\n", ULLONG_MAX);
}
