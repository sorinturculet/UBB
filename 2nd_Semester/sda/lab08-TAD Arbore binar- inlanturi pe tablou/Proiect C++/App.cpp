#include <iostream>
#include <cassert>

#include "TestExtins.h"
#include "TestScurt.h"
#include "AB.h"

//problema 15 tema TAD ArboreBinar(cu iterator in preodine,inordine,postordine si latime)-
// reprezentare cu inlantuiri pe tablou
using namespace std;

void testElementMinim(){

    AB abc;
    try {
        abc.elementMinim();
    }
    catch (exception&) {
        assert(true); //ar trebui sa arunce exceptie
    }
    AB a8(8), a, a7(a8,7,a), a6(a7,6,a), a5(a6,5,a), a4(a5,4,a), a3(a4,3,a), a2(a3,20,a), ab(a2,1,a);
    assert(ab.elementMinim()==1);
    AB abb(9);
    assert(abb.elementMinim()==9);

}
int main() {
	testAll();
	testAllExtins();
	cout<<"End\n";
    testElementMinim();
    cout<<"End Minim";
    return 0;
}
