/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 50

int main(void) {
  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }
  LED_blink(LED0, LED_1HZ);
  // LED_set(LED0, LED_ON);
 
  while (1) {
    k_msleep(SLEEP_MS);
  }
  return 0;
}
