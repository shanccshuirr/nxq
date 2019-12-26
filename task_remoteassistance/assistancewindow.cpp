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
#include "assistancewindow.h"
DWIDGET_USE_NAMESPACE

class AssistanceWindowPrivate
{

public:
    AssistanceWindowPrivate(AssistanceWindow *parent) : q_ptr(parent) {
        timerTwo = new QTimer();
        timerFive = new QTimer();
        spinnerWait = new DSpinner ();
        spinnercon = new DSpinner ();
    }
    ~ AssistanceWindowPrivate(){
          delete timerTwo;
          delete timerFive;
    }
    void initUI();//初始化
    void setBackground(const QPixmap &pixmap);

    QWidget *createActions(QList<QWidget *> buttons,bool isVertical=true);//多个按钮的布局
    QWidget *createMainAction();//主界面 按钮的布局和槽函数
    QWidget *createCopyAction();//复制成功界面 按钮的布局和槽函数
    QWidget *createInputAction();//输入界面 按钮的布局和槽函数
    QWidget *createWaitAction();//等待界面 按钮的布局和槽函数
    QWidget *createDisolayCodeAction();//验证码显示界面 按钮的布局和槽函数
    QWidget *createConnectAction();//连接界面 按钮的布局和槽函数
    QWidget *createConnectFailAction();//连接失败界面 按钮的布局和槽函数
    QWidget *createConnectSuccessAction();//连接成功界面 按钮的布局和槽函数


    QWidget *wrapLayout(QLayout *layout);
    QString copyText(QLabel* code);//复制验证码到粘贴板
    QString random(unsigned int n);//随机数
    void setTitle(bool flag, QString);//设置标题

    QWidget *createMainView();//创建主界面
    QWidget *createConnectView();//创建连接界面
    QWidget *createWaitCodeView();//创建等待界面
    QWidget *createInputView();//创建输入界面
    QWidget *createDisplayCodeView();//创建验证码显示界面
    QWidget *createCopySussceView();//创建复制成功界面
    QWidget *createConnectFailView();//创建连接失败界面
    QWidget *createConnectSuccessView();//创建连接成功界面


    //QStack<QWidget *> viewStack;
    QVBoxLayout *centralLayout      = Q_NULLPTR;//布局
    QWidget *mainView               = Q_NULLPTR;//主界面
    QWidget *waitCodView         = Q_NULLPTR;//等待界面
    QWidget *displayCodeView       = Q_NULLPTR;//验证码显示界面
    QWidget *inPutView               = Q_NULLPTR;//输入界面
    QWidget *connectView            = Q_NULLPTR;//连接界面
    QWidget *connectFailView            = Q_NULLPTR;//连接失败界面
    QWidget *connectSuccessView            = Q_NULLPTR;//连接成功界面
    QWidget *copySussceView          = Q_NULLPTR;//复制成功界面
    QWidget *recordWidget           = Q_NULLPTR;
    /********************/

    QLabel* codeLab            = Q_NULLPTR;//显示验证码
    QLabel* inputHint            = Q_NULLPTR;//输入验证码提示
    QLineEdit* inPutCodeEdit       = Q_NULLPTR;//输入验证码

    QTimer * timerTwo              = Q_NULLPTR;//计时器
    QTimer * timerFive             = Q_NULLPTR;//计时器
    DWidget* head                  = Q_NULLPTR;//标题

    DSpinner* spinnerWait = nullptr; //旋转图标
    DSpinner* spinnercon = nullptr; //旋转图标
    QPixmap backgroundPixmap;

    AssistanceWindow *q_ptr;
    QString m_code = " ";//验证码
private:
    Q_DECLARE_PUBLIC(AssistanceWindow)
};



