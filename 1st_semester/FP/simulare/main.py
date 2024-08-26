from repository.TvShowRepository import TvShowRepositoryFile
from service.TvShowService import TvShowService
from UI.console import console

repository=TvShowRepositoryFile('data/shows.txt')
service=TvShowService(repository)

console=console(service)
console.run()