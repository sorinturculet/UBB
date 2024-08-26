from functionalities import *
def test_f11():
    listatest=[Cheltuiala('Adidasi','450','Imbracaminte','4')]
    elementAdaugat=Cheltuiala('Orez','450','Mancare','4')
    listafinala=Adaugare(listatest,elementAdaugat)
    assert (len(listafinala)) == 2
def test_f12():
    listatest = [Cheltuiala('Adidasi', '450', 'Imbracaminte', '4')]
    index = 0
    elementDeActualizat=Cheltuiala('Ghete', '450', 'Imbracaminte', '4')
    assert (actualizareCheltuiala(listatest,index,elementDeActualizat)[0].name)==elementDeActualizat.name
def test_f21():
    listatest = [Cheltuiala('Adidasi', '450', 'Imbracaminte', '4'),Cheltuiala('Geaca_Ski', '550', 'Imbracaminte', '4')]
    dayToDelete='4'
    listatest=StergereDay(listatest,dayToDelete)
    assert len(listatest)==0
def test_f22():
    listatest = [Cheltuiala('Adidasi', '450', 'Imbracaminte', '4'),Cheltuiala('Geaca_Ski', '550', 'Imbracaminte', '4')]
    dayToDelete='4'
    dayToDelete2='4'
    listatest=StergereDayInterval(listatest,dayToDelete,dayToDelete2)
    assert len(listatest)==0
def test_f23():
    listatest = [Cheltuiala('Adidasi', '450', 'Imbracaminte', '4'),Cheltuiala('Geaca_Ski', '550', 'Imbracaminte', '4')]
    typeToDelete='Imbracaminte'
    listatest=StergereType(listatest,typeToDelete)
    assert len(listatest)==0
def test_f41():
    pass
def test_f42():
    pass
def test_f43():
    pass
def test_f44():
    pass
def test_f51():
    listatest = [Cheltuiala('Adidasi', '450', 'Imbracaminte', '4'), Cheltuiala('Geaca_Ski', '550', 'Imbracaminte', '4')]
    typeToDelete = 'Imbracaminte'
    listatest = FiltrareType(listatest, typeToDelete)
    assert len(listatest) == 0
def test_f52():
    listatest = [Cheltuiala('Adidasi', '450', 'Imbracaminte', '4'), Cheltuiala('Geaca_Ski', '550', 'Imbracaminte', '4')]
    sumToDelete = '500'
    listatest = FiltrareSum(listatest, sumToDelete)
    assert len(listatest) == 1
test_f11()
test_f12()
test_f21()
test_f22()
test_f23()
test_f51()
test_f52()

