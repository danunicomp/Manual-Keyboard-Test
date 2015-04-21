#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>


#include <QVector>
#include <QMainWindow>
#include <QApplication>
#include <QtGui/QPushButton>
#include <QObject>
#include <QWidget>


#include <algorithm>
#include <sstream>
#include <iterator>

#include "cls_unicode.h"
#include "newkeyboard.h"
#include "signalHandler.h"

#define _MAKE 1000;
#define _BREAK 1999;

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

  //  buttons.push_back(ui->pos122);


}

MainWindow::~MainWindow()
{
    delete ui;

}

////////////////////////////////////////////////////////////////////

 void MainWindow::RealTest(void) {
  int x =0;
  bool resultkey=false;
  std::vector<int> buffer;

  cls_UniCode Keyboard;

   std::ostringstream oss;

  SignalHandler signalHandler;
  // Register signal handler to handle kill signal
  signalHandler.setupSignalHandlers();

  std::string ExpectedUni; std::string ReadUni;
  std::string MakeString, BreakString;
  this->DeclareKeys();

  for (x=0; x<buttons.size(); ++x) {    // make all keys gray
     buttons[x]->setPalette(QPalette(QColor(Qt::darkGray)));
   }
  QWidget::repaint();

    int currentkey = 0;

  try {
       for (x=0; x < this->ExpectedMakeUnicode.size()*2; ++ x) {
            buttons[currentkey]->setPalette(QPalette(QColor(Qt::blue)));
            buttons[currentkey]->repaint();

            QWidget::repaint();

            buffer = Keyboard.GetUnicodeBuffer();
            if (buffer[0] == 1999) {

            //  cout << "NAKE ";
            ReadUni = this->VectorToString(buffer);
            MakeString = ReadUni;

            if (ReadUni == ExpectedMakeUnicode[currentkey].c_str() )
              {resultkey = true;} else {resultkey = false;}
            if (resultkey) {
                //cout << " GOOD  ";
                buttons[currentkey]->setPalette(QPalette(QColor(Qt::green)));
                buttons[currentkey]->repaint();
            }
            else {    // MAKE FAIL
                 ShowFailure(currentkey, ReadUni, 1999);
             break;
            }
            //   cout << "Read: " << ReadUni  << "   " << "Expeded: " << ExpectedMakeUnicode[currentkey].c_str() << endl;

            }

         if (buffer[0] == 1000)  {

         //cout << "BREAK ";
         ReadUni = this->VectorToString(buffer);
         BreakString = ReadUni;
         if (ReadUni == ExpectedBreakUnicode[currentkey].c_str() ) {resultkey = true;} else {resultkey = false;}
         if (resultkey)
          {
             //cout << " GOOD  ";
             buttons[currentkey]->setPalette(QPalette(QColor(Qt::green)));
             buttons[currentkey]->repaint();

           }
         else {
             //cout << "FAIL  ";
             ShowFailure(currentkey, ReadUni, 1000);

             break;
           }
      //    cout <<  "Read: " << ReadUni  << "   " << "Expeded: " << ExpectedBreakUnicode[currentkey].c_str() << endl;
      //  cout << "this->ExpectedMakeUnicode.push_back(\"" << MakeString << "\");this->ExpectedBreakUnicode.push_back(\"" << BreakString << "\");" << endl;
          ++currentkey;
       }

         }  // end nmain loop


     }// END TRY
    catch (SignalException& e)
    {
      std::cerr << "SignalException: " << e.what() << std::endl;
      cout << "exit" << endl;
    }
 }

 //////////////////////////////////////////////////////////////////

 void MainWindow::ShowFailure(int CurrentPosition, string ReceivedUnicode, int MakeOrBreak) {
   std::ostringstream oss;
  ui->textBrowser->clear();
   buttons[CurrentPosition]->setPalette(QPalette(QColor(Qt::red)));
   buttons[CurrentPosition]->repaint();
   oss << "Key Fail. Position: " << this->position[CurrentPosition] ;
   ui->textBrowser->append(oss.str().c_str());
   oss.str("");
   oss << "Read: " << ReceivedUnicode;
   ui->textBrowser->append(oss.str().c_str());
   oss.str("");
     oss << "Expected: " ;
   if (MakeOrBreak == 1999) {
       oss << this->ExpectedMakeUnicode[CurrentPosition];
   }
   if (MakeOrBreak == 1000) {
       oss << this->ExpectedBreakUnicode[CurrentPosition];
     }

   ui->textBrowser->append(oss.str().c_str());
   ui->textBrowser->update();
   QWidget::repaint();
 }


 //////////////////////////////////////////////////////////////////
 std::string MainWindow::VectorToString(std::vector<int> CurVector) {
   std::string ret;
   std::ostringstream oss;
   for (unsigned int x=0; x < CurVector.size()-1; ++x) {
       oss << CurVector[x] << " ";
     }
   oss << CurVector.back();
   return oss.str();
 }


