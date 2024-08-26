from service.player_service import PlayerService
class Console():
    def __init__(self,player_service:PlayerService):
        self.__player_service=player_service
    def Menu(self):
        print('Bine ati venit')
        print('Alegeti una din urmatoarele optiuni:')
        print('1.Cautare dupa string')
        print('2.Sortare dupa media punctelor jucatori')
    def string_search(self):
        str=input('Introduceti stringul pentru a cauta pozitiile jucatorilor')
        list=self.__player_service.find_players_by_position(str)
        for element in list:
            print(element)
        if len(list)==0:
            print('Nu exista jucatori cu acest string in pozitia lor')
    def performance(self):
        str=input('Introduceti ID jucator')
        str2=input('Introduceti nr de meciuri jucate')
        mvpplayer=self.__player_service.get_player_performance(str,str2)
        print(mvpplayer)
    def run(self):
        while True:
            self.Menu()
            option=input('')
            match option:
                case '1':self.string_search()
                case '2':self.performance()