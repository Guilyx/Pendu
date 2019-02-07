#ifndef PENDU_H
#define PENDU_H

#include <QString>
#include <QList>

class Pendu
{
public:
    Pendu(int taille);
    QString toString();
    int propose(QChar entry);


    int getMtaille() const;
    QString getMmot() const;
    QString getMcherche() const;
    int getMnbcoup() const;

    bool getWin() const;

private:
    int mtaille;
    QString mmot;

    QString mcherche;
    QList<QChar> mdeja_propose;
    int mnbcoup = 0;
};

#endif // PENDU_H