//////////////////////////////////////////////////////////////////

void MainWindow::DoTest(void) {

  std::vector<int> buffer;
  std::string buildoutput = "";
  cls_UniCode Keyboard;
  std::ostringstream oss;
//  int t = 0;
  for (int z=0; z<10; ++z) {
      buffer = Keyboard.GetUnicodeBuffer();
      buildoutput = "";
      for ( unsigned int x=0; x<buffer.size(); ++x) {
        oss << buffer[x] << ",";
        ui->textBrowser->update();
 //       QWidget::repaint();
      }
      buffer.clear();
      buildoutput = oss.str();
      ui->textBrowser->append(buildoutput.c_str());
      ui->textBrowser->append("Hello");
      ui->textBrowser->update();
      QWidget::repaint();
      oss.str("");
      oss.clear();
      std::cout << buildoutput.c_str() << std::endl;
  }
}

/////////////////////////////////////////////////////////

void MainWindow::on_btnCycle_clicked()
{

      test = 1;
this->stopcycle = false;

 // buttons.push_back(ui->pos122);



this->DeclareKeys();

  int x =0;

  //button = CurrentKeyboard.button;
  ui->textBrowser->append("HellO");
    ui->textBrowser->update();



      for (x=0; x<buttons.size(); ++x) {
          buttons[x]->setPalette(QPalette(QColor(Qt::gray)));
        }

        // button[0]->setPalette(QPalette(QColor(Qt::green)));
       for (x =0; x<buttons.size(); ++x) {
            buttons[x]->setPalette(QPalette(QColor(Qt::blue)));

            QWidget::repaint();
      //    QObject().thread()->usleep(1000);
            usleep(100000);
            buttons[x]->setPalette(QPalette(QColor(Qt::green)));


            QWidget::repaint();

            QApplication::processEvents();

            //MainWindow::CheckForBreak(button[x-1]);
            if (this->stopcycle) break;

        }
    }


//////************************************

//********************************

void MainWindow::on_btnStop_clicked()
{
  // In the constructor, connect the button to the slot.
  //connect( ui->pushButton_3, SIGNAL( clicked() ), this, SLOT( MainWindow::CheckForBreak(1) ) );
 // button[x-1]->setPalette(QPalette(QColor(Qt::red)));
//  QWidget::repaint();
this->stopcycle = true;
}


void MainWindow::on_GetUnicodes_clicked()
{
  using namespace std;

//   ui->textBrowser->setText("Hello");
//  ui->textBrowser->clear();
//   ui->textEdit->setText("Hello Woeld");

       MainWindow::RealTest();
}

