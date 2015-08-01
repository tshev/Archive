#include <stdio.h>
#include <stdlib.h>
int fibo(int n) {
	if (n < 2) {
		return n;
	}
	int a=1, b=1;
	int i, tmp;
	for(i = 2; i < n; i++) {
		tmp = a + b;
		a = b;
		b = tmp;
	}
	return tmp;
	
}
int main(int argc, char **argv) {
	printf("%d\n", fibo(atoi(argv[1])));
}
