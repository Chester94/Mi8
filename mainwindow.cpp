#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec *cyrillicCodec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForTr(cyrillicCodec);
    QTextCodec::setCodecForLocale(cyrillicCodec);
    QTextCodec::setCodecForCStrings(cyrillicCodec);


    QFile pass("C:\\resources\\password.txt");
    pass.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream pass_stream(&pass);

    pass_stream >> password;
    pass.close();


    t = new QTimer;


    ui->setupUi(this);


    this->setWindowTitle("Terminal #1548");


    ui->label_Error->hide();

    QPixmap background("C:\\resources\\background.png");
    ui->backgroundLabel->setPixmap(background);

    QMovie *movie = new QMovie("C:\\resources\\Umbrella.gif");
    ui->backgroungGif->setMovie(movie);
    movie->start();


    QObject::connect( t, SIGNAL( timeout() ), this, SLOT( InputResolution() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InputResolution()
{
    ui->linePassword->setMaxLength(11);
    ui->label_Error->setVisible(false);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return )
    {
        if( ui->linePassword->displayText().length() != 0 )
        {
            if( ui->linePassword->displayText().toLower() == password )
            {
                Dialog *dial = new Dialog;
                dial->exec();
            }
            else
                ui->label_Error->setVisible(true);

            ui->linePassword->setMaxLength(0);
            t->start(5000);

            ui->linePassword->clear();
        }

        ui->linePassword->setFocus();
    }
    event->accept();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //event->ignore();
    event->accept();
}
