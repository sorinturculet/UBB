from domain.player import Jucator
class MVPCandidate():
    def __init__(self,player:Jucator,n_of_matches):
        self.__player=player
        self.__n_of_matches=n_of_matches
    def get_points_average(self):
        return self.__player.getPuncte()//self.__n_of_matches
    def __str__(self):
        return "Player ID:"+str(self.__player.getId())+'|'+'Player Name:'+str(self.__player.getName())+'|'+'Average Points:'+str(self.get_points_average())
