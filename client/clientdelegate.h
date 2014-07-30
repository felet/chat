#ifndef CLIENTDELEGATE_H
#define CLIENTDELEGATE_H

#include <QString>

class ClientDelegate {
public:
    virtual void setName(QString name) = 0;
};

#endif // CLIENTDELEGATE_H
