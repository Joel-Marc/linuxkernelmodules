## ASSN-2 - The /proc File System

Proc is a pseudo file system for interfacing with the kernel internal data structures. As a user, you can use proc files for system diagnostics  – CPU, memory, Interrupts and many more. You can also configure a lot of parameters like scheduler parameters, kernel objects, memory and more

The common interaction with proc is using cat and echo from the shell. For example:
```
cat /proc/cpuinfo
echo "50"> /proc/sys/kernel/sched_rr_timeslice_ms
```

For more reference : [PROC](https://devarea.com/linux-kernel-development-creating-a-proc-file-and-interfacing-with-user-space/) and [OS BOOK 10th ed](https://cloudflare-ipfs.com/ipfs/bafykbzaceauk2vnr3wg4srylh77es27jzpzfczhva3ruj6k2j2kndwfk6g7e4?filename=%2810%29%20Abraham%20Silberschatz%20-%20Operating%20System%20Concepts%20%5Bwith%20eText%20Access%20Code%5D-Wiley%20%282018%29.pdf)


This assignment will involve designing two kernel modules:

1. Design a kernel module that creates a /proc file named /proc/jiffies that reports the current value of jiffies when the /proc/jiffies file
is read, such as with the command

```cat /proc/jiffies```

Be sure to remove /proc/jiffies when the module is removed.

2. Design a kernel module that creates a proc file named /proc/seconds that reports the number of elapsed seconds since the kernel module was loaded. 
This will involve using the value of jiffies as well as the HZ rate. When a user enters the command
```
cat /proc/seconds
```
your kernel module will report the number of seconds that have elapsed since the kernel module was first loaded. Be sure to remove /proc/seconds when the module is removed.

