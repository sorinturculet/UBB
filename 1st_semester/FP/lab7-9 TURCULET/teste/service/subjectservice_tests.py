from service.SubjectService import *
from repository.SubjectRepo import *
from domain.subject import *
from domain.SubjectValidator import *
import unittest

class SubjectServiceTest(unittest.TestCase):
    def setUp(self)->None:
        repo=SubjectRepository()
        validator=SubjectValidator()
        self.__srv=SubjectController(repo,validator)
    def test_add_subject(self):
        self.__srv.add_subject(1,'Mate','Sb')
        self.assertEqual(len(self.__srv.get_all()),1)
    def test_delete_subject(self):
        self.__srv.add_subject(1,'Mate','Sb')
        self.__srv.delete_subject(1)
        self.assertEqual(len(self.__srv.get_all()),0)
    def test_update_subject(self):
        self.__srv.add_subject(1,'Mate','Sb')
        self.__srv.update_subject(1,'Matematica','Stefan Berinde')
        subj=self.__srv.find_subject(1)
        self.assertEqual(subj.getName(),'Matematica')
        self.assertEqual(subj.getProfessor(),'Stefan Berinde')