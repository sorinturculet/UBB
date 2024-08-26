class Student:
    def __init__(self,id,name):
        self.__list=[id,name]
    def getId(self):
        return self.__list[0]
    def getName(self):
        return self.__list[1]
    def setName(self,NewName):
        self.__list[1]=NewName
    def setId(self,NewId):
        self.__list[0]=NewId
    def __eq__(self, other):
        return self.getId() == other.getId()
    def __str__(self):
        return "ID:"+ str(self.getId())+"|"+'Name:'+str(self.getName())