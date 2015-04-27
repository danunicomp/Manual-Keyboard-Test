#include <QtCore>
#include "clsreadwsefile.h"

clsReadWSEFile::clsReadWSEFile(QObject *parent) :
  QObject(parent)
{
}

int clsReadWSEFile::ReadWSEFile (QString FileName)
{
  qDebug() << "Reading File";
  QFile file(FileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Error opening";
    return;
    }
  QTextStream in(&file);
  while (!in.atEnd()) {
      QString line = in.readLine();
      qDebug() << line;
  }
}
