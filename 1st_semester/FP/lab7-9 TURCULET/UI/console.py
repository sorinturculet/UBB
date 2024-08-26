from service.StudentService import *
from service.SubjectService import *
from service.MarkService import *
import random
class Console:
    def __init__(self,controller: StudentController,controllerSub:SubjectController,controllermark:MarkController):
        self.__student_service=controller
        self.__subject_service=controllerSub
        self.__mark_service=controllermark
    def print_menu(self):
        '''
        printeaza meniul
        :return:
        '''
        print('Bine ai venit! Poti selecta una din urmatoarele functionalitati')
        print('1.Add student')
        print('2.Remove Student')
        print('3.Find student')
        print('4.Modify Student')
        print('5.Add subject')
        print('6.Remove subject')
        print('7.Find subject')
        print('8.Modify subject')
        print('9.Create Mark')
        print('10.Delete Mark')
        print('PS. Print Students')
        print('PSU.Print subjects')
        print('PM.Print Marks')
        print('RS.Add random students')
        print('RSN.Add n random students')
        print('RSU.Add random subject')
        print('STAT1.Afiseaza studentii de la o anumita materie ordonati')
        print('STAT2.Afiseaza primii 20% din studenti dupa medie')
        print('STAT3.Afiseaza toti studentii cu media mai mare de 5 sortati dupa note')
        print('STAT3B.Afiseaza toti studentii cu media mai mare de 5 sortati dupa nota si alfabetic ')

    def add_studentUI(self):
        '''
        adauga un student folosind date din consola
        :return:
        '''
        id=input('Introduceti id-ul studentului')
        name=input('Introduceti numele studentului')
        try:
            id=int(id)
            self.__student_service.add_student(id,name)
        except ValueError as e:
            print('EROARE')
    def delete_studentUI(self):
        '''
        sterge un student folosind date din consola
        :return:
        '''
        id=input('Introduceti id studentului pe care vreti sa-l stergeti ')
        try:
            id=int(id)
            self.__student_service.delete_student(id)
        except ValueError as e:
            print('Nu exista un student cu acest ID')
    def find_studentUI(self):
        '''
        cauta un student folosind date din consola
        :return:
        '''
        id=input('Introduceti id-ul pentru a afla date despre student')
        try:
            id=int(id)
            student=self.__student_service.find_student(id)
            if student:
                print(Student)
            else:
                raise ValueError("Nu exista un student cu acest id")
        except ValueError as e:
            print('Nu exista un student cu acest ID')
    def update_studentUI(self):
        '''
        updateaza un student folosing date din consola
        :return:
        '''
        id=input("Introduceti id ul studentului pe care doriti sa l schimbati")
        newname=input('Introduceti numele nou al studentului')
        try:
            id=int(id)
            self.__student_service.update_student(id,newname)
        except ValueError as e:
            print('Eroare')

    def add_subjectUI(self):
        '''
        adauga o materie folosing date din consola
        :return:
        '''
        id=input('Introduceti id ul pentru materie')
        name=input('Introduceti numele materiei')
        professor=input('Introduceti profesorul pentru materie')
        try:
            id=int(id)
            self.__subject_service.add_subject(id,name,professor)
        except ValueError as e:
            print('EROARE')
    def delete_subjectUI(self):
        '''
        sterge o materie folosing date din consola
        :return:
        '''
        id=input('Introduceti idu-ul materiei pe care vreti sa o stergeti')
        try:
            id=int(id)
            self.__subject_service.delete_subject(id)
        except ValueError as e:
            print('eroare')
    def find_subjectUI(self):
        '''
        cauta o materie folosing date din consola
        :return:
        '''
        id = input('Introduceti idu=-ul materiei pe care vreti sa o cautati')
        try:
            id=int(id)
            subject=self.__subject_service.find_subject(id)
            if subject:
                print(subject)
            else:
                raise ValueError("Nu exista subject cu acest ID")
        except ValueError as e:
            print('Nu exista subject cu acest ID')
    def update_subjectUI(self):
        '''
        cauta o materie folosing date din consola
        :return:
        '''
        id=input('Introduceti id-ul materiei pe care doriti sa o schimbati')
        newname=input('Introduceti numele nou al materiei')
        newprofessor=input("Introduceti numele nou al profesorului")
        try:
            id=int(id)
            self.__subject_service.update_subject(id,newname,newprofessor)
        except ValueError as e:
            print('Nu exista materie cu acest id')

    def print_studentsUI(self):
        '''
        printeaza studentii
        :return:
        '''
        students=self.__student_service.print_student()
        for student in students:
            print(student)
    def print_subjectsUI(self):
        '''
        printeaza materiile
        :return:
        '''
        subjects=self.__subject_service.get_all()
        for subject in subjects:
            print(subject)
    def create_mark(self):
        '''
        creaza un event, prin idstudent, idmaterie si nota
        :return:
        '''
        idstudent=input('Introduceti id ul studentului')
        idmaterie=input('Introduceti id ul materiei')
        mark=input('Introduceti nota corespunzatoare')
        idstudent=int(idstudent)
        idmaterie=int(idmaterie)
        try:
            self.__mark_service.create_mark(idstudent,idmaterie,mark)
        except ValueError as e:
            print('Eroare')
    def delete_mark(self):
        '''
        sterge un event cautandu-l dupa datele sale
        :return:
        '''
        idstudent=input('Introduceti id ul studentului')
        idmaterie=input('Introduceti id ul materiei')
        mark=input('Introduceti nota corespunzatoare')
        idstudent=int(idstudent)
        idmaterie=int(idmaterie)
        mark=event(idstudent,idmaterie,mark)
        try:
            self.__mark_service.delete_mark(mark)
        except ValueError as e:
            print('Eroare')
    def stat_1(self):
        '''
        afiseaza studentii dupa notele lor de la materia ceruta
        :return:
        '''
        idmaterie=input('Introduceti id ul materiei dupa care vreti sa ordonati studentii')
        idmaterie=int(idmaterie)
        list=self.__mark_service.stat_1(idmaterie)
        for mark in list:
            print(mark)
        if(len(list)==0):
            print('Materia nu are inca note incarcate')
    def stat_2(self):
        '''
        afiseaza primii 20% din studenti dupa media lor.
        :return:
        '''
        list=self.__mark_service.stat_2()
        if len(list):
            for index in range(0,len(list)):
                print(list[index][0],list[index][1])
        else:
            print('Nu exista note asociate studentilor')
    def stat_3(self):
        '''
        afiseaza studentii cu media mai mare de 5
        :return:
        '''
        list=self.__mark_service.stat_3()
        if len(list):
            for index in range(0,len(list)):
                print(list[index][0],list[index][1])
        else:
            print('Nu exista note asociate studentilor')
    def stat_3b(self):
        '''
        afiseaza studentii cu media mai mare de 5
        :return:
        '''
        list=self.__mark_service.stat_3s()
        if len(list):
            for index in range(0,len(list)):
                print(list[index][0],list[index][1])
        else:
            print('Nu exista note asociate studentilor')
    def print_marks(self):
        '''
        afiseaza toate notele assigned
        :return:
        '''
        marks=self.__mark_service.get_all()
        for mark in marks:
            print(mark)
    def randomStud(self):
        '''
        creaza un student aleatoriu
        :return:
        '''
        first_names = ('Marius', 'Ionut', 'Italianu','Mexicanu','Americanu','Vali','Mirel','Portaru','Snaila')
        last_names = ('Spaider', 'Bormasina', 'Nicovala','DJ-ul','Tarla','Calculator','Haina')
        id=random.randint(0,200)
        while True:
            student = self.__student_service.find_student(id)
            if student:
                id=random.randint(0,200)
            else:
                break
        name=random.choice(first_names)+' '+random.choice(last_names)
        self.__student_service.add_student(id,name)
    def randomStudN(self):
        '''
        creeaza n studenti aleatorii folosind functia de mai sus
        :return:
        '''
        n=input('Introduceti n pentru care vom genera n studenti aleatoriu')
        n=int(n)
        for index in range(0,n):
            self.randomStud()
    def randomSubject(self):
        '''
        creaza un subject aleatoriu
        :return:
        '''
        first_names = ('Marius', 'Ionut', 'Italianu','Mexicanu','Americanu','Vali')
        last_names = ('Spaider', 'Bormasina', 'Salam','DJ-ul')
        id=random.randint(0,200)
        Materii=('MAtematica','Informatica','Geografie','Smecherie','Teoria Dublajelor')
        professor=random.choice(first_names)+' '+random.choice(last_names)
        self.__subject_service.add_subject(id,random.choice(Materii),professor)
    def test(self):
        self.__student_service.add_student(10, 'Marius')
        self.__student_service.add_student(11, 'Marius')
        self.__student_service.add_student(12, 'Marius')
        self.__student_service.add_student(13, 'Marius')
        self.__student_service.add_student(14, 'Marius')
        self.__subject_service.add_subject(10,'Mate1','SB')
        self.__subject_service.add_subject(11,'Mate2','SB')
        self.__mark_service.create_mark(10,10,10)
        self.__mark_service.create_mark(11,10,7)
        self.__mark_service.create_mark(12,10,8)
        self.__mark_service.create_mark(13,10,5)
        self.__mark_service.create_mark(10, 11, 9)
        self.__mark_service.create_mark(11, 11, 3)
        self.__mark_service.create_mark(12, 11, 2)
        self.__mark_service.create_mark(13, 11, 9)

    def run(self):
        while True:
            self.print_menu()
            option=input('>')
            match option:
                case '1': self.add_studentUI()
                case '2':self.delete_studentUI()
                case '3':self.find_studentUI()
                case '4':self.update_studentUI()
                case '5':self.add_subjectUI()
                case '6':self.delete_subjectUI()
                case '7':self.find_subjectUI()
                case '8':self.update_subjectUI()
                case '9':self.create_mark()
                case '10':self.delete_mark()
                case '11':self.find_mark()
                case 'PS':self.print_studentsUI()
                case 'PSU':self.print_subjectsUI()
                case 'PM':self.print_marks()
                case 'RS':self.randomStud()
                case 'RSN':self.randomStudN()
                case 'RSU':self.randomSubject()
                case 'STAT1':self.stat_1()
                case 'STAT2':self.stat_2()
                case 'STAT3':self.stat_3()
                case 'STAT3B':self.stat_3b()
                case 'TEST':self.test()

