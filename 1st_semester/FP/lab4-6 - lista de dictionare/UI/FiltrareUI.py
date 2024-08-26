from Utilities.Cheltuiala import *
def inputFiltrareType():

    typeToDelete = input("Introduceti tipul cheltuielilor pe care doriti sa le stergeti")
    while typeToDelete not in typesOfCheltuieli:
        print(
            'Tipul cheltuielii trebuie sa fie unul din urmatoarele:"Mancare","Intretinere","Imbracaminte","Telefon","Altele"')
        typeToDelete = input("Introduceti tipul cheltuielilor pe care doriti sa le stergeti")
    return typeToDelete
def inputFiltrareSum():
    sumToDelete = input("Introduceti suma pentru care doriti sa stergeti cheltuielile mai mici")
    return sumToDelete
def filterConfirmation():
    print('Stergere efectuata cu succes')