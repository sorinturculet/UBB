#include <stdio.h>

int citire()
{/*
 functia afiseaza un mesaj, citeste un numar si il returneaza
 pre:-
 parametru:n
 tip n: int
 postconditii:n
 */
	int n;
	printf("Introduceti un numar natural: ");
	scanf_s("%d", &n);
	return n;
}
int prim(int n)
{	/*
	primeste un numar si verifica daca acesta este prim
	parametru:n
	tip n: int
	preconditii:n>2
	postconditii: returneaza: 0/1 
	*/
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	for (int i = 3;i <= n / 2;i += 1)
		if (n % i == 0)
			return 0;
	return 1;
}
void numereprime(int n,int v[])
	{/*
	 primeste un numar si il descompune ca suma de 2 numere prime

	 parametru:n
	 tip n:int
	 preconditie:n>2
	 parametru:v
	 tip v:vector de int
	 postconditie:pune in vector cele 2 numere care au suma n
	 */
	if (n <= 2)
	{
		printf("Numarul nu este mai mare decat 2\n");
			return;
	}
	for(int i=2;i<=n/2+1;i+=1)
		if (prim(i))
			if (prim(n-i))
			{
				v[0] = i;
				v[1] = n - i;
				break;
			}
	}
void maimiciprime(int n, int v[], int *contor)
	/*
	* 	 primeste un numar si returneaza in lista toata numerele mai mici decat el primi

	 parametru:n
	 tip n:int
	 preconditie:n>2
	 parametru:v
	 tip v:vector de int
	 postconditie:pune in vector cele numerele prime < n
	*/
	{
	for (int i = 2;i <n;i++)
		if (prim(i))
		{
			v[*contor] = i;
            (*contor)++;
		}
	}
int main()
{	/*
	afiseaza meniul. Daca se selecteaza valoarea 1, se calculeaza cele 2 numere prime ca suma a unui n, daca se selecteaza 2 se va inchide programul

	*/
	printf("Bine ati venit! \n");
	int n;
	while(1)
	{	
		printf("Introduceti o comanda dintre urmatoarele:\n 1.Calculeaza 2 numere prime\n 2.Inchidere program\n 3.Nr prime mai mici decat n\n");
		int comanda;
		scanf_s("%d", &comanda);
		if (comanda == 1)
		{
			n = citire();
			int sir[3];
			numereprime(n,sir);
			printf("Cele 2 numere a caror suma este %d sunt %d si %d\n", n, sir[0], sir[1]);
		}
		if (comanda == 2)
			break;
		if (comanda == 3)
		{
			n = citire();
			int sir[1000];
			int contor = 0;
			maimiciprime(n, sir,&contor);
			printf("Numerele prime mai mici decat n sunt:\n");
				for (int i = 0;i < contor;i++)
					printf("%d ", sir[i]);
                printf("\n");
		}
	}
}