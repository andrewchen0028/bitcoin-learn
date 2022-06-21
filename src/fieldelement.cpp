#include "fieldelement.hpp"

#include <stdexcept>

using namespace boost::multiprecision;

FieldElement::FieldElement(uint256_t number, uint256_t characteristic) {
  // `number` and `characteristic` are both type uint (positive).
  // Check that `number` is in range [0, characteristic).
  if (number >= characteristic) {
    throw std::invalid_argument(
        "Received field element with number greater than or equal to "
        "characteristic");
  }

  m_number = number;
  m_characteristic = characteristic;
}

std::ostream& operator<<(std::ostream& os, const FieldElement& fe) {
  // Display field element characteristic and number.
  return os << "FieldElement_" << fe.getCharacteristic() << "("
            << fe.getNumber() << ")";
}

FieldElement& FieldElement::operator+=(const FieldElement& rhs) {
  // Throw exception if characteristics are different.
  if (this->getCharacteristic() != rhs.getCharacteristic()) {
    throw std::invalid_argument(
        "Cannot add elements of different characteristic");
  }

  // Modular-add rhs.
  this->m_number += rhs.getNumber();
  this->m_number %= this->m_characteristic;
  return *this;
}

FieldElement& FieldElement::operator-=(const FieldElement& rhs) {
  // Throw exception if characteristics are different.
  if (this->getCharacteristic() != rhs.getCharacteristic()) {
    throw std::invalid_argument(
        "Cannot subtract elements of different characteristic");
  }

  // Modular-subtract rhs.
  if (this->m_number >= rhs.getNumber()) {
    this->m_number -= rhs.getNumber();
  } else {
    this->m_number = this->m_characteristic - rhs.getNumber() + this->m_number;
  }
  return *this;
}

FieldElement operator+(FieldElement lhs, const FieldElement& rhs) {
  lhs += rhs;  // Reuse compound assignment.
  return lhs;  // Return the result by value (uses move constructor).
};

FieldElement operator-(FieldElement lhs, const FieldElement& rhs) {
  lhs -= rhs;  // Reuse compound assignment.
  return lhs;  // Return the result by value (uses move constructor).
};

bool operator==(const FieldElement& lhs, const FieldElement& rhs) {
  // Characteristic and number must both be equal.
  return lhs.getNumber() == rhs.getNumber() &&
         lhs.getCharacteristic() == rhs.getCharacteristic();
};

bool operator!=(const FieldElement& lhs, const FieldElement& rhs) {
  return !(lhs == rhs);
};
