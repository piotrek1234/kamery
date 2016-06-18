#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&socket, SIGNAL(connected()), this, SLOT(on_connected()));
    connect(&socket, SIGNAL(disconnected()), this, SLOT(on_disconnected()));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(on_received()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connected()
{
    ui->textEdit->append("Connected to "+socket.peerAddress().toString()+" at port "+QString::number(socket.peerPort()));
    ui->pushButton->setText("rozłącz");
    ui->label->setText("połączno");
}

void MainWindow::on_disconnected()
{
    ui->textEdit->append("Disconnected");
    ui->pushButton->setText("połącz");
    ui->label->setText("rozłączono");
}

void MainWindow::on_received()
{
    QString data = socket.readAll();
    ui->textEdit->append(data);
}

void MainWindow::on_pushButton_clicked()
{
    if(socket.isOpen())
    {
        socket.close();
    }
    else
    {
        socket.connectToHost(ui->lineEdit_10->text(), 6001);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    socket.write(QString("(S,C,H,"+ui->lineEdit_9->text()+")").toStdString().c_str());
}

void MainWindow::on_pushButton_5_clicked()
{
    socket.write(QString("(S,C,0,0)").toStdString().c_str());
}

void MainWindow::on_pushButton_6_clicked()
{
    socket.write(QString("(S,C,1,0)").toStdString().c_str());
}

void MainWindow::on_pushButton_3_clicked()
{
    socket.write(QString("(S,C,0,"+ui->lineEdit->text()+","+ui->lineEdit_2->text()+\
                         ","+ui->lineEdit_3->text()+",1,"+ui->lineEdit_4->text()+")").toStdString().c_str());
}

void MainWindow::on_pushButton_4_clicked()
{
    socket.write(QString("(S,C,1,"+ui->lineEdit_5->text()+","+ui->lineEdit_8->text()+\
                         ","+ui->lineEdit_7->text()+",1,"+ui->lineEdit_6->text()+")").toStdString().c_str());
}

void MainWindow::on_pushButton_7_clicked()
{
    socket.write(QString("S,C,Q,"+ui->lineEdit_11->text()+")").toStdString().c_str());
    /*ui->lineEdit_16->setText(ui->lineEdit_11->text());
    ui->lineEdit_17->setText(ui->lineEdit_11->text());
    ui->lineEdit_18->setText(ui->lineEdit_11->text());*/
}

void MainWindow::on_pushButton_8_clicked()
{
    socket.write(QString("(S,C,2,"+ui->lineEdit_13->text()+","+ui->lineEdit_14->text()+\
                         ","+ui->lineEdit_12->text()+",1,"+ui->lineEdit_15->text()+")").toStdString().c_str());
}

void MainWindow::on_pushButton_12_clicked()
{
    socket.write(QString("(S,C,S,0)").toStdString().c_str());
}

void MainWindow::on_pushButton_11_clicked()
{
    socket.write(QString("(S,C,S,1)").toStdString().c_str());
}

void MainWindow::on_pushButton_10_clicked()
{
    socket.write(QString("(S,C,S,2)").toStdString().c_str());
}

void MainWindow::on_pushButton_9_clicked()
{
    socket.write(QString("(S,C,2,0)").toStdString().c_str());
}
