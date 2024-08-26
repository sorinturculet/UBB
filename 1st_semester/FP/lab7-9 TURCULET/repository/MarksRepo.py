from domain.event import *
class EventRepository:
    def __init__(self):
        self.__events=[]
    def add_event(self,event:event):
        '''
        adauga un event,
        :param event: event
        :return:
        '''
        self.__events.append(event)
    def find(self,searchedEvent:event):
        '''
        cauta un event
        :param searchedEvent: event
        :return:
        '''
        for event in self.__events:
            if searchedEvent==event:
                return event
        return None
    def get_all(self):
        '''
        returneaa lista cu toate eventurile
        :return: list of events
        '''
        return self.__events
    def delete_event(self,searchEvent:event):
        '''
        sterge un event din lista
        :param searchEvent:
        :return:
        '''
        if self.find(searchEvent):
            self.__events.remove(searchEvent)
    def update_event(self,event:event,newmark):
        '''
        updateaza un event ,cautandu l si dandu i o noua nota
        :param event: event
        :param newmark: int
        :return:
        '''
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

class EventRepoFile():
    def __init__(self,filename):
        self.__filename=filename
    def __load_from_file(self):
        """
        Incarca datele din fisier
        :return: lista de seriale din fisier
        :rtype: list of Serial objects
        :raises: ...
        """
        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            return

        lines = f.readlines()
        # lines: ['C1001;Superstore;2019;98', 'F1001; Arrow;2012;170',...]
        all_marks = []
        for line in lines:
            student_id, subject_id, mark= [token.strip() for token in line.split(';')]
            student_id = int(student_id)
            subject_id = int(subject_id)
            mark = int(mark)
            m = event(student_id,subject_id,mark)
            all_marks.append(m)

        f.close()
        return all_marks

    def __save_to_file(self, all_marks):
        """
        Salveaza serialele in fisier
        """
        with open(self.__filename, 'w') as f:
            for mark in all_marks:
                mark_string = str(mark.getStudent()) + ';' + str(mark.getSubject()) + ';' + str(
                    mark.getMark())+ '\n'
                f.write(mark_string)

    def add_event(self,event:event):
        '''
        adauga un event,
        :param event: event
        :return:
        '''
        events=self.get_all()
        events.append(event)
        self.__save_to_file(events)
    def find(self,searchedEvent:event):
        '''
        cauta un event
        :param searchedEvent: event
        :return:
        '''
        events=self.get_all()
        for event in events:
            if searchedEvent==event:
                return event
        return None
    def get_all(self):
        '''
        returneaa lista cu toate eventurile
        :return: list of events
        '''
        return self.__load_from_file()
    def delete_event(self,searchEvent:event):
        '''
        sterge un event din lista
        :param searchEvent:
        :return:
        '''
        events=self.get_all()
        if self.find(searchEvent):
            events.remove(searchEvent)
        self.__save_to_file(events)
    def update_event(self,event:event,newmark):
        '''
        updateaza un event ,cautandu l si dandu i o noua nota
        :param event: event
        :param newmark: int
        :return:
        '''
        e=self.find(event)
        if e is None:
            raise ValueError('Event doesnt exist')
        else:
            events=self.get_all()
            for eventin in events:
                if eventin==event:
                    eventin.setMark(newmark)
            self.__save_to_file(events)
    def delete_all(self):
        self.__save_to_file([])