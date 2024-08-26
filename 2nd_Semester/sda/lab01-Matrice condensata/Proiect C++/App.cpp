#include <iostream>
#include "Matrice.h"
#include "TestExtins.h"
#include "TestScurt.h"
#include <cassert>
using namespace std;

void test_transpusa(){
    Matrice m(10,10);
    for(int j=0; j<m.nrColoane(); j++)
        m.modifica(4,j,3);
    for(int i=0; i<m.nrLinii(); i++)
        for(int j=0; j<m.nrColoane(); j++)
            if (i==4) {
                assert(m.element(i, j) == 3);
            }
            else
                assert(m.element(i,j) == NULL_TELEMENT);
    m.Transpusa();
    for(int i=0; i<m.nrLinii(); i++)
        for(int j=0; j<m.nrColoane(); j++)
            if (j==4) {
                assert(m.element(i, j) == 3);
            }
            else
                assert(m.element(i,j) == NULL_TELEMENT);

}
int main() {

    test_transpusa();
    testAll();
    testAllExtins();

	cout<<"End";
}
