#ifndef _MORSE_H_
#define _MORSE_H_

#include <arduino.h>
#include <map>

#define DEFAULT_UNIT_LENGTH 500

/*
  1. The length of a dot is one unit.
  2. A dash is three units.
  3. The space between parts of the same letter is one unit.
  4. The space between letters is three units.
  5. The space between words is seven units.
*/

class Morse
{
  public:
    std::map<char, byte[2]> morseChars;
    int unit = DEFAULT_UNIT_LENGTH;

    Morse(void (*onDot)(), void (*onDash)() );
    void print(String str);

  private:
    void (*dotFunction)();
    void (*dashFunction)();
    void inline emmitMorse(char letter);

};

#endif
