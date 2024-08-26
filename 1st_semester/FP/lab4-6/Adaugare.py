from UI.AdaugareUI import *
from Utilities.Getters import *
from Utilities.Validation import *
def Adaugare(list,listaElementeNoi):
    '''
    citeste cheltuiala si o adauga in lista
    Preconditions: Citeste o noua cheltuiala, avand cele 4 atribute separate prin spatiu
                    Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
    Post-Conditions: Lista de cheltuieli actualizata.
    '''

    list.append(listaElementeNoi)
    return list


def verifyElementInList(list,listaDeActualizat):
    indexElementDeActualizat = int(-1)
    for index, element in enumerate(list):
        if getName(element)== getName(listaDeActualizat):
            if (getSum(element) == getSum(listaDeActualizat)):
                if (getDay(element) == getDay(listaDeActualizat)):
                    indexElementDeActualizat = index
    return indexElementDeActualizat

def actualizareCheltuiala(list,indexOld,elementDeActualizat):
    '''
        Cauta in lista o cheltuiala existenta, introdusa de utilizator si o actualizeaza
        Preconditions: Citeste o cheltuiala veche, pe care o cauta in lista.
                        Citeste o noua cheltuiala, avand cele 4 atribute separate prin spatiu
                        Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
        Post-Conditions: Lista de cheltuieli actualizata.
    '''
    list[indexOld]=elementDeActualizat
    return list
