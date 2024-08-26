from domain.student import *
class StudentRepository:
    def __init__(self):
        self.__students=[]
    def find(self, id):
        """
        Gaseste task-ul cu id dat
        :param id: id-ul cautat
        :type id: int
        :return: task-ul cu id dat
        :rtype: Task
        """
        for Student in self.__students:
            if Student.getId() == id:
                return Student
        return None
    def addStudent(self, Student: Student):
        '''
        Adds a student to the list
        :param Student: Student
        :return:
        '''
        if self.find(Student.getId()):
            raise ValueError('A student with this id already exists.')
        self.__students.append(Student)
    def deleteStudent(self, id):
        '''
        Deletes a student by id
        :param id: int
        :return:
        '''
        StudentToDelete=self.find(id)
        if StudentToDelete is None:
            raise ValueError("These isn't a student with this id")
        self.__students.remove(StudentToDelete)
        return StudentToDelete
    def update_student(self,id,newname):
        '''
        Updates a student
        :param id: int
        :param newname: str
        :return:
        '''
        StudentToUpdate=self.find(id)
        if StudentToUpdate:
            for student in self.__students:
                if student==StudentToUpdate:
                    student.setName(newname)
        else:
            raise ValueError("Nu exista student cu acest id")
    def getAll(self):
        '''
        returns all students
        :return:
        '''
        return self.__students

class StudentRepoFile:
    def __init__(self,filename):
        self.__filename=filename
    def __load_from_file(self):
        """
                Incarca datele din fisier
                :return: lista cu clientii din fisier
                :rtype: list of Clients
                """

        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            raise ValueError('File ERROR')
        students = []
        lines = f.readlines()
        for line in lines:
            student_id, student_name = [token.strip() for token in line.split(';')]
            a = Student(int(student_id), student_name)
            students.append(a)
        f.close()
        return students
    def __save_to_file(self, student_list):
        """
        Salveaza in fisier studentii dati
        :return: -
        :rtype: -
        """
        with open(self.__filename, 'w') as f:
            for student in student_list:
                student_string = str(student.getId()) + ';' + str(student.getName())+ '\n'
                f.write(student_string)
    def find(self, id):
        """
        Gaseste task-ul cu id dat
        :param id: id-ul cautat
        :type id: int
        :return: task-ul cu id dat
        :rtype: Task
        """
        students=self.getAll()
        for Student in students:
            if Student.getId() == id:
                return Student
        return None
    def addStudent(self, Student: Student):
        '''
        Adds a student to the list
        :param Student: Student
        :return:
        '''
        students=self.getAll()
        if self.find(Student.getId()) is not None:
            print('Id duplicat')
            return
        students.append(Student)
        self.__save_to_file(students)
    def deleteStudent(self, id):
        '''
        Deletes a student by id
        :param id: int
        :return:
        '''
        StudentToDelete=self.find(id)
        if StudentToDelete is None:
            raise ValueError("These isn't a student with this id")
        students=self.getAll()
        students.remove(StudentToDelete)
        self.__save_to_file(students)
        return StudentToDelete
    def update_student(self,id,newname):
        '''
        Updates a student
        :param id: int
        :param newname: str
        :return:
        '''
        StudentToUpdate=self.find(id)
        students=self.getAll()
        if StudentToUpdate:
            for student in students:
                if student==StudentToUpdate:
                    student.setName(newname)
            self.__save_to_file(students)
        else:
            raise ValueError("Nu exista student cu acest id")
    def getAll(self):
        '''
        returns all students
        :return:
        '''
        return self.__load_from_file()
    def delete_all(self):
        self.__save_to_file([])