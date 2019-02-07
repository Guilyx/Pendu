#include "../shared/qstd.h"
#include "pendu.h"
using namespace qstd;

int main()
{
    QString lettre;

    cout << "Hello" << endl;
    Pendu P1(15);
    cout << P1.getMmot() << " -> " << P1.getMcherche() << endl;

    while (P1.getMcherche() != P1.getMmot()){
        cout << "Choisir une lettre a tester" << endl;
        cin >> lettre;
        cout << lettre << " a ete trouve " << P1.propose(lettre[0]) << "  fois." << endl;
        cout << P1.getMcherche() << endl;
    }

    cout << "Vous avez win en " << P1.getMnbcoup() << " !" << endl;
}
