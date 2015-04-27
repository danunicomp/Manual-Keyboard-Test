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
  std::vector<QString> kbMakes;
  std::vector<QString> kbBreaks;
  std::vector<QString> kbDescription;


private:
  int ReadFile(QString);
  std::vector<QString> lines;
  int ParseWSELine(void);
  int ParsePosition(QString);
  int ParseMakes(QString);
  int ParseBreaks(QString);
  int ParseDescription(QString);

signals:
  
public slots:
  
};

#endif // CLSREADWSEFILE_H