AssistanceWindow::AssistanceWindow(QWidget *parent) :
    DMainWindow(parent), dd_ptr(new AssistanceWindowPrivate(this))
{
    Q_D(AssistanceWindow);

    stackMainWindows = new QStackedWidget(this);
    setCentralWidget(stackMainWindows);
    tit = this->titlebar();
    d->initUI();
}

 AssistanceWindow::~AssistanceWindow()
{

}

 bool AssistanceWindow::eventFilter(QObject *target, QEvent *event)
 {


 }




QWidget *AssistanceWindowPrivate::createMainView()
{
//    Q_Q(ActivatorWindow);

    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 10, 0, 0);
    QLabel* oneTu= new QLabel();
    QImage *img=new QImage;
    img->load(":/images/001.png");
    oneTu->setPixmap(QPixmap::fromImage(*img));
    oneTu->setScaledContents(true);
    centralLayout->addWidget(oneTu, 0, Qt::AlignCenter);
    centralLayout->addSpacing(20);

    QFont font;//字体大小
    DPalette pe;//字体颜色
    pe.setColor(DPalette::WindowText, Qt::gray);//

    font.setPointSize(8);
    QLabel* word = new QLabel();
    word->setWordWrap(true);
    word->setFont(font);
    word->setPalette(pe);
    word->setText("这是由deepin团队开发的远程协助应用，如果您在使用的过程中遇到困难，或者友人求助于你，请点击下方的我要求助或帮助别人.");
    word->setAlignment(Qt::AlignHCenter);
    word->setMinimumSize(320,40);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(0);
    centralLayout->addWidget(createMainAction(), 0, Qt::AlignCenter);//主界面 按钮的布局和槽函数
    setTitle(false,"远程协助");
    return  wrapLayout(centralLayout);
}

QWidget *AssistanceWindowPrivate::createDisplayCodeView()
{
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 10, 0, 0);
    QLabel* oneTu= new QLabel();
    QImage *img=new QImage;
    img->load(":/images/001.png");
    oneTu->setPixmap(QPixmap::fromImage(*img));
    oneTu->setScaledContents(true);
    centralLayout->addWidget(oneTu, 0, Qt::AlignCenter);
    centralLayout->addSpacing(20);

    QFont font;
    DPalette pe;
    font.setPointSize(25);
    codeLab = new QLabel();
    codeLab->setMinimumSize(300,50);
    codeLab->setFont(font);
    codeLab->setAlignment(Qt::AlignHCenter);

    //codeEdit->setStyleSheet()
    centralLayout->addWidget(codeLab,0,Qt::AlignCenter);
    centralLayout->addWidget(createDisolayCodeAction(), 0, Qt::AlignCenter);
    return  wrapLayout(centralLayout);
}

QWidget *AssistanceWindowPrivate::createCopySussceView()
{
    Q_Q(AssistanceWindow);
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 10, 0, 0);

    QFont font;

    DPalette pe;
    pe.setColor(DPalette::WindowText, Qt::gray);

    font.setPointSize(15);
    QLabel* copyMsg = new QLabel();
    copyMsg->setFont(font);
    copyMsg->setText("复制成功到粘贴板");
    copyMsg->setAlignment(Qt::AlignHCenter);


    font.setPointSize(8);
    QLabel* word = new QLabel();
    word->setWordWrap(true);
    word->setFont(font);
    word->setPalette(pe);
    word->setText("连接成功后，此界面会自动隐藏到任务栏");
    word->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(copyMsg,0,Qt::AlignCenter);
    centralLayout->addSpacing(10);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(10);
    centralLayout->addWidget(createCopyAction(), 0, Qt::AlignCenter);
    return  wrapLayout(centralLayout);
}

QWidget *AssistanceWindowPrivate::createWaitCodeView()
{
    Q_Q(AssistanceWindow);
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 30, 0, 0);

    spinnerWait->setMinimumSize(50,50);
    centralLayout->addWidget(spinnerWait, 0, Qt::AlignCenter);

    QFont font;
    font.setPointSize(12);

    QLabel* word = new QLabel();
    word->setWordWrap(true);
    word->setFont(font);
    word->setText("正在生成请求验证码，请稍后...");
    word->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addWidget(createWaitAction(), 0, Qt::AlignCenter);
    return  wrapLayout(centralLayout);

}

