echo "Build started."
echo "Compiling bcm2835.c ..."
gcc -c bcm2835.c
echo "Compiling main.cpp, gpio.cpp ..."
g++ -c main.cpp gpio.cpp
echo "Linking main.o, gpio.o, bcm2835.o to rpi-gpio ..."
g++ -o rpi-gpio main.o gpio.o bcm2835.o
rm *.o*
echo "Done."
