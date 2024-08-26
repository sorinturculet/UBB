from Utilities.Cheltuiala import *
from Utilities.Validation import *
def inputStergereDay():
    dayToDelete = input('Introduceti ziua din care vreti sa stergeti cheltuielile')
    return dayToDelete
def inputStergereDayInterval():
    dayToDelete = input('Introduceti ziua incepand cu care vreti sa stergeti cheltuielile')
    dayToDelete2 = input('Introduceti ziua de sfarsit din care vreti sa stergeti cheltuielile')
    return dayToDelete,dayToDelete2
def inputStergereType():
    typeToDelete = input("Introduceti tipul cheltuielilor pe care doriti sa le stergeti")
    while not validateType(typeToDelete):
        print('Tipul cheltuielii trebuie sa fie unul din urmatoarele:"Mancare","Intretinere","Imbracaminte","Telefon","Altele"')
        typeToDelete = input("Introduceti tipul cheltuielilor pe care doriti sa le stergeti")
    return typeToDelete
def deleteConfirmation():
    print('Stergere efectuata cu succes')