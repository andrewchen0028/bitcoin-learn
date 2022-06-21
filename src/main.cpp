#include <iostream>

#include "fieldelement.hpp"

// TODO: Move tests into dedicated test suite.
int main() {
  {
    FieldElement a(2, 31);
    FieldElement b(2, 31);
    FieldElement c(15, 31);
    assert(a == b);
    assert(a != c);
    assert(!(a != b));

    std::cout << "Checkpoint: operator== and operator!=\n";
  }

  {
    FieldElement a(2, 31);
    FieldElement b(15, 31);
    assert(a + b == FieldElement(17, 31));

    FieldElement c(17, 31);
    FieldElement d(21, 31);
    assert(c + d == FieldElement(7, 31));

    std::cout << "Checkpoint: operator+\n";
  }

  {
    FieldElement a(29, 31);
    FieldElement b(4, 31);
    assert(a - b == FieldElement(25, 31));

    FieldElement c(15, 31);
    FieldElement d(30, 31);
    assert(c - d == FieldElement(16, 31));

    std::cout << "Checkpoint: operator-\n";
  }

  {
    FieldElement a(24, 31);
    FieldElement b(19, 31);
    assert(a * b == FieldElement(22, 31));

    std::cout << "Checkpoint: operator* [field]\n";
  }

  {
    FieldElement a(24, 31);
    uint b = 2;
    assert(b * a == a + a);

    std::cout << "Checkpoint: operator* [scalar]\n";
  }

  {
    FieldElement a(17, 31);
    assert(a.pow(3) == FieldElement(15, 31));

    FieldElement b(5, 31);
    FieldElement c(18, 31);
    assert(b.pow(5) * c == FieldElement(16, 31));

    std::cout << "Checkpoint: FieldElement::pow()\n";
  }

  {
    FieldElement a(3, 31);
    FieldElement b(24, 31);
    assert(a / b == FieldElement(4, 31));

    FieldElement c(17, 31);
    assert(c.pow(-3) == FieldElement(29, 31));

    FieldElement d(4, 31);
    FieldElement e(11, 31);
    assert(d.pow(-4) * e == FieldElement(13, 31));

    std::cout << "Checkpoint: operator/\n";
  }

  return 0;
}