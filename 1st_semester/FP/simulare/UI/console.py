from service.TvShowService import TvShowService
class console():
    def __init__(self,service:TvShowService):
        self.__service = service
    def menu(self):
        print("Welcome")
        print("Select an option")
        print("1.Search shows by string inside genre")
        print("2.User preference for show")
        print("P.Print all shows")
        print("E.exit the program")
    def search_show_genre(self):
        search = input("Please input the string you want to search:")
        list=self.__service.find_by_genre(search)
        for show in list:
            print(show)
        if len(list)==0:
            print("No shows found")
    def user_rating(self):
        user_show = input("Please input the show you just watched:")
        user_rating=input("Please input the number of episodes you watched:")
        show,verdict=self.__service.show_preference(user_show,user_rating)
        print(str(show)+'||User verdict:'+verdict)
        if len(verdict)==0:
            print("No shows found")
    def get_all(self):
        shows=self.__service.get_all()
        for show in shows:
            print(show)
    def run(self):
        while True:
            self.menu()
            option=input("")
            match option:
                case "1":self.search_show_genre()
                case "2":self.user_rating()
                case "P":self.get_all()
                case "E":return