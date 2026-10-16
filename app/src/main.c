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
  LED_set(LED1, LED_ON);
  uint8_t duty_cycle = 0;
  while (1) {
    LED_pwm(LED2, LED_ON);

    if(duty_cycle == 100) {
      duty_cycle = 0;
      LED_toggle(LED3);
    }
    else{
      duty_cycle++;
    }
    k_msleep(SLEEP_MS);
  }
  return 0;
}
