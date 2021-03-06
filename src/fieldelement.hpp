#ifndef FIELDELEMENT_HPP_
#define FIELDELEMENT_HPP_

#include <boost/multiprecision/cpp_int.hpp>

// TODO: This field element arithmetic is quite possibly broken, especially if
// uint256_t over/underflows are involved. Worth checking and fixing if
// necessary.
class FieldElement {
 private:
  boost::multiprecision::uint256_t m_number;
  boost::multiprecision::uint256_t m_characteristic;

 public:
  FieldElement(boost::multiprecision::uint256_t number,
               boost::multiprecision::uint256_t characteristic);

  boost::multiprecision::uint256_t getNumber() const { return m_number; }
  boost::multiprecision::uint256_t getCharacteristic() const {
    return m_characteristic;
  }

  FieldElement pow(int exp);

  FieldElement& operator+=(const FieldElement& rhs);
  FieldElement& operator-=(const FieldElement& rhs);
  FieldElement& operator*=(const FieldElement& rhs);
  FieldElement& operator/=(const FieldElement& rhs);
  friend FieldElement operator+(FieldElement lhs, const FieldElement& rhs);
  friend FieldElement operator-(FieldElement lhs, const FieldElement& rhs);
  friend FieldElement operator*(FieldElement lhs, const FieldElement& rhs);
  friend FieldElement operator/(FieldElement lhs, const FieldElement& rhs);
  friend FieldElement operator*(uint lhs, const FieldElement& rhs);
};

std::ostream& operator<<(std::ostream& os, const FieldElement& fe);

bool operator==(const FieldElement& lhs, const FieldElement& rhs);

bool operator!=(const FieldElement& lhs, const FieldElement& rhs);

#endif