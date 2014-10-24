## What is this?

C++11 introduced [native type-safe enums](http://en.wikipedia.org/wiki/C%2B%2B11#Strongly_typed_enumerations), which are defined using the keywords `enum class`. Unlike regular C++ enums, these cannot be implicitly converted to the underlying integral type. However, these do not support iteration in a robust way.

`enum.h` provides an interface for a type-safe, iterable enumeration class.

## How do I use it?

Using this class is dead easy; simply create your own enumeration class which inherits from it, and which contains its enum values as public static const members. Then, in the corresponding .cc file, call the INIT_ENUM(your_class_name_here) macro, and initialize each member with the integer value used to sort them.

An example of this is shown in `color.h` & `color.cc`.

## How does it work?

Values of the enumeration are static instances of the derived class, and support iteration through a private static set containing pointers to these instances. The enum values are sorted by the integer values supplied to them during initialization. The set can be accessed using public const iterators which are members of the base class.

Additionally, `enum.h` supports the creation of a subset of the enum values. BuildSubset takes an initializer list of members, and can be traversed using the range-based `for` syntax introduced in C++11.
