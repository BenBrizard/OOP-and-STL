/********************************************
* Titre: Travail pratique #6 - ExceptionArgumentInvalide.h
* Date: 10 avril 2018
* Auteur: Benoit Brizard
*******************************************/
#ifndef EXCEPTIONARGUMENTINVALIDE_H
#define EXCEPTIONARGUMENTINVALIDE_H

#include <QException>
#include <QString>

class ExceptionArgumentInvalide : public QException {
public:
    ExceptionArgumentInvalide(QString s="") : s_(s) {}
    virtual QString what() {return s_;}
private:
    QString s_;
};
#endif // EXCEPTIONARGUMENTINVALIDE_H
