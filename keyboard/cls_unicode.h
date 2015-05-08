#ifndef CLS_UNICODE_H
#define CLS_UNICODE_H

#include <vector>
#include <termios.h>
#include <QObject>


class cls_UniCode : public QObject
{
    Q_OBJECT

public:
    explicit cls_UniCode(QObject *parent = 0);
       std::vector<int> GetUnicodeBuffer (void);
       long long int GetUnicodeInt(void);

public slots:

private:
    void clean_up(int) ;
    void get_mode(int);
    int is_a_console(int);
    int open_a_console(const char *);
    int getfd(const char *);

    int oldkbmode;
    void quit(int);
    struct termios newkb;
    struct termios old;
    bool isCheckingCodes;

signals:
  void QuitScan();

};

#endif // CLS_UNICODE_H
