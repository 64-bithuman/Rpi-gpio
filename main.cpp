#include "gpio.h"
#include <iostream>
using namespace std;
string com;
string mode;
int gpio;
void pinout();
int main()
{
    cout << "IOcontrol for Raspberry Pi. Copyright (c) Vinuda Liyanage 2023\n";
    cout << "To view a list of available commands and how to use them, type in help and press enter.\n";
    cout << "NOTE: All commands require the GPIO number of corresponding to the pin number\n";
    cout << "To view the GPIO numbers for each pin, enter pinout\n";
    cout << "To exit this program, enter #exit\n";
    while (true)
    {
    a:
        cin.clear();
        fflush(stdin);
        cout << endl
             << "Enter command > ";
        cin >> com >> gpio >> mode;
        cin.clear();
        fflush(stdin);
        if (com == "pinout")
        {
            pinout();
        }
        if (com == "set")
        {
            if (gpio > 26)
            {
                cout << "Error: Invalid GPIO pin\n";
                goto a;
            }
            if (mode == "read")
            {
                cout << READ_GPIO(gpio) << endl;
            }
            else if (mode == "on" || mode == "ON")
            {
                GPIO_ON(gpio);
            }
            else if (mode == "off" || mode == "OFF")
            {
                GPIO_OFF(gpio);
            }
            else
            {
                cout << "Error: Invalid use of 'set' command. Enter -help for command usage info.\n";
            }
        }
        if (com == "config")
        {
            if (gpio > 26)
            {
                cout << "Error: Invalid GPIO pin\n";
                goto a;
            }
            if (mode == "in" || mode == "out")
            {
                GPIO_FUNC(gpio, mode);
            }
            else
            {
                cout << "Error: Invalid use of 'config' command. Enter -help for command usage info.\n";
            }
        }
        if (com == "clearall")
        {
            GPIO_CLR_ALL();
            cout << "All GPIO pins have been cleared.\n";
        }
        if (com == "clear")
        {
            if (gpio > 26)
            {
                cout << "Error: Invalid GPIO pin\n";
                goto a;
            }
            GPIO_CLR(gpio);
        }
        if (com == "#exit")
        {
            exit(0);
        }
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