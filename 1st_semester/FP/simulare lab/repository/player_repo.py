from domain.player import Jucator
class PlayerRepoFile():
    def __init__(self,filename):
        self.__filename=filename
    def __load_from_file(self):
        try:
            f=open(self.__filename,'r')
        except:
            raise ValueError("Could'nt open file")
        players=[]
        lines=f.readlines()
        for line in lines:
            player_id,player_name,player_position,player_points=[token.strip() for token in line.split(',')]
            player=Jucator(player_id,player_name,player_position,int(player_points))
            players.append(player)
        f.close()
        return players
    def __save_to_file(self,players:list):
        with open(self.__filename,'w')as f:
            for player in players:
                player_string=str(player.getId())+','+str(player.getName())+','+str(player.getPosition())+','+str(player.getPoints())
                f.write(player_string)
    def find(self,id):
        players=self.__load_from_file()
        for player in players:
            if(player.getId()==id):
                return player
        return None
    def get_all(self):
        return self.__load_from_file()

