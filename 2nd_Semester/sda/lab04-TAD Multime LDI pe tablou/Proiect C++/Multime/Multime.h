#pragma once
#define NULL_TELEM (-1)
typedef int TElem;

class IteratorMultime;

class Multime {
	friend class IteratorMultime;

    private:
		int cp;
        int prim,ultim,primLiber;
        TElem *e;
        int *urm;
        int *prec;

        void aloca(int i){
            i=primLiber;
            primLiber=urm[primLiber];
        }
        void dealoca(int i){
            urm[i]=primLiber;
            prec[primLiber]=i;
            primLiber=i;
        }


    public:
 		//constructorul implicit
        Multime() : cp(8), prim(-1), ultim(-1), primLiber(0) {
            // alocam dinamic
            e = new int[cp];
            prec = new int[cp];
            urm = new int[cp];

            // initializam urm si prec
            for (int i = 0; i < cp; ++i) {
                urm[i] = i + 1; // urm
                prec[i] = i - 1; // prev
            }
            urm[cp - 1] = -1; //final
            prec[0] = -1; // inceput
        }

    ~Multime() {
        delete[] e;
        delete[] prec;
        delete[] urm;
    }
		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(TElem e);

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(TElem e);

		//verifica daca un element se afla in multime
		bool cauta(TElem elem) const;


		//intoarce numarul de elemente din multime;
		int dim() const;

		//verifica daca multimea e vida;
		bool vida() const;

		//returneaza un iterator pe multime
		IteratorMultime iterator() const;
        //print reprezentare

        int diferentaMaxMin() const;
        void print();
		// destructorul multimii
};




