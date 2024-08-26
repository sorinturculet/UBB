from Utilities.Getters import *
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
    obiectNou=Cheltuiala(listaElementeNoi[0],listaElementeNoi[1],listaElementeNoi[2],listaElementeNoi[3])
    return obiectNou

