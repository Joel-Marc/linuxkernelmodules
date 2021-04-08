## REFER!!!
A full beginners guide to programming Linux Kernel Module can be read here : [The Linux Kernel Module Programming Guide](https://tldp.org/LDP/lkmpg/2.4/lkmpg.pdf) and [OS BOOK 10th ed](https://cloudflare-ipfs.com/ipfs/bafykbzaceauk2vnr3wg4srylh77es27jzpzfczhva3ruj6k2j2kndwfk6g7e4?filename=%2810%29%20Abraham%20Silberschatz%20-%20Operating%20System%20Concepts%20%5Bwith%20eText%20Access%20Code%5D-Wiley%20%282018%29.pdf)


## ASSN-1 - Loading and Removing Kernel Modules & Kernel Data Structures
The first part of this project involves following a series of steps for creating and inserting a module into the Linux kernel.
You can list all kernel modules that are currently loaded by entering the command
```
lsmod
```

This command will list the current kernel modules in three columns: name, size, and where the module is being used.
The function simple init() is the module entry point, which represents the function that is invoked when the module is loaded into the kernel.
Similarly, the simple exit() function is the module exit point— the function that is called when the module is removed from the kernel.

The module entry point function must return an integer value, with 0 representing success and any other value representing failure. 
The module exit point function returns void. Neither the module entry point nor the module exit point is passed any parameters. 
The two following macros are used for registering the module entry and exit points with the kernel:

```
module init()
module exit()
```

Notice how both the module entry and exit point functions make calls to the printk() function. printk() is the kernel equivalent of printf(),
yet its output is sent to a kernel log buffer whose contents can be read by the **dmesg** command. One difference between printf()* and printk() is that
printk() allows us to specify a priority flag whose values are given in the <linux/printk.h> include file. In this instance, the priority is KERN INFO,
which is defined as an informational message.

The final lines—MODULE LICENSE(), MODULE DESCRIPTION(), and MODULE AUTHOR()— represent details regarding the software license, description
of the module, and author.  
To compile the module, enter the following
on the command line:

```make```

The compilation produces several files. The file simple.ko represents the compiled kernel module. The following step illustrates inserting this module
into the Linux kernel.

### Loading and Removing Kernel Modules
Kernel modules are loaded using the insmod command, which is run as follows:

```sudo insmod 1.ko```

To check whether the module has loaded, enter the **lsmod** command and search for the module simple. Recall that the module entry point is invoked when the
module is inserted into the kernel. To check the contents of this message in the kernel log buffer, enter the command

```dmesg```

You should see the message "Loading Module."

Removing the kernel module involves invoking the rmmod command :
```
sudo rmmod 1.ko
```
Be sure to check with the dmesg command to ensure the module has been removed. Because the kernel log buffer can fill up quickly, it often makes sense to clear the buffer periodically. This can be accomplished as follows:
```
sudo dmesg -c
```
Once you are able to correctly load and unload your module, complete the following additional steps:

1. Print out the value of GOLDEN RATIO PRIME in the simple init() function.
2. Print out the greatest common divisor of 3,300 and 24 in the simple exit() function.

In Linux, the rate at which the timer ticks (the tick rate) is the value HZ defined in <asm/param.h>. The value of HZ determines the frequency of the timer interrupt, 
and its value varies by machine type and architecture.
For example, if the value of HZ is 100, a timer interrupt occurs 100 times per second, or every 10 milliseconds. Additionally, the kernel keeps track of the
global variable jiffies, which maintains the number of timer interrupts that have occurred since the system was booted. 
The jiffies variable is declared in the file <linux/jiffies.h>.

1. Print out the values of jiffies and HZ in the simple init() function.
2. Print out the value of jiffies in the simple exit() function.

### Kernel Data Structures
The second part of this project involves modifying the kernel module so that it uses the kernel linked-list data structure.

In the module entry point, create a linked list containing five struct birthday elements. Traverse the linked list and output its contents to the kernel log buffer.
Invoke the dmesg command to ensure the list is properly constructed once the kernel module has been loaded.
In the module exit point, delete the elements from the linked list and return the free memory back to the kernel. 
Again, invoke the dmesg command to check that the list has been removed once the kernel module has been unloaded.
