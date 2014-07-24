#include "color.h"
#include "enum.h"

template<>
typename Enum<Color>::ItemsSet Enum<Color>::items_{};

const Color Color::blue(0);
const Color Color::green(1);
const Color Color::red(2);
const Color Color::white(3);
const Color Color::yellow(4);
const Color Color::multicolor(5);
const Color Color::hidden(7);
