#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTextCodec>

#include <QPixmap>
#include <QMovie>

#include <QTimer>

#include <QString>

#include <QKeyEvent>
#include <QCloseEvent>

#include <QFile>
#include <QTextStream>

#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    QTimer *t;
    QString password;

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void closeEvent(QCloseEvent *event);

public slots:
    void InputResolution();

};

#endif // MAINWINDOW_H
