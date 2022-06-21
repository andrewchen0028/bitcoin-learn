#ifndef FIELDELEMENT_HPP_
#define FIELDELEMENT_HPP_

#include <boost/multiprecision/cpp_int.hpp>

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
};

std::ostream& operator<<(std::ostream& os, FieldElement const& fe);

bool operator==(const FieldElement& lhs, const FieldElement& rhs);

bool operator!=(const FieldElement& lhs, const FieldElement& rhs);

FieldElement operator+(const FieldElement& lhs, const FieldElement& rhs);

#endif