# IOcontrol v1.0.1
Now with improved command processing and user input bug fixes.
This version supports reading bit values from GPIO pins and changing the state of GPIO pins (ON to OFF); but more functionality will be added in future releases. There are 5 available commands. Each of their functions are described below.

***
1. "config n p" : This command configures the gpio number n to either 'in' (input) or 'out' (output) as indicated by p.  
2. "set n p" : This command sets the gpio n to either 'read' (read gpio), 'on' (turn gpio on) or 'off' (turn gpio off) as indicated by p.  
3. "#exit" : This command exits the program.  
4. "pinout" : This command shows a list of pins and their corresponding GPIO numbers.  
5. "help" : This command shows a list of available commands and their usage.   
***Note: commands must be entered into the program without quotes.***
