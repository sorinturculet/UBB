from repository.StudentRepo import *
from domain.student import *
import unittest
class TestStudentRepo(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo=StudentRepository()
        self.__add_predifined_students()
    def __add_predifined_students(self):
        student=Student(10,'Marius')
        self.__repo.addStudent(student)
        student2=Student(11, 'catalin')
        self.__repo.addStudent(student2)
        student3 = Student(12, 'Marius')
        self.__repo.addStudent(student3)
        student4 = Student(13, 'sergiu')
        self.__repo.addStudent(student4)
        student5 = Student(14, 'Marios')
        self.__repo.addStudent(student5)
    def test_size(self):
        self.assertEqual(len(self.__repo.getAll()),5)
    def test_find(self):
        p=self.__repo.find(10)
        self.assertTrue(p.getName()=='Marius')
    def test_delete_student(self):
        self.__repo.deleteStudent(10)
        self.assertEqual(len(self.__repo.getAll()),4)
        self.assertEqual(self.__repo.find(10),None)
    def test_update_student(self):
        self.__repo.update_student(12,'Andrei')
        p=self.__repo.find(12)
        self.assertEqual(p.getName(),'Andrei')
class TestStudentRepoFile(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo=StudentRepoFile('student_repo_test.txt')
        self.__add_predifined_students()
    def __add_predifined_students(self):
        student=Student(10,'Marius')
        student2=Student(11, 'catalin')
        student3 =Student(12, 'Marius')
        student4= Student(13, 'sergiu')
        student5= Student(14, 'Marios')
        self.__repo.addStudent(student)
        self.__repo.addStudent(student2)
        self.__repo.addStudent(student3)
        self.__repo.addStudent(student4)
        self.__repo.addStudent(student5)
    def test_size(self):
        self.assertEqual(len(self.__repo.getAll()),5)
    def test_find(self):
        p=self.__repo.find(10)
        self.assertTrue(p.getName()=='Marius')
    def test_delete_student(self):
        self.__repo.deleteStudent(10)
        self.assertEqual(len(self.__repo.getAll()),4)
        self.assertEqual(self.__repo.find(10),None)
    def test_update_student(self):
        self.__repo.update_student(12,'Andrei')
        p=self.__repo.find(12)
        self.assertEqual(p.getName(),'Andrei')
    def tearDown(self) -> None:
        self.__repo.delete_all()