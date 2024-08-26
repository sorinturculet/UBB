from domain.event import *
class EventRepository:
    def __init__(self):
        self.__events=[]
    def add_event(self,event:event):
        self.__events.append(event)
    def find(self,searchedEvent:event):
        for event in self.__events:
            if searchedEvent==event:
                return event
        return None
    def get_all(self):
        return self.__events
    def delete_event(self,searchEvent:event):
        if self.find(searchEvent):
            self.__events.remove(searchEvent)
    def update_event(self,event:event,newmark):
        e=self.find(event)
        if e is None:
            raise ValueError('Event already exist')
        else:
            for events in self.__events:
                if events==event:
                    events.setMark(newmark)

def test_add_event():
    st=Student(7,'Sorin')
    sub=Subject(8,'Matematica','SB')
    mark=event(7,8,9)
    test_repo=EventRepository()
    test_repo.add_event(mark)
    assert(len(test_repo.get_all())==1)
test_add_event()