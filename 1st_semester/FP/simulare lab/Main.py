from service.player_service import *
from repository.player_repo import *
from UI.console import *

playerrepo=PlayerRepoFile('data/players.txt')
playerservice=PlayerService(playerrepo)
console=Console(playerservice)
console.run()