QWidget *AssistanceWindowPrivate::createInputView()
{

    Q_Q(AssistanceWindow);
    auto centralLayout = new QVBoxLayout();//initHeader(ActivatorWindow::tr("Activate"));
    centralLayout->setContentsMargins(0, 10, 0, 0);
    QFont font;
    DPalette pe;

    font.setPointSize(25);
    inPutCodeEdit = new QLineEdit ();
    inPutCodeEdit->setMinimumSize(300,40);
    inPutCodeEdit->setFont(font);
    inPutCodeEdit->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(inPutCodeEdit,0,Qt::AlignCenter);
    centralLayout->addSpacing(10);

    font.setPointSize(10);

    pe.setColor(DPalette::WindowText, Qt::gray);

    inputHint = new QLabel();
    //word->setMinimumSize(300,30);
    inputHint->setWordWrap(true);
    inputHint->setFont(font);
    inputHint->setPalette(pe);
    inputHint->setWordWrap(true);

    inputHint->setText("请你输入协助别人的六位数字验证码，完成后点击开始协助对方");
    inputHint->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(inputHint,0,Qt::AlignCenter);
    centralLayout->addSpacing(10);
    centralLayout->addWidget(createInputAction(),0,Qt::AlignCenter);
    return  wrapLayout(centralLayout);


}

QWidget *AssistanceWindowPrivate::createConnectView()
{
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 30, 0, 0);


    spinnercon->setMinimumSize(50,50);
    centralLayout->addWidget(spinnercon, 0, Qt::AlignCenter);

    QFont font;
    font.setPointSize(12);

    QLabel* word = new QLabel();
    word->setWordWrap(true);
    word->setFont(font);
    word->setText("正在建立连接，请稍后");
    word->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(0);
    centralLayout->addWidget(createConnectAction(), 0, Qt::AlignCenter);

    return  wrapLayout(centralLayout);
}

QWidget *AssistanceWindowPrivate::createConnectSuccessView()
{
    Q_Q(AssistanceWindow);
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 30, 0, 0);

    QFont font;
    font.setPointSize(15);
    DPalette pe;
    pe.setColor(DPalette::WindowText, Qt::gray);

    QLabel* copyMsg = new QLabel();
    copyMsg->setFont(font);
    copyMsg->setText("您正在进行远程协助");
    copyMsg->setAlignment(Qt::AlignHCenter);


    font.setPointSize(10);
    QLabel* word = new QLabel();
    word->setPalette(pe);
    word->setWordWrap(true);
    word->setFont(font);
    word->setText("当前已经有一个连接回话，如果您想建立新的连接，请先断开");
    word->setAlignment(Qt::AlignHCenter);

    centralLayout->addWidget(copyMsg,0,Qt::AlignCenter);
    centralLayout->addSpacing(20);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(30);
    centralLayout->addWidget(createConnectSuccessAction(), 0, Qt::AlignCenter);
    return  wrapLayout(centralLayout);

}

QWidget *AssistanceWindowPrivate::createConnectFailView()
{
    Q_Q(AssistanceWindow);
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 30, 0, 0);


    QFont font;
    font.setPointSize(15);
    DPalette pe;
    pe.setColor(DPalette::WindowText, Qt::gray);

    QLabel* copyMsg = new QLabel();
    copyMsg->setFont(font);
    copyMsg->setText("连接失败");
    copyMsg->setAlignment(Qt::AlignHCenter);


    font.setPointSize(10);
    QLabel* word = new QLabel();
    word->setPalette(pe);
    word->setWordWrap(true);
    word->setFont(font);
    word->setText("网络状态不是很稳定，请点击重试按钮再次尝试连接");
    word->setAlignment(Qt::AlignHCenter);

    centralLayout->addWidget(copyMsg,0,Qt::AlignCenter);
    centralLayout->addSpacing(10);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(10);
    centralLayout->addWidget(createConnectFailAction(), 0, Qt::AlignCenter);

    return  wrapLayout(centralLayout);
}

