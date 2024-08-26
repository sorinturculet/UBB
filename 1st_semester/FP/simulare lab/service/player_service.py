from domain.player import Jucator
from domain.mvp import *
from repository.player_repo import PlayerRepoFile
class PlayerService():
    def __init__(self,repo:PlayerRepoFile):
        self.__repo=repo
    def find_players_by_position(self,string):
        players=self.__repo.get_all()
        playersposition=[]
        for player in players:
            playerposition=player.getPozitie()
            if string in playerposition:
                playersposition.append(player)
        return playersposition
    def get_player_performance(self,id,numberofmatches):
        player=self.__repo.find(id)
        numberofmatches=int(numberofmatches)
        mvp=MVPCandidate(player,numberofmatches)
        return mvp
