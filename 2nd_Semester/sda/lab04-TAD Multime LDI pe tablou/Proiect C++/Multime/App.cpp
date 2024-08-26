
#include "TestExtins.h"
#include "TestScurt.h"
#include "Multime.h"
#include <iostream>
#include <cassert>

using namespace std;
//Lista inlantuita ( reprezentare inlantuiri pe tablou)
// TAD MULTIME- FOLOSIND LDI

void testDif(){
    Multime m;
    assert(m.diferentaMaxMin()==-1);
    for (int i = 0; i < 10; i++) {
        int k=i*3;
        m.adauga(k);
    }
    assert(m.diferentaMaxMin()==27);
    m.adauga(-3);
    //9*3-(-3)=30;
    assert(m.diferentaMaxMin()==30);

}
int main() {

    testDif();
    cout << "Test DIFERENTA done" << endl;

	testAll();
	testAllExtins();

	cout << "That's all!" << endl;

}
