#include "Morse.h"
#include <arduino.h>

Morse::Morse(void (*onDot)(), void (*onDash)() )
{
  dotFunction = onDot;
  dashFunction = onDash;
  if (!morseChars.empty())
    return; //It is actually initialized, so lets not do it again.

  /*
    1. The length of a dot is one unit.
    2. A dash is three units.
    3. The space between parts of the same letter is one unit.
    4. The space between letters is three units.
    5. The space between words is seven units.
  */

  morseChars['a'][0] = 2;
  morseChars['b'][0] = 4;
  morseChars['c'][0] = 4;
  morseChars['d'][0] = 3;
  morseChars['e'][0] = 1;
  morseChars['f'][0] = 4;
  morseChars['g'][0] = 3;
  morseChars['h'][0] = 4;
  morseChars['i'][0] = 2;
  morseChars['j'][0] = 4;
  morseChars['k'][0] = 3;
  morseChars['l'][0] = 4;
  morseChars['m'][0] = 2;
  morseChars['n'][0] = 2;
  morseChars['o'][0] = 3;
  morseChars['p'][0] = 4;
  morseChars['q'][0] = 4;
  morseChars['r'][0] = 3;
  morseChars['s'][0] = 3;
  morseChars['t'][0] = 1;
  morseChars['u'][0] = 4;
  morseChars['v'][0] = 4;
  morseChars['w'][0] = 3;
  morseChars['x'][0] = 4;
  morseChars['y'][0] = 4;
  morseChars['z'][0] = 4;

  morseChars['1'][0] = 5;
  morseChars['2'][0] = 5;
  morseChars['3'][0] = 5;
  morseChars['4'][0] = 5;
  morseChars['5'][0] = 5;
  morseChars['6'][0] = 5;
  morseChars['7'][0] = 5;
  morseChars['8'][0] = 5;
  morseChars['9'][0] = 5;
  morseChars['0'][0] = 5;

  morseChars['a'][1] = B01000000;
  morseChars['b'][1] = B10000000;
  morseChars['c'][1] = B10100000;
  morseChars['d'][1] = B10000000;
  morseChars['e'][1] = B00000000;
  morseChars['f'][1] = B00100000;
  morseChars['g'][1] = B11000000;
  morseChars['h'][1] = B00000000;
  morseChars['i'][1] = B00000000;
  morseChars['j'][1] = B01110000;
  morseChars['k'][1] = B10100000;
  morseChars['l'][1] = B01000000;
  morseChars['m'][1] = B11000000;
  morseChars['n'][1] = B10000000;
  morseChars['o'][1] = B11100000;
  morseChars['p'][1] = B01100000;
  morseChars['q'][1] = B11010000;
  morseChars['r'][1] = B01000000;
  morseChars['s'][1] = B00000000;
  morseChars['t'][1] = B10000000;
  morseChars['u'][1] = B00100000;
  morseChars['v'][1] = B00010000;
  morseChars['w'][1] = B01100000;
  morseChars['x'][1] = B10010000;
  morseChars['y'][1] = B10110000;
  morseChars['z'][1] = B11000000;

  morseChars['1'][1] = B01111000;
  morseChars['2'][1] = B00111000;
  morseChars['3'][1] = B00011000;
  morseChars['4'][1] = B00001000;
  morseChars['5'][1] = B00000000;
  morseChars['6'][1] = B10000000;
  morseChars['7'][1] = B11000000;
  morseChars['8'][1] = B11100000;
  morseChars['9'][1] = B11110000;
  morseChars['0'][1] = B11111000;

}

void Morse::print(String str) {
  for (int i = 0; i < str.length(); i++)
  {
    if (isspace (str[i]))
    {
      delay(unit * 4);
      //because there is alway 3 units after each letter, when a space comes, I just add 3 units (total=7)
    }
    else {
      //emitt character
      emmitMorse(str[i]);
      delay(unit * 2); //Because emmitMorse adds an the separation delay of 1 unit, I just need to add 2 (total=3)
    }

  }
}

void inline Morse::emmitMorse(char letter) {
  for (int i = 0; i < morseChars[letter][0]; i++)
  {
    //digitalWrite(pin, on);

    if ((morseChars[letter][1] >> 7 - i) & 1)
    {
      //delay(unit * 3); //Show a dash
      dashFunction();

    }
    else
    {
      //delay(unit); //Show a dot.
      dotFunction();
    }

    //digitalWrite(pin, off);
    delay(unit);
  }
}
