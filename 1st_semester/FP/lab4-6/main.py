from UI.PrintMenu import PrintMenu
from functionalities import *
def meniu():
    PrintMenu()
    list=[]
    list.append(Cheltuiala('Adidasi','450','Imbracaminte','4'))
    list.append(Cheltuiala('Adidasi','550','Imbracaminte','4'))
    list.append(Cheltuiala('Orez','10','Mancare','10'))
    while(True):
        n=input()
        match n:
            case '1.1':
                f11(list)
            case '1.2':
                f12(list)
            case'2.1':
                f21(list)
            case'2.2':
                f22(list)
            case'2.3':
                f23(list)
            case'3.1':
                f31(list)
            case'3.2':
                f32(list)
            case '3.3':
                f33(list)
            case '4.1':
                f41(list)
            case '4.2':
                f42(list)
            case '4.3':
                f43(list)
            case '4.4':
                f44(list)
            case'5.1':
                f51(list)
            case '5.2':
                f52(list)
            case '6':
                pass
            case other:
                print('Optiune Invalida')
        printareLista(list)

meniu()


