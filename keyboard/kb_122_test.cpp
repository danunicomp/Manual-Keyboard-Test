
#include <QVector>
#include <QMainWindow>
#include <QApplication>
#include <QtGui/QPushButton>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QThread>
#include <QFile>

#include <QDesktopWidget>

#include "kb_122_test.h"
#include "ui_kb_122_test.h"

#include "cls_readwsefile.h"
#include "cls_unicode.h"



kb_122_Test::kb_122_Test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kb_122_Test)
{
    ui->setupUi(this);

    //Put the dialog in the screen center
     const QRect screen = QApplication::desktop()->screenGeometry();
     this->move( screen.center() - this->rect().center() );

}

kb_122_Test::~kb_122_Test()
{
    delete ui;
}


void kb_122_Test::on_btnClose_clicked()
{
    this->close();
}

////////////////////////////////////////////////////////////////////
 void kb_122_Test::DoTest2015 (void) {
 //    bool resultkey=false;
     QVector<int> buffer;

     std::string ExpectedUni; std::string ReadUni;
     std::string MakeString, BreakString;
    QString hexadecimal;    QString s;

     clsReadWSEFile KeyScanCodes;
     int code;

     KeyScanCodes.ReadWSEFile("/home/pi/unicomp/keyboard/_testkeyboard.wse");

     DefineKeyboard();

     int signed x;
     // READ WSE FILE
     for (x=0; x< KeyScanCodes.kbPositions.size(); ++x) {
         qDebug() << KeyScanCodes.kbPositions[x] << " Make: " << KeyScanCodes.kbMakes[x] << " Break: " << KeyScanCodes.kbBreaks[x];
       //  NewPosition.push_back(KeyScanCodes.kbPositions[x]);
     }

     // MAKE ALL BUTTONS ON UI GRAY
     for (x=0; x<buttons.size(); ++x) {    // make all keys gray
        buttons[x]->setPalette(QPalette(QColor(Qt::lightGray)));
      }
     QWidget::repaint();

     cls_UniCode kbtest;

     for(x=0; x<buttons.size(); ++x) {
     //    buttons[x]->
     }

     x=0;
     while(code != -1) {
         buttons[x/2]->setPalette(QPalette(QColor(Qt::blue)));
         buttons[x/2]->repaint();
         code = kbtest.GetUnicodeInt();
         s = QString::number(code);
         hexadecimal.setNum(code,16);
         ui->txbOutput->append(hexadecimal);
         buttons[x/2]->setPalette(QPalette(QColor(Qt::green)));
         buttons[x/2]->repaint();
         ++x;
         if (x > buttons.size()) {
             for (x=0; x<buttons.size(); ++x) {    // make all keys gray
                buttons[x]->setPalette(QPalette(QColor(Qt::darkGray)));
              }
             x = 0;
         }

    }

 }

void kb_122_Test::on_btnStartTest_clicked()
{
    DoTest2015();
}

