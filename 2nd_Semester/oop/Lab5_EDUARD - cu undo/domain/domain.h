
typedef struct {
    char* denumire;
    char* producator;
    int cantitate;
}Produs;
// nume - char*
// producator - char*
// cantitate - int
// Functia creaza un nou produs
extern Produs* crearePr(char* nume, char* producator, int cantitate);
extern Produs* duplicatePr(Produs* Pr);
void destroyPr(Produs* tr);
