# Messenger
A Mono Task for typing messages with a phone-like keypad.

## Building options

To enable SD filesystem to be mounted at "/sd":

    make -e SDFS=true clean all

To build with C++11 support:

    make -e C11=true clean all

Both switches can be combined to build with SDFS and C++ 11.