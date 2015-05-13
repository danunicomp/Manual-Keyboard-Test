#include <vector>
#include <termios.h>
#include <linux/keyboard.h>
#include <sys/ioctl.h> /* ioctl */
#include <fcntl.h> /* open */
#include <stdio.h>
#include <linux/kd.h>
#include <string>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <cstdlib>
#include <qtimer.h>

#include "cls_unicode.h"
#include <signal.h>
#include <errno.h>

#include "signalHandler.h"
#include <QMainWindow>
#include <QApplication>


cls_UniCode::cls_UniCode(QObject *parent) :
    QObject(parent)
{
}

using namespace std;



/*******************   NEW GET SCANCODE NEW STRING    ****************************/

void SigDetect(int sign);

void SigDetect(int sign) {
  //  QCoreApplication::processEvents();
//  signal(SIGALRM, SigDetect); //Set alarm clock for 3 seconds.
  //alarm(1);
 // printf("ALARM\n");
//  printf("Sign: %i\n", sign);
 // signal(SIGALRM, SIG_IGN);
  close(7);
  //cls_UniCode::clean_up(7);
 return;
}
/////////////////////////////////////
QVector<QString>
cls_UniCode::GetNewUnicodeBuffer (void) {
    int show_keycodes = 1;
    int fd;
    //  int iret;

    //  cout << cls_UniCode::QObject.objectName();

   int  buf[19];
    int scancodes;
    QVector<QString> newbuf;
    int i, n;

    fd = cls_UniCode::getfd(NULL);
    if (fd == -1) {
    //  perror("Not in sudo??");
        std::exit(1);
    }

    this->isCheckingCodes = true;

    // THIS IS THE HOOK
    if (tcgetattr(fd, &old) == -1)
         perror("tcgetattr");
    if (tcgetattr(fd, &newkb) == -1)
         perror("tcgetattr");

    QCoreApplication::processEvents();

    newkb.c_lflag &= ~ (ICANON | ECHO | ISIG);
    newkb.c_iflag = 0;

    newkb.c_cc[VMIN] = 1;
    newkb.c_cc[VTIME] = 1;	/* 0.1 sec intercharacter timeout */

    if (tcsetattr(fd, TCSAFLUSH, &newkb) == -1) {
         perror("tcsetattr");
    }

    if (ioctl(fd, KDSKBMODE, show_keycodes ? K_MEDIUMRAW : K_RAW)) {
        cout << "Fail?? " << endl;
        perror("KDSKBMODE");
        clean_up(fd);
        close(fd);
    }

    usleep(10);

    int fullcode;

    alarm(4);
    signal(SIGALRM, SigDetect);

    n = read(fd, &buf, sizeof(buf));
    QCoreApplication::processEvents();
    if (n == -1) {
   //  cout << "ERROR READING USAGE CODE";
        clean_up(fd);
        return newbuf;
    }

// ------------------  DECODE  ----
    fullcode = buf[0];

// CONVERTS LONG INTEGER INTO BYTES
    // n is the number of scan codes

    if (fullcode > 0 ) {
        scancodes = 0;
        for (i=0;i<n; ++i) {
          buf[i] = ((fullcode & (255 << (8*i))) >> (8*i) );
          ++ scancodes;
        }

        QString s = ""; int tmp;
        if (n > 1) {
            for (tmp = 0; tmp < n-1; ++tmp) {
               // cout << "POS: " << tmp << " " << buf[tmp] << endl;
                s = s + QString::number(buf[tmp]) + " ";
            }
            s = s + QString::number(buf[tmp]);
        }
        else {
            s = QString::number(buf[0]);
        }
        if (buf[0] < 128) newbuf.push_back("1000");
        else newbuf.push_back("9999");

        newbuf.push_back(s);
    }

// ---------------------------------
    clean_up(fd);
    close(fd);
    return newbuf;
}


////////////////////  GET INT  SCANCODE  ////////////////////////////////////////////
long long int
cls_UniCode::GetUnicodeInt(void) {

    int show_keycodes = 1;
    int fd;
    //  int iret;

    //  cout << cls_UniCode::QObject.objectName();

    long long int  buf[19];
    //int scancodes;
    std::vector<int> newbuf;
    int  n;

    fd = cls_UniCode::getfd(NULL);
    if (fd == -1) {
    //  perror("Not in sudo??");
        std::exit(1);
    }

   // qDebug() << "Global fd: " << this->fd_current << "   old fd: " << fd;

    this->isCheckingCodes = true;

    // THIS IS THE HOOK
    if (tcgetattr(fd, &old) == -1)
         perror("tcgetattr");
    if (tcgetattr(fd, &newkb) == -1)
         perror("tcgetattr");

    QCoreApplication::processEvents();

    newkb.c_lflag &= ~ (ICANON | ECHO | ISIG);
    newkb.c_iflag = 0;

    newkb.c_cc[VMIN] = 1;
    newkb.c_cc[VTIME] = 1;	/* 0.1 sec intercharacter timeout */

    if (tcsetattr(fd, TCSAFLUSH, &newkb) == -1) {
         perror("tcsetattr");
    }

    if (ioctl(fd, KDSKBMODE, show_keycodes ? K_MEDIUMRAW : K_RAW)) {
        cout << "Fail?? " << endl;
        perror("KDSKBMODE");
        clean_up(fd);
        close(fd);
    }

    usleep(10);

    //int fullcode;

    alarm(4);
    // signal(SIGALRM, quit());
    signal(SIGALRM, SigDetect);

    n = read(fd, &buf, sizeof(buf));
    QCoreApplication::processEvents();
    if (n == -1) {
   //  cout << "ERROR READING USAGE CODE";
     clean_up(fd);
     return n;
    }

    clean_up(fd);
    close(fd);
    return buf[0];

}
//////////////////// END GET INT BUFFER ////////////////////////////////////////////




