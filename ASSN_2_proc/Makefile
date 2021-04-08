obj-m += seconds.o

obj-m += jiffies.o

all:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	
clean:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
