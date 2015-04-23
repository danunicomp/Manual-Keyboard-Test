#include "startkeypressthread.h"

#include <QtCore>
#include <QDebug>

StartKeypressThread::StartKeypressThread()
{

}

void StartKeypressThread::run() {

  qDebug() << "Running....";
  for (int x=0; x<10000; ++x) {
      qDebug() << x;
      usleep(100);
    }

}

void StartKeypressThread::start() {

  qDebug() << "Running....start";

}
