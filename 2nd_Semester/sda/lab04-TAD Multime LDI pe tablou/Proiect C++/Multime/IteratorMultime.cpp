#include <exception>
#include "IteratorMultime.h"
#include "Multime.h"
#include<iostream>;
using namespace std;
/*
 * Complexitate
 * Theta(1)
 */
IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	curent=m.prim;
}
/*
 * Complexitate
 * Theta(1)
 */

void IteratorMultime::prim() {
	curent=multime.prim;
}

/*
 * Complexitate
 * Theta(1)
 */
void IteratorMultime::urmator() {
    if(!valid())
        throw std::exception();
    curent=multime.urm[curent];
}

/*
 * Complexitate
 * Theta(1)
 */
TElem IteratorMultime::element() const {
    return multime.e[curent];

}
/*
 * Complexitate
 * Theta(1)
 */
bool IteratorMultime::valid() const {
	if(curent==-1)
        return false;
    return true;
}
