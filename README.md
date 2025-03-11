# Code for 6Sens Project : blinky application test for my own MBDT50Q (based on nRF52840) board

## Overview
Simply Blinky example to know how to install, to configure and to use Zephyr RTOS.
The Blinky example shows how to configure GPIO pins as outputs which can also be used to drive LEDs on the hardware usually delivered as "User LEDs" on many of the supported boards in Zephyr. The Blinky sample blinks green LED (Tx LED of RFM95W transmission) and an another LED (Rx LED of RFM95W transmission) forever using GPIO API.

This application also prints "Hello World" to the console and allows us that the device tree board file is correct (especially UART communication).
The version of Zephyr RTOS used is the version v3.6.0.

For Zephyr documentation, please click on this link: https://docs.zephyrproject.org/3.6.0/

**Board used** : Original MDBT50Q board, powered by battery/solar panel. (see 6sens_project_nrf52 repository/hardware part, for more information.)

## Building and Running
The following commands clean build folder, build and flash the sample:

**Command to use**

west build -p always -b mdbt50q_lora_dev applications/nrf52840_rtos_blinky

west flash --runner pyocd