from Utilities.Getters import *
def CautareGreaterSum(list,sumLimit):
    '''
        citeste o suma si afiseaza toate cheltuielile avand suma mai mare
        Preconditions: Citeste suma de la utilizator
                        Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
        Post-Conditions: Lista de cheltuieli dorita afisata.
        '''
    existsElement=0
    for element in list:
        if(getSum(element)>=sumLimit):
            existsElement=1
            print(element)
    if(existsElement==0):
        print('Nu exista cheltuiala cu suma mai mare decat cea introdusa')

def CautareDaySum(list,dayLimit,sumLimit):
    '''
            citeste o zi si o suma si afiseaza toate cheltuielile avand suma mai mare
            Preconditions: Citeste suma de la utilizator
                            Citeste ziua de la utilizator
                            Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
            Post-Conditions: Lista de cheltuieli dorita afisata.
            '''
    existsElement = 0
    for element in list:
        if (getSum(element) <= sumLimit and getDay(element)<=dayLimit):
            existsElement = 1
            print(element)
    if (existsElement == 0):
        print('Nu exista cheltuiala cu suma mai mare decat cea introdusa')


def CautareType(list,typeToSearch):
    '''
                citeste un tip si afiseaza toate cheltuielile avand tipul cerut
                Preconditions: Citeste tipul de la utilizator
                                Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
                Post-Conditions: Lista de cheltuieli dorita afisata.
                '''
    existsElement = 0
    for element in list:
        if (getType(element)==typeToSearch):
            existsElement = 1
            print(element)
    if (existsElement == 0):
        print('Nu exista cheltuiala care sa aiba tipul introdus')