# 5) Generați bilete la PRONOSPORT pentru un bilet cu N meciuri. Pronosticurile pentru un meci
# pot fi 1,X,2. Generați toate variantele astfel încât: pronosticul de la ultimul meci nu poate fi X
# și există un maxim de două meciuri cu pronosticul 1.

def SolutionFound(list):
    print(list)
def Verify(n,list):
    numberof1=0
    for pariu in list:
        if pariu=='1':
            numberof1+=1
    if numberof1>2:
        return False
    if len(list)<n:
        return False
    if list[-1]=='X':
        return False
    return True
def backtrackingSuperbet(n,list):
    listofbets=['1','2','X']
    if Verify(n,list):
        SolutionFound(list)
        return

    for j in listofbets:
        list[-1]=j
        backtrackingSuperbet(n,list)
    list.pop()
n=5
backtrackingSuperbet(n,[])