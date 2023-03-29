
#include <fstream>
#include <string>
#ifndef GPIO_H
#define GPIO_H

static uint8_t index_u;
static bool first_time = true;
void GPIO_FUNC(uint8_t gpio, std::string function);
void GPIO_ON(uint8_t gpio);
void GPIO_OFF(uint8_t gpio);
void READ_GPIO(uint8_t gpio, int &value);
#endif