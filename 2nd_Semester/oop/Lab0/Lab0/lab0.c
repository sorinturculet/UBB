#include <stdio.h>
int main()
{
	printf("Hello world\n");
	int n;
	int suma = 0;
	printf("Introduceti un numar natural: ");
	scanf_s("%d", &n);
	for (int a = 1;a <= n;a+=1)
	{
		printf("Introduceti nr:");
		int numar;
		scanf_s("%d", &numar);
		suma += numar;
	}
	printf(" Suma numerelor este : %d\n", suma);

	printf("Introduceti numere pana la aparitia lui 0: \n");
	int suma2 = 0;
		while(1)
		{
			printf("Introduceti un numar:\n");
			int n = 0;
			scanf_s("%d", &n);
			suma2 += n;
		if (n == 0)
			break;
		}
		printf("Suma este:%d\n", suma2);
}