## What is `enum.h`?

C++11 introduced [native type-safe enums](http://en.wikipedia.org/wiki/C%2B%2B11#Strongly_typed_enumerations), which are defined using the keywords `enum class`. Unlike regular C++ enums, these cannot be implicitly converted to the underlying integral type. However, these do not support iteration in a robust way.

`enum.h` provides an interface for a type-safe, iterable enumeration class.

## How do I use `enum.h`?

Using `enum.h` is dead easy; simply create your own enumeration class which inherits from it, and which contains its enum values as public static const members. Then, in the corresponding .cc file, call the INIT_ENUM(your_class_name_here) macro, and initialize each member with the integer value used to sort them.

An example of this is shown in `color.h` & `color.cc`.

## What functionality does `enum.h` provide?

Classes deriving from `enum.h` support iteration in a couple of ways:

The global set of all enumeration values can be iterated over using the const iterator access functions of `enum.h`. However, this syntax is unwieldy (as is most iterator syntax pre-C++11), especially since the iterators must be doubly dereferenced, as the global set contains *pointers* to the enum values.

The recommended way to iterate over enum values is to create your own (sub)set of them using the `BuildSubset` static member function. This function takes an initializer list of enum values, and can be traversed using the range-based `for` syntax introduced in C++11.

## How does `enum.h` work?

Values of the enumeration are static instances of the derived class, and support iteration through a private static set containing pointers to these instances. The enum values are sorted by the integer values supplied to them during initialization. The set can be accessed using public const iterators which are members of the base class.

## What dependencies does `enum.h` have?

`enum.h` has no dependencies, but requires a compiler supporting C++11 features.
