

#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QScopedPointer>

class AssistanceControlPrivate;
class AssistanceControl : public QObject
{
    Q_OBJECT


public:
    explicit AssistanceControl(QObject *parent = Q_NULLPTR);
    ~AssistanceControl();

public slots:

Q_SIGNALS:

private:
    QScopedPointer<AssistanceControlPrivate> dd_ptr;
    Q_DECLARE_PRIVATE_D(qGetPtrHelper(dd_ptr), AssistanceControl)
};
#endif



