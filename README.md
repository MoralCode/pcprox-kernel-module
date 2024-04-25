# Kernel Module: PCProx USB RF Card Reader

## Overview

This kernel module provides support for PCProx USB RF card readers on Linux systems. The PCProx USB RF card reader is a USB device used for reading radio frequency identification (RFID) cards.

## Prerequisites

- Linux kernel headers installed on your system (`linux-headers-*` package).
- Basic knowledge of kernel module development.
- Understanding of USB device communication.

## Usage

### Building the Module

1. Clone or download the source code for the module.
2. Navigate to the module directory.
3. Run `make` to build the module.

### Loading the Module

Load the module into the kernel using `insmod`:

```bash
sudo insmod pcprox_module.ko
```

### Unloading the Module

Unload the module from the kernel using `rmmod`:

```bash
sudo rmmod pcprox_module
```

### Checking Module Status

Check the kernel log (`dmesg`) for module initialization messages and any errors:

```bash
dmesg | grep pcprox_module
```

alternatively:

```bash
sudo journalctl --since "1 hour ago" | grep pcprox_module 
```
## Configuration

No configuration options are currently available for this module.

## Troubleshooting

If the module fails to load or function correctly, check the following:

- Ensure that the correct kernel headers are installed.
- Verify that the PCProx USB RF card reader is connected to a USB port.
- Check the kernel log (`dmesg`) for any error messages related to the module.

## License

This project is licensed under the [GNU General Public License v2.0](LICENSE).
