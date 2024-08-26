from Utilities.Getters import *
def RaportSumOfType(list,type):
    '''
        citeste un tip de cheltuiala si returneaza suma cheltuielilor cu acel tip
        Preconditions: Citeste un tip
        Post-Conditions: Suma totala a cheltuielolor
    '''
    sum=0
    for element in list:
        if(getType(element))==type:
            sum+=int(element.sum)
    return sum
def RaportDayMaxSum(list):
    '''
            Calculeaza ziua cu cea mai mare suma cheltuita
            Preconditions: Lista de element
            Post-Conditions: Ziua cu cheltuiala maxima
        '''
    SumMax=0
    DayMax=1
    for Day in range(1,31):
        SumDay=0
        for element in list:
            if getDay(element)==Day:
                SumDay+=getDay(element)
        if(SumDay>SumMax):
            SumMax=SumDay
            DayMax=Day
    return Day
def RaportSum(list,sum):
    '''
              Primeste o suma si returneaza o lista cu elemente care au suma egala cu cea introdusa
              Preconditions: Lista de elemente, suma
              Post-Conditions: Lista de elemente cu suma respectiva
          '''
    listSumOnly=[]
    for element in list:
        if getSum(element)==sum:
            listSumOnly.append(element)
    return listSumOnly
def RaportSortType(list,type):
    '''
              Primeste un tip si returneaza o lista cu elemente care au aceleasi tip cu cel introdus
              Preconditions: Lista de elemente, tipul
              Post-Conditions: Lista de elemente cu tipul respectiv
          '''
    listTypeOnly=[]
    for element in list:
        if getType(element) == type:
            listTypeOnly.append(element)
    return listTypeOnly
