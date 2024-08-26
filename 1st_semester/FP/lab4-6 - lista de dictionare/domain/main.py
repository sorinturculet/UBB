from UI.PrintMenu import PrintMenu
from domain.functionalities import *
def meniu():
    PrintMenu()
    TaskManager=createTaskManager()
    while(True):
        n=input()
        match n:
            case '1.1':
                f11(TaskManager)
            case '1.2':
                f12(TaskManager)
            case'2.1':
                f21(TaskManager)
            case'2.2':
                f22(TaskManager)
            case'2.3':
                f23(TaskManager)
            case'3.1':
                f31(TaskManager)
            case'3.2':
                f32(TaskManager)
            case '3.3':
                f33(TaskManager)
            case '4.1':
                f41(TaskManager)
            case '4.2':
                f42(TaskManager)
            case '4.3':
                f43(TaskManager)
            case '4.4':
                f44(TaskManager)
            case'5.1':
                f51(TaskManager)
            case '5.2':
                f52(TaskManager)
            case '6':
                undo(TaskManager)
            case 'UNDO':
                undo(TaskManager)
            case other:
                print('Optiune Invalida')
        printareLista(TaskManager)
        printareListaUndo(TaskManager)

meniu()


