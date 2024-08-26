class Subject:
    def __init__(self,id,name,professor):
        self.__id=id
        self.__name=name
        self.__professor=professor
    def getId(self):
        return self.__id
    def getName(self):
        return self.__name
    def getProfessor(self):
        return self.__professor
    def setName(self, NewName):
        self.__name = NewName
    def setId(self, NewId):
        self.__id = NewId
    def setProfessor(self,newProfessor):
        self.__professor=newProfessor
    def __eq__(self, other):
        return self.getId() == other.getId()
    def __str__(self):
        return "ID:"+ str(self.getId())+"|"+'Name:'+str(self.getName())+"|"+"Professor:"+str(self.getProfessor())