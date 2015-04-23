#ifndef CLS_UNICOMPCODE_H
#define CLS_UNICOMPCODE_H

#include <QtCore>

class cls_UnicompCode : public QThread
{
public:
  cls_UnicompCode();


protected:
    void run();

};

#endif // CLS_UNICOMPCODE_H
