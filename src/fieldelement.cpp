#include "fieldelement.hpp"

#include <stdexcept>

using namespace boost::multiprecision;

FieldElement::FieldElement(uint256_t number, uint256_t characteristic) {
  // `number` and `characteristic` are both positive.
  // Check that `number` is in range [0, characteristic).
  if (number >= characteristic) {
    throw std::invalid_argument(
        "Received field element with number greater than or equal to "
        "characteristic");
  }

  m_number = number;
  m_characteristic = characteristic;
}

std::ostream& operator<<(std::ostream& os, FieldElement const& fe) {
  // Display field element characteristic and number.
  return os << "FieldElement_" << fe.getCharacteristic() << "("
            << fe.getNumber() << ")";
}

bool operator==(const FieldElement& lhs, const FieldElement& rhs) {
  // Characteristic and number must both be equal.
  return lhs.getNumber() == rhs.getNumber() &&
         lhs.getCharacteristic() == rhs.getCharacteristic();
};

bool operator!=(const FieldElement& lhs, const FieldElement& rhs) {
  return !(lhs == rhs);
};

FieldElement operator+(const FieldElement& lhs, const FieldElement& rhs) {
  // Throw exception if characteristics are different.
  if (lhs.getCharacteristic() != rhs.getCharacteristic()) {
    throw std::invalid_argument(
        "Field addition undefined for elements of different characteristic");
  }

  // Add element numbers with characteristic modulus.
  return FieldElement(
      (lhs.getNumber() + rhs.getNumber()) % lhs.getCharacteristic(),
      lhs.getCharacteristic());
};