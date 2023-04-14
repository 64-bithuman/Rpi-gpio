#include "gpio.h"
#include <iostream>
#include <string.h>
#include <string>
extern "C"
{
#include "bcm2835.h"
}
using namespace std;
static char *com = NULL;
static char *mode = NULL;
const char *delimeter = " ";
char input[100];
const int size = 100;
static int gpio;
static int gpio_val;
void pinout();
void commands();
void process_input();
int main()
{
    cout << "IOcontrol v1.0.1 for Raspberry Pi. Copyright (c) Vinuda Liyanage 2023\n";
    cout << "To view a list of available commands and how to use them, type in 'help' without quotes and press enter.\n";
    cout << "NOTE: All commands require the GPIO number of corresponding to the pin number\n";
    cout << "To view the GPIO numbers for each pin, enter pinout.\n";
    cout << "To exit this program, enter #exit.\n";
    if (!bcm2835_init())
    {
        cout << "Unable to open /dev/mem. Access denied." << endl;
        return 1;
    }
    while (true)
    {
    a:
        cin.clear();
        fflush(stdin);
        cout << endl
             << "Enter command > ";
        cin.getline(input, 100);
        fflush(stdin);
        process_input();
        if (com != NULL)
        {
            if (strcmp(com, "pinout") == 0)
            {
                pinout();
            }
            if (strcmp(com, "set") == 0)
            {
                if (gpio > 40 || gpio < 0)
                {
                    cout << "Error: Invalid GPIO pin\n";
                    goto a;
                }
                if (mode == NULL)
                {
                    cout << "Error: Invalid use of 'set' command. Enter -help for command usage info.\n";
                    goto a;
                }

                if (strcmp(mode, "read") == 0)
                {
                    READ_GPIO(gpio, gpio_val);
                    cout << gpio_val << endl;
                }
                else if (strcmp(mode, "on") == 0 || strcmp(mode, "ON") == 0)
                {
                    GPIO_ON(gpio);
                    cout << "GPIO " << gpio << " has been pulled to HIGH\n";
                }
                else if (strcmp(mode, "off") == 0 || strcmp(mode, "ON") == 0)
                {
                    GPIO_OFF(gpio);
                    cout << "GPIO " << gpio << " has been pulled to LOW\n";
                }
                else
                {
                    cout << "Error: Invalid use of 'set' command. Enter -help for command usage info.\n";
                }
            }

            if (strcmp(com, "config") == 0)
            {
                if (mode == NULL)
                {
                    cout << "Error: Invalid use of 'config' command. Enter -help for command usage info.\n";
                    goto a;
                }

                if (gpio > 40 || gpio < 0)
                {
                    cout << "Error: Invalid GPIO pin\n";
                    goto a;
                }
                if (strcmp(mode, "in") == 0 || strcmp(mode, "out") == 0)
                {
                    GPIO_FUNC(gpio, mode);
                    cout << "GPIO " << gpio << " has been configured for " << mode << "put\n";
                }
                else
                {
                    cout << "Error: Invalid use of 'config' command. Enter -help for command usage info.\n";
                }
            }

            if (strcmp(com, "#exit") == 0)
            {
                bcm2835_close();
                exit(0);
            }
            if (strcmp(com, "help") == 0)
            {
                commands();
            }
        }
    }
}
void process_input()
{
    char *gpio_str;
    com = strtok(input, delimeter);
    if (com != NULL)
    {
        if (strcmp(com, "config") == 0 || strcmp(com, "set") == 0)
        {
            gpio_str = strtok(0, delimeter);
            if (gpio_str != NULL)
            {
                gpio = strtol(gpio_str, NULL, 10);
            }
            mode = strtok(0, delimeter);
            if (mode == NULL)
            {
                puts("Error: Invalid input!");
            }
        }
    }
    else
    {
        puts("Error: Invalid input!");
    }
}
void pinout()
{
    cout << "Pin number:   GPIO\n";
    cout << "1: 3v3 power\n";
    cout << "2: 5v power\n";
    cout << "3: GPIO 2 (SDA)\n";
    cout << "4: 3v3 power\n";
    cout << "5: GPIO 3\n";
    cout << "6: Ground\n";
    cout << "7: GPIO 4 (GPCLK0)\n";
    cout << "8: GPIO 14 (TXD)\n";
    cout << "9: Ground\n";
    cout << "10: GPIO 15 (RXD)\n";
    cout << "11: GPIO 17\n";
    cout << "12: GPIO 8 (PCM_CLK)\n";
    cout << "13: GPIO 27\n";
    cout << "14: Ground\n";
    cout << "15: GPIO 22\n";
    cout << "16: GPIO 23\n";
    cout << "17: 3v3 power\n";
    cout << "18: GPIO 24\n";
    cout << "19: GPIO 10 (MOSI)\n";
    cout << "20: Ground\n";
    cout << "21: GPIO 9 (MISO)\n";
    cout << "22: GPIO 25\n";
    cout << "23: GPIO 11 (SCLK)\n";
    cout << "24: GPIO 8 (CE0)\n";
    cout << "25: Ground\n";
    cout << "26: GPIO 7 (CE1)\n";
    cout << "27: GPIO 0 (ID_SD)\n";
    cout << "28: GPIO 1 (ID_SC)\n";
    cout << "29: GPIO 5\n";
    cout << "30: Ground\n";
    cout << "31: GPIO 6\n";
    cout << "32: GPIO 12 (PWM0)\n";
    cout << "33: GPIO 13 (PWM1)\n";
    cout << "34: Ground\n";
    cout << "35: GPIO 19 (PCM_FS)\n";
    cout << "36: GPIO 16\n";
    cout << "37: GPIO26\n";
    cout << "38: GPIO 20 (PCM_DIN)\n";
    cout << "39: Ground\n";
    cout << "40: GPIO 21 (PCM_DOUT)\n";
}
void commands()
{
    cout << "\n1. config n p : This command configures the gpio number n to either 'in' (input) or 'out' (output) as indicated by p.\n";
    cout << "2. set n p : This command sets the gpio n to either 'read' (read gpio), 'on' (turn gpio on) or 'off' (turn gpio off) as indicated by p.\n";
    cout << "3. #exit : This command exits the program.\n";
    cout << "4. pinout : This command shows a list of pins and their corresponding GPIO numbers.\n";
    cout << "5. help : This command shows a list of available commands and their usage.\n";
}