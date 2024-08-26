#include <utility>
#include <vector>
#include <algorithm>
#include "elev.h"
#include "domain.h"

using namespace std;
class Repository{
private:
    vector<Elev> elevi;
    vector<Atelier> Ateliere;
    string filename;
    string filename2;
public:
    //Constructor
    Repository(string filename,string filename2):filename{std::move(filename)},filename2{std::move(filename2)}{
        loadFromFile();
    };
    //functia de a lua din fisier
    void loadFromFile();
    //Sorteaza elevii dupa nume.
    void sortare();
    //Returneaza toti elevii
    vector<Elev> getAllElevi();
    //Returneaza toate atelierii
    vector<Atelier> getAllAteliere();
};