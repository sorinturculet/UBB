from Utilities.Cheltuiala import *
from Utilities.Validation import *
def mesajCitire():
    '''
    Afiseaza mesajul pentru functionalitatea Iesire
    '''
    print('Introduceti pentru cheltuiala urmatoarele proprietati separate prin spatiu:numele,suma, tipul si ziua efectuarii cheltuielii')
    print('Tipul cheltuielii trebuie sa fie unul din urmatoarele:"Mancare","Intretinere","Imbracaminte","Telefon","Altele"')
    str = input()
    return str

def mesajConfirmareAdaugare():
    '''
    Afiseaza mesajul pentru confirmarea functionalitatii Iesire
    :return:
    '''
    print('Cheltuiala a fost adaugata cu succes')
def invalidTypeInput():
    print('Tipul cheltuielii este invalid.')
def mesajCheltuialaInvalid():
    print('Cheltuiala introdusa nu este valida')
def verifyInvalidIndex():
    print('Elementul cautat nu exista printre cheltuielile existente')
def oldElement():
    '''
        Afiseaza mesajul pentru functionalitatea actualizareCheltuiala
        '''
    print('Introduceti numele,suma,tipul si ziua cheltuiielii pe care doriti sa o actualizati.')
    str = input()
    return str

def MesajElementDeActualizat():
    print('Introduceti datele pentru cheltuiala actualizata')
    name= input('Introduceti numele cheltuielii actualizate')
    suma = input('Introduceti suma cheltuielii actualizate')
    type=input('Introduceti tipul cheltuielii actualizate')
    while type not in typesOfCheltuieli:
        print('Tipul cheltuielii trebuie sa fie unul din urmatoarele:"Mancare","Intretinere","Imbracaminte","Telefon","Altele"')
        type=input('Introduceti tipul cheltuielii actualizate')
    day = input('Introduceti ziua cheltuielii actualizate')
    return Cheltuiala(name,suma,type,day)
