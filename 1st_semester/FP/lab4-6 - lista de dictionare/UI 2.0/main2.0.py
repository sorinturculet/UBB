from UI.PrintMenu import PrintMenu
from domain.functionalities import *
from InputSeparator import MultipleOptionRequest
def meniu():
    PrintMenu()
    TaskManager=createTaskManager()
    while(True):
        #add, Mancare 20 Mancare 30;add,Cartela 40 Telefon 20;undo;delete,30
        n=input()
        TaskManager=MultipleOptionRequest(TaskManager,n)
        print("Lista finala este:")
        printareLista(TaskManager)

meniu()