void kb_122_Test::DefineKeyboard(void) {

    buttons.clear();

    this->buttons.push_back(ui->pos122);
    this->buttons.push_back(ui->pos123);
    this->buttons.push_back(ui->pos124);
    this->buttons.push_back(ui->pos125);
    this->buttons.push_back(ui->pos126);
    this->buttons.push_back(ui->pos127);
    this->buttons.push_back(ui->pos128);
    this->buttons.push_back(ui->pos129);
    this->buttons.push_back(ui->pos130);
    this->buttons.push_back(ui->pos131);
    this->buttons.push_back(ui->pos132);
    this->buttons.push_back(ui->pos133);
    this->buttons.push_back(ui->pos121);
    this->buttons.push_back(ui->pos120);
    this->buttons.push_back(ui->pos119);
    this->buttons.push_back(ui->pos118);
    this->buttons.push_back(ui->pos117);
    this->buttons.push_back(ui->pos116);
    this->buttons.push_back(ui->pos115);
    this->buttons.push_back(ui->pos114);
    this->buttons.push_back(ui->pos113);
    this->buttons.push_back(ui->pos112);
    this->buttons.push_back(ui->pos111);
    this->buttons.push_back(ui->pos110);
    this->buttons.push_back(ui->pos070);
    this->buttons.push_back(ui->pos065);
    this->buttons.push_back(ui->pos001);
    this->buttons.push_back(ui->pos002);
    this->buttons.push_back(ui->pos003);
    this->buttons.push_back(ui->pos004);
    this->buttons.push_back(ui->pos005);
    this->buttons.push_back(ui->pos006);
    this->buttons.push_back(ui->pos007);
    this->buttons.push_back(ui->pos008);
    this->buttons.push_back(ui->pos009);
    this->buttons.push_back(ui->pos010);
    this->buttons.push_back(ui->pos011);
    this->buttons.push_back(ui->pos012);
    this->buttons.push_back(ui->pos013);
    this->buttons.push_back(ui->pos015);
    this->buttons.push_back(ui->pos075);
    this->buttons.push_back(ui->pos080);
    this->buttons.push_back(ui->pos085);
    this->buttons.push_back(ui->pos090);
    this->buttons.push_back(ui->pos095);
    this->buttons.push_back(ui->pos100);
    this->buttons.push_back(ui->pos105);
    this->buttons.push_back(ui->pos106);
    this->buttons.push_back(ui->pos101);
    this->buttons.push_back(ui->pos096);
    this->buttons.push_back(ui->pos091);
    this->buttons.push_back(ui->pos086);
    this->buttons.push_back(ui->pos081);
    this->buttons.push_back(ui->pos076);
    this->buttons.push_back(ui->pos028);
    this->buttons.push_back(ui->pos027);
    this->buttons.push_back(ui->pos026);
    this->buttons.push_back(ui->pos025);
    this->buttons.push_back(ui->pos024);
    this->buttons.push_back(ui->pos023);
    this->buttons.push_back(ui->pos022);
    this->buttons.push_back(ui->pos021);
    this->buttons.push_back(ui->pos020);
    this->buttons.push_back(ui->pos019);
    this->buttons.push_back(ui->pos018);
    this->buttons.push_back(ui->pos017);
    this->buttons.push_back(ui->pos016);
    this->buttons.push_back(ui->pos066);
    this->buttons.push_back(ui->pos071);
    this->buttons.push_back(ui->pos072);
    this->buttons.push_back(ui->pos067);
    this->buttons.push_back(ui->pos030);
    this->buttons.push_back(ui->pos031);
    this->buttons.push_back(ui->pos032);
    this->buttons.push_back(ui->pos033);
    this->buttons.push_back(ui->pos034);
    this->buttons.push_back(ui->pos035);
    this->buttons.push_back(ui->pos036);
    this->buttons.push_back(ui->pos037);
    this->buttons.push_back(ui->pos038);
    this->buttons.push_back(ui->pos039);
    this->buttons.push_back(ui->pos040);
    this->buttons.push_back(ui->pos041);
    this->buttons.push_back(ui->pos042);
    this->buttons.push_back(ui->pos043);
    this->buttons.push_back(ui->pos082);
    this->buttons.push_back(ui->pos092);
    this->buttons.push_back(ui->pos097);
    this->buttons.push_back(ui->pos102);
    this->buttons.push_back(ui->pos107);
    this->buttons.push_back(ui->pos108);
    this->buttons.push_back(ui->pos103);
    this->buttons.push_back(ui->pos098);
    this->buttons.push_back(ui->pos093);
    this->buttons.push_back(ui->pos088);
    this->buttons.push_back(ui->pos083);
    this->buttons.push_back(ui->pos078);
    this->buttons.push_back(ui->pos057);
    this->buttons.push_back(ui->pos055);
    this->buttons.push_back(ui->pos054);
    this->buttons.push_back(ui->pos053);
    this->buttons.push_back(ui->pos052);
    this->buttons.push_back(ui->pos051);
    this->buttons.push_back(ui->pos050);
    this->buttons.push_back(ui->pos049);
    this->buttons.push_back(ui->pos048);
    this->buttons.push_back(ui->pos047);
    this->buttons.push_back(ui->pos046);
    this->buttons.push_back(ui->pos045);
    this->buttons.push_back(ui->pos044);
    this->buttons.push_back(ui->pos068);
    this->buttons.push_back(ui->pos073);
    this->buttons.push_back(ui->pos074);
    this->buttons.push_back(ui->pos069);
    this->buttons.push_back(ui->pos058);
    this->buttons.push_back(ui->pos060);
    this->buttons.push_back(ui->pos061);
    this->buttons.push_back(ui->pos062);
    this->buttons.push_back(ui->pos064);
    this->buttons.push_back(ui->pos084);
    this->buttons.push_back(ui->pos099);
    this->buttons.push_back(ui->pos104);
}
