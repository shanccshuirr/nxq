#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>

class Factory : public QObject
{
    Q_OBJECT
public:
    explicit Factory(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // FACTORY_H
