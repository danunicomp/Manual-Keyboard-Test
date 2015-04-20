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

#include "cls_unicode.h"
#include <signal.h>
#include <errno.h>

#include "signalHandler.h"


cls_UniCode::cls_UniCode(QObject *parent) :
    QObject(parent)
{
}

using namespace std;

/*******************   MAIN    ****************************/
 std::vector<int> cls_UniCode::GetUnicodeBuffer (void) {
         int show_keycodes = 1;
    int fd;
    int iret;


    int  buf[19];
    int scancodes;
    std::vector<int> newbuf;
    int i, n;

    fd = cls_UniCode::getfd(NULL);
    if (fd == -1) {
    //  perror("No in sudo??");
      std::exit(1);
    }
    /* the program terminates when there is no input for 10 secs */
   // signal(SIGALRM, watch_dog(fd));

  //  cls_UniCode::get_mode(fd);


    // THIS IS THE HOOK
    if (tcgetattr(fd, &old) == -1)
            perror("tcgetattr");
    if (tcgetattr(fd, &newkb) == -1)
            perror("tcgetattr");
    ///////////////////////////
    SignalHandler signalHandler;
    // Register signal handler to handle kill signal
    signalHandler.setupSignalHandlers();

    try {

    newkb.c_lflag &= ~ (ICANON | ECHO | ISIG);
    newkb.c_iflag = 0;

    // new.c_cc[VMIN] = sizeof(buf);
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

    /* show keycodes - 2.6 allows 3-byte reports */
    int t;
 //
    for (t=0; t<19; ++t) {
        buf[t] = 0;
    }
 //    usleep(1000000);


     //   alarm(100);
        int fullcode;

         n = read(fd, buf, sizeof(buf));

            if (n == -1) { cout << "ERROR"; clean_up(fd); return newbuf; }
        i = 0;
        int y = buf[0];
        fullcode = y;

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
      iret = EXIT_FAILURE;
    }

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
    fd = open(fnam, O_RDWR);
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
