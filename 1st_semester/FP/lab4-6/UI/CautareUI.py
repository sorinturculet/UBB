from Utilities.Cheltuiala import *
def inputCautareGreaterSum():
    sumLimit = input("Introduceti suma dorita pentru a afisa cheltuielile mai mari decat aceasta")
    return sumLimit
def inputCautareDaySum():
    dayLimit = input("Introduceti ziua dorita pentru a afisa cheltuielile facute inainte de aceasta")
    sumLimit = input("Introduceti suma dorita pentru a afisa cheltuielile mai mici decat aceasta")
    return dayLimit,sumLimit
def inputCautareType():

    typeToSearch = input("Introduceti tipul cheltuielilor pe care doriti sa le vedeti")
    while typeToSearch not in typesOfCheltuieli:
        print(
            'Tipul cheltuielii trebuie sa fie unul din urmatoarele:"Mancare","Intretinere","Imbracaminte","Telefon","Altele"')
        typeToSearch=input("Introduceti tipul cheltuielilor pe care doriti sa le vedeti")
    return typeToSearch