#include <iostream>
#include <numeric>

namespace my_math
{
  class Frac final
  {
  private:

    long ntor_;
    uint dtor_;

  public:

    Frac ( long ntor, long dtor = 1u );
    Frac ( const Frac & f ) = default;
    Frac ( Frac && f ) = default;

    Frac & operator= ( const Frac & f ) = default;
    Frac & operator= ( Frac && f ) = default;

    ~Frac ( ) = default;

    long numerator ( ) const;
    uint denomerator ( ) const;

    bool is_eq ( const Frac & f) const;

    Frac operator- ( ) const;
    Frac & operator+= ( const Frac & f );
    Frac & operator-= ( const Frac & f );
    Frac & operator*= ( const Frac & f );
    Frac & operator/= ( const Frac & f );
  };

  bool operator== ( const Frac & lhs, const Frac & rhs );
  bool operator!= ( const Frac & lhs, const Frac & rhs );

  Frac operator+ ( const Frac & lhs, const Frac & rhs );
  Frac operator- ( const Frac & lhs, const Frac & rhs );
  Frac operator* ( const Frac & lhs, const Frac & rhs );
  Frac operator/ ( const Frac & lhs, const Frac & rhs );

  std::ostream & operator<< (const std::ostream & ost, const Frac & f );


  //! Methods realisations


  /**
   * @brief Frac class constructor
   * @param ntor
   * @param dtor
   */
  Frac::Frac ( long ntor, long dtor /* = 1u */ )
  {
    int sign = 1;

    if (dtor == 0)
      throw std::runtime_error("Denomerator = 0");
    else if (dtor < 0)
      sign = -1;

    auto gcd = std::gcd(ntor, dtor);

    ntor_ = sign * ntor / gcd;
    dtor_ = sign * dtor / gcd;
  }

  /**
   * @brief Numerator getter
   * @return .ntor_ val
   */
  long Frac::numerator ( ) const
  { return ntor_; }

  /**
   * @brief denomerator getter
   * @return .dtor_ val
   */
  uint Frac::denomerator ( ) const
  { return dtor_; }

  /**
   * @brief unary minus operator
   * @return minus itself
   */
  Frac Frac::operator- ( ) const
  { return Frac{-ntor_, dtor_}; }

  /**
   * @brief Checking if two fractions are equal
   * @param f
   * @return true or false
   */
  bool Frac::is_eq ( const Frac & f ) const
  { return ntor_ == f.ntor_ && dtor_ == f.dtor_; }

  /**
   * @brief add f to current fraction
   * @param f
   * @return new itself
   */
  Frac & Frac::operator+= ( const Frac & f )
  {
    ntor_ = ntor_ * f.dtor_ + f.ntor_ * dtor_;
    dtor_ *= f.dtor_;
    
    auto gcd = std::gcd(ntor_, dtor_);

    ntor_ /= gcd;
    dtor_ /= gcd;

    return *this;
  }

  /**
   * @brief sub f from current fraction
   * @param f
   * @return new itself
   */
  Frac & Frac::operator-= ( const Frac & f )
  {
    operator+= (-f);
    return *this;
  }

  /**
   * @brief mul current fraction by f
   * @param f
   * @return new itself
   */
  Frac & Frac::operator*= ( const Frac & f )
  {
    ntor_ *= f.ntor_;
    dtor_ *= f.dtor_;

    auto gcd = std::gcd(ntor_, dtor_);

    ntor_ /= gcd;
    dtor_ /= gcd; 

    return *this;
  }

  /**
   * @brief div current fraction by f
   * @param f
   * @return new itself
   */
  Frac & Frac::operator/= ( const Frac & f )
  {
    if (f.ntor_ == 0)
      throw std::runtime_error("Dividing by zero");

    int sign = (f.ntor_ < 0) ? -1 : 1;
    ntor_ *= sign * f.dtor_;
    dtor_ *= sign * f.ntor_;

    auto gcd = std::gcd(ntor_, dtor_);

    ntor_ /= gcd;
    dtor_ /= gcd; 

    return *this;
  }





   //! Outer methods' realisations



  /**
   * @brief is rhs equal to lhs
   * @param lhs
   * @param rhs
   * @return true or false
   */
  bool operator== ( const Frac & lhs, const Frac & rhs )
  { return Frac{lhs}.is_eq(rhs); }

  /**
   * @brief is not rhs equal to lhs
   * @param lhs
   * @param rhs
   * @return true or false
   */
  bool operator!= ( const Frac & lhs, const Frac & rhs )
  { return !Frac{lhs}.is_eq(rhs); }

  /**
   * @brief add two fractions
   * @param lhs
   * @param rhs
   * @return result of addition
   */
  Frac operator+ ( const Frac & lhs, const Frac & rhs )
  { return Frac{lhs} += rhs; }

  /**
   * @brief sub two fractions
   * @param lhs
   * @param rhs
   * @return result of sub
   */
  Frac operator- ( const Frac & lhs, const Frac & rhs )
  { return Frac{lhs} -= rhs; }

  /**
   * @brief mul two fractions
   * @param lhs
   * @param rhs
   * @return result of mul
   */
  Frac operator* ( const Frac & lhs, const Frac & rhs )
  { return Frac{lhs} *= rhs; }

  /**
   * @brief div two fractions
   * @param lhs
   * @param rhs
   * @return result of div
   */
  Frac operator/ ( const Frac & lhs, const Frac & rhs )
  { return Frac{lhs} /= rhs; }

  /**
   * @brief output operator
   * @param ost
   * @param f
   * @return output stream
   */
  std::ostream & operator<< ( std::ostream & ost, const Frac & f )
  {
    ost << f.numerator() << "/" << f.denomerator();
    return ost;
  }

}

