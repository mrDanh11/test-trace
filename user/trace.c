<<<<<<< HEAD
#include "kernel/param.h"
=======
>>>>>>> test-trace-2
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

<<<<<<< HEAD
int
main(int argc, char *argv[])
{
  int i;
  char *nargv[MAXARG];

  if(argc < 3 || (argv[1][0] < '0' || argv[1][0] > '9')){
    fprintf(2, "Usage: %s mask command\n", argv[0]);
    exit(1);
  }

  if (trace(atoi(argv[1])) < 0) {
    fprintf(2, "%s: trace failed\n", argv[0]);
    exit(1);
  }
  
  for(i = 2; i < argc && i < MAXARG; i++){
    nargv[i-2] = argv[i];
  }
  exec(nargv[0], nargv);
  exit(0);
=======
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(2, "Usage: trace mask command...\n");
        exit(1);
    }
    
    int mask = atoi(argv[1]);
    if (trace(mask) < 0) {
        fprintf(2, "trace: failed\n");
        exit(1);
    }
    
    exec(argv[2], &argv[2]);
    fprintf(2, "exec failed\n");
    exit(1);
>>>>>>> test-trace-2
}
