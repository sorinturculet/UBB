from domain.TvShow import *
from domain.ShowEvaluation import *
import unittest
class DomainTests(unittest.TestCase):
    def setUp(self):
        pass
    def test_get_tv_show(self):
        show=TvShow('COM1','The Good Place','fantasy comedy',53)
        self.assertEqual(show.get_id_show(),'COM1')
        self.assertEqual(show.get_title(),'The Good Place')
        self.assertEqual(show.get_genre(),'fantasy comedy')
        self.assertEqual(show.get_number_of_episodes(),53)
    def test_eq_tv_episode(self):
        show=TvShow('COM1','The Good Place','fantasy comedy',53)
        show2=TvShow('COM2','The Good Place2','fantasy comedy',53)
        self.assertTrue(show!=show2)
    def test_get_preference(self):
        show=TvShow('COM1','The Good Place','fantasy comedy',53)
        ShowEvaluationshow=ShowEvaluation(show,18)
        print(ShowEvaluationshow.get_preference())
        self.assertEqual(ShowEvaluationshow.get_preference(),18/53)
