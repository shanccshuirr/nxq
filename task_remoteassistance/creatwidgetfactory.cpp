#include "creatwidgetfactory.h"

CreatWidgetFactory::CreatWidgetFactory()
{

}
QWidget *CreatWidgetFactory::createMainView()
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
    QFont font;
    DPalette pe;
    pe.setColor(DPalette::WindowText, Qt::gray);

    font.setPointSize(8);
    QLabel* word = new QLabel();
    word->setWordWrap(true);
    word->setFont(font);
    word->setPalette(pe);
    word->setText("这是由deepin团队开发的远程协助应用，如果您在使用的过程中遇到困难，或者友人求助于你，请点击下方的我要求助或帮助别人.");
    word->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(20);
    centralLayout->addWidget(createMainAction(), 0, Qt::AlignCenter);
    wrapLayout(centralLayout)->setWindowTitle(QString(AssistanceWindow::tr("远程协助")));
    setTitle(false,"远程协助");
    return  wrapLayout(centralLayout);
}

QWidget *CreatWidgetFactory::createDisplayCodeView()
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

QWidget *CreatWidgetFactory::createCopySussceView()
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

QWidget *CreatWidgetFactory::createWaitCodeView()
{
    Q_Q(AssistanceWindow);
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 50, 0, 0);

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

QWidget *CreatWidgetFactory::createInputView()
{

    Q_Q(AssistanceWindow);
    auto centralLayout = new QVBoxLayout();//initHeader(ActivatorWindow::tr("Activate"));
    centralLayout->setContentsMargins(0, 20, 0, 0);
    QFont font;
    DPalette pe;

    font.setPointSize(25);
    inPutCodeEdit = new QLineEdit ();
    inPutCodeEdit->setMinimumSize(300,50);
    inPutCodeEdit->setFont(font);
    inPutCodeEdit->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(inPutCodeEdit,0,Qt::AlignCenter);
    centralLayout->addSpacing(30);

    font.setPointSize(10);

    pe.setColor(DPalette::WindowText, Qt::gray);

    QLabel* word = new QLabel();
    word->setWordWrap(true);
    word->setFont(font);
    word->setPalette(pe);
    word->setText("请你输入协助别人的验证码，完成后点击开始协助对方");
    word->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(10);

    font.setPointSize(10);
    pe.setColor(DPalette::WindowText, Qt::red);
    inputHint = new QLabel();
    inputHint->setWordWrap(true);
    inputHint->setFont(font);
    inputHint->setPalette(pe);
//    inputHint->setText("输入非法，可能有非数字");
    inputHint->setAlignment(Qt::AlignHCenter);
    centralLayout->addWidget(inputHint,0,Qt::AlignCenter);

    centralLayout->addWidget(createInputAction(),0,Qt::AlignCenter);
    return  wrapLayout(centralLayout);


}

QWidget *CreatWidgetFactory::createConnectView()
{
    QVBoxLayout* centralLayout = new QVBoxLayout();
    centralLayout->setContentsMargins(0, 30, 0, 0);


    spinnercon->setMinimumSize(50,50);
    centralLayout->addWidget(spinnercon, 0, Qt::AlignCenter);

    QTextEdit* word = new QTextEdit();
    word->append("正在建立连接，请稍后");
    word->setAlignment(Qt::AlignHCenter);

    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(52);
    centralLayout->addWidget(createConnectAction(), 0, Qt::AlignCenter);

    return  wrapLayout(centralLayout);
}

QWidget *CreatWidgetFactory::createConnectSuccessView()
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

QWidget *CreatWidgetFactory::createConnectFailView()
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
    centralLayout->addSpacing(30);
    centralLayout->addWidget(word,0,Qt::AlignCenter);
    centralLayout->addSpacing(30);
    centralLayout->addWidget(createConnectFailAction(), 0, Qt::AlignCenter);

    return  wrapLayout(centralLayout);
}

QWidget *CreatWidgetFactory::wrapLayout(QLayout *layout)
{
    auto wrapWidget = new QWidget;
    wrapWidget->setLayout(layout);
    //wrapWidget->resize(200,200);
    return wrapWidget;
}

void CreatWidgetFactory::pasteInputSerial(QLineEdit *key)
{

}

QString CreatWidgetFactory::copyText(QLabel* code)
{
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    clipboard->setText(code->text());
    QString originalText = clipboard->text();//获取剪贴板上文本信息
    qDebug()<<"copyText :"<< originalText;
    return originalText;
}

void CreatWidgetFactory::sleep(unsigned int msec)
{
        QTime dieTime = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
QString CreatWidgetFactory::random(unsigned int n)
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

void CreatWidgetFactory::spin(QLabel *pLabel,QString path)
{
    QMatrix leftmatrix;
    leftmatrix.rotate(360);
    pLabel->setPixmap(QPixmap("path").transformed(leftmatrix,Qt::SmoothTransformation));
}

void CreatWidgetFactory::setTitle(bool flag,QString title)
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
    centralLayout->addSpacing(160);
    centralLayout->addWidget(leftLab,0,Qt::AlignCenter);
    centralLayout->addWidget(rightLab,0,Qt::AlignCenter);
    centralLayout->addSpacing(0);
    head->setLayout(centralLayout);
    q->tit->setCustomWidget(head);
}

void CreatWidgetFactory::setWidget()
{

}


void CreatWidgetFactory::initUI()
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

void CreatWidgetFactory::setBackground(const QPixmap &pixmap)
{

}



QWidget *CreatWidgetFactory::createMainAction()
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

QWidget *CreatWidgetFactory::createWaitAction()
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

QWidget *CreatWidgetFactory::createDisolayCodeAction()
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

QWidget *CreatWidgetFactory::createConnectAction()
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

        if(inPutCodeEdit->text() == m_code){
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

QWidget *CreatWidgetFactory::createConnectFailAction()
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

QWidget *CreatWidgetFactory::createConnectSuccessAction()
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

QWidget *CreatWidgetFactory::createCopyAction()
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





QWidget *CreatWidgetFactory::createActions(QList<QWidget *> buttons,bool isVertical)
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