QWidget *AssistanceWindowPrivate::wrapLayout(QLayout *layout)
{
    auto wrapWidget = new QWidget;
    wrapWidget->setLayout(layout);
    //wrapWidget->resize(200,200);
    return wrapWidget;
}



QString AssistanceWindowPrivate::copyText(QLabel* code)
{
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    clipboard->setText(code->text());
    QString originalText = clipboard->text();//获取剪贴板上文本信息
    qDebug()<<"copyText :"<< originalText;
    return originalText;
}

QString AssistanceWindowPrivate::random(unsigned int n)
{
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int code = qrand() % n;
    if(code<100000){
        code+= 100000;
    }
    return QString::number(code);
}


void AssistanceWindowPrivate::setTitle(bool flag,QString title)
{
    Q_Q(AssistanceWindow);
    head = new DWidget();
    QHBoxLayout* centralLayout = new QHBoxLayout();
         QLabel * leftLab = new QLabel();
    if(flag){
        if(!title.compare("我要求助")){
             leftLab->setPixmap((QPixmap(":/images/005.png")));
        }else {
             leftLab->setPixmap((QPixmap(":/images/006.png")));
    }


    }else {
        leftLab = nullptr;
    }

    QLabel * rightLab = new QLabel();

    rightLab->setText(title);
    centralLayout->addSpacing(100);
    centralLayout->addWidget(leftLab,0,Qt::AlignCenter);
    centralLayout->addWidget(rightLab,0,Qt::AlignCenter);
    centralLayout->addSpacing(0);
    head->setLayout(centralLayout);
    q->tit->setCustomWidget(head);
}


void AssistanceWindowPrivate::initUI()
{
    Q_Q(AssistanceWindow);

    mainView = createMainView();
    waitCodView = createWaitCodeView();
    inPutView = createInputView();
    connectView = createConnectView();
    displayCodeView  = createDisplayCodeView();
    copySussceView = createCopySussceView();
    connectFailView = createConnectFailView();
    connectSuccessView = createConnectSuccessView();


    q->stackMainWindows->addWidget(mainView);
    q->stackMainWindows->addWidget(waitCodView);
    q->stackMainWindows->addWidget(inPutView);
    q->stackMainWindows->addWidget(connectView);
    q->stackMainWindows->addWidget(displayCodeView);
    q->stackMainWindows->addWidget(copySussceView);
    q->stackMainWindows->addWidget(connectFailView);
    q->stackMainWindows->addWidget(connectSuccessView);
    q->stackMainWindows->setCurrentWidget(mainView);



}

void AssistanceWindowPrivate::setBackground(const QPixmap &pixmap)
{

}



QWidget *AssistanceWindowPrivate::createMainAction()
{
    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;
    auto iHelp = new DToolButton;

    iHelp->setText(AssistanceWindow::tr("我要求助"));
    iHelp->setIcon(QIcon(QPixmap(":/images/002.png")));
    iHelp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    iHelp->setObjectName("WhiteButton");
    iHelp->connect(iHelp, &DPushButton::clicked, q, [ = ]() {


       q->stackMainWindows->setCurrentWidget(waitCodView);
       recordWidget = waitCodView;
       spinnerWait->start();
       qDebug()<<"createHelpAction iHelp";
       m_code = random(999999);
       timerTwo->start(2000);
       setTitle(true,"我要求助");

    });


    auto hHelp = new DToolButton;
    hHelp->setText(AssistanceWindow::tr("帮助别人"));
    hHelp->setIcon(QIcon(QPixmap(":/images/003.png")));
    hHelp->setObjectName("WhiteButton");
    hHelp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    hHelp->connect(hHelp, &DPushButton::clicked, q, [ = ]() {

        q->stackMainWindows->setCurrentWidget(inPutView);
        recordWidget = inPutView;
        setTitle(true,"帮助别人");
    });


    auto desktopAction = createActions({iHelp, hHelp});

    layout->addWidget(desktopAction);

    return wrapLayout(layout);
}

