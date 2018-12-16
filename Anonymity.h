#ifndef ANONYMITY_H
#define ANONYMITY_H
#include "User.h"

/* �����û� */
class Anonymity : public User
{
public:
    Anonymity(){}
    virtual QString Show() override {return "Anonymity!";}
    virtual bool SignIn(QString name, QString pw) override final{return true;}
    virtual void SignOut () override final {}
};

#endif // ANONYMITY_H
