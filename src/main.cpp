#include <iostream>

#include "fieldelement.hpp"

int main() {
  FieldElement a(2, 11);
  FieldElement b(4, 11);

  assert(a == a);
  std::cout << "Checkpoint: operator==\n";

  assert(a != b);
  std::cout << "Checkpoint: operator!=\n";

  assert(a + a == b);
  std::cout << "Checkpoint: operator+\n";

  assert(b + b + b == FieldElement(1, 11));
  std::cout << "Checkpoint: operator+ (wrapped)\n";

  return 0;
}