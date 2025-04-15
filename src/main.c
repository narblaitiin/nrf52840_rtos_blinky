/*
 * Copyright (c) 2025
 * Regis Rousseau
 * Univ Lyon, INSA Lyon, Inria, CITI, EA3720
 * SPDX-License-Identifier: Apache-2.0
 */

//  ========== includes ====================================================================
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

//  ========== defines =====================================================================
/* 2000 msec = 2 sec */
#define SLEEP_TIME_MS   2000

/* the devicetree node identifier for the aliases leds */
#define LED_TX DT_ALIAS(ledtx)
#define LED_RX DT_ALIAS(ledrx)

//  ========== globals =====================================================================
/* a build error on this line means your board is unsupported */
static const struct gpio_dt_spec led_tx = GPIO_DT_SPEC_GET(LED_TX, gpios);
static const struct gpio_dt_spec led_rx = GPIO_DT_SPEC_GET(LED_RX, gpios);

//  ========== main ========================================================================
int8_t main(void)
{
	int8_t ret = 0;

	// configurations of LEDs
	gpio_pin_configure_dt(&led_tx, GPIO_OUTPUT_ACTIVE);
	gpio_pin_configure_dt(&led_rx, GPIO_OUTPUT_ACTIVE);

	// LEDs off
	gpio_pin_set_dt(&led_tx, 0);
	gpio_pin_set_dt(&led_rx, 0);

	// beginning forever loop
	while (1) {
		printk("Hello World! %s\n", CONFIG_BOARD);
		ret = gpio_pin_toggle_dt(&led_tx);
		if (ret < 0) {
			return 0;
		}
		ret = gpio_pin_toggle_dt(&led_rx);
		if (ret < 0) {
			return 0;
		}
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}