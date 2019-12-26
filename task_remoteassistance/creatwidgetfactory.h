#ifndef CREATWIDGETFACTORY_H
#define CREATWIDGETFACTORY_H

#include <QObject>
#include <QDebug>
#include <QStack>
#include <QDate>
#include <QTimer>
#include <QPainter>
#include <QLabel>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMouseEvent>

#include <ddialog.h>
#include <DThemeManager>
#include <DPushButton>
#include <DWidgetUtil>
#include <DStandardPaths>
#include <DHiDPIHelper>
#include <DTitlebar>
#include <DApplication>
#include <QClipboard>
#include <dtoast.h>
#include <DSuggestButton>
#include <dfilechooseredit.h>
//#include <QMessageBox>
//#include <DMessageBox>
#include <QTextEdit>
#include <DSpinner>
#include <DToolButton>
class CreatWidgetFactory
{
public:
    CreatWidgetFactory();
    QWidget *createActions(QList<QWidget *> buttons,bool isVertical=true);
    QWidget *createMainAction();
    QWidget *createCopyAction();
    QWidget *createInputAction();
    QWidget *createWaitAction();
    QWidget *createDisolayCodeAction();
    QWidget *createConnectAction();
    QWidget *createConnectFailAction();
    QWidget *createConnectSuccessAction();


    QWidget *wrapLayout(QLayout *layout);
    void pasteInputSerial(QLineEdit *key);
    QString copyText(QLabel* code);
    void sleep(unsigned int msec);
    QString random(unsigned int n);
    void spin(QLabel*,QString);
    void setTitle(bool flag, QString);
    void setWidget();

    QWidget *createMainView();
    QWidget *createConnectView();
    QWidget *createWaitCodeView();
    QWidget *createInputView();
    QWidget *createDisplayCodeView();
    QWidget *createCopySussceView();
    QWidget *createConnectFailView();
    QWidget *createConnectSuccessView();


};

#endif // CREATWIDGETFACTORY_H