// *************************************************************************************
void MainWindow::DeclareKeys (void) {

  this->buttons.clear();
  this->position.clear();
  this->ExpectedBreakUnicode.clear();
  this->ExpectedMakeUnicode.clear();

  /*
   *






   */

  this->buttons.push_back(ui->pos122); this->position.push_back(122); this->ExpectedMakeUnicode.push_back("1999 0 129 183");this->ExpectedBreakUnicode.push_back("1000 128 129 183");
    this->buttons.push_back(ui->pos123); this->position.push_back(123);this->ExpectedMakeUnicode.push_back("1999 0 129 184");this->ExpectedBreakUnicode.push_back("1000 128 129 184");
    this->buttons.push_back(ui->pos124); this->position.push_back(124);this->ExpectedMakeUnicode.push_back("1999 0 129 185");this->ExpectedBreakUnicode.push_back("1000 128 129 185");
    this->buttons.push_back(ui->pos125); this->position.push_back(125);this->ExpectedMakeUnicode.push_back("1999 0 129 186");this->ExpectedBreakUnicode.push_back("1000 128 129 186");
    this->buttons.push_back(ui->pos126); this->position.push_back(126);this->ExpectedMakeUnicode.push_back("1999 0 129 187");this->ExpectedBreakUnicode.push_back("1000 128 129 187");
    this->buttons.push_back(ui->pos127); this->position.push_back(127);this->ExpectedMakeUnicode.push_back("1999 0 129 188");this->ExpectedBreakUnicode.push_back("1000 128 129 188");
    this->buttons.push_back(ui->pos128); position.push_back(128);;this->ExpectedMakeUnicode.push_back("1999 0 129 189");this->ExpectedBreakUnicode.push_back("1000 128 129 189");
    this->buttons.push_back(ui->pos129); position.push_back(129);;this->ExpectedMakeUnicode.push_back("1999 0 129 190");this->ExpectedBreakUnicode.push_back("1000 128 129 190");
    this->buttons.push_back(ui->pos130); position.push_back(130);;this->ExpectedMakeUnicode.push_back("1999 0 129 191");this->ExpectedBreakUnicode.push_back("1000 128 129 191");
    this->buttons.push_back(ui->pos131); position.push_back(131);;this->ExpectedMakeUnicode.push_back("1999 0 129 192");this->ExpectedBreakUnicode.push_back("1000 128 129 192");
    this->buttons.push_back(ui->pos132); position.push_back(132);;this->ExpectedMakeUnicode.push_back("1999 0 129 193");this->ExpectedBreakUnicode.push_back("1000 128 129 193");
    this->buttons.push_back(ui->pos133); position.push_back(133);;this->ExpectedMakeUnicode.push_back("1999 0 129 194");this->ExpectedBreakUnicode.push_back("1000 128 129 194");

    this->buttons.push_back(ui->pos121); position.push_back(121);this->ExpectedMakeUnicode.push_back("1999 88");this->ExpectedBreakUnicode.push_back("1000 216");
    this->buttons.push_back(ui->pos120); position.push_back(120);this->ExpectedMakeUnicode.push_back("1999 87");this->ExpectedBreakUnicode.push_back("1000 215");
    this->buttons.push_back(ui->pos119); position.push_back(119);this->ExpectedMakeUnicode.push_back("1999 68");this->ExpectedBreakUnicode.push_back("1000 196");
    this->buttons.push_back(ui->pos118); position.push_back(118);this->ExpectedMakeUnicode.push_back("1999 67");this->ExpectedBreakUnicode.push_back("1000 195");
    this->buttons.push_back(ui->pos117); position.push_back(117);this->ExpectedMakeUnicode.push_back("1999 66");this->ExpectedBreakUnicode.push_back("1000 194");
    this->buttons.push_back(ui->pos116); position.push_back(116);this->ExpectedMakeUnicode.push_back("1999 65");this->ExpectedBreakUnicode.push_back("1000 193");
    this->buttons.push_back(ui->pos115); position.push_back(115);this->ExpectedMakeUnicode.push_back("1999 64");this->ExpectedBreakUnicode.push_back("1000 192");
    this->buttons.push_back(ui->pos114); position.push_back(114);this->ExpectedMakeUnicode.push_back("1999 63");this->ExpectedBreakUnicode.push_back("1000 191");
    this->buttons.push_back(ui->pos113); position.push_back(113);this->ExpectedMakeUnicode.push_back("1999 62");this->ExpectedBreakUnicode.push_back("1000 190");
    this->buttons.push_back(ui->pos112); position.push_back(112);this->ExpectedMakeUnicode.push_back("1999 61");this->ExpectedBreakUnicode.push_back("1000 189");
    this->buttons.push_back(ui->pos111); position.push_back(111);this->ExpectedMakeUnicode.push_back("1999 60");this->ExpectedBreakUnicode.push_back("1000 188");
    this->buttons.push_back(ui->pos110); position.push_back(110);this->ExpectedMakeUnicode.push_back("1999 59");this->ExpectedBreakUnicode.push_back("1000 187");

    this->buttons.push_back(ui->pos070); position.push_back(70); this->ExpectedMakeUnicode.push_back("1999 42 59");this->ExpectedBreakUnicode.push_back("1000 170 187");
    this->buttons.push_back(ui->pos065); position.push_back(65);this->ExpectedMakeUnicode.push_back("1999 70");this->ExpectedBreakUnicode.push_back("1000 198");
    this->buttons.push_back(ui->pos001); position.push_back(1);this->ExpectedMakeUnicode.push_back("1999 41");this->ExpectedBreakUnicode.push_back("1000 169");
    this->buttons.push_back(ui->pos002); position.push_back(2);
    this->buttons.push_back(ui->pos003); position.push_back(3);
    this->buttons.push_back(ui->pos004); position.push_back(4);
    this->buttons.push_back(ui->pos005); position.push_back(5);
    this->buttons.push_back(ui->pos006); position.push_back(6);
    this->buttons.push_back(ui->pos007); position.push_back(7);
    this->buttons.push_back(ui->pos008); position.push_back(8);
    this->buttons.push_back(ui->pos009); position.push_back(9);
    this->buttons.push_back(ui->pos010); position.push_back(10);
    this->buttons.push_back(ui->pos011); position.push_back(11);
    this->buttons.push_back(ui->pos012); position.push_back(12);
    this->buttons.push_back(ui->pos013); position.push_back(13);
    this->buttons.push_back(ui->pos015); position.push_back(15);
    this->buttons.push_back(ui->pos075); position.push_back(75);
    this->buttons.push_back(ui->pos080); position.push_back(80);
    this->buttons.push_back(ui->pos085); position.push_back(85);
    this->buttons.push_back(ui->pos090); position.push_back(90);
    this->buttons.push_back(ui->pos095); position.push_back(95);
    this->buttons.push_back(ui->pos100); position.push_back(100);
    this->buttons.push_back(ui->pos105); position.push_back(105);
    this->buttons.push_back(ui->pos106); position.push_back(106);
    this->buttons.push_back(ui->pos101); position.push_back(101);
    this->buttons.push_back(ui->pos096); position.push_back(96);
    this->buttons.push_back(ui->pos091); position.push_back(91);
    this->buttons.push_back(ui->pos086); position.push_back(86);
    this->buttons.push_back(ui->pos081); position.push_back(81);
    this->buttons.push_back(ui->pos076); position.push_back(76);
    this->buttons.push_back(ui->pos028); position.push_back(28);
    this->buttons.push_back(ui->pos027); position.push_back(27);
    this->buttons.push_back(ui->pos026); position.push_back(26);
    this->buttons.push_back(ui->pos025); position.push_back(25);
    this->buttons.push_back(ui->pos024); position.push_back(24);
    this->buttons.push_back(ui->pos023); position.push_back(23);
    this->buttons.push_back(ui->pos022); position.push_back(22);
    this->buttons.push_back(ui->pos021); position.push_back(21);
    this->buttons.push_back(ui->pos020); position.push_back(20);
    this->buttons.push_back(ui->pos019); position.push_back(19);
    this->buttons.push_back(ui->pos018); position.push_back(18);
    this->buttons.push_back(ui->pos017); position.push_back(17);
    this->buttons.push_back(ui->pos016); position.push_back(16);
    this->buttons.push_back(ui->pos066); position.push_back(65);
    this->buttons.push_back(ui->pos071); position.push_back(71);
    this->buttons.push_back(ui->pos072); position.push_back(72);
    this->buttons.push_back(ui->pos067); position.push_back(67);
    this->buttons.push_back(ui->pos030); position.push_back(30);
    this->buttons.push_back(ui->pos031); position.push_back(31);
    this->buttons.push_back(ui->pos032); position.push_back(32);
    this->buttons.push_back(ui->pos033); position.push_back(33);
    this->buttons.push_back(ui->pos034); position.push_back(34);
    this->buttons.push_back(ui->pos035); position.push_back(35);
    this->buttons.push_back(ui->pos036); position.push_back(36);
    this->buttons.push_back(ui->pos037); position.push_back(37);
    this->buttons.push_back(ui->pos038); position.push_back(38);
    this->buttons.push_back(ui->pos039); position.push_back(39);
    this->buttons.push_back(ui->pos040); position.push_back(40);
    this->buttons.push_back(ui->pos041); position.push_back(41);
    this->buttons.push_back(ui->pos042); position.push_back(42);
    this->buttons.push_back(ui->pos043); position.push_back(43);
    this->buttons.push_back(ui->pos082); position.push_back(82);
    this->buttons.push_back(ui->pos092); position.push_back(92);
    this->buttons.push_back(ui->pos097); position.push_back(97);
    this->buttons.push_back(ui->pos102); position.push_back(102);
    this->buttons.push_back(ui->pos107); position.push_back(107);
    this->buttons.push_back(ui->pos108); position.push_back(108);
    this->buttons.push_back(ui->pos103); position.push_back(103);
    this->buttons.push_back(ui->pos098); position.push_back(98);
    this->buttons.push_back(ui->pos093); position.push_back(93);
    this->buttons.push_back(ui->pos088); position.push_back(88);
    this->buttons.push_back(ui->pos083); position.push_back(83);
    this->buttons.push_back(ui->pos078); position.push_back(78);
    this->buttons.push_back(ui->pos057); position.push_back(57);
    this->buttons.push_back(ui->pos055); position.push_back(55);
    this->buttons.push_back(ui->pos054); position.push_back(54);
    this->buttons.push_back(ui->pos053); position.push_back(53);
    this->buttons.push_back(ui->pos052); position.push_back(52);
    this->buttons.push_back(ui->pos051); position.push_back(51);
    this->buttons.push_back(ui->pos050); position.push_back(50);
    this->buttons.push_back(ui->pos049); position.push_back(49);
    this->buttons.push_back(ui->pos048); position.push_back(48);
    this->buttons.push_back(ui->pos047); position.push_back(47);
    this->buttons.push_back(ui->pos046); position.push_back(46);
    this->buttons.push_back(ui->pos045); position.push_back(45);
    this->buttons.push_back(ui->pos044); position.push_back(44);
    this->buttons.push_back(ui->pos068); position.push_back(68);
    this->buttons.push_back(ui->pos073); position.push_back(73);
    this->buttons.push_back(ui->pos074); position.push_back(74);
    this->buttons.push_back(ui->pos069); position.push_back(69);
    this->buttons.push_back(ui->pos058); position.push_back(58);
    this->buttons.push_back(ui->pos060); position.push_back(60);
    this->buttons.push_back(ui->pos061); position.push_back(61);
    this->buttons.push_back(ui->pos062); position.push_back(62);
    this->buttons.push_back(ui->pos064); position.push_back(64);
    this->buttons.push_back(ui->pos084); position.push_back(84);
    this->buttons.push_back(ui->pos099); position.push_back(99);
    this->buttons.push_back(ui->pos104); position.push_back(104);

  this->ExpectedMakeUnicode.push_back("1999 2");this->ExpectedBreakUnicode.push_back("1000 130");
  this->ExpectedMakeUnicode.push_back("1999 3");this->ExpectedBreakUnicode.push_back("1000 131");
  this->ExpectedMakeUnicode.push_back("1999 4");this->ExpectedBreakUnicode.push_back("1000 132");
  this->ExpectedMakeUnicode.push_back("1999 5");this->ExpectedBreakUnicode.push_back("1000 133");
  this->ExpectedMakeUnicode.push_back("1999 6");this->ExpectedBreakUnicode.push_back("1000 134");
  this->ExpectedMakeUnicode.push_back("1999 7");this->ExpectedBreakUnicode.push_back("1000 135");
  this->ExpectedMakeUnicode.push_back("1999 8");this->ExpectedBreakUnicode.push_back("1000 136");
  this->ExpectedMakeUnicode.push_back("1999 9");this->ExpectedBreakUnicode.push_back("1000 137");
  this->ExpectedMakeUnicode.push_back("1999 10");this->ExpectedBreakUnicode.push_back("1000 138");
  this->ExpectedMakeUnicode.push_back("1999 11");this->ExpectedBreakUnicode.push_back("1000 139");
  this->ExpectedMakeUnicode.push_back("1999 12");this->ExpectedBreakUnicode.push_back("1000 140");
  this->ExpectedMakeUnicode.push_back("1999 13");this->ExpectedBreakUnicode.push_back("1000 141");
  this->ExpectedMakeUnicode.push_back("1999 14");this->ExpectedBreakUnicode.push_back("1000 142");
  this->ExpectedMakeUnicode.push_back("1999 0 129 128");this->ExpectedBreakUnicode.push_back("1000 128 129 128");
  this->ExpectedMakeUnicode.push_back("1999 104");this->ExpectedBreakUnicode.push_back("1000 232");
  this->ExpectedMakeUnicode.push_back("1999 109");this->ExpectedBreakUnicode.push_back("1000 237");
  this->ExpectedMakeUnicode.push_back("1999 1");this->ExpectedBreakUnicode.push_back("1000 129");
  this->ExpectedMakeUnicode.push_back("1999 69");this->ExpectedBreakUnicode.push_back("1000 197");
  this->ExpectedMakeUnicode.push_back("1999 55");this->ExpectedBreakUnicode.push_back("1000 183");
  this->ExpectedMakeUnicode.push_back("1999 98");this->ExpectedBreakUnicode.push_back("1000 226");
  this->ExpectedMakeUnicode.push_back("1999 78");this->ExpectedBreakUnicode.push_back("1000 206");
  this->ExpectedMakeUnicode.push_back("1999 73");this->ExpectedBreakUnicode.push_back("1000 201");
  this->ExpectedMakeUnicode.push_back("1999 72");this->ExpectedBreakUnicode.push_back("1000 200");
  this->ExpectedMakeUnicode.push_back("1999 71");this->ExpectedBreakUnicode.push_back("1000 199");
  this->ExpectedMakeUnicode.push_back("1999 111");this->ExpectedBreakUnicode.push_back("1000 239");
  this->ExpectedMakeUnicode.push_back("1999 110");this->ExpectedBreakUnicode.push_back("1000 238");
  this->ExpectedMakeUnicode.push_back("1999 107");this->ExpectedBreakUnicode.push_back("1000 235");
  this->ExpectedMakeUnicode.push_back("1999 27");this->ExpectedBreakUnicode.push_back("1000 155");
  this->ExpectedMakeUnicode.push_back("1999 26");this->ExpectedBreakUnicode.push_back("1000 154");
  this->ExpectedMakeUnicode.push_back("1999 25");this->ExpectedBreakUnicode.push_back("1000 153");
  this->ExpectedMakeUnicode.push_back("1999 24");this->ExpectedBreakUnicode.push_back("1000 152");
  this->ExpectedMakeUnicode.push_back("1999 23");this->ExpectedBreakUnicode.push_back("1000 151");
  this->ExpectedMakeUnicode.push_back("1999 22");this->ExpectedBreakUnicode.push_back("1000 150");
  this->ExpectedMakeUnicode.push_back("1999 21");this->ExpectedBreakUnicode.push_back("1000 149");
  this->ExpectedMakeUnicode.push_back("1999 20");this->ExpectedBreakUnicode.push_back("1000 148");
  this->ExpectedMakeUnicode.push_back("1999 19");this->ExpectedBreakUnicode.push_back("1000 147");
  this->ExpectedMakeUnicode.push_back("1999 18");this->ExpectedBreakUnicode.push_back("1000 146");
  this->ExpectedMakeUnicode.push_back("1999 17");this->ExpectedBreakUnicode.push_back("1000 145");
  this->ExpectedMakeUnicode.push_back("1999 16");this->ExpectedBreakUnicode.push_back("1000 144");
  this->ExpectedMakeUnicode.push_back("1999 15");this->ExpectedBreakUnicode.push_back("1000 143");
  this->ExpectedMakeUnicode.push_back("1999 119");this->ExpectedBreakUnicode.push_back("1000 247");
  this->ExpectedMakeUnicode.push_back("1999 56 88");this->ExpectedBreakUnicode.push_back("1000 184 216");
  this->ExpectedMakeUnicode.push_back("1999 29 61");this->ExpectedBreakUnicode.push_back("1000 157 189");
  this->ExpectedMakeUnicode.push_back("1999 0 129 132");this->ExpectedBreakUnicode.push_back("1000 128 129 132");
  this->ExpectedMakeUnicode.push_back("1999 58");this->ExpectedBreakUnicode.push_back("1000 186");
  this->ExpectedMakeUnicode.push_back("1999 30");this->ExpectedBreakUnicode.push_back("1000 158");
  this->ExpectedMakeUnicode.push_back("1999 31");this->ExpectedBreakUnicode.push_back("1000 159");
  this->ExpectedMakeUnicode.push_back("1999 32");this->ExpectedBreakUnicode.push_back("1000 160");
  this->ExpectedMakeUnicode.push_back("1999 33");this->ExpectedBreakUnicode.push_back("1000 161");
  this->ExpectedMakeUnicode.push_back("1999 34");this->ExpectedBreakUnicode.push_back("1000 162");
  this->ExpectedMakeUnicode.push_back("1999 35");this->ExpectedBreakUnicode.push_back("1000 163");
  this->ExpectedMakeUnicode.push_back("1999 36");this->ExpectedBreakUnicode.push_back("1000 164");
  this->ExpectedMakeUnicode.push_back("1999 37");this->ExpectedBreakUnicode.push_back("1000 165");
  this->ExpectedMakeUnicode.push_back("1999 38");this->ExpectedBreakUnicode.push_back("1000 166");
  this->ExpectedMakeUnicode.push_back("1999 39");this->ExpectedBreakUnicode.push_back("1000 167");
  this->ExpectedMakeUnicode.push_back("1999 40");this->ExpectedBreakUnicode.push_back("1000 168");
  this->ExpectedMakeUnicode.push_back("1999 43");this->ExpectedBreakUnicode.push_back("1000 171");
  this->ExpectedMakeUnicode.push_back("1999 28");this->ExpectedBreakUnicode.push_back("1000 156");
  this->ExpectedMakeUnicode.push_back("1999 103");this->ExpectedBreakUnicode.push_back("1000 231");
  this->ExpectedMakeUnicode.push_back("1999 75");this->ExpectedBreakUnicode.push_back("1000 203");
  this->ExpectedMakeUnicode.push_back("1999 76");this->ExpectedBreakUnicode.push_back("1000 204");
  this->ExpectedMakeUnicode.push_back("1999 77");this->ExpectedBreakUnicode.push_back("1000 205");
  this->ExpectedMakeUnicode.push_back("1999 74");this->ExpectedBreakUnicode.push_back("1000 202");
  this->ExpectedMakeUnicode.push_back("1999 96");this->ExpectedBreakUnicode.push_back("1000 224");
  this->ExpectedMakeUnicode.push_back("1999 81");this->ExpectedBreakUnicode.push_back("1000 209");
  this->ExpectedMakeUnicode.push_back("1999 80");this->ExpectedBreakUnicode.push_back("1000 208");
  this->ExpectedMakeUnicode.push_back("1999 79");this->ExpectedBreakUnicode.push_back("1000 207");

  this->ExpectedMakeUnicode.push_back("1999 106");this->ExpectedBreakUnicode.push_back("1000 234");
  this->ExpectedMakeUnicode.push_back("1999 102");this->ExpectedBreakUnicode.push_back("1000 230");
  this->ExpectedMakeUnicode.push_back("1999 105");this->ExpectedBreakUnicode.push_back("1000 233");
  this->ExpectedMakeUnicode.push_back("1999 54");this->ExpectedBreakUnicode.push_back("1000 182");
  this->ExpectedMakeUnicode.push_back("1999 53");this->ExpectedBreakUnicode.push_back("1000 181");
  this->ExpectedMakeUnicode.push_back("1999 52");this->ExpectedBreakUnicode.push_back("1000 180");
  this->ExpectedMakeUnicode.push_back("1999 51");this->ExpectedBreakUnicode.push_back("1000 179");
  this->ExpectedMakeUnicode.push_back("1999 50");this->ExpectedBreakUnicode.push_back("1000 178");
  this->ExpectedMakeUnicode.push_back("1999 49");this->ExpectedBreakUnicode.push_back("1000 177");
  this->ExpectedMakeUnicode.push_back("1999 48");this->ExpectedBreakUnicode.push_back("1000 176");
  this->ExpectedMakeUnicode.push_back("1999 47");this->ExpectedBreakUnicode.push_back("1000 175");
  this->ExpectedMakeUnicode.push_back("1999 46");this->ExpectedBreakUnicode.push_back("1000 174");
  this->ExpectedMakeUnicode.push_back("1999 45");this->ExpectedBreakUnicode.push_back("1000 173");
  this->ExpectedMakeUnicode.push_back("1999 44");this->ExpectedBreakUnicode.push_back("1000 172");
  this->ExpectedMakeUnicode.push_back("1999 86");this->ExpectedBreakUnicode.push_back("1000 214");
  this->ExpectedMakeUnicode.push_back("1999 42");this->ExpectedBreakUnicode.push_back("1000 170");
  this->ExpectedMakeUnicode.push_back("1999 0 129 135");this->ExpectedBreakUnicode.push_back("1000 128 129 135");
  this->ExpectedMakeUnicode.push_back("1999 99");this->ExpectedBreakUnicode.push_back("1000 227");

  this->ExpectedMakeUnicode.push_back("1999 125");this->ExpectedBreakUnicode.push_back("1000 253");
  this->ExpectedMakeUnicode.push_back("1999 127");this->ExpectedBreakUnicode.push_back("1000 255");
  this->ExpectedMakeUnicode.push_back("1999 29");this->ExpectedBreakUnicode.push_back("1000 157");
  this->ExpectedMakeUnicode.push_back("1999 56");this->ExpectedBreakUnicode.push_back("1000 184");
  this->ExpectedMakeUnicode.push_back("1999 57");this->ExpectedBreakUnicode.push_back("1000 185");
  this->ExpectedMakeUnicode.push_back("1999 100");this->ExpectedBreakUnicode.push_back("1000 228");
  this->ExpectedMakeUnicode.push_back("1999 97");this->ExpectedBreakUnicode.push_back("1000 225");
  this->ExpectedMakeUnicode.push_back("1999 108");this->ExpectedBreakUnicode.push_back("1000 236");
  this->ExpectedMakeUnicode.push_back("1999 82");this->ExpectedBreakUnicode.push_back("1000 210");
  this->ExpectedMakeUnicode.push_back("1999 83");this->ExpectedBreakUnicode.push_back("1000 211");


}
///////////////////////////////////////////////////////////////////////


  void MainWindow::KbLoad122 (void) {


    /*

    this->buttons.push_back(ui->pos122); this->position.push_back(122);
     this->buttons.push_back(ui->pos123); this->position.push_back(123);
     this-> button.push_back(ui->pos124); this->position.push_back(124);
     button.push_back(ui->pos125); position.push_back(125);
     button.push_back(ui->pos126); position.push_back(126);
     button.push_back(ui->pos127); position.push_back(127);
     button.push_back(ui->pos128); position.push_back(128);
     button.push_back(ui->pos129); position.push_back(129);
     button.push_back(ui->pos130); position.push_back(130);
     button.push_back(ui->pos131); position.push_back(131);
     button.push_back(ui->pos132); position.push_back(132);
     button.push_back(ui->pos133); position.push_back(133);
     button.push_back(ui->pos121); position.push_back(121);
     button.push_back(ui->pos120); position.push_back(120);
     button.push_back(ui->pos119); position.push_back(119);
     button.push_back(ui->pos118); position.push_back(118);
     button.push_back(ui->pos117); position.push_back(117);
     button.push_back(ui->pos116); position.push_back(116);
     button.push_back(ui->pos115); position.push_back(115);
     button.push_back(ui->pos114); position.push_back(114);
     button.push_back(ui->pos113); position.push_back(113);
     button.push_back(ui->pos112); position.push_back(112);
     button.push_back(ui->pos111); position.push_back(111);
     button.push_back(ui->pos110); position.push_back(110);
     button.push_back(ui->pos070); position.push_back(70);
     button.push_back(ui->pos065); position.push_back(65);
     button.push_back(ui->pos001); position.push_back(1);
     button.push_back(ui->pos002); position.push_back(2);
     button.push_back(ui->pos003); position.push_back(3);
     button.push_back(ui->pos004); position.push_back(4);
     button.push_back(ui->pos005); position.push_back(5);
     button.push_back(ui->pos006); position.push_back(6);
     button.push_back(ui->pos007); position.push_back(7);
     button.push_back(ui->pos008); position.push_back(8);
     button.push_back(ui->pos009); position.push_back(9);
     button.push_back(ui->pos010); position.push_back(10);
     button.push_back(ui->pos011); position.push_back(11);
     button.push_back(ui->pos012); position.push_back(12);
     button.push_back(ui->pos013); position.push_back(13);
     button.push_back(ui->pos015); position.push_back(15);
     button.push_back(ui->pos075); position.push_back(75);
     button.push_back(ui->pos080); position.push_back(80);
     button.push_back(ui->pos085); position.push_back(85);
     button.push_back(ui->pos090); position.push_back(90);
     button.push_back(ui->pos095); position.push_back(95);
     button.push_back(ui->pos100); position.push_back(100);
     button.push_back(ui->pos105); position.push_back(105);
     button.push_back(ui->pos106); position.push_back(106);
     button.push_back(ui->pos101); position.push_back(101);
     button.push_back(ui->pos096); position.push_back(96);
     button.push_back(ui->pos091); position.push_back(91);
     button.push_back(ui->pos086); position.push_back(86);
     button.push_back(ui->pos081); position.push_back(81);
     button.push_back(ui->pos076); position.push_back(76);
     button.push_back(ui->pos028); position.push_back(28);
     button.push_back(ui->pos027); position.push_back(27);
     button.push_back(ui->pos026); position.push_back(26);
     button.push_back(ui->pos025); position.push_back(25);
     button.push_back(ui->pos024); position.push_back(24);
     button.push_back(ui->pos023); position.push_back(23);
     button.push_back(ui->pos022); position.push_back(22);
     button.push_back(ui->pos021); position.push_back(21);
     button.push_back(ui->pos020); position.push_back(20);
     button.push_back(ui->pos019); position.push_back(19);
     button.push_back(ui->pos018); position.push_back(18);
     button.push_back(ui->pos017); position.push_back(17);
     button.push_back(ui->pos016); position.push_back(16);
     button.push_back(ui->pos066); position.push_back(65);
     button.push_back(ui->pos071); position.push_back(71);
     button.push_back(ui->pos072); position.push_back(72);
     button.push_back(ui->pos067); position.push_back(67);
     button.push_back(ui->pos030); position.push_back(30);
     button.push_back(ui->pos031); position.push_back(31);
     button.push_back(ui->pos032); position.push_back(32);
     button.push_back(ui->pos033); position.push_back(33);
     button.push_back(ui->pos034); position.push_back(34);
     button.push_back(ui->pos035); position.push_back(35);
     button.push_back(ui->pos036); position.push_back(36);
     button.push_back(ui->pos037); position.push_back(37);
     button.push_back(ui->pos038); position.push_back(38);
     button.push_back(ui->pos039); position.push_back(39);
     button.push_back(ui->pos040); position.push_back(40);
     button.push_back(ui->pos041); position.push_back(41);
     button.push_back(ui->pos042); position.push_back(42);
     button.push_back(ui->pos043); position.push_back(43);
     button.push_back(ui->pos082); position.push_back(82);
     button.push_back(ui->pos092); position.push_back(92);
     button.push_back(ui->pos097); position.push_back(97);
     button.push_back(ui->pos102); position.push_back(102);
     button.push_back(ui->pos107); position.push_back(107);
     button.push_back(ui->pos108); position.push_back(108);
     button.push_back(ui->pos103); position.push_back(103);
     button.push_back(ui->pos098); position.push_back(98);
     button.push_back(ui->pos093); position.push_back(93);
     button.push_back(ui->pos088); position.push_back(88);
     button.push_back(ui->pos083); position.push_back(83);
     button.push_back(ui->pos078); position.push_back(78);
     button.push_back(ui->pos057); position.push_back(57);
     button.push_back(ui->pos055); position.push_back(55);
     button.push_back(ui->pos054); position.push_back(54);
     button.push_back(ui->pos053); position.push_back(53);
     button.push_back(ui->pos052); position.push_back(52);
     button.push_back(ui->pos051); position.push_back(51);
     button.push_back(ui->pos050); position.push_back(50);
     button.push_back(ui->pos049); position.push_back(49);
     button.push_back(ui->pos048); position.push_back(48);
     button.push_back(ui->pos047); position.push_back(47);
     button.push_back(ui->pos046); position.push_back(46);
     button.push_back(ui->pos045); position.push_back(45);
     button.push_back(ui->pos044); position.push_back(44);
     button.push_back(ui->pos068); position.push_back(68);
     button.push_back(ui->pos073); position.push_back(73);
     button.push_back(ui->pos074); position.push_back(74);
     button.push_back(ui->pos069); position.push_back(69);
     button.push_back(ui->pos058); position.push_back(58);
     button.push_back(ui->pos060); position.push_back(60);
     button.push_back(ui->pos061); position.push_back(61);
     button.push_back(ui->pos062); position.push_back(62);
     button.push_back(ui->pos064); position.push_back(64);
     button.push_back(ui->pos084); position.push_back(84);
     button.push_back(ui->pos099); position.push_back(99);
     button.push_back(ui->pos104); position.push_back(104);
  */


   }