QWidget *AssistanceWindowPrivate::createWaitAction()
{
    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;
    auto funButton = new QPushButton(AssistanceWindow::tr("取消"));
    funButton->setObjectName("WhiteButton");
    funButton->connect(funButton, &DPushButton::clicked, q, [ = ]() {
       q->stackMainWindows->setCurrentWidget(mainView);
       recordWidget = mainView;
       setTitle(false,"远程协助");
       timerTwo->stop();
       qDebug()<<"createBtAction funButton";
    });

    timerTwo->connect(timerTwo,&QTimer::timeout,q,[ = ](){

        codeLab->setText(m_code);
        q->stackMainWindows->setCurrentWidget(displayCodeView);
        recordWidget = displayCodeView;
        qDebug()<<"createBtAction funButton";
        timerTwo->stop();
    });
    funButton->setMinimumSize(200, 36);
    layout->addWidget(funButton);
    return wrapLayout(layout);
}

QWidget *AssistanceWindowPrivate::createDisolayCodeAction()
{
    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;

    auto funButton = new QPushButton(AssistanceWindow::tr("复制"));
    funButton->setObjectName("WhiteButton");
    funButton->connect(funButton, &DPushButton::clicked, q, [ = ]() {
       QString pasteValue = copyText(codeLab);
       if(pasteValue!=""){
           q->stackMainWindows->setCurrentWidget(copySussceView);
           recordWidget = copySussceView;
           qDebug()<<"createDisolayCodeAction funButton";
       }else {
           qDebug()<<"copy fail!";
        }

    });

    funButton->setMinimumSize(200, 36);

    layout->addWidget(funButton);

    return wrapLayout(layout);
}

QWidget *AssistanceWindowPrivate::createConnectAction()
{
    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;

    auto funButton = new QPushButton(AssistanceWindow::tr("取消"));
    funButton->setObjectName("WhiteButton");
    funButton->connect(funButton, &DPushButton::clicked, q, [ = ]() {
       q->stackMainWindows->setCurrentWidget(inPutView);
       recordWidget = inPutView;
       timerFive->stop();
       qDebug()<<"createConnectAction funButton";
    });

    timerFive->connect(timerFive,&QTimer::timeout,q,[ = ](){

        if(!inPutCodeEdit->text().compare(m_code)){
            q->stackMainWindows->setCurrentWidget(connectSuccessView);
            recordWidget = connectSuccessView;
            qDebug()<<"createConnectAction success funButton";
        }else {
            q->stackMainWindows->setCurrentWidget(connectFailView);
            recordWidget = connectFailView;
            qDebug()<<"createConnectAction fail funButton";
        }
        timerFive->stop();
    });

    funButton->setMinimumSize(200, 36);

    layout->addWidget(funButton);

    return wrapLayout(layout);
}

QWidget *AssistanceWindowPrivate::createConnectFailAction()
{

    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;

    auto funButton = new QPushButton(AssistanceWindow::tr("重试"));
    funButton->setObjectName("WhiteButton");
    funButton->connect(funButton, &DPushButton::clicked, q, [ = ]() {

        q->stackMainWindows->setCurrentWidget(inPutView);
        recordWidget = connectView;
//        timerFive->start(5000);
        qDebug()<<"createConnectAction success funButton";
    });

    funButton->setMinimumSize(200, 36);
    layout->addWidget(funButton);

    return wrapLayout(layout);
}

