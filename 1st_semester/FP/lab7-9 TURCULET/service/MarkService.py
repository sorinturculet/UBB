from domain.event import *
from repository.StudentRepo import *
from repository.SubjectRepo import *
from repository.MarksRepo import *
from utils.shellsort import shellsort
from utils.bubblesort import bubble_sort
from utils.recursive_functions import length,average_mark
class MarkController:
    def __init__(self,MarkRepo:EventRepository,StudentRepo:StudentRepository,SubjectRepo:SubjectRepository):
        self.__mark_repo=MarkRepo
        self.__student_repo=StudentRepo
        self.__subject_repo=SubjectRepo
    def create_mark(self,student_id,subject_id,mark):
        '''
        creeaza un mark
        :param student_id: int
        :param subject_id:int
        :param mark: int
        :return:
        '''
        student=self.__student_repo.find(student_id)
        if student is None:
            raise ValueError('Student doesnt exist')
        subject=self.__subject_repo.find(subject_id)
        if student is None:
            raise ValueError('Subject doesnt exist')
        mark=event(student_id,subject_id,mark)
        self.__mark_repo.add_event(mark)
        return mark
    def find_mark(self,mark):
        '''
        cauta un mark
        :param mark: event
        :return:
        '''
        return self.__mark_repo.find(event)
    def delete_mark(self,mark):
        '''
        sterge un mark
        :param mark: event
        :return:
        '''
        self.__mark_repo.delete_event(mark)
    def stat_1(self,idmaterie):
        '''
        Ordoneaza studentii de la o anumita materie dupa note si alfabetic.
        :param idmaterie: int
        :return: list of students
        '''
        list = []
        marks = self.get_all()
        for mark in marks:
            if mark.getSubject()==idmaterie:
                list.append(mark)
        bubble_sort(list,lambda el:el.getMark(),reverse=True)
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
            # n_of_marks=0
            # sum_of_marks=0
            # for mark in marks:
            #     if mark.getStudent()==student.getId():
            #         sum_of_marks+=mark.getMark()
            #         n_of_marks+=1
            sum_of_marks,n_of_marks=average_mark(marks,student)
            list.append([student,sum_of_marks])
        bubble_sort(list,lambda el:el[1],reverse=True)
        if length(list)%5==0 :
            list=list[:length(list)//5]
        else:
            list = list[:length(list) // 5 + 1]
        return list
    def stat_3(self):
        '''
        Afiseaza toti studentii cu media mai mare de 5
        :return: lista cu studentii
        '''
        listStud = self.__student_repo.getAll()
        list = []
        marks = self.get_all()
        for student in listStud:
            # n_of_marks=0
            # sum_of_marks=0
            # for mark in marks:
            #     if mark.getStudent()==student.getId():
            #         sum_of_marks+=mark.getMark()
            #         n_of_marks+=1
            sum_of_marks, n_of_marks = average_mark(marks, student)
            list.append([student, sum_of_marks])
        bubble_sort(list,key=lambda el : (el[1],el[0].getName()),reverse=True) #numele sunt si ele descrescatoare
        listaAdmisi=[]
        for element in list:
            if element[1]>=5:
                listaAdmisi.append(element)
        return listaAdmisi
    def stat_3s(self):
        lista=self.stat_3()
        bubble_sort(bubble_sort(lista,key=lambda el:el[0].getName()),key=lambda el : el[1],reverse=True)
        return lista
    def get_all(self):
        '''
        returneaza toate markurile
        :return:
        '''
        return self.__mark_repo.get_all()
