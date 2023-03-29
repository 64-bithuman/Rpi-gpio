#include "gpio.h"
#include <iostream>
extern "C"
{
#include "bcm2835.h"
}
using namespace std;
string com;
string mode;
int gpio;
int gpio_val;
void pinout();
void commands();
int main()
{
    cout << "IOcontrol for Raspberry Pi. Copyright (c) Vinuda Liyanage 2023\n";
    cout << "To view a list of available commands and how to use them, type in 'help 0 0' without quotes and press enter.\n";
    cout << "NOTE: All commands require the GPIO number of corresponding to the pin number\n";
    cout << "To view the GPIO numbers for each pin, enter pinout 0 0\n";
    cout << "To exit this program, enter #exit 0 0\n";
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
        cin >> com >> gpio >> mode;
        cin.clear();
        fflush(stdin);
        if (com == "pinout")
        {
            pinout();
        }
        if (com == "set")
        {
            if (gpio > 40 || gpio < 0)
            {
                cout << "Error: Invalid GPIO pin\n";
                goto a;
            }
            if (mode == "read")
            {
                READ_GPIO(gpio, gpio_val);
                cout << gpio_val << endl;
            }
            else if (mode == "on" || mode == "ON")
            {
                GPIO_ON(gpio);
                cout << "GPIO " << gpio << " has been pulled to HIGH\n";
            }
            else if (mode == "off" || mode == "OFF")
            {
                GPIO_OFF(gpio);
                cout << "GPIO " << gpio << " has been pulled to LOW\n";
            }
            else
            {
                cout << "Error: Invalid use of 'set' command. Enter -help for command usage info.\n";
            }
        }
        if (com == "config")
        {
            if (gpio > 40 || gpio < 0)
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
        if (com == "#exit")
        {
            bcm2835_close();
            exit(0);
        }
        if(com == "help"){
            commands();
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
void commands(){
cout << "\n1. config n p : This command configures the gpio number n to either 'in' (input) or 'out' (output) as indicated by p.\n";
cout << "2. set n p : This command sets the gpio n to either 'read' (read gpio), 'on' (turn gpio on) or 'off' (turn gpio off) as indicated by p.\n";
cout << "3. #exit n n : This command exits the program; n can be any value.\n";
cout << "4. pinout : This command shows a list of pins and their corresponding GPIO numbers.\n";
cout << "5. help n n : This command shows a list of available commands and their usage. n can be any value.\n";
}