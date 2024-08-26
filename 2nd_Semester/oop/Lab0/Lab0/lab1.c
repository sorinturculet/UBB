#include <stdio.h>

int citire()
{
	int n;
	printf("Introduceti un numar natural: ");
	scanf_s("%d", &n);
	return n;
}
int main()
{
	printf("Hello world\n");
	int n;
	n=citire();
	
}