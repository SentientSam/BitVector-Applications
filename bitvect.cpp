/*
  bitvect.cpp
  Created 1-31-2019
  cop3330
  Samuel Lamb
  lamb
*/

#include <iostream>
#include <bitvect.h>

namespace fsu
{
  //----------------------------------
  //     Global operators
  //----------------------------------

  bool operator == (const fsu::BitVector& v1 , const fsu::BitVector& v2)
  {
    if (v1.Size() != v2.Size())
      return 0;
    for (size_t i = 0; i < v1.Size(); ++i)
    {
      if (v1.Test(i) && !v2.Test(i))
        return 0;
      if (v2.Test(i) && !v2.Test(i))
        return 0;
    }
    return 1;
  }
  bool operator != (const fsu::BitVector& v1 , const fsu::BitVector& v2)
  {
    return !(v1 == v2);
  }
  std::ostream& operator << (std::ostream& os, const fsu::BitVector& a)
  {
    for (size_t i = 0; i < a.Size(); ++i)
      os << a[i];
    return os;
  }

  //----------------------------------
  //     class BitVector
  //---------------------------------

BitVector::BitVector(): byteArray_(nullptr), byteArraySize_(64)
{
  byteArraySize_ = ((64 + 7)/8);
  byteArray_ = new uint8_t [byteArraySize_];
  for (size_t i = 0; i < byteArraySize_; ++i)
  {
    byteArray_[i] = 0x00;
  }
}

BitVector::BitVector(size_t size):byteArray_(nullptr),byteArraySize_(size)
{
  byteArraySize_ = ((size + 7)/8);
  byteArray_ = new uint8_t[byteArraySize_];
  if (byteArray_ == 0)
  {
    std::cerr << "** BitVector memory allocation failure -- terminating program.\n";
    exit(EXIT_FAILURE);
  }
  for (size_t i = 0; i < byteArraySize_; ++i)
  {
    byteArray_[i] = 0x00;
  }
}

BitVector::BitVector (const BitVector& a) : byteArray_(nullptr), byteArraySize_(a.byteArraySize_)
{
  byteArraySize_ = a.byteArraySize_;
  byteArray_ = new uint8_t[a.byteArraySize_];
  for(size_t i = 0; i < byteArraySize_; ++i)
  {
    a.byteArray_[i] = 0x00;
  }
}
BitVector :: ~BitVector ()
{
  delete [] byteArray_;
}
BitVector& BitVector:: operator = (const BitVector& a)
{
  if(this != &a)
  {
    if(byteArraySize_!= a.byteArraySize_)
    {
      delete [] byteArray_;
      byteArraySize_ = a.byteArraySize_;
      byteArray_ = new unsigned char [byteArraySize_];
      if(byteArray_ == 0)
      {
        std::cerr << "** BitVector memory allocation failure-- terminating program.\n";
        exit (EXIT_FAILURE);
      }
    }
    for(size_t i = 0; i < a.byteArraySize_; ++i)
    {
      byteArray_[i] = 0x00;
    }
  }
  return *this;
}
void BitVector :: Set()                     // make all bits = 1
    {
      for(size_t i = 0; i < byteArraySize_;++i)
      {
        byteArray_[i] = 255;
      }
    }
void BitVector :: Set (size_t index)       // make bit at index = 1
    {
      byteArray_[ByteNumber(index)] |= Mask(index);
    }  
void BitVector :: Unset()                    // make all bits = 0
    {
      for(size_t i = 0; i < byteArraySize_;++i)
      {
        byteArray_[i] = 0;
      }
    } 
void BitVector :: Unset  (size_t index)   // make bit at index = 0
    {
      byteArray_[ByteNumber(index)] &= -Mask(index); 
    }
void BitVector :: Flip()              // change all bits 
    {
      for(size_t i = 0; i < byteArraySize_; i++)
      {
         byteArray_[i] = -byteArray_[i];
      }
    }
void BitVector :: Flip (size_t index)       // change bit at index
    {
      byteArray_[ByteNumber(index)] ^= Mask(index);
    }
bool BitVector :: Test(size_t index) const
    {
      return 0 != (byteArray_[ByteNumber(index)] &Mask(index));
    }
size_t BitVector :: Size() const
    {
      return byteArraySize_ *8;
    }
void BitVector::Expand (size_t size)
    {
      size_t newByteArraySize = ((size + 7)/8);
      uint8_t *newByteArray_ = new uint8_t [newByteArraySize];
        for (size_t i = 0; i < byteArraySize_; ++i)
        {
          newByteArray_[i] = byteArray_[i];
        }
      delete[] byteArray_;
      byteArray_ = newByteArray_;
      byteArraySize_ = newByteArraySize;
    }
void BitVector::Dump  (std::ostream& os) const
    {
      os << '\t';
      for (size_t i = 0; i < Size(); ++i)
       os << Test(i);
      os << "\n\t";
      for (size_t i = 0; i < Size(); ++i)
       os << (i % 10);
      os << '\n';
    }
size_t BitVector::ByteNumber (size_t index) const 
{
  index = index >> 3;
  return index;
}
unsigned char BitVector::Mask (size_t index)
{
  size_t shiftamount = index & (size_t) 0x07;
  return 0x01 << shiftamount;
}
}
