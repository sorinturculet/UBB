#include"domain.h"
#include<malloc.h>
#include<string.h>

extern Produs* crearePr(char* nume, char* producator, int cantitate)
{
    Produs* material=malloc(sizeof (Produs));
    //size_t in loc de int pentru a scapa de warning
    size_t nrc= strlen(nume)+1;
    material->denumire = malloc(nrc*sizeof(char));
    if(material->denumire != NULL)
        strcpy(material->denumire, nume);

    nrc=strlen(producator) + 1;
    material->producator = malloc(nrc*sizeof (char));
    if (material->producator != NULL)
        strcpy(material->producator, producator);

    material->cantitate = cantitate;
    return material;
}
extern Produs* duplicatePr(Produs* Pr){
    Produs* duplicat= crearePr(Pr->denumire,Pr->producator,Pr->cantitate);
    return duplicat;
}
void destroyPr(Produs * tr){
    free(tr->denumire);
    free(tr->producator);
    free(tr);
}
