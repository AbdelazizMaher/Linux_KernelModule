#ifndef PLATFORM_H
#define PLATFORM_H

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/sysfs.h>
#include <linux/gpio.h>


/*permission codes */
#define RDONLY          	0x01
#define WRONLY          	0X10
#define RDWR            	0x11

#define GPIO_22  			22
#define GPIO_23  			23
#define GPIO_25	  			25

enum platform_dev_names
{
	GREEN_LED = 0,
	BLUE_LED,
	RED_LED
};

enum GPIO_Direction
{
	INPUT = 0,
	OUTPUT,
};

enum GPIO_OutMode
{
	GPIO_PIN_MODE_OUTPUT_OD = 0,
	GPIO_PIN_MODE_OUTPUT_PP,
};

struct platform_device_private_data
{
	int PinNumber;
	int Direction;
    int OutMode;
	int Value;
	int perm;
	struct cdev cdev;
};


struct platform_driver_private_data
{
	int total_devices;
	dev_t device_number;
	struct class *GPIO_class;
	struct device *GPIO_device;
};


#endif