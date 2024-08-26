//
// Created by sorn on 18-Mar-24.
//

#include "ui.h"
#include<stdio.h>
#include<string.h>
void firstoption(MyList* l){
    int day,sum;
    char type[200],description[200];
    printf("Introduceti ziua:");
    scanf("%d",&day);
    printf("Introduceti suma:");
    scanf("%d",&sum);

    rewind(stdin);
    printf("Introduceti tipul tranzactiei:");
    fgets(type,200,stdin);
    type[strlen(type)-1]=0;
    rewind(stdin);
    printf("Introduceti descrierea tranzactiei:");
    fgets(description,200,stdin);
    rewind(stdin);
    if(addTransactionToList(l,day,sum,type,description)==1)
        printf("Tranzactie adaugata cu succes\n");
}
void secondoption(MyList* l){

    printf("Tranzactiile actuale sunt:\n");
    printAll(l);
    printf("Introduceti numarul tranzactiei pe care doriti a o modifica:");
    int pos;
    scanf("%d",&pos);
    pos--;
    if(l->len<pos)
    {
        printf("Pozitie invalida");
        return ;
    }
    int day,sum;
    char type[200],description[200];
    printf("Introduceti ziua:");
    scanf("%d",&day);
    printf("Introduceti suma:");
    scanf("%d",&sum);
    getchar();
    printf("Introduceti tipul tranzactiei:");
    fgets(type,200,stdin);
    printf("Introduceti descrierea tranzactiei:");
    fgets(description,200,stdin);
    type[strlen(type)-1]=0;
    modifyTransactionInList(l,pos,day,sum,type,description);
}
void thirdoption(MyList* l){

    printf("Tranzactiile actuale sunt:\n");
    printAll(l);
    printf("Introduceti numarul tranzactiei pe care doriti a o sterge:\n");
    int pos;
    scanf("%d",&pos);
    pos-=1;
    if(pos>l->len)
        printf("Pozitie prea mare\n");
    else if(pos<0)
        printf("Pozitie prea mica\n");
    else deleteTransactionFromList(l,pos);
}
void forthoption(MyList* l){
    char crt[200];
    char ord[10];
    int suma=0;
    printf("Introduceti criteriul dupa care vreti sa vizualizati(tip/suma)\n");
    scanf("%s",crt);
    if(strcmp(crt,"tip")!=0 && strcmp(crt,"suma")!=0)
    {
        printf("Nu este un criteriu valid\n");
        return ;
    }
    else {
        if (strcmp(crt, "tip") == 0) {
            printf("Introduceti tipul dupa care vreti sa vizualizati\n");
            scanf("%s", ord);

            MyList* l_filter;
            l_filter=filterByType(l,ord);
            printAll(l_filter);
            destroyList(l_filter);

        }
        if (strcmp(crt, "suma") == 0) {
            printf("Introduceti suma cu care vreti sa filtram\n");
            scanf("%d",&suma);
            printf("Introduceti daca vreti sa filtram valorile mai mari sau mai mici decat suma(M/m)\n");
            scanf("%s",ord);
            if(strcmp(ord,"M")!=0 && strcmp(ord,"m")!=0){
                printf("Eroare! Introduceti M sau m!\n");
                return ;
            }
            MyList* l_filter;
            l_filter=filterByInt(l,ord,suma);
            printAll(l_filter);
            destroyList(l_filter);
        }
    }
}
void fifthoption(MyList* l){
    char crt[200];
    char ord[10];
    printf("Introduceti criteriul dupa care vreti sa ordonati(suma/zi)\n");

    scanf("%s",crt);
    if(strcmp(crt,"suma")!=0 && strcmp(crt,"zi")!=0)
    {
        printf("Nu este un criteriu valid\n");
        return ;
    }
    printf("Introduceti cum doriti sa fie ordonate ('c' pt crescator, 'd' pt descrescator):\n");
    scanf("%s",ord);
    if(strcmp(ord,"c")!=0 && strcmp(ord,"d")!=0)
    {
        printf("Nu este un criteriu valid\n");
        return ;
    }
    int (*f)(const void*, const void*);
    if(strcmp(crt,"zi")==0) {
        if (strcmp(ord, "c") == 0)
            f = cmpfunc_ZC;
        else
            f = cmpfunc_ZD;
    }
    if(strcmp(crt,"suma")==0) {
        if (strcmp(ord, "c") == 0)
            f = cmpfunc_SC;
        else
            f = cmpfunc_SD;
    }
    orderList(l,f);

    printf("Lista ordonata este:\n");
    printAll(l);
}

void printAll(MyList* l){
    if(l->len==0)
        printf("Nu exista tranzactii inregistrate.\n");
    for(int i=0;i<l->len;++i){
        Transaction* tr = l->myList[i];
        printf("%d. %d,%d,%s,%s\n",i+1,tr->day,tr->sum,tr->type,tr->description);
        //destroyTransaction(&tr);
    }
}
void load_transactions(MyList* l){
    addTransactionToList(l,1,30,"Intrare","Bani");
    addTransactionToList(l,2,300,"Intrare","adidasi");
    addTransactionToList(l,3,20,"Intrare","papuci");
    addTransactionToList(l,4,900,"Intrare","cantina");
    addTransactionToList(l,4,900,"Iesire","chirie");
}
void show_ui(){
    MyList* l=createList();
    int option;
    testall();
    while(1){
        printf("Bine ati venit\n");
        printf("Selectati o optiune:\n");
        printf("1.Adaugare tranzactii\n");
        printf("2.Modificare tranzactie existenta\n");
        printf("3.Sterge tranzactie existenta\n");
        printf("4.Vizualizare tranzactie dupa criteriu\n");
        printf("5.Vizualizare tranzactie ordonate\n");\
        printf("6.Iesire program.\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                firstoption(l);
                break;
            case 2:
                secondoption(l);
                break;
            case 3:
                thirdoption(l);
                break;
            case 4:
                forthoption(l);
                break;
            case 5:
                fifthoption(l);
                break;
            case 6:
                deleteAllTransaction(l);
                return;
            case 10:printAll(l);
                break;
            case 11:
                load_transactions(l);
                break;
            case 12:
                deleteAllTransaction(l);
                break;
            default:printf("Optiune invalida");
        }
    }
}