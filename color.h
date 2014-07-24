#ifndef COLOR_H_
#define COLOR_H_

#include "enum.h"

class Color: public Enum<Color> {
 public:
  using Enum::Enum;

  static const Color blue;
  static const Color green;
  static const Color red;
  static const Color white;
  static const Color yellow;
  static const Color multicolor;
  static const Color hidden;

};

#endif
