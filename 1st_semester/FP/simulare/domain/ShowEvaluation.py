from domain.TvShow import TvShow
class ShowEvaluation:
    def __init__(self, tvShow: TvShow,number_of_episodes_watched:int):
        self.__tvShow = tvShow
        self.__number_of_episodes_watched =number_of_episodes_watched
    def get_preference(self):
        total_episodes=self.__tvShow.get_number_of_episodes()
        total_episodes=int(total_episodes)
        return self.__number_of_episodes_watched/total_episodes
