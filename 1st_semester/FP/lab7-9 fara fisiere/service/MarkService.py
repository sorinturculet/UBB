from domain.event import *
from repository.StudentRepo import *
from repository.SubjectRepo import *
from repository.MarksRepo import *
class MarkController:
    def __init__(self,MarkRepo:EventRepository,StudentRepo:StudentRepository,SubjectRepo:SubjectRepository):
        self.__mark_repo=MarkRepo
        self.__student_repo=StudentRepo
        self.__subject_repo=SubjectRepo
    def create_mark(self,student_id,subject_id,mark):
        student=self.__student_repo.find(student_id)
        if student is None:
            raise ValueError('Student doesnt exist')
        subject=self.__subject_repo.find(subject_id)
        if student is None:
            raise ValueError('Subject doesnt exist')
        mark=event(student_id,subject_id,mark)
        self.__mark_repo.add_event(mark)
    def find_mark(self,mark):
        return self.__mark_repo.find(event)
    def delete_mark(self,mark):
        self.__mark_repo.delete_event(mark)
    def stat_1(self,idmaterie):
        list = []
        marks = self.get_all()
        for mark in marks:
            if mark.getSubject()==idmaterie:
                list.append(mark)
        for i,element1 in enumerate(list):
            for j,element2  in enumerate(list):
                if element1.getMark()>element2.getMark():
                    list[i],list[j]=list[j],list[i]
                elif element1.getMark()==element2.getMark():
                    stud1=self.__student_repo.find(element1.getStudent())
                    stud2=self.__student_repo.find(element2.getStudent())
                    if stud1.getName()>stud2.getName():
                        list[i],list[j]=list[j],list[i]
        return list
    def stat_2(self):
        '''
        Ordoneaza studentii dupa media notelor lor, dupa care returneaza primii 20% printr-o lista de liste avand primul element id studetn si al doilea media lor
        :return:lista de liste
        '''
        listStud=self.__student_repo.getAll()
        list=[]
        marks=self.get_all()
        for student in listStud:
            n_of_marks=0
            sum_of_marks=0
            for mark in marks:
                if mark.getStudent()==student.getId():
                    sum_of_marks+=mark.getMark()
                    n_of_marks+=1
            if sum_of_marks!=0:
                sum_of_marks/=n_of_marks
            list.append([student,sum_of_marks])
        for i,element1 in enumerate(list):
            for j,element2  in enumerate(list):
                if element1[1]>element2[1]:
                    list[i],list[j]=list[j],list[i]
                elif element1[1]==element2[1]:
                    if element1[0].getName()>element2[0].getName():
                        list[i],list[j]=list[j],list[i]
        if len(list)%5==0 :
            list=list[:len(list)//5]
        else:
            list = list[:len(list) // 5 + 1]
        return list

    def get_all(self):
        return self.__mark_repo.get_all()
