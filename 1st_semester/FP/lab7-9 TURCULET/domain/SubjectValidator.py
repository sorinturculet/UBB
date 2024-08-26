class SubjectValidator:
    def __int__(self):
        pass
    def ValidateSubject(self,subject):
        """
        Valideaza un task dat
        :param task: task-ul care se valideaza
        :return: -
         :raises: ValueError daca task-ul nu e valid
        """
        errors=[]
        if int(subject.getId())<0:
            errors.append("Id must be a positive number")
        if len(subject.getName())==0:
            errors.append("Subject should have a name")
        if len(subject.getProfessor())==0:
            errors.append('Subject should have a professor')
        if len(errors)>0:
            error_string='\n'.join(errors)
            raise ValueError(error_string)