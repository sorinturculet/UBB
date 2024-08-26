from utils.bubblesort import bubble_sort
from utils.shellsort import shellsort
import unittest
class TestSortari(unittest.TestCase):
    def test_bubble_sort(self):
        list=[1,10,3,5,6,4,9,7,8,2]
        bubble_sort(list)
        self.assertEqual(list,[1,2,3,4,5,6,7,8,9,10])
        list = [1, 10, 3, 6,5, 4, 9, 7, 8, 2]
        bubble_sort(list,reverse=True)
        self.assertEqual(list, [10,9,8,7,6,5,4,3,2,1])

class TestShellSort(unittest.TestCase):
    def test_shell_sort(self):
        list=[1,10,3,5,6,4,9,7,8,2]
        list=shellsort(list)
        self.assertEqual(list,[1,2,3,4,5,6,7,8,9,10])