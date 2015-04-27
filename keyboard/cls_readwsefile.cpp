#include <QtCore>
#include "cls_readwsefile.h"
#include <QVector>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

clsReadWSEFile::clsReadWSEFile(QObject *parent) :
  QObject(parent)
{
}

using namespace std;

//READ WSE FILE AND LOAD VECTOR WITH EACH LINE. RETURNS -1 IF FAIL
int clsReadWSEFile::ReadWSEFile (QString FileName)
{
  //unsigned int x = 0;
  //string buf = "";


  qDebug() << "Reading File";
  QFile file(FileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Error opening";
    return -1;
    }
  QTextStream in(&file);
  QString line;
  while (!in.atEnd()) {
      line = in.readLine();

      if (line[0] != '#' && line.size() != 0 ) {
          line = line.simplified(); // take out all tabs and extra spaces in line
          qDebug() << "Line: " << line;
          // BEGIN PARSING ELLIMATES
          ParsePosition(line);
          ParseMakes(line);
          ParseBreaks(line);
          ParseDescription(line);
      }
  }

//  for(x=0; x<kbPositions.size(); ++x) {
//      qDebug() << kbPositions[x];
//  }
  return 1;
}

//  PARSE WSE LINE
int ParseWSELine(void) {

  return 1;
}

// TAKE LINE FROM WSE AND PARSE OUT POSITIONS INTO VECTOR
int clsReadWSEFile::ParsePosition(QString line) {
    std::ostringstream buf;
    int pos;

    for (int x=0; x < line.size(); ++x) {
        if (line[x] != ' '  && line[x] != '\t' && line[x] != '+') {
            buf << line[x].toAscii();
          }
        else {
            pos = atoi(buf.str().c_str());
            kbPositions.push_back(pos);
            //qDebug() << buf.str().c_str();
            break;
        }
    }
    return 1;
}

// PARSE MAKES
int clsReadWSEFile::ParseMakes(QString line) {
    bool domakes = false;
    std::ostringstream buf;
    buf.str("");
    QString make;
    for (int x=0; x < line.size(); ++x) {
        if (line[x] == '+' && domakes == false) {
            domakes = true;
        } else if (line[x] == '+' && domakes == true) {
            domakes = false;
        }
        if (domakes && line[x] != '+') {
            buf << line[x].toAscii();
        }
        make = buf.str().c_str();

    }
    make = make.simplified();
    kbMakes.push_back(make);

    qDebug() << "Make: " << make;
    return 1;
}

int clsReadWSEFile::ParseBreaks(QString line) {
    bool dobreaks = false;
    std::ostringstream buf;
    buf.str("");

    QString breaks;

    for (int x=0; x < line.size(); ++x) {
        if (line[x] == '-' && dobreaks == false) {
            dobreaks = true;
        } else if (line[x] == '-' && dobreaks == true) {
            dobreaks = false;
        }
        if (dobreaks && line[x] != '-') {
            buf << line[x].toAscii();
        }
        breaks = buf.str().c_str();

    }
    kbBreaks.push_back(breaks);
    qDebug() << "Break: " << breaks;
    return 1;
}

int clsReadWSEFile::ParseDescription(QString line) {
    std::ostringstream buf;
    buf.str("");

    QString description;

    for (int x=0; x < line.size(); ++x) {
        if (line[x] == '!') {
            description = line.right(line.size()-x-1);
 //                   QStringRef subString(line, x, line.size()-x);
            break;
        }
    }
    description = description.simplified();
    kbDescription.push_back(description);
    qDebug() << "Description: " << description;
    return 1;
}
