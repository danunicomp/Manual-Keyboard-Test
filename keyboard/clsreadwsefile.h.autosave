#ifndef CLSREADWSEFILE_H
#define CLSREADWSEFILE_H

#include <QObject>

class clsReadWSEFile : public QObject
{
  Q_OBJECT
public:
  explicit clsReadWSEFile(QObject *parent = 0);
  int ReadWSEFile (QString FileName);
  vector<int> kbPositions;
  vector<std::string> kbMakes;
  vector<std::string> kbBreaks;

private:
  int ReadFile(QString);
signals:
  
public slots:
  
};

#endif // CLSREADWSEFILE_H
