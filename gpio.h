#ifndef GPIO_H
#define GPIO_H
#include <fstream>
#include <string>
static uint8_t index_u;
static bool first_time = true;
void GPIO_FUNC(uint8_t gpio, std::string function);
void GPIO_ON(uint8_t gpio);
void GPIO_OFF(uint8_t gpio);
void GPIO_CLR(uint8_t gpio);
void GPIO_CLR_ALL();
long READ_GPIO(uint8_t gpio);
#endif