from Utilities.Getters import *
def createTaskManager() -> dict:
    """
    Creeaza o structura prin care gestionam datele din aplicatie
    :return: dictionar cu 2 chei:
            current_task_list: lista curenta de task-uri (lista de lucru)
            undo_list: lista de undo
    """
    return {'current_task_list': [], 'undo_list': []}
def validateDay(day):
    '''
        Verifies if day is valid
        :param day:
        :return True|False:
    '''
    if day<'0' or day>'32':
        return False
    return True
def validareSum(sum):
    '''
        Verifies if sum is valid
        :param sum:
        :return True|False:
    '''
    if sum<'0':
        return False
    return True
from Utilities.Cheltuiala import typesOfCheltuieli
def validateType(type):
    '''
        Verifies if type is valid
        :param type:
        :return True|False:
     '''
    if type not in typesOfCheltuieli:
        return False
    return True

def validateCheltuiala(cheltuiala):
    if validateType(getType(cheltuiala)) and validateDay(getSum(cheltuiala)) and validateDay(getDay(cheltuiala)):
        return True
    return False
def validateInputAdaugare(str):
    listaElementeNoi = str.split()
    listaElementeNoi = [x for x in listaElementeNoi]
    if len(listaElementeNoi) != 4:
        return False
    if validareSum(listaElementeNoi[1]) and validateType(listaElementeNoi[2]) and validateDay(listaElementeNoi[3]):
        return True
    return False

def createCheltuiala(str):
    listaElementeNoi = str.split()
    listaElementeNoi = [x for x in listaElementeNoi]
    obiectNou= {'name':listaElementeNoi[0],'sum':listaElementeNoi[1],'type':listaElementeNoi[2],'day':listaElementeNoi[3]}
    return obiectNou
