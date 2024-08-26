
from domain.Adaugare import *
from domain.Stergere import *
from domain.Cautari import *
from domain.Rapoarte import *
from domain.Filtrare import *

from UI.AdaugareUI import *
from UI.CautareUI import *
from UI.StergereUI import *
from UI.RapoarteUI import *
from UI.FiltrareUI import *
def printareLista(TaskManager):
    currentList=getCurrentList(TaskManager)
    for element in currentList:
        print(element)
def printareListaUndo(TaskManager):
    UndoList=getUndoList(TaskManager)
    print('lIST DE UNDO ESTE:')
    for index,LIST in enumerate(UndoList):
        print(index)
        for element in LIST:
            print(element)

def f11(list):
    listaElementeNoi=mesajCitire()
    try:
        validateInputAdaugare(listaElementeNoi)
        Adaugare(list,createCheltuiala(listaElementeNoi))
    except:
        mesajCheltuialaInvalid()

def f12(list):
    listaDeActualizat = oldElement()
    lista=getCurrentList(list)
    if (validateInputAdaugare(listaDeActualizat)):
        indexOld=verifyElementInList(lista,createCheltuiala(listaDeActualizat))
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
