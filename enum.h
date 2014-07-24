#ifndef ENUM_H_
#define ENUM_H_

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <set>

template <class T>
class Enum {
 private:
  // Comparator used to determine enum item ordering
  struct EnumLTComparator {
    bool operator() (const T* e1, const T* e2) {
      return e1->value() < e2->value();
    }
  };

 public:
  typedef std::set<const T*, EnumLTComparator> ItemsSet;
  typedef typename ItemsSet::size_type set_size_type;
  typedef typename ItemsSet::const_iterator const_iterator;
  typedef typename ItemsSet::const_reverse_iterator const_r_iterator;

  int value() const { return value_; }
  static set_size_type size() { return items_.size(); }

  // Iteration
  static const_iterator begin() { return items_.cbegin(); }
  static const_iterator end() { return items_.cend(); }
  static const_r_iterator rbegin() { return items_.crbegin(); }
  static const_r_iterator rend() { return items_.crend(); }

  bool operator== (T e2) const {return this->value() == e2.value();}

  // Return a set which contains pointers to any number of unique enum items
  static ItemsSet Subset(std::initializer_list<T> items) {
    ItemsSet subset;
    for (auto i: items) {
      subset.insert(CorrespondingEnum(i.value()));
    }
    return subset;
  }

 protected:
  // Constructors
  explicit Enum(int value): value_(value) {
    // Warn clients if they try to add multiple items with the same value
    if (IsValidValue(value)) {
      std::cerr << "The value \'" << value << "\' has been assigned to "
                << "multiple items in this enum. All duplicates are omitted "
                << "from the set." << std::endl;
      return;
    }

    // This cast seems ugly, since the object being constructed by the
    //   inheriting class will already be of type T, but I don't see any
    //   way around this.
    items_.insert(static_cast<T*>(this));
  }
  // Compiler-generated copy and copy-assign ctors generate local copies of
  //   the static enum items

 private:
  static const T* CorrespondingEnum(int value) {
    auto EnumPredicateCorresponds = [value](const T* elem) -> bool {
      return elem->value() == value;
    };

    const_iterator it = find_if(items_.begin(),
                                items_.end(),
                                EnumPredicateCorresponds);

    return (it != items_.end()) ? *it : nullptr;
  }
  static bool IsValidValue(int value) {
    return CorrespondingEnum(value) != nullptr;
  }

  int value_;
  static ItemsSet items_;
};

#endif
