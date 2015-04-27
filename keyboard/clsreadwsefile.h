#ifndef CLSREADWSEFILE_H
#define CLSREADWSEFILE_H

#include <QObject>
#include <vector>

class clsReadWSEFile : public QObject
{
  Q_OBJECT
public:
  explicit clsReadWSEFile(QObject *parent = 0);
  int ReadWSEFile (QString FileName);
  std::vector<int> kbPositions;
  std::vector<std::string> kbMakes;
  std::vector<std::string> kbBreaks;

private:
  int ReadFile(QString);
signals:
  
public slots:
  
};

#endif // CLSREADWSEFILE_H
