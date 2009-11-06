
// 
// mojo.c
// 
// (c) 2009 TJ Holowaychuk <tj@vision-media.ca> (MIT Licensed)
//

#include <string.h>
#include "mojo.h"

static void
usage() {
  printf("mojo %s\n", MOJO_VERSION);
  printf("usage: mojo < in > out\n");
}

int 
main(int argc, char **argv) {
  if (argc && strcmp(argv[1], "--help") == 0) usage();
  else Mojo_parse();
  return 0;
}

