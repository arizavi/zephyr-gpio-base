/*
 * File: pin_defs.h
 * Author: Ali Rizavi 
 * Date: December 8, 2024
 * Description: Basic GPIO functionalities for the project.
 */
#pragma once

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/util.h>
#include <zephyr/drivers/gpio.h>

//--------------------------------------------------------------------------
//Notice:
//node <zephyr,user> in .overlay is reference as zephyr_user
//item user_gpio_01-gpios is reference as user_gpio_01_gpios ('-' becomes '_')

/* Define pins */
#define USER_NODE           DT_PATH(zephyr_user)

#define USER_GPIO_01        DT_PHANDLE_BY_IDX(USER_NODE, user_gpio_01_gpios, 0)
#define USER_GPIO_02        DT_PHANDLE_BY_IDX(USER_NODE, user_gpio_02_gpios, 0)
#define USER_GPIO_03        DT_PHANDLE_BY_IDX(USER_NODE, user_gpio_03_gpios, 0)
#define USER_GPIO_04        DT_PHANDLE_BY_IDX(USER_NODE, user_gpio_04_gpios, 0)

#define USER_GPIO_01_PIN    DT_GPIO_PIN(USER_NODE, user_gpio_01_gpios)
#define USER_GPIO_02_PIN    DT_GPIO_PIN(USER_NODE, user_gpio_02_gpios)
#define USER_GPIO_03_PIN    DT_GPIO_PIN(USER_NODE, user_gpio_03_gpios)
#define USER_GPIO_04_PIN    DT_GPIO_PIN(USER_NODE, user_gpio_04_gpios)

#define USER_GPIO_01_FLAGS  DT_GPIO_FLAGS(USER_NODE, user_gpio_01_gpios)
#define USER_GPIO_02_FLAGS  DT_GPIO_FLAGS(USER_NODE, user_gpio_02_gpios)
#define USER_GPIO_03_FLAGS  DT_GPIO_FLAGS(USER_NODE, user_gpio_03_gpios)
#define USER_GPIO_04_FLAGS  DT_GPIO_FLAGS(USER_NODE, user_gpio_04_gpios)

/* Adjust per application */
#define USER_GPIO_01_INIT   GPIO_OUTPUT | USER_GPIO_01_FLAGS
#define USER_GPIO_02_INIT   GPIO_OUTPUT | USER_GPIO_02_FLAGS
#define USER_GPIO_03_INIT   GPIO_OUTPUT | USER_GPIO_03_FLAGS
#define USER_GPIO_04_INIT   GPIO_OUTPUT | USER_GPIO_04_FLAGS

/* Compile-time checks for device tree status */
BUILD_ASSERT(DT_NODE_HAS_STATUS(USER_GPIO_01, okay), "USER_GPIO_01 is not enabled in the device tree");
BUILD_ASSERT(DT_NODE_HAS_STATUS(USER_GPIO_02, okay), "USER_GPIO_02 is not enabled in the device tree");
BUILD_ASSERT(DT_NODE_HAS_STATUS(USER_GPIO_03, okay), "USER_GPIO_03 is not enabled in the device tree");
BUILD_ASSERT(DT_NODE_HAS_STATUS(USER_GPIO_04, okay), "USER_GPIO_04 is not enabled in the device tree");

/* Device existence checks */
BUILD_ASSERT(DT_NODE_EXISTS(USER_GPIO_01), "USER_GPIO_01 device node does not exist");
BUILD_ASSERT(DT_NODE_EXISTS(USER_GPIO_02), "USER_GPIO_02 device node does not exist");
BUILD_ASSERT(DT_NODE_EXISTS(USER_GPIO_03), "USER_GPIO_03 device node does not exist");
BUILD_ASSERT(DT_NODE_EXISTS(USER_GPIO_04), "USER_GPIO_04 device node does not exist");

/* Declare device bindings */
extern const struct device *user_gpio_01_dev;
extern const struct device *user_gpio_02_dev;
extern const struct device *user_gpio_03_dev;
extern const struct device *user_gpio_04_dev;

/* Declare the GPIO specification using the device tree */
extern const struct gpio_dt_spec user_gpio_01_dt_spec;
extern const struct gpio_dt_spec user_gpio_02_dt_spec;
extern const struct gpio_dt_spec user_gpio_03_dt_spec;
extern const struct gpio_dt_spec user_gpio_04_dt_spec;
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
/* Function to check device readiness */
bool check_gpio_devices_ready(void);

/* Function to configure GPIO pins */
void configure_gpio_pins(void);

/* Function to initialize GPIO */
void init_gpio(void);
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
/* Define a struct for GPIO device and pin */
struct gpio_info {
    const struct device *dev;
    gpio_pin_t pin;
};

#define CONFIGURE_GPIO(index) gpio_pin_configure(user_gpio_##index##_dev, USER_GPIO_##index##_PIN, USER_GPIO_##index##_FLAGS)
#define SET_GPIO(index) gpio_pin_set(user_gpio_##index##_dev, USER_GPIO_##index##_PIN, 1)
#define CLEAR_GPIO(index) gpio_pin_set(user_gpio_##index##_dev, USER_GPIO_##index##_PIN, 0)
#define TOGGLE_GPIO(index) gpio_pin_toggle(user_gpio_##index##_dev, USER_GPIO_##index##_PIN)
//--------------------------------------------------------------------------