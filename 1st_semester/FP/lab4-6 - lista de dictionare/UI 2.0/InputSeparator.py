
from domain.Adaugare import *
from domain.Stergere import *
from domain.Filtrare import *
from Utilities.Getters import *
from domain.functionalities import *
ListCommands=['add','delete','filter','undo']
def ValidateCommand(command):
    if command in ListCommands:
        return True
    return False
def InputSeparator(n):
    listRequest=[element.strip() for element in n.split(';')]
    for index,element in enumerate(listRequest):
        listRequest[index]=element.split(',')
    return listRequest

def MultipleOptionRequest(list,n):
    listRequest=InputSeparator(n)
    for request in listRequest:
        if(ValidateCommand(request[0])):
            match request[0]:
                case 'add':
                    validateInputAdaugare(request[1])
                    Adaugare(list, createCheltuiala(request[1]))
                case 'delete':
                     StergereDay(list,request[1])
                case 'filter':
                    FiltrareSum(list,request[1])
                case 'undo':
                    undo(list)
            printareLista(list)
            print('')
    return list
