
from Adaugare import *
from Stergere import *
from Cautari import *
from Rapoarte import *
from Filtrare import *

from UI.AdaugareUI import *
from UI.CautareUI import *
from UI.StergereUI import *
from UI.RapoarteUI import *
from UI.FiltrareUI import *
def printareLista(list):
    for cheltuiala in list:
        print(cheltuiala.__str__())
def f11(list):
    listaElementeNoi=mesajCitire()
    if(validateInputAdaugare(listaElementeNoi)):
        Adaugare(list,createCheltuiala(listaElementeNoi))
    else:
        mesajCheltuialaInvalid()
    return list

def f12(list):
    listaDeActualizat = oldElement()
    if (validateInputAdaugare(listaDeActualizat)):
        indexOld=verifyElementInList(list,createCheltuiala(listaDeActualizat))
    if(indexOld>=0):
        elementDeActualizat=MesajElementDeActualizat()
        actualizareCheltuiala(list,indexOld,elementDeActualizat)
        mesajConfirmareAdaugare()
    else:
        verifyInvalidIndex()
def f21(list):
    dayToDelete=inputStergereDay()
    StergereDay(list,dayToDelete)
    deleteConfirmation()
def f22(list):
    dayToDelete,dayToDelete2=inputStergereDayInterval()
    StergereDayInterval(list,dayToDelete,dayToDelete2)
    deleteConfirmation()
def f23(list):
    typeToDelete=inputStergereType()
    StergereType(list,typeToDelete)
    deleteConfirmation()
def f31(list):
    sum=inputCautareGreaterSum()
    CautareGreaterSum(list,sum)
def f32(list):
    dayLimit,sumLimit=inputCautareDaySum()
    CautareDaySum(list,dayLimit,sumLimit)
    deleteConfirmation()
def f33(list):
    typeToSearch=inputCautareType()
    CautareType(list,typeToSearch)
    deleteConfirmation()
def f41(list):
    TypeToSearch=inputRaportType()
    print("Cheltuielile de tipul introdus aduna suma de "+str((RaportSumOfType(list,TypeToSearch))))
def f42(list):
    print("Ziua cu suma cheltuita maxima este ziua "+str((RaportDayMaxSum(list))))
def f43(list):
    sumToSearch=inputRaportSum()
    listaSum=RaportSum(list,sumToSearch)
    print("Elementele cu suma introdusa sunt urmatoarele")
    printareLista(listaSum)
def f44(list):
    TypeToSearch=inputRaportType()
    listaType=RaportSortType(list,TypeToSearch)
    print("Elementele cu tipul introdus sunt")
    printareLista(listaType)
def f51(list):
    typeToDelete=inputFiltrareType()
    FiltrareType(list,typeToDelete)
    filterConfirmation()
def f52(list):
    sumToDelete = inputFiltrareSum()
    FiltrareType(list, sumToDelete)
    filterConfirmation()
