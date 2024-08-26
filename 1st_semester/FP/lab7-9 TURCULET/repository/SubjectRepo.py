from domain.subject import *
class SubjectRepository:
    def __init__(self):
        self.__Subjects=[]
    def find(self,id):
        '''
        Searches for a student by id
        :param id:  int
        :return: student or none if it doesnt exist
        '''
        for Subject in self.__Subjects:
            if Subject.getId()==id:
                return Subject
        return None
    def addSubject(self,Subject:Subject):
        '''
        Adds a subject to the list
        :param Subject: Subject
        :return:
        '''
        if self.find(Subject.getId()):
            raise ValueError("A subject with that id already exists")
        self.__Subjects.append(Subject)
    def removeSubject(self,id):
        '''
        Removes a subject by searching it by id
        :param id: int
        :return:
        '''
        SubjectToDelete = self.find(id)
        if SubjectToDelete is None:
            raise ValueError("These isn't a subject with this id")
        self.__Subjects.remove(SubjectToDelete)
    def getAll(self):
        '''
        returns all subjects
        :return:
        '''
        return self.__Subjects
    def updateSubject(self,id,newName,newProfessor):
        '''
        updates a subject
        :param id: int
        :param newName:str
        :param newProfessor:str
        :return:
        '''
        subject=self.find(id)
        if subject:
            for subject2 in self.__Subjects:
                if subject2==subject:
                    subject2.setName(newName)
                    subject2.setProfessor(newProfessor)
        else:
            raise ValueError('Nu exista materie cu acest id')
class SubjectRepoFile():
    def __init__(self,filename):
        self.__filename=filename
    def __load_from_file(self):
        """
               Loads data from file
                :return: lista of Clients
                :rtype: list of Clients
                """

        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            raise ValueError('File ERROR')

        subjects = []
        lines = f.readlines()
        for line in lines:
            subject_id, subject_name,subject_professor= [token.strip() for token in line.split(';')]
            a = Subject(int(subject_id), subject_name,subject_professor)
            subjects.append(a)
        f.close()
        return subjects
    def __save_to_file(self, subject_list):
        """
        Salveaza in fisier studentii dati
        :return: -
        :rtype: -
        """
        with open(self.__filename, 'w') as f:
            for subject in subject_list:
                subject_string = str(subject.getId()) + ';' + str(subject.getName())+ ';' + str(subject.getProfessor())+ '\n'
                f.write(subject_string)
    def find(self,id):
        '''
        Searches for a student by id
        :param id:  int
        :return: student or none if it doesnt exist
        '''
        subjects=self.getAll()
        for Subject in subjects:
            if Subject.getId()==id:
                return Subject
        return None
    def addSubject(self,Subject:Subject):
        '''
        Adds a subject to the list
        :param Subject: Subject
        :return:
        '''
        if self.find(Subject.getId()):
            raise ValueError("A subject with that id already exists")
        subjects=self.getAll()
        subjects.append(Subject)
        self.__save_to_file(subjects)
    def removeSubject(self,id):
        '''
        Removes a subject by searching it by id
        :param id: int
        :return:deleted subject
        '''
        SubjectToDelete = self.find(id)
        if SubjectToDelete is None:
            raise ValueError("These isn't a subject with this id")
        subjects=self.getAll()
        subjects.remove(SubjectToDelete)
        self.__save_to_file(subjects)
        return SubjectToDelete
    def getAll(self):
        '''
        returns all subjects
        :return:list
        '''
        return self.__load_from_file()
    def updateSubject(self,id,newName,newProfessor):
        '''
        updates a subject
        :param id: int
        :param newName:str
        :param newProfessor:str
        :return:
        '''
        subject=self.find(id)
        subjects=self.getAll()
        if subject:
            for subject2 in subjects:
                if subject2==subject:
                    subject2.setName(newName)
                    subject2.setProfessor(newProfessor)
            self.__save_to_file(subjects)
        else:
            raise ValueError('Nu exista materie cu acest id')
    def delete_all(self):
        '''
        deletes all subjects
        :return:
        '''
        self.__save_to_file([])