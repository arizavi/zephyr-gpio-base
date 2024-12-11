/*
 * File: pin_defs.c
 * Author: Ali Rizavi 
 * Date: December 8, 2024
 * Description: Basic GPIO functionalities for the project.
 */
#include "pin_defs.h"

/* Define the GPIO specification using the device tree */
const struct gpio_dt_spec user_gpio_01_dt_spec = GPIO_DT_SPEC_GET(USER_NODE, user_gpio_01_gpios);
const struct gpio_dt_spec user_gpio_02_dt_spec = GPIO_DT_SPEC_GET(USER_NODE, user_gpio_02_gpios);
const struct gpio_dt_spec user_gpio_03_dt_spec = GPIO_DT_SPEC_GET(USER_NODE, user_gpio_03_gpios);
const struct gpio_dt_spec user_gpio_04_dt_spec = GPIO_DT_SPEC_GET(USER_NODE, user_gpio_04_gpios);

/* Define device bindings */
const struct device *user_gpio_01_dev = DEVICE_DT_GET(USER_GPIO_01);
const struct device *user_gpio_02_dev = DEVICE_DT_GET(USER_GPIO_02);
const struct device *user_gpio_03_dev = DEVICE_DT_GET(USER_GPIO_03);
const struct device *user_gpio_04_dev = DEVICE_DT_GET(USER_GPIO_04);

bool check_gpio_devices_ready(void) {
    if (!device_is_ready(user_gpio_01_dev)) {
        printk("USER_GPIO_01 device not ready\n");
        return false;
    }
    if (!device_is_ready(user_gpio_02_dev)) {
        printk("USER_GPIO_02 device not ready\n");
        return false;
    }
    if (!device_is_ready(user_gpio_03_dev)) {
        printk("USER_GPIO_03 device not ready\n");
        return false;
    }
    if (!device_is_ready(user_gpio_04_dev)) {
        printk("USER_GPIO_04 device not ready\n");
        return false;
    }
    return true;
}

void configure_gpio_pins(void) {
    /* Configure GPIO pins */
    // gpio_pin_configure(user_gpio_01_dev, USER_GPIO_01_PIN, GPIO_OUTPUT | USER_GPIO_01_FLAGS);
    // gpio_pin_configure_dt(&user_gpio_01_dt_spec, GPIO_OUTPUT | USER_GPIO_01_FLAGS);

    gpio_pin_configure_dt(&user_gpio_01_dt_spec, USER_GPIO_01_INIT);
    gpio_pin_configure_dt(&user_gpio_02_dt_spec, USER_GPIO_02_INIT);
    gpio_pin_configure_dt(&user_gpio_03_dt_spec, USER_GPIO_03_INIT);
    gpio_pin_configure_dt(&user_gpio_04_dt_spec, USER_GPIO_04_INIT);
}

void init_gpio(void) {
    if (check_gpio_devices_ready()) {
        configure_gpio_pins();
    } else {
        printk("Error: One or more GPIO devices are not ready.\n");
    }
}

