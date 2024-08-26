from repository.TvShowRepository import TvShowRepositoryFile
from domain.ShowEvaluation import *
class TvShowService:
    def __init__(self,repository: TvShowRepositoryFile):

        self.__repository = repository
    def find_by_genre(self,show_genre):
        '''
        finds shows that have the genre string related to the string given
        :param show_genre:
        :return:
        '''
        return self.__repository.find_shows_by_genre(show_genre)
    def show_preference(self,show_id,number_of_episodes_watched):
        '''
        returns the verdict of a user based on the number of episodes watched
        :param show_id: str
        :param number_of_episodes_watched: int
        :return:
        '''
        number_of_episodes_watched=int(number_of_episodes_watched)

        show=self.__repository.find_show_by_id(show_id)
        if show is None:
            raise ValueError('No show FOUND')
        show_evaluation=ShowEvaluation(show,number_of_episodes_watched)
        rating=show_evaluation.get_preference()
        if rating>2/3:
            return show,'favorit'
        elif rating>1/3:
            return show,'if_bored'
        else:
            return show,'disliked'
        return self.__repository.user_preference(show_id,number_of_episodes_watched)
    def get_all(self):
        '''
        returns all shows
        :return:
        '''
        return self.__repository.get_all()