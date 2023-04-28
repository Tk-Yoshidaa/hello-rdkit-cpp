#include <iostream>
#include <GraphMol/SmilesParse/SmilesParse.h>

using namespace std;
using namespace RDKit;

int main(int argc, char ** argv)
{
    if (argc > 1)
    {
        cout << "Input SMILES: " << argv[1] << endl;
        RWMol * mol = SmilesToMol(argv[1]);
        if (mol != nullptr)
            cout << "Input SMILES Successfully parsed!!" << endl;
    }
    cout << "Hello RDKit on C++ !!" << endl;
}