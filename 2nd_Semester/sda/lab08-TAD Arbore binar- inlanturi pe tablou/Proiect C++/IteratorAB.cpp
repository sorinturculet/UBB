#include <iostream>
#include "AB.h"
#include "IteratorAB.h"
/*
 * Complexitate
 * O(prim+1);
 */
IteratorInordine::IteratorInordine(const AB& _ab):ab(_ab) {
    this->curent=ab.radacina;
    prim();
}
/*
 * Complexitate
 * 0(n)
 * BC-O(1)-nu are la stanga subarbore
 * WC-O(n)-este arbore cu noduri doar spre dreapte
 */
void IteratorInordine::prim(){
    this->curent=ab.radacina;
    while(!st.empty())
        st.pop();
    while(curent!=-1){
        st.push(curent);
        curent=ab.stanga[curent];
    }
    if(!st.empty())
        curent=st.top();
}
/*
 * Complexitate
 * Theta(1)
 */
bool IteratorInordine::valid(){
	if(this->curent!=-1)
        return true;
    return false;
}
/*
 * Complexitate
 * Theta(1)
 */
TElem IteratorInordine::element() {
	TElem e=ab.v[curent];
    return e;
}
/*
 * Complexitate
 * O(n)-tot arborele este in continuare spre stanga,
 * O(1)-nu exista subarbore drept
 */
void IteratorInordine::urmator(){
	curent=st.top();
    st.pop();
    if(ab.dreapta[curent]!=-1){
        curent=ab.dreapta[curent];
        while(curent!=-1){
            st.push(curent);
            curent=ab.stanga[curent];
        }
    }
    if(!st.empty())
        curent=st.top();
    else curent=-1;
}


/*
 * Complexitate
 * O(1);
 */
IteratorPreordine::IteratorPreordine(const AB& _ab):ab(_ab){
	this->curent=ab.radacina;
    if(curent!=-1)
        st.push(curent);
}
/*
 * Complexitate
 * Theta(1);
 */
void IteratorPreordine::prim(){
    this->curent=ab.radacina;
    while(!st.empty())
        st.pop();
    if(curent!=-1)
        st.push(curent);
}

/*
 * Complexitate
 * Theta(1);
 */
bool IteratorPreordine::valid(){
	if(st.empty())
        return false;
    return true;
}
/*
 * Complexitate
 * Theta(1);
 */
TElem IteratorPreordine::element(){
	int e=st.top();
    curent=e;
    st.pop();
    return ab.v[e];
}
/*
 * Complexitate
 * Theta(1);
 */
void IteratorPreordine::urmator(){
    if(ab.dreapta[curent]!=-1)
	    st.push(ab.dreapta[curent]);
    if(ab.stanga[curent]!=-1)
        st.push(ab.stanga[curent]);

}

/*
 * Complexitate
 * O(prim+1);
 */
IteratorPostordine::IteratorPostordine(const AB& _ab):ab(_ab){
    curent=ab.radacina;
    prim();
}
/*
 * Complexitate
 * O(n)
 */
void IteratorPostordine::prim() {
    curent = ab.radacina;
    while (!st.empty())
        st.pop();
    if(curent!=-1) {
        while (curent != -1){//pun pana la stange
            st.push(std::make_pair(curent, 0));
            curent = ab.stanga[curent];
        }

        while (true) {
            std::pair<int, int> top = st.top();
            st.pop();
            int p = top.first;
            int k = top.second;
            if (k == 0) {
                // If we haven't traversed the right subtree of p, we add it back to the stack
                // and move to its right child
                st.push(std::make_pair(p, 1));
                curent = ab.dreapta[p];
                // We then add all the left children of the current node to the stack
                while (curent != -1) {

                    st.push(std::make_pair(curent, 0));
                    curent = ab.stanga[curent];
                }

            } else {
                curent = p;
                break;
            }
        }
    }
}
/*
 * Complexitate
 * O(1);
 */
bool IteratorPostordine::valid(){
	if(curent==-1 and st.empty())
        return false;
    return true;
}
/*
 * Complexitate
 * O(1);
 */
TElem IteratorPostordine::element(){

 	return ab.v[curent];
}
/*
 * Complexitate
 * O(n)
 */
void IteratorPostordine::urmator() {
    if(st.empty()) {
        curent = -1;
        return;
    }
    while(true) {
        std::pair<int, int> top = st.top();
        st.pop();
        int p = top.first;
        int k = top.second;
        if(k == 0) {
            // If we haven't traversed the right subtree of p, we add it back to the stack
            // and move to its right child
            st.push(std::make_pair(p, 1));
            curent = ab.dreapta[p];
            // We then add all the left children of the current node to the stack
            while(curent != -1) {

                st.push(std::make_pair(curent, 0));
                curent = ab.stanga[curent];
            }

        }
        else {
            curent=p;
            break;
        }
    }
}
/*
 * Complexitate
 * Theta(1)
 */
IteratorLatime::IteratorLatime(const AB& _ab):ab(_ab){
	curent=ab.radacina;
    prim();
}
/*
 * Complexitate
 * Theta(1)
 */
void IteratorLatime::prim(){
	curent=ab.radacina;
    while(!q.empty())
        q.pop();
    q.push(curent);
}

/*
 * Complexitate
 * Theta(1)
 */
bool IteratorLatime::valid(){
	if(curent!=-1)
        return true;
	return false;
}
/*
 * Complexitate
 * Theta(1)
 */
TElem IteratorLatime::element(){
	TElem e=ab.v[curent];
	return e;
}
/*
 * Complexitate
 * Theta(1)
 */
void IteratorLatime::urmator(){
    curent=q.front();
    q.pop();
    if(ab.stanga[curent]!=-1)
        q.push(ab.stanga[curent]);
    if(ab.dreapta[curent]!=-1)
        q.push(ab.dreapta[curent]);
    if(!q.empty())
        curent=q.front();
    else curent=-1;
}
