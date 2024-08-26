#include <stdio.h>
#include "service/Service.h"
#include "Teste.h"
#include "list/listamea.h"
//Problema 6

void adaugare(ManagerLists* store) {
	int ok = 1;
	while (ok) {
		printf("Introduceti numele materiei prime: ");
		char nume[256];
		scanf("%s", nume);
		if (!validare_nume(nume)) {
			printf("Numele materiei prime trebuie sa contina minim 3 litere!\n");
			continue;
		}
		printf("Introduceti numele producatorului: ");
		char prod[256];
		scanf("%s", prod);
		if (!validare_producator(prod)) {
			printf("Numele producatorului trebuie sa contina minim 3 litere!\n");
			continue;
		}
		printf("Introduceti cantitatea: ");
		int cant;
		scanf("%d", &cant);
		if (!validare_cantitate(cant)) {
			printf("Cantitate insuficienta!\n");
			continue;
		}
		int index = cauta(store, nume);
		if (index == -1)
		{
			add(store, nume, prod, cant);
			printf("Adaugarea a avut loc cu succes!\n");
		}
		else {
			update(store, cant, index);
			printf("Produsul exista deja in baza de date, stocul a fost actualizat\n");
		}
		ok = 0;
	}
}

void modificare1(ManagerLists* store) {
	int ok = 1;
	while (ok) {
		printf("Introduceti numele produsului care doriti sa modificat din baza de date: ");
		char nume[256];
		scanf("%s", nume);
		if (!validare_nume(nume)) {
			printf("Numele materiei prime trebuie sa contina minim 3 litere!\n");
			continue;
		}
		int index = cauta(store, nume);
		if (index != -1) {
			printf("Introduceti cantitatea noua: ");
			int cant;
			scanf("%d", &cant);
			modificare(store, index, cant);
			ok = 0;
			printf("Modificarea a avut loc cu succes!");
		}
		else {
			printf("Materia prima nu a fost gasita!");
		}
		
	}
}

void stergere(ManagerLists* store) {
	int ok = 1;
	while (ok) {
		printf("Introduceti numele produsului care doriti sa fie sters din baza de date: ");
		char nume[256];
		scanf("%s", nume);
		if (!validare_nume(nume)) {
			printf("Numele materiei prime trebuie sa contina minim 3 litere!\n");
			continue;
		}
		int index = cauta(store, nume);
		if (index != -1) {
			remove_prod(store,index);
			ok = 0;
			printf("Produsul a fost sters cu succes!\n");
		}
		else {
			printf("Materia prima nu a fost gasita!\n");
		}
	}
}

void vizualizare(ManagerLists* store) {
	printf("1) Nume \n2) Cantitate \n0) Iesire\n");
	int optiune;
	scanf("%d", &optiune);

	printf("1) Crescator \n2) Descrescator \n0) Iesire\n");
	int monotonie;
	scanf("%d", &monotonie);
	if ((optiune == 1 || optiune == 2) && (monotonie == 1 || monotonie == 2)) {
		MyList* lista= createList((void (*)(void *)) destroyPr);
		if(optiune == 1 && monotonie == 1)
			ordonare(store, lista, criteriu_nume_cresc);
		else if (optiune == 1 && monotonie == 2)
			ordonare(store, lista, criteriu_nume_descr);
		else if (optiune == 2 && monotonie == 1)
			ordonare(store, lista, criteriu_cant_cresc);
		else if (optiune == 2 && monotonie == 2)
			ordonare(store, lista, criteriu_cant_descr);
		for (int j = 0; j < lista->lungime; j++)
			printf("%s -- %s -- %d\n", ((Produs*)lista->v[j])->denumire, ((Produs*)lista->v[j])->producator, ((Produs*)lista->v[j])->cantitate);
		eliberator(lista);
	}
	else printf("Introduceti valori adecvate!\n");
}

