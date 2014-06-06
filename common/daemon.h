#ifndef _DAEMON_H_
#define _DAEMON_H_

#include "head.h"

int init_daemon(void)
{
  pid_t pid;
  /* parent exits , child continues */
  if((pid = fork()) < 0)
    return -1;
  else if(pid != 0)
    exit(0);

  setsid(); /* become session leader */

  return 0;
}

#endif
