from repository.MarksRepo import *
from domain.event import *
import unittest

class TestMarksRepo(unittest.TestCase):
    def setUp(self):
        self.__repo=EventRepository()
        self.__add_predefined_marks()
    def __add_predefined_marks(self):
        m=event(1,1,10)
        m2=event(2,2,9)
        self.__repo.add_event(m)
        self.__repo.add_event(m2)
    def test_size(self):
        self.assertEqual(len(self.__repo.get_all()),2)
    def test_delete(self):
        m2=event(2,2,9)
        self.__repo.delete_event(m2)
        self.assertEqual(len(self.__repo.get_all()),1)
    def test_update(self):
        m=event(1,1,10)
        self.__repo.update_event(m,9)
        m = event(1, 1, 9)
        searchedmark=self.__repo.find(m)
        self.assertEqual(searchedmark.getMark(),9)
class TestMarksRepoFile(unittest.TestCase):
    def setUp(self):
        self.__repo=EventRepoFile('marks_repo_tests.txt')
        self.__add_predefined_marks()
    def __add_predefined_marks(self):
        m=event(1,1,10)
        m2=event(2,2,9)
        self.__repo.add_event(m)
        self.__repo.add_event(m2)
    def test_size(self):
        self.assertEqual(len(self.__repo.get_all()),2)
    def test_delete(self):
        m2=event(2,2,9)
        self.__repo.delete_event(m2)
        self.assertEqual(len(self.__repo.get_all()),1)
    def test_update(self):
        m=event(1,1,10)
        self.__repo.update_event(m,9)
        m = event(1, 1, 9)
        searchedmark=self.__repo.find(m)
        self.assertEqual(searchedmark.getMark(),9)
    def tearDown(self):
        self.__repo.delete_all()
