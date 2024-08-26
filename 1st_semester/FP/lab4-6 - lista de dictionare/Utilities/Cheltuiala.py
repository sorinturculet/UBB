class Cheltuiala:
    def __init__(self, name, sum, type, day):
        self.name =name
        self.sum=sum
        self.type=type
        self.day=day

    def __str__(self):
        return f'The cheltuiala object:{self.name},{self.sum},{self.type},{self.day}'

typesOfCheltuieli = ("Mancare","Intretinere","Imbracaminte","Telefon","Altele")
