from Utilities.Getters import *
def FiltrareType(list,typeToDelete):
    '''
        Citeste un tip de cheltuiala, si sterge toate cheltuielile avand acel tip
        Preconditions: Citeste un string avand un tip valid de cheltuiala. si sterge toate cheltuielile de acel tip
                    Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
        Post-Conditions: Lista de cheltuieli actualizata.
    '''
    CurrentList = getCurrentList(list)
    updateUndoList(list, makeListCopy(CurrentList))
    for element in CurrentList[:]:
        if (getType(element) == typeToDelete):
            CurrentList.remove(element)
    return list

def FiltrareSum(list,sumToDelete):
    '''
        Citeste un tip de cheltuiala, si sterge toate cheltuielile avand suma mai mica
        Preconditions: Citeste un string avand o anumita suma de cheltuiala. si sterge toate cheltuielile cu suma sub
                        Afiseaza mesaje pentru a ajuta utitlizatorul in cazul in care nu se introduc valori bune
        Post-Conditions: Lista de cheltuieli actualizata.
    '''
    CurrentList = getCurrentList(list)
    updateUndoList(list, makeListCopy(CurrentList))
    for element in list[:]:
        if (getSum(element)<= sumToDelete):
            CurrentList.remove(element)
    return list