#include <iostream>

#include "fieldelement.hpp"

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

  // {  a = FieldElement(3, 31);
  //   b = FieldElement(24, 31);
  //   self.assertEqual(a / b, FieldElement(4, 31));
  //   a = FieldElement(17, 31);
  //   self.assertEqual(a**-3, FieldElement(29, 31));
  //   a = FieldElement(4, 31);
  //   b = FieldElement(11, 31);
  //   self.assertEqual(a**-4 * b, FieldElement(13, 31));
  //   std::cout << "Checkpoint: operator/\n";}

  return 0;
}