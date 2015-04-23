#ifndef STARTKEYPRESSTHREAD_H
#define STARTKEYPRESSTHREAD_H

#include <QtCore>


class StartKeypressThread : public QThread
{
public:
  StartKeypressThread();
  void run();
  void start();
};

#endif // STARTKEYPRESSTHREAD_H
