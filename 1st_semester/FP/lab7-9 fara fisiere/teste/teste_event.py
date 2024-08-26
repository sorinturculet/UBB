from domain.event import *
def testCreateEvent():
    st=event(7,8,10)
    assert st.getStudent()==7
    assert st.getSubject()==8
    assert st.getMark()==10
def testEqual():
    st1=event(7,8,10)
    st2=event(7,8,9)
    assert st1!=st2
def testWrite():
    st1=event(7,8,10)
    text=print(st1)
def testSetName():
    st1=event(7,8,10)
    st1.setStudent(8)
    assert st1.getStudent()==8

testCreateEvent()
testEqual()
testSetName()
#testWrite()