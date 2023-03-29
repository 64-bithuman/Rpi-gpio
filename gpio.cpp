#include "gpio.h"
extern "C"
{
#include "bcm2835.h"
}
using namespace std;
uint8_t gpio_func[54]; // Array to store exported GPIOs
string exp1 = "/sys/class/gpio/export";
string unexp1 = "/sys/class/gpio/unexport";
void GPIO_FUNC(uint8_t gpio, string function)
{
    if (function == "out" || function == "OUT")
    {
        bcm2835_gpio_fsel(gpio, BCM2835_GPIO_FSEL_OUTP);
    }
    if (function == "in" || function == "IN")
    {
        bcm2835_gpio_fsel(gpio, BCM2835_GPIO_FSEL_INPT);
    }
}
void GPIO_ON(uint8_t gpio)
{
    bcm2835_gpio_write(gpio, HIGH);
}
void GPIO_OFF(uint8_t gpio)
{
    bcm2835_gpio_write(gpio, LOW);
}
void READ_GPIO(uint8_t gpio, int &value)
{
    value = bcm2835_gpio_lev(gpio);
}
