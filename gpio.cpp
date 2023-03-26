#include "gpio.h"
using namespace std;
uint8_t gpio_func[54]; // Array to store exported GPIOs
ofstream export_f;     // File object for GPIO pin export
ofstream unexport_f;   // File object for GPIO pin unexport
ofstream gpio_set;     // File object to set GPIO pin to ON/OFF
ifstream gpio_read;    // File object to read from GPIO pin
string exp1 = "/sys/class/gpio/export";
string unexp1 = "/sys/class/gpio/unexport";
void GPIO_FUNC(uint8_t gpio, string function)
{
    string gpio_str = gpio + "";
    if (first_time == true)
    { // Set index to 0 if function is executed for the first time.
        index_u = 0;
    }
    if (first_time == false)
    { // Add one to index if function is not executed for the first time.
        index_u++;
    }
    for (int i = 0; i < 54; i++)
    { //"for" loop to check if the pin to be exported is already in the exported pins array.
        uint8_t pin = gpio_func[i];
        if (pin == gpio)
        {
            unexport_f.open(unexp1.c_str());
            unexport_f << gpio;
            unexport_f.close();
            gpio_func[i] = 90; // Remove GPIO from exported list.
        }
    }
    gpio_func[index_u] = gpio; // If pin is not already exported, write pin to exported pins list.
    export_f.open(exp1.c_str());
    export_f << gpio;
    export_f.close();
    first_time = false;
    string setdir1 = "/sys/class/gpio/gpio" + gpio;
    string setdir2 = setdir1 + "/direction";
    gpio_set.open(setdir2.c_str());
    gpio_set << function;
    gpio_set.close();
}
void GPIO_ON(uint8_t gpio)
{
    string setdir1 = "/sys/class/gpio/gpio" + gpio;
    string setdir2 = setdir1 + "/value";
    gpio_set.open(setdir2.c_str());
    gpio_set << 1;
    gpio_set.close();
}
void GPIO_OFF(uint8_t gpio)
{
    string setdir1 = "/sys/class/gpio/gpio" + gpio;
    string setdir2 = setdir1 + "/value";
    gpio_set.open(setdir2.c_str());
    gpio_set << 0;
    gpio_set.close();
}
void GPIO_CLR(uint8_t gpio)
{
    unexport_f.open(unexp1.c_str());
    unexport_f << gpio;
    unexport_f.close();
}
void GPIO_CLR_ALL()
{
    for (int i = 0; i < 54; i++)
    {
        if (gpio_func[i] != 90)
        {
            GPIO_CLR(gpio_func[i]);
        }
    }
}
long READ_GPIO(uint8_t gpio)
{
    string setdir1 = "/sys/class/gpio/gpio" + gpio;
    string setdir2 = setdir1 + "/value";
    gpio_read.open(setdir2.c_str());
    long l;
    gpio_read >> l;
    return l;
}
