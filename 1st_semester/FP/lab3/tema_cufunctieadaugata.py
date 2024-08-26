#adaugam si functia max(i,j)+3=12
def citire():
    str=input('introduceti lista de numere separata prin spatiu')
    lst=str.split()
    lst = [ int(x) for x in lst ]
    print('Numerele au fost stocate')
    return lst
def prim(n):
    if(n<2):
        return 0
    elif(n==2):
        return 1
    elif(n%2==0):
        return 0
    else:
        for i in range(3,n//2,2):
            if(n%i==0):
                return 0
        return 1
def numere_prime(listaprime):
    indicefinalsecv=int(0)
    secvmax=int(0)
    secvactuala=int(0)
    for indice,element in enumerate(listaprime):
        if(prim(element)):
            secvactuala+=1
            if(secvmax<secvactuala):
                secvmax=secvactuala
                indicefinalsecv=indice
        else:
            secvactuala=0
    if(secvmax==0):
        print('Nu exista o secventa cu proprietatea ceruta')
        return []
    else:
        print('Secventa cu proprietatea ceruta este:')
        print(listaprime[indicefinalsecv+1-secvmax:indicefinalsecv+1])
        return listaprime[indicefinalsecv+1-secvmax:indicefinalsecv+1]
def triplete(listatrp):
    indicefinalsecv=int(0)
    secvmax=int(0)
    secvactuala=0
    i=0
    #de implementat verificare primele 3 si dupa contorizare spre dreapta cu verificare stanga.
    if(listatrp[0]==listatrp[2] or listatrp[1]==listatrp[2] or listatrp[0]==listatrp[1]):
        secvactuala=3
        secvmax=3
        indicefinalsecv=3
    for i in range(3,len(listatrp)):
        if(listatrp[i]==listatrp[i-1] or listatrp[i-1]==listatrp[i-2] or listatrp[i-2]==listatrp[i]):
            if(secvactuala==0):
                secvactuala=3
            else:
                secvactuala+=1
            if(secvmax<secvactuala):
                secvmax=secvactuala
                indicefinalsecv=i 
        else:
            secvactuala=0
    if(secvmax==0):
        print('Nu exista o secventa cu proprietatea ceruta')
        return []
    else:
        print('Secventa cu proprietatea ceruta este:')
        print(listatrp[indicefinalsecv+1-secvmax:indicefinalsecv+1])
        return listatrp[indicefinalsecv+1-secvmax:indicefinalsecv+1]
def semne_contrare(listasemne):
    indicefinalsecv=int(1)
    secvmax=int(1)
    secvactuala=1 #luam primul element ca fiind o secventa
    i=1
    for i in range(1,len(listasemne)):
        if(listasemne[i]*listasemne[i-1]<0):
            secvactuala+=1
            if(secvmax<secvactuala):
                secvmax=secvactuala
                indicefinalsecv=i
        else:
            secvactuala=1
    print('Secventa cu proprietatea ceruta este:')
    print(listasemne[indicefinalsecv+1-secvmax:indicefinalsecv+1])  
    return listasemne[indicefinalsecv+1-secvmax:indicefinalsecv+1]
def exit_menu():
    exit()
def meniu():
    lista=[]
    while(True):
        print('MENIU:\n1.Citire\n2.Verificare secv prime')
        print('3.Verificare secv cu o valoare comuna intre toate 3 alaturate')
        print('4.Verificare secv maxima de numere cu semne contrare\n5.Iesire meniu')
        n=int(input('introduceti numarul corespondent functionalitatii dorite'))
        match n:
            case 1:
                lista=citire()
            case 2:numere_prime(lista)
            case 3:triplete(lista)
            case 4:semne_contrare(lista)
            case 5:exit_menu()
def test_numere_prime():
    assert numere_prime([2,3,5,7,6,6,8,9,2,5]) == [2, 3, 5, 7]
    assert numere_prime([4,4,4,6,8,10]) == []
    assert numere_prime([0,0,0,0,0,3]) == [3]

def test_triplete():
    assert triplete([2,3,5,7,6,6,8,9,2,5])==[7, 6, 6, 8]
    assert triplete([4,4,4,6,8,10])==[4, 4, 4, 6]
    assert triplete([0,0,0,0,0,3,3,3,3,3,5,3])==[0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 5, 3]
    assert triplete([0,0,0,0,0,5,3,3,3,3,3,5,3])==[5, 3, 3, 3, 3, 3, 5, 3]
# test_numere_prime()
# test_triplete()
meniu()
