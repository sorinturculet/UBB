from domain.functionalities import *
def test_f11():
    listatest=[createCheltuiala('Adidasi 400 Imbracaminte 4')]
    elementAdaugat=createCheltuiala('Orez 450 Mancare 4')
    listafinala=Adaugare(listatest,elementAdaugat)
    assert (len(listafinala)) == 2
def test_f12():
    listatest = [createCheltuiala('Adidasi 400 Imbracaminte 4')]
    index = 0
    elementDeActualizat=createCheltuiala('Ghete 450 Imbracaminte 4')
    assert (getName(actualizareCheltuiala(listatest,index,elementDeActualizat)[0]))==getName(elementDeActualizat)
def test_f21():
    listatest = [createCheltuiala('Adidasi 400 Imbracaminte 4'),createCheltuiala('GeacaSki 400 Imbracaminte 4')]
    dayToDelete='4'
    listatest=StergereDay(listatest,dayToDelete)
    assert len(listatest)==0
def test_f22():
    listatest = [createCheltuiala('Adidasi 400 Imbracaminte 4'),createCheltuiala('GeacaSki 400 Imbracaminte 4')]
    dayToDelete='4'
    dayToDelete2='4'
    listatest=StergereDayInterval(listatest,dayToDelete,dayToDelete2)
    assert len(listatest)==0
def test_f23():
    listatest = [createCheltuiala('Adidasi 400 Imbracaminte 4'), createCheltuiala('GeacaSki 400 Imbracaminte 4')]
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
    listatest = [createCheltuiala('Adidasi 400 Imbracaminte 4'), createCheltuiala('GeacaSki 400 Imbracaminte 4')]
    typeToDelete = 'Imbracaminte'
    listatest = FiltrareType(listatest, typeToDelete)
    assert len(listatest) == 0
def test_f52():
    listatest = [createCheltuiala('Adidasi 400 Imbracaminte 4'), createCheltuiala('GeacaSki 400 Imbracaminte 4')]
    sumToDelete = '500'
    listatest = FiltrareSum(listatest, sumToDelete)
    assert len(listatest) == 0
test_f11()
test_f12()
test_f21()
test_f22()
test_f23()
test_f51()
test_f52()

