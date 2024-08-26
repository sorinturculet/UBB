class Jucator:
    def __init__(self,id_jucator,nume,pozitie,puncte):
        self.__id_jucator=id_jucator
        self.__nume=nume
        self.__pozitie=pozitie
        self.__puncte=puncte
    def setId(self,id):
        self.__id_jucator=id
    def setName(self,name):
        self.__nume=name
    def setPozitie(self,position):
        self.__pozitie=position
    def setPuncte(self,points):
        self.puncte=points
    def getId(self):
         return self.__id_jucator
    def getName(self):
        return self.__nume
    def getPozitie(self):
        return self.__pozitie
    def getPuncte(self):
        return self.__puncte
    def __eq__(self, other):
        return self.getId()==other.getId()
    def __str__(self):
        return 'ID:'+str(self.getId())+'|'+'Name:'+str(self.getName())+'|'+'Pozitie:'+str(self.getPozitie())+'|'+'Points:'+str(self.getPuncte())+'|'