from service.StudentService import *
from repository.StudentRepo import *
from domain.student import *
import unittest
class TestStudentService(unittest.TestCase):
    def setUp(self)->None:
        repo=StudentRepository()
        validator=StudentValidator()
        self.__srv=StudentController(repo,validator)
    def test_add_student(self):
        added_student=self.__srv.add_student(1,'Marios')
        self.assertEqual(added_student.getName(),'Marios')
        self.assertEqual(added_student.getId(),1)
        self.assertEqual(len(self.__srv.print_student()),1)
    def test_delete_student(self):
        added_student=self.__srv.add_student(1,'Marios')
        deleted_student=self.__srv.delete_student(1)
        self.assertEqual(len(self.__srv.print_student()),0)
    def test_update_student(self):
        added_student=self.__srv.add_student(1,'Marios')
        self.__srv.update_student(1,'Marius')
        stud=self.__srv.find_student(1)
        self.assertEqual(stud.getName(),'Marius')