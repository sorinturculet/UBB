from domain.TvShow import TvShow
from domain.ShowEvaluation import ShowEvaluation
class TvShowRepositoryFile():
    def __init__(self,filename):
        self.__filename = filename
    def __load_from_file(self):
        '''
        loads the list of shows from the file
        :return: list of shows
        '''
        try:
            f=open(self.__filename,'r')
        except:
            raise ValueError("Could'nt open file")
        lines=f.readlines()
        shows=[]
        for line in lines:
            id_show, title, genre, number_of_episodes=[token.strip() for token in line.split(',')]
            number_of_episodes=int(number_of_episodes)
            show=TvShow(id_show,title,genre,number_of_episodes)
            shows.append(show)
        f.close()
        return shows
    def __save_to_file(self,shows):
        '''
        saves to file the list of shows
        :param shows: list
        :return:
        '''
        f=open(self.__filename,'w')
        for show in shows:
            showstring=str(show.get_id())+','+str(show.get_title())+','+str(show.get_genre())+','+str(show.get_number_of_episodes())
            f.write(showstring)
    def find_show_by_id(self,show_id:str):
        '''
        searches a show by id
        :param show_id: str
        :return: show or none if show doesnt exist
        '''
        shows=self.__load_from_file()
        for show in shows:
            if show.get_id_show()==show_id:
                return show
        return None
    def find_shows_by_genre(self,show_genre:str):
        '''
        searches shows that have show_genre in their genre field
        :param show_genre: str
        :return: list of shows
        '''
        shows=self.__load_from_file()
        shows_genre=[]
        for show in shows:
            if show_genre in show.get_genre():
                shows_genre.append(show)
        return shows_genre

    def get_all(self):
        '''
        returns all shows
        :return:
        '''
        return self.__load_from_file()
    def tearDown(self):
        self.__save_to_file([])