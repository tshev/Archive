#include <stdio.h>
#include <stdlib.h>
int fibo(int n) {
	if (n < 2) {
		return n;
	}
	else return fibo(n-1) + fibo(n-2);
}
int main(int argc, char** argv) {
	printf("%d\n", fibo(atoi(argv[1])));
}
