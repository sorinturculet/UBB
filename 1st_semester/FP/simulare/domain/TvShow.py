class TvShow():
    def __init__(self,id_show:str,title:str,genre:str,number_of_episodes:int):
        self.__id_show=id_show
        self.__title=title
        self.__genre=genre
        self.__number_of_episodes=number_of_episodes
    def set_id_show(self,id_show:str):
        self.__id_show=id_show
    def set_title(self,title:str):
        self.__title=title
    def set_genre(self,genre:str):
        self.__genre=genre
    def set_number_of_episodes(self,number_of_episodes:int):
        self.__number_of_episodes=number_of_episodes
    def get_id_show(self):
        return self.__id_show
    def get_title(self):
        return self.__title
    def get_genre(self):
        return self.__genre
    def get_number_of_episodes(self):
        return self.__number_of_episodes
    def __eq__(self, other):
        return self.__id_show==other.__id_show
    def __str__(self):
        return 'ID:'+str(self.get_id_show())+'|'+'Title:'+str(self.get_title())+'|'+'Genre:'+str(self.get_genre())+'|'+'Num of episodes:'+str(self.get_number_of_episodes())