/*******************   GET BUFFER    ****************************/
 std::vector<int> cls_UniCode::
 GetUnicodeBuffer (void) {
    int show_keycodes = 1;
    int fd;
  //  int iret;

  //  cout << cls_UniCode::QObject.objectName();

    int  buf[19];
    int scancodes;
    std::vector<int> newbuf;
    int i, n;

    fd = cls_UniCode::getfd(NULL);
    if (fd == -1) {
    //  perror("Not in sudo??");
      std::exit(1);
    }
    ///////////////////////////
    SignalHandler signalHandler;
    // Register signal handler to handle kill signal
    signalHandler.setupSignalHandlers();

/*
    QTimer *timer = new QTimer( myObject );
    connect( timer, SIGNAL(timeout()), myObject, SLOT(quit(fd)) );
    timer->start( 2000, TRUE ); // 2 seconds single-shot timer
*/



    /*
    signal(SIGALRM, cls_UniCode::quit(fd));

    signal(SIGHUP, cls_UniCode::quit(fd));
    signal(SIGINT, cls_UniCode::quit(fd));
    signal(SIGQUIT, cls_UniCode::quit(fd));
    signal(SIGILL, cls_UniCode::quit(fd));
    signal(SIGTRAP, cls_UniCode::quit(fd));
    signal(SIGABRT, cls_UniCode::quit(fd));
    signal(SIGIOT, cls_UniCode::quit(fd));
    signal(SIGFPE, cls_UniCode::quit(fd));
    signal(SIGKILL, cls_UniCode::quit(fd));
    signal(SIGUSR1, cls_UniCode::quit(fd));
    signal(SIGSEGV, cls_UniCode::quit(fd));
    signal(SIGUSR2, cls_UniCode::quit(fd));
    signal(SIGPIPE, cls_UniCode::quit(fd));
    signal(SIGTERM, cls_UniCode::quit(fd));
#ifdef SIGSTKFLT
    signal(SIGSTKFLT, cls_UniCode::quit(fd));
#endif
    signal(SIGCHLD, cls_UniCode::quit(fd));
    signal(SIGCONT, cls_UniCode::quit(fd));
    signal(SIGSTOP, cls_UniCode::quit(fd));
    signal(SIGTSTP, cls_UniCode::quit(fd));
    signal(SIGTTIN, cls_UniCode::quit(fd));
    signal(SIGTTOU, cls_UniCode::quit(fd));
*/

    // THIS IS THE HOOK
    if (tcgetattr(fd, &old) == -1)
            perror("tcgetattr");
    if (tcgetattr(fd, &newkb) == -1)
            perror("tcgetattr");



    try {
QCoreApplication::processEvents();


    newkb.c_lflag &= ~ (ICANON | ECHO | ISIG);
    newkb.c_iflag = 0;


    newkb.c_cc[VMIN] = 1;
    newkb.c_cc[VTIME] = 1;	/* 0.1 sec intercharacter timeout */

    if (tcsetattr(fd, TCSAFLUSH, &newkb) == -1)
            perror("tcsetattr");


    if (ioctl(fd, KDSKBMODE, show_keycodes ? K_MEDIUMRAW : K_RAW)) {
        cout << "Fail?? " << endl;
        perror("KDSKBMODE");
        clean_up(fd);
        close(fd);
        return newbuf;
    }

    usleep(10);

    int t;
    for (t=0; t<19; ++t) {
        buf[t] = 0;
    }
    alarm(4);
    // signal(SIGALRM, quit());
    signal(SIGALRM, SigDetect);
        int fullcode;
        QCoreApplication::processEvents();
         n = read(fd, buf, sizeof(buf));
        QCoreApplication::processEvents();
        if (n == -1) { cout << "ERROR"; clean_up(fd); return newbuf; }
        i = 0;
        int y = buf[0];
        fullcode = y;

// CONVERTS LONG INTEGER INTO BYTES
        // n is the number of scan codes

        scancodes = 0;
        for (i=0;i<n; ++i) {
          buf[i] = ((fullcode & (255 << (8*i))) >> (8*i) );
          ++ scancodes;
        }

    newbuf.clear();
        if (buf[0] < 128) {
           newbuf.push_back(1999);
        }
        else
        {
           newbuf.push_back(1000);
        }


            for (t=0;t<scancodes;++t) {
                newbuf.push_back(buf[t]);
//               if ( newbuf[0] == 1) {
//                   clean_up(fd);
//                   close(fd);
//                   return newbuf;
//               }
//     buf[t] = 0;  //flush buffer
            }

            clean_up(fd);
            close(fd);
            return newbuf;
} // end try
    catch (SignalException& e)
    {
      std::cerr << "SignalException: " << e.what() << std::endl;
     // iret = EXIT_FAILURE;
    }

return newbuf;
}



 ////////////////////////////////////////////////////

 // ******* CLEAN UP ************************
