/*
 * File: main.c
 * Author: Ali Rizavi 
 * Date: December 8, 2024
 * Description: Basic GPIO functionalities for the project.
 */

#include "pin_defs.h"

int main(void)
{
    /* Initialize GPIO devices and configure pins using the helper function */
    init_gpio();

    while (1) {
        /* Toggle GPIO pins */
        gpio_pin_toggle_dt(&user_gpio_01_dt_spec);
        gpio_pin_toggle_dt(&user_gpio_02_dt_spec);
        gpio_pin_toggle_dt(&user_gpio_03_dt_spec);
        gpio_pin_toggle_dt(&user_gpio_04_dt_spec);

        k_msleep(1000);
    }
}

