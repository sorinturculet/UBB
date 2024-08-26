from service.MarkService import *
from repository.SubjectRepo import *
from domain.event import *
import unittest
class MarkServiceTest(unittest.TestCase):
    def setUp(self)->None:
        self.__stud_repo=StudentRepository()
        self.__subject_repo=SubjectRepository()

        mark_repo=EventRepository()
        self.__srv=MarkController(mark_repo,self.__stud_repo, self.__subject_repo)
    def test_add_mark(self):
        student=Student(1,'Marius')
        self.__stud_repo.addStudent(student)
        subject=Subject(1,'Mate','SB')
        self.__subject_repo.addSubject(subject)
        self.__srv.create_mark(1,1,10)
        self.assertEqual(len(self.__srv.get_all()),1)
    def test_delete_mark(self):

        student=Student(1,'Marius')
        self.__stud_repo.addStudent(student)
        subject=Subject(1,'Mate','SB')
        self.__subject_repo.addSubject(subject)
        mark=self.__srv.create_mark(1,1,10)
        self.assertEqual(len(self.__srv.get_all()),1)
        self.__srv.delete_mark(mark)
        self.assertEqual(len(self.__srv.get_all()),0)
    def test_stat_2(self):
        student=Student(10,'Marius')
        self.__stud_repo.addStudent(student)
        student=Student(11,'Stefan')
        self.__stud_repo.addStudent(student)
        student=Student(12,'George')
        self.__stud_repo.addStudent(student)
        student=Student(13,'gIGEL')
        self.__stud_repo.addStudent(student)
        student=Student(14,'Kylian')
        self.__stud_repo.addStudent(student)
        student=Student(15,'Marius')
        self.__stud_repo.addStudent(student)
        subject=Subject(10,'Mate1','SB')
        self.__subject_repo.addSubject(subject)
        subject = Subject(11, 'Mate2', 'SB')
        self.__subject_repo.addSubject(subject)
        self.__srv.create_mark(10,10,10)
        self.__srv.create_mark(11,10,7)
        self.__srv.create_mark(12,10,8)
        self.__srv.create_mark(13,10,5)
        self.__srv.create_mark(10, 11, 9)
        self.__srv.create_mark(11, 11, 3)
        self.__srv.create_mark(12, 11, 2)
        self.__srv.create_mark(13, 11, 9)
        list=self.__srv.stat_2()
        self.assertEqual(len(list),2)
        print(list)
        self.assertEqual(list[0][0].getName(),'Marius')
        self.assertEqual(list[0][1],9.5)