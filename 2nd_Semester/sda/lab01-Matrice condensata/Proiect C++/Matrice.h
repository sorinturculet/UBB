#pragma once

typedef int TElem;


#define NULL_TELEMENT 0

class Matrice {

private:

    int nrLines;
    int nrCols;

    int cap=2;
    int l=0;

    int *cols;
    int *lines;
    TElem *values;


public:

	//constructor
    //Complexitate Theta(nrCols), se initializeaza cu 0 toate coloanele;
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);

    //void PRINT();
    //Theta(1), deoarece dealoca spatiu.
	//destructor
	~Matrice();
    void Transpusa();
    //Theta(nrLines), se parcurge pentru o coloana, elementele existente dupa linii.
    //Best case(O(1), elementul e pe primul pe linie/ nu exista elemente pe linie.
    //Worst caseO(nrLines)
	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;

    //Theta(1)
	// returnare numar linii
	int nrLinii() const;

    //Theta(1)
	// returnare numar coloane
	int nrColoane() const;

    //Avem complexitate pentru redimensionare Theta(2)+Theta(nrLinii)+2*Theta(nrLinii)+Theta(nrCols)
    // Total Theta(nrLines+ nrCols)
    //Bestcase O(1), elementul e primul pe linia sa
    //WorstcaseO(nrLines+nrCols), nu exista elementul
	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);

};







