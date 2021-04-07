#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>

/* This function is called when the module is loaded. */ int simple_init(void)
{
printk(KERN_INFO "Loading Module\n");
printk(KERN_INFO "GOLDEN RATIO : %llu\n", GOLDEN_RATIO_PRIME);
printk(KERN_INFO "JIFFIES : %ld\n",jiffies);
return 0;

}
/* This function is called when the module is removed. */ void simple_exit(void)
{
printk(KERN_INFO "Removing Module\n");
printk(KERN_INFO "GCD OF 3300 and 24  IS : %ld\n",gcd(3300,24));
printk(KERN_INFO "HZ : %d\nJIFFIES : %ld\n",HZ,jiffies);
}
/* Macros for registering module entry and exit points. */ 
module_init(simple_init);

module_exit(simple_exit); 
MODULE_LICENSE("GPL"); 
MODULE_DESCRIPTION("Simple Module"); MODULE_AUTHOR("SGG");