void filtrare(ManagerLists* store)
{
	printf("1) Filtrare dupa prima litera \n2) Filtrare dupa cantitate mai mica decat un numar dat \n0) Iesire\n");
	int optiune;
	scanf("%d", &optiune);
	if (optiune == 1)
	{
		char litera[20];
		printf("Introduceti litera: ");
		scanf("%s", litera);
		MyList* lista= createList((void (*)(void *)) destroyPr);
		filtr_litera(store, lista, litera);
		for (int j = 0; j < lista->lungime; j++)
		{
            printf("%s -- %s -- %d\n", ((Produs*)lista->v[j])->denumire, ((Produs*)lista->v[j])->producator, ((Produs*)lista->v[j])->cantitate);
		}
		eliberator(lista);
	}
	else if (optiune == 2) {
		int cant;
		printf("Introduceti cantitatea: ");
		scanf("%d", &cant);
		MyList* lista= createList((void (*)(void *)) destroyPr);
		filtr_cantitate(store, lista, cant);
		for (int j = 0; j < lista->lungime; j++)
		{
            printf("%s -- %s -- %d\n", ((Produs*)lista->v[j])->denumire, ((Produs*)lista->v[j])->producator, ((Produs*)lista->v[j])->cantitate);
		}
		eliberator(lista);
	}
}
void filtrare_2(ManagerLists* store)
{
    printf("Introduceti numele producatorului dupa care vreti sa filtrati.");
    char prod[200];
    scanf("%s", prod);
    puts("HERE");
    MyList* lista= createList((void (*)(void *)) destroyPr);
    filtr_producator(store, lista, prod);
    for (int j = 0; j < lista->lungime; j++)
    {
        printf("%s -- %s -- %d\n", ((Produs*)lista->v[j])->denumire, ((Produs*)lista->v[j])->producator, ((Produs*)lista->v[j])->cantitate);
    }
    eliberator(lista);
}
void undoOption(ManagerLists* store){
    undoFunction(store);
}
void load(ManagerLists* store){

    add(store, "Zahar", "Tarom", 100);
    add(store, "Sare", "Wizz", 200);
    add(store,"Miere", "Asus", 300);
}
void printAll(MyList* lista){
    for (int j = 0; j < lista->lungime; j++)
        printf("%s -- %s -- %d\n", ((Produs*)lista->v[j])->denumire, ((Produs*)lista->v[j])->producator, ((Produs*)lista->v[j])->cantitate);

}
void start()
{
    ManagerLists store=createManagerList();

	int n = 1;
	while (n != 0) {
		//system("cls");
		printf("1) adaugare de materie prima (daca exista deja in stoc se actualizeaza cantitatea) \n2) modificare materie prima \n3) stergere  materie prima \n4) Vizualizare materii prime care satisfac un criteriu (numele incepe cu o litera data, cantitatea disponibila e mai mica decat un numar dat) \n5) Vizualizare materii prime din stoc ordonat dupa nume sau cantitate disponibila(crescator / descrescator) \n6)Undo 7)Filtrare Producator 0) Iesire\n");
		scanf("%d", &n);
			switch (n) {
			case 1:
				adaugare(&store);
				break;
			case 2:
				modificare1(&store);
				break;
			case 3:
				stergere(&store);
				break;
			case 4:
				filtrare(&store);
				break;
			case 5:
				vizualizare(&store);
				break;
            case 6:
                undoOption(&store);
                break;
            case 7:filtrare_2(&store);
                break;
            case 11:
                load(&store);
                break;
            case 10:
                printAll(store.l);
                break;
			case 0:
				n = 0;
                    destroyManagerList(&store);
				break;
            default:
                printf("Optiune invalid\n");
                break;
			}
	}
}

void test_all()
{
	test_adaugare();
	test_cautare();
	test_update();
	test_remove();
    test_ordonare();
	test_modificare();
	test_filtrLit();
    test_filtrCant();
    test_filtrProd();
    test_validare();
    test_liste_liste();
    test_undo();
}

int main()
{
	test_all();
    //start();
	return 0;
}