from domain.subject import *
def testAddSubject():
    sb1=Subject('4','Math','Sberinde')
    assert sb1.getId()=='4'
    assert sb1.getName()=='Math'
    assert sb1.getProfessor()=='Sberinde'
def testEqualSubjects():
    sb1=Subject('4','Math','Sberinde')
    sb2=Subject('4','Math','Sberinde')
    assert sb1==sb2
def testSetName():
    sb1 = Subject('4', 'Math', 'Sberinde')
    sb1.setName('Mathematics')
    assert sb1.getName()=='Mathematics'
def testWrite():
    sb1 = Subject('4', 'Math', 'Sberinde')
    print(sb1)
testAddSubject()
testEqualSubjects()
testSetName()
#testWrite()