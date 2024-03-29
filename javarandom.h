#include <stdexcept>

#include <boost/cstdint.hpp>

using boost::int32_t;
using boost::int64_t;
using boost::uint64_t;

class JavaRandom
{
public:
  JavaRandom( int64_t seed = 0 )
  {
    setSeed(seed);
  }

  void setSeed( int64_t seed )
  {
    seed_ = (seed ^ INT64_C(0x5DEECE66D)) & ((INT64_C(1) << 48) - 1);
  }

  uint32_t next( int32_t bits )
  {
    seed_ = (seed_ * INT64_C(0x5DEECE66D) + INT64_C(0xB)) & 
        ((INT64_C(1) << 48) - 1);
    return (int32_t)(uint64_t(seed_) >> (48 - bits));
  }

  int32_t nextInt()
  {
    return next(32);
  }

  int32_t nextInt( int32_t n )
  {
    if (n <= 0)
      throw std::runtime_error("n must be positive");
    if ((n & -n) == n) // i.e., n is a power of 2
      return (int32_t)((n * (int64_t)next(31)) >> 31);

    int32_t bits, val;
    do
    {
      bits = next(31);
      val = bits % n;
    } while (bits - val + (n - 1) < 0);
    return val;
  }

protected:
  int64_t seed_;
};

// vim: ts=2 sw=2 et:
