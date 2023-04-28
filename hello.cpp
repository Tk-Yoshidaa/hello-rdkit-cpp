#include <iostream>
#include <memory>
#include <GraphMol/MolOps.h>
#include <GraphMol/SmilesParse/SmilesParse.h>


using namespace std;
using namespace RDKit;

int main(int argc, char ** argv)
{
    if (argc == 1)
    {
        cout << "Hello RDKit on C++ !!" << endl;
        cout << "Usage: ./hello SMILES" << endl;
        exit(0);
    }

    cout << "Input SMILES: " << argv[1] << endl;
    unique_ptr<RWMol> mol;
    try
    {
        mol.reset((SmilesToMol(argv[1])));
    }
    catch (MolSanitizeException & e)
    {
        cerr << "Failed to parse, what: " << e.what() << endl;
        exit(1);
    }
    if (!mol)
    {
        cerr << "Failed to parse, SmilesToMol returned nullptr" << endl;
        exit(1);
    }

    cout << "Input SMILES Successfully parsed!!" << endl;
    cout << "Molecule Information:" << endl;
    cout << "\t# of atoms: " << mol->getNumAtoms() << endl;
    cout << "\t# of bonds: " << mol->getNumBonds() << endl;
    cout << "\t# of SSSR rings: " << MolOps::findSSSR(* mol) << endl;

}