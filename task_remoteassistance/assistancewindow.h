#ifndef TEST_H
#define TEST_H

#include <QScopedPointer>
#include <DMainWindow>
DWIDGET_USE_NAMESPACE
#include <QWidget>
#include <QStackedWidget>
#include <DSpinner>

class AssistanceWindowPrivate;
class AssistanceWindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit AssistanceWindow(QWidget *parent = Q_NULLPTR);
    ~AssistanceWindow();
    bool eventFilter(QObject *target, QEvent *event) override;
Q_SIGNALS:

public Q_SLOTS:

protected:
    //virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    //virtual void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    //TODO: private
Q_SIGNALS:


private:
    DTitlebar * tit;//标题栏
    QStackedWidget *stackMainWindows ;//栈指针
    QScopedPointer<AssistanceWindowPrivate> dd_ptr;
    Q_DECLARE_PRIVATE_D(qGetPtrHelper(dd_ptr), AssistanceWindow)
};


#endif
