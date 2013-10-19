stm32_systemetric
=================

This is the STM32 F3 Discovery board firmware that Systemetric will use for the robot(s). (Coming soon.)

https://electroncastle.googlecode.com/files/STM32F3%20Discovery%20%E2%80%93%20developing%20and%20debugging%20on%20Linux%20with%20Eclipse.pdf

This PDF contains instructions on how to get this working on Linux.
Some important things must be noted, however.

1) Rather than using the outdated Summo ARM toolchain, use gcc-arm-none-eabi, a.k.a. GNU Tools for ARM Embedded Processors, available here: https://launchpad.net/gcc-arm-embedded
   You can just download the prebuilt binaries and put them where the PDF tells you to put the Summo toolchain.

2) The following edit must be made to stm_projects/common/Makefile.common:
   Find a line in the file beginning "CFLAGS+=" and add "-I$(DEVICE)/Include" (without quotes) to the end. There are several lines beginning with that, it doesn't matter which one you append to.

Now, cd into ~/stm32_projects and clone this repository in. Hopefully, it'll clone into its own stm32_systemetric folder.

The rest of the instructions in the PDF should be sufficient.
