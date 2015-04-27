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
  int x = 0;
  //string buf = "";
  std::ostringstream buf;
  int pos;
  buf.str("");

  qDebug() << "Reading File";
  QFile file(FileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Error opening";
    return -1;
    }
  QTextStream in(&file);
  while (!in.atEnd()) {
      QString line = in.readLine();
      if (line[0] != '#') {
          buf.str("");
          this->lines.push_back(line);
          for (x=0; x < line.size(); ++x) {
              if (line[x] != ' '  && line[x] != '\t' && line[x] != '+') {
                  buf << line[x].toAscii();
                }
              else {
                  pos = stoi(buf.str().c_str());
                  kbPositions.push_back(pos);
                  qDebug() << buf.str().c_str();
                  break;
                }
           }

         // qDebug() << line;
      }
  }
  return 1;
}

//  PARSE WSE LINE
int ParseWSELine(void) {

  return 1;
}
