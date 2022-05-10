#ifndef INTTYPES_H
#define INTTYPES_H

#ifdef _NO_DEFINITE
#include "stdint.h"
#else
typedef signed char       int8_t;
typedef signed short      int16_t;
typedef signed long        int32_t;
typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned long      uint32_t;
typedef long long            int64_t;
typedef unsigned long long            uint64_t;
//    typedef signed __int64       int64_t;
//   typedef unsigned __int64     uint64_t;
#endif

#endif
