

#include <QTimer>
#include <QBuffer>
#include <QFile>
#include <QCoreApplication>
#include <QSystemTrayIcon>
#include <QDebug>

#include <DWidgetUtil>
#include <DHiDPIHelper>
#include "assistancecontrol.h"


class AssistanceWindow;

DWIDGET_USE_NAMESPACE
class AssistanceControlPrivate
{
public:

   AssistanceControlPrivate(AssistanceControl *parent) : q_ptr(parent) {}



    AssistanceWindow * assistancewindow    = Q_NULLPTR;




     AssistanceControl *q_ptr;
    Q_DECLARE_PUBLIC(AssistanceControl)
};





AssistanceControl::AssistanceControl(QObject *parent)
{

}

AssistanceControl::~AssistanceControl()
{

}

