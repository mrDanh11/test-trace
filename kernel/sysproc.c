#include "types.h"
#include "riscv.h"
#include "defs.h"
<<<<<<< HEAD
#include "date.h"
=======
>>>>>>> test-trace-2
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
<<<<<<< HEAD
#include "sysinfo.h"
=======
>>>>>>> test-trace-2

uint64
sys_exit(void)
{
  int n;
<<<<<<< HEAD
  if(argint(0, &n) < 0)
    return -1;
=======
  argint(0, &n);
>>>>>>> test-trace-2
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
<<<<<<< HEAD
  if(argaddr(0, &p) < 0)
    return -1;
=======
  argaddr(0, &p);
>>>>>>> test-trace-2
  return wait(p);
}

uint64
sys_sbrk(void)
{
<<<<<<< HEAD
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
=======
  uint64 addr;
  int n;

  argint(0, &n);
>>>>>>> test-trace-2
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

<<<<<<< HEAD
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
=======
  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
>>>>>>> test-trace-2
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

<<<<<<< HEAD
  if(argint(0, &pid) < 0)
    return -1;
=======
  argint(0, &pid);
>>>>>>> test-trace-2
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

<<<<<<< HEAD
uint64
sys_trace()
{
  int mask;

  if (argint(0, &mask) < 0)
      return -1;

  struct proc *pro = myproc();
  printf("trace pid: %d\n", pro->pid);
  pro->trace_mask = mask;

  return 0;
}

uint64
sys_sysinfo()
{
  uint64 param;
  if(argaddr(0, &param) < 0)
    return -1;
  
  struct sysinfo info;
  info.freemem = get_free_memory();
  info.nproc = get_proccesses_num();

  struct proc *p = myproc();
  if (copyout(p->pagetable, param, (char *)&info, sizeof(info)) < 0)
    return -1;

  return 0;
}
=======
// trace function
uint64 sys_trace(void) {
    int mask;

    // Lấy đối số syscall vào biến mask
    argint(0, &mask);

    // Cập nhật trace_mask cho tiến trình hiện tại
    struct proc *p = myproc();
    p->trace_mask = mask;

    return 0;
}


>>>>>>> test-trace-2
