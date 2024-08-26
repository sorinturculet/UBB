from Utilities.Cheltuiala import *

def inputRaportType():
    typeToSearch = input("Introduceti tipul cheltuielilor pe care doriti sa le vedeti")
    while typeToSearch not in tipuriCheltuieli:
        print(
            'Tipul cheltuielii trebuie sa fie unul din urmatoarele:"Mancare","Intretinere","Imbracaminte","Telefon","Altele"')
        typeToSearch = input("Introduceti tipul cheltuielilor pe care doriti sa le vedeti")
    return typeToSearch
def inputRaportSum():
    sum=input("Introduceti suma pentru a tipari toate cheltuielile cu aceasta suma")
    return sum
