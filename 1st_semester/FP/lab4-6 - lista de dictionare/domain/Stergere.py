from Utilities.Getters import *
def StergereDay(list,dayToDelete):
    '''
        Citeste o zi, si sterge toate cheltuielile din acea zi
        Preconditions: Citeste un string, avand un numar care reprezinta ziua lunii.
                        Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
        Post-Conditions: Lista de cheltuieli actualizata.
        '''
    CurrentList = getCurrentList(list)
    updateUndoList(list, makeListCopy(CurrentList))
    for element in CurrentList[:]:
        if(getDay(element)==dayToDelete):
            CurrentList.remove(element)
    return list

def StergereDayInterval(list,dayToDelete,dayToDelete2):
    '''
            Citeste o zi de inceput si o zi de final, si sterge toate cheltuielile dintre acele 2 zile
            Preconditions: Citeste doua string,fiecare avand un numar care reprezinta ziua lunii, a<b
                            Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
            Post-Conditions: Lista de cheltuieli actualizata.
            '''
    CurrentList = getCurrentList(list)
    updateUndoList(list, makeListCopy(CurrentList))
    for element in CurrentList[:]:
        if (getDay(element)>= dayToDelete and getDay(element)<=dayToDelete2):
            CurrentList.remove(element)
    return list

def StergereType(list,typeToDelete):
    '''
               Citeste un tip de cheltuiala, si sterge toate cheltuielile avand acel tip
               Preconditions: Citeste un string avand un tip valid de cheltuiala. si sterge toate cheltuielile de acel tip
                               Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
               Post-Conditions: Lista de cheltuieli actualizata.
               '''
    CurrentList = getCurrentList(list)
    updateUndoList(list, makeListCopy(CurrentList))
    for element in CurrentList[:]:
        if(getType(element)==typeToDelete):
            CurrentList.remove(element)
    return list