void cls_UniCode::clean_up(int fd ) {

    if (ioctl(fd, KDSKBMODE, oldkbmode)) {

        return;
    }

    if (tcsetattr(fd, 0, &old) == -1) {
        perror("tcsetattr");

    }
    //if (tcsetattr(fd, 0, &cls_UniCode.old.) == -1)
    //    perror("tcsetattr");
    close(fd);
    return;
}

// ************ GET MODE ***********************
// DOESN't DO ANYTHING???
// ****************************
void cls_UniCode::get_mode(int fd) {
    string m;

    if (ioctl(fd, KDGKBMODE, &oldkbmode)) {
            perror("KDGKBMODE");
            cout <<  "fail get_mode" << endl;
            clean_up(fd);
            close(fd);
            return;
    }
    switch(oldkbmode) {
        case K_RAW:
            m = "RAW"; break;
        case K_XLATE:
            m = "XLATE"; break;
        case K_MEDIUMRAW:
            m = "MEDIUMRAW"; break;
        case K_UNICODE:
            m = "UNICODE"; break;
    }
}
// *********************************************************
////////////////////////////////////////////////////////

// ***************** IS A CONSOLE *************************
int cls_UniCode::is_a_console(int fd) {
    char arg;

    arg = 0;
    return (isatty (fd)
        && ioctl(fd, KDGKBTYPE, &arg) == 0
        && ((arg == KB_101) || (arg == KB_84)));
}

//////////////////////////////////////////////////////////

// ***************** OPEN A CONSOLE *********************
int cls_UniCode::open_a_console(const char *fnam) {
    int fd;

    /*
     * For ioctl purposes we only need some fd and permissions
     * do not matter. But setfont:activatemap() does a write.
     */
    fd = open(fnam, O_RDWR );
    if (fd < 0)
        fd = open(fnam, O_WRONLY);
    if (fd < 0)
        fd = open(fnam, O_RDONLY);
    if (fd < 0)
        return -1;
    if (!is_a_console(fd)) {
        close(fd);
        return -1;
    }
    return fd;
}

///////////////////////////////////////////////////////////
void cls_UniCode::quit(int fd) {
  cls_UniCode::clean_up(fd);
  exit(1);
}

// ***************  GET FD *****************************
//  GET FILE DISCRIPTER. INPUT
int cls_UniCode::getfd(const char *fnam) {
    int fd;
   //     printf ("FINDING FD\n");
    if (fnam) {
        fd = cls_UniCode::open_a_console(fnam);
        if (fd >= 0) {
                   // printf ("FD FOUND   NULL");
            return fd;
                }
        fprintf(stderr,"Couldn't open %s\n", fnam);
        return -1;
    }

    fd = cls_UniCode::open_a_console("/proc/self/fd/0");
    if (fd >= 0) {
   //        printf ("FD FOUND   /proc/self/fd/0");
            return fd;
        }

    fd = cls_UniCode::open_a_console("/dev/tty");
    if (fd >= 0) {
 //           printf ("FD FOUND   /dev/tty");
            return fd;
        }

    fd = cls_UniCode::open_a_console("/dev/tty0");
    if (fd >= 0) {
 //         printf ("FD FOUND   /dev/tty0");
            return fd;
        }
    fd = cls_UniCode::open_a_console("/dev/vc/0");
    if (fd >= 0)  {
 //         printf ("FD FOUND   /dev/vc/0");
            return fd;
        }
    fd = cls_UniCode::open_a_console("/dev/console");
    if (fd >= 0)  {
 //         printf ("FD FOUND   /dev/console");
            return fd;
        }
//           printf ("FD NOT FOUND\n");
    for (fd = 0; fd < 3; fd++)
        if (is_a_console(fd))
            return fd;

    fprintf(stderr, "Couldn't get a file descriptor referring to the console\nAre you running as SUDO??\n");
    return -1;		/* total failure */
}
