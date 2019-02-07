#include "pendu.h"
#include <../shared/qstd.h>
#include <QFile>
#include <QList>
#include <QTime>
#include <random>

using namespace qstd;

Pendu::Pendu(int taille): mtaille(taille)
{
    QFile file("../shared/liste_francais.txt");
    if(!file.open(QIODevice::ReadOnly)) {
    cerr<<"Fichier non trouvé !"<<endl;
    }
    QList<QString> mots[25];
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString word;
        word=in.readLine();
        int taille=word.length();
        mots[taille].append(word);
    }
    for(int i=1;i<25;i++){
        cout<<"Nombre de mots de taille "<<i<<" : "<<mots[i].size()<<endl;
    }

    cout << "======================" << endl;

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int random_choice = qrand()%(mots[taille].size());
    mmot = mots[taille][random_choice];
    cout << mots[taille][random_choice] << endl;

    for (int i=0; i < mmot.length(); i++){
        mcherche += "_";
    }
}

QString Pendu::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"Mot a trouver : " << getMmot() << endl << "Pendu : " << getMcherche();
    return res;
}

int Pendu::propose(QChar entry)
{
    int occur = 0;

    if (not(mdeja_propose.contains(entry))){
        mdeja_propose.append(entry);
        for (int ind = 0; ind < mmot.length() ; ind++){
            if (mmot.at(ind) == entry){
                mcherche[ind] = entry;
                occur++;
            }

        }
    }

    else{
        occur = -1;
    }

    mnbcoup++;
    return occur;
}

int Pendu::getMtaille() const
{
    return mtaille;
}

QString Pendu::getMmot() const
{
    return mmot;
}

QString Pendu::getMcherche() const
{
    return mcherche;
}

int Pendu::getMnbcoup() const
{
    return mnbcoup;
}
