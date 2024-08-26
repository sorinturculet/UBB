class StudentValidator:
    def __init__(self):
        pass

    def StudentValidator(self, student):
        """
        Valideaza un task dat
        :param task: task-ul care se valideaza
        :return: -
        :raises: ValueError daca task-ul nu e valid
        """
        errors = []
        if(int(student.getId())<0):
            errors.append('Id must be a positive number')
        if(student.getName()==''):
            errors.append('Student should have a name')
        if len(errors) > 0:
            error_string = '\n'.join(errors)
            raise ValueError(error_string)