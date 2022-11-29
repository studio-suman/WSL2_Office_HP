#include "common.h"

  main(int argc, char *argv[])  {
  int fd, k;
  char *buf = "hello ";
  struct rlimit rlim = {100,100};
  setrlimit(RLIMIT_FSIZE, &rlim);
  fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0600);
  for (k=0; k<20; k++)   {
      printf("attempting to write  %d bytes\n", strlen(buf));
      write(fd, buf, strlen(buf));
      printf("successfully written %d bytes\n", strlen(buf));
  }
  close(fd);
}