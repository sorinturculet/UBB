from repository.SubjectRepo import *
from domain.subject import *
import unittest
class TestStudentRepo(unittest.TestCase):
    def setUp(self) ->None:
        self.__repo=SubjectRepository()
        self.__add_predefined_subjects()
    def __add_predefined_subjects(self):
        s=Subject(1,'Mate','SB')
        self.__repo.addSubject(s)
        s=Subject(2,'Sport','Alergatoru pe Sate')
        self.__repo.addSubject(s)
        s=Subject(3,'Economie','Mama')
        self.__repo.addSubject(s)
    def test_size(self):
        self.assertTrue(len(self.__repo.getAll()),3)
    def test_find(self):
        s=self.__repo.find(1)
        self.assertEqual(s.getName(),'Mate')
        self.assertEqual(s.getProfessor(),'SB')
    def test_delete(self):
        self.__repo.removeSubject(1)
        self.assertEqual(len(self.__repo.getAll()),2)
        self.assertEqual(self.__repo.find(1),None)
    def test_update(self):
        self.__repo.updateSubject(2,'Sport','Fotbalistu')
        s=self.__repo.find(2)
        self.assertTrue(s.getProfessor()=='Fotbalistu')
class TestStudentRepoFile(unittest.TestCase):
    def setUp(self) ->None:
        self.__repo=SubjectRepoFile('subject_repo_test.txt')
        self.__add_predefined_subjects()
    def __add_predefined_subjects(self):
        s=Subject(1,'Mate','SB')
        self.__repo.addSubject(s)
        s=Subject(2,'Sport','Alergatoru pe Sate')
        self.__repo.addSubject(s)
        s=Subject(3,'Economie','Mama')
        self.__repo.addSubject(s)
    def test_size(self):
        self.assertTrue(len(self.__repo.getAll()),3)
    def test_find(self):
        s=self.__repo.find(1)
        self.assertEqual(s.getName(),'Mate')
        self.assertEqual(s.getProfessor(),'SB')
    def test_delete(self):
        self.__repo.removeSubject(1)
        self.assertEqual(len(self.__repo.getAll()),2)
        self.assertEqual(self.__repo.find(1),None)
    def test_update(self):
        self.__repo.updateSubject(2,'Sport','Fotbalistu')
        s=self.__repo.find(2)
        self.assertTrue(s.getProfessor()=='Fotbalistu')
    def tearDown(self) -> None:
        self.__repo.delete_all()