QWidget *AssistanceWindowPrivate::createConnectSuccessAction()
{
    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;

    auto funButton = new QPushButton(AssistanceWindow::tr("断开"));
    funButton->setObjectName("WhiteButton");
    funButton->connect(funButton, &DPushButton::clicked, q, [ = ]() {

       q->stackMainWindows->setCurrentWidget(mainView);
         recordWidget = mainView;
         setTitle(false,"远程协助");
       qDebug()<<"createConnectSuccessAction funButton";
    });

    funButton->setMinimumSize(200, 36);

    layout->addWidget(funButton);

    return wrapLayout(layout);
}

QWidget *AssistanceWindowPrivate::createCopyAction()
{
    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;

    auto funButton = new QPushButton(AssistanceWindow::tr("返回"));
    funButton->setObjectName("WhiteButton");
    funButton->connect(funButton, &DPushButton::clicked, q, [ = ]() {

       q->stackMainWindows->setCurrentWidget(mainView);
       recordWidget = mainView;
       setTitle(false,"远程协助");
       qDebug()<<"createCopyAction funButton";
    });

    funButton->setMinimumSize(200, 36);

    layout->addWidget(funButton);

    return wrapLayout(layout);
}

QWidget *AssistanceWindowPrivate::createInputAction()
{
    Q_Q(AssistanceWindow);
    auto layout = new QVBoxLayout;
    auto returnBt = new DSuggestButton(AssistanceWindow::tr("返回"));//operator BT

    returnBt->connect(returnBt, &DSuggestButton::clicked, q, [ = ]()
    {

         q->stackMainWindows->setCurrentWidget(mainView);
         recordWidget = mainView;
         setTitle(false,"远程协助");
         inPutCodeEdit->clear();
    });

    auto operBt = new DSuggestButton(AssistanceWindow::tr("取消"));//operator BT

    q->connect(inPutCodeEdit, &QLineEdit::textChanged,
     [ = ]()
    {

        QRegExp wx("[0-9]{1,6}");
        QValidator *latitude = new QRegExpValidator(wx);
        inPutCodeEdit->setValidator(latitude);
        QString fullkey = inPutCodeEdit->text();
        if(fullkey.length()==6){
            operBt->setText("连接");
            operBt->setEnabled(true);
        }else {
            operBt->setText("取消");
        }
        QFont font;
        DPalette pe;
        int pos = 6;
        QRegExpValidator keyValidator(wx);
        bool keyValid = !((keyValidator.validate(fullkey, pos) != QValidator::Acceptable));
        bool flag = fullkey.isEmpty();
        if(!keyValid&&!flag){

            inputHint->setText("输入非法，可能是非数字");
            pe.setColor(DPalette::WindowText, Qt::red);
            inputHint->setPalette(pe);
        }else {
            inputHint->setText("请你输入协助别人的六位数字验证码，完成后点击开始协助对方");
            pe.setColor(DPalette::WindowText, Qt::gray);
            inputHint->setPalette(pe);
        }
    });

    operBt->connect(operBt, &DSuggestButton::clicked, q, [ = ]()
    {
        if(!operBt->text().compare("连接")){
            q->stackMainWindows->setCurrentWidget(connectView);
            recordWidget = connectView;
            spinnercon->start();
            timerFive->start(5000);
        } else {
                q->stackMainWindows->setCurrentWidget(mainView);
                recordWidget = connectView;
                inPutCodeEdit->clear();
        }

       });
    auto desktopAction = createActions({operBt, returnBt});

    layout->addWidget(desktopAction);
    return wrapLayout(layout);
}



QWidget *AssistanceWindowPrivate::createActions(QList<QWidget *> buttons,bool isVertical)
{
    auto actionWidget = new QWidget;
    actionWidget->setMinimumHeight(10);
    QBoxLayout *actionLayout = nullptr;

    actionLayout = new QVBoxLayout(actionWidget);

    for (auto button : buttons) {
        button->setMinimumSize(200, 36);
        actionLayout->addWidget(button);
        actionLayout->setAlignment(button, Qt::AlignHCenter | Qt::AlignTop);
        actionLayout->setSpacing(20);
    }
    actionWidget->setTabOrder(buttons.last(), buttons.first());
    return actionWidget;
}














