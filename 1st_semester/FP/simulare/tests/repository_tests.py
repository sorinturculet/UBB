from repository.TvShowRepository import *
import unittest
class RepositoryTests(unittest.TestCase):
    def setUp(self):
        self.repository =TvShowRepositoryFile('shows_tests.txt')
    def test_load_tests(self):
        items=self.repository.get_all()
        self.assertEqual(len(items),10)
    def test_find(self):
        show=self.repository.find_show_by_id('THR1')
        self.assertEqual(show.get_title(),'Mindhunter')
    def test_find_genre(self):
        list=self.repository.find_shows_by_genre('comedy')
        self.assertEqual(len(list),3)
    def test_user_preferences(self):
        show,rating=self.repository.user_preference('FAN4',1)
        self.assertEqual(rating,'disliked')
        show, rating = self.repository.user_preference('FAN4', 4)
        self.assertEqual(rating, 'if_bored')
        show, rating = self.repository.user_preference('FAN4', 8)
        self.assertEqual(rating, 'favorit')
