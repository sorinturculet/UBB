#include "IteratorDictionar.h"
#include "Dictionar.h"
#include<exception>
using namespace std;
/*
 * Complexitate:
 * Overall: Theta(1)
 */
IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
	this->curent=d.primul;
}

/*
 * Complexitate:
 * Overall: Theta(1)
 */
void IteratorDictionar::prim() {
	this->curent=dict.primul;
}
/*
 * Complexitate:
 * Overall: Theta(1)
 */

void IteratorDictionar::urmator() {
    if(!valid())
        throw std::exception();
    this->curent= this->curent->urmator();
}

/*
 * Complexitate:
 * Overall: Theta(1)
 */
TElem IteratorDictionar::element() const{
    if(valid())
	    return curent->elem();
	return TElem (-1, -1);
}
/*
 * Complexitate:
 * Overall: Theta(1)
 */

bool IteratorDictionar::valid() const {
	if(curent== nullptr)
	    return false;
    return true;
}

