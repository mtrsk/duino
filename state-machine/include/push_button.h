#include <Arduino.h>

class PushButton
{
    private:
        byte pin;
        byte state;
    public:
        PushButton(byte pin);

        void init();

        byte readState();
};
