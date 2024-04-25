/* 

 * pcprox_module.c - The simplest kernel module. 

 */ 

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/printk.h> /* Needed for pr_info() */ 


static struct usb_device_id pcprox_table[] = {
    { USB_DEVICE(0x0c27, 0x3bfa) },
    {}
};

MODULE_DEVICE_TABLE(usb, pcprox_table);

static int pcprox_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    // Probe function, called when device is connected
    printk(KERN_INFO "PCProx device connected\n");
    return 0; // Success
}

static void pcprox_disconnect(struct usb_interface *interface)
{
    // Disconnect function, called when device is disconnected
    printk(KERN_INFO "PCProx device disconnected\n");
}

static struct usb_driver pcprox_driver = {
    .name = "pcprox",
    .id_table = pcprox_table,
    .probe = pcprox_probe,
    .disconnect = pcprox_disconnect,
};

static int __init pcprox_init(void)
{
    // Module initialization
    return usb_register(&pcprox_driver);
}

static void __exit pcprox_exit(void)
{
    // Module cleanup
    usb_deregister(&pcprox_driver);
}

module_init(pcprox_init);
module_exit(pcprox_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Adrian Edwards");
MODULE_DESCRIPTION("PCProx USB RF Card Reader Module");