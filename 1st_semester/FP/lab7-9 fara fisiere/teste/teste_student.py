from domain.student import *
def testCreateStudent():
    st=Student('7','Italianu')
    assert st.getId()=='7'
    assert st.getName()=='Italianu'
def testEqual():
    st1=Student('7','Italianu')
    st2=Student('9','Italianu')
    st3=Student('9','Austriacu')
    assert st1!=st2
    assert st2==st3
def testWrite():
    st1=Student('9','Mexicanu')
    text=print(st1)
def testSetName():
    st1=Student('7','Italianu')
    st1.setName('Mexicanu')
    assert st1.getName()=='Mexicanu'

testCreateStudent()
testEqual()
testSetName()
#testWrite()