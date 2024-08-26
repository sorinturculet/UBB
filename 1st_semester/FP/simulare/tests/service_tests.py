from repository.TvShowRepository import *
from service.TvShowService import *
import unittest
class ServiceTests(unittest.TestCase):
    def setUp(self):
        self.__repository = TvShowRepositoryFile('shows_tests.txt')
        self.__service=TvShowService(self.__repository)
    def test_find_by_genre(self):
        shows=self.__service.find_by_genre('psychological')
        self.assertEqual(len(shows),2)
    def test_show_preference(self):
        show,rating=self.__service.show_preference('THR1',2)
        self.assertEqual(rating,'disliked')
    def test_get(self):
        shows=self.__service.get_all()
        self.assertEqual(len(shows),10)