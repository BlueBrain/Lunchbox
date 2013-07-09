
/* Copyright (c) 2007-2013, Stefan Eilemann <eile@equalizergraphics.com>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * @file lunchbox/types.h
 * Basic type definitions not provided by the operating system.
 */

#ifndef LUNCHBOX_TYPES_H
#define LUNCHBOX_TYPES_H

#include <string>
#include <vector>
#include <sys/types.h>

#ifndef _MSC_VER
#  include <stdint.h>
#endif

#ifdef _WIN32
#  include <basetsd.h>

typedef int        socklen_t;

#  ifdef _MSC_VER
typedef UINT64     uint64_t;
typedef INT64      int64_t;
typedef UINT32     uint32_t;
typedef INT32      int32_t;
typedef UINT16     uint16_t;
typedef INT16      int16_t;
typedef UINT8      uint8_t;
typedef INT8       int8_t;
#    ifndef HAVE_SSIZE_T
typedef SSIZE_T    ssize_t;
#      define HAVE_SSIZE_T
#    endif
#  endif // Win32, Visual C++
#endif // Win32

#define LB_BIT1  (0x00000001u)
#define LB_BIT2  (0x00000002u)
#define LB_BIT3  (0x00000004u)
#define LB_BIT4  (0x00000008u)
#define LB_BIT5  (0x00000010u)
#define LB_BIT6  (0x00000020u)
#define LB_BIT7  (0x00000040u)
#define LB_BIT8  (0x00000080u)

#define LB_BIT9  (0x00000100u)
#define LB_BIT10 (0x00000200u)
#define LB_BIT11 (0x00000400u)
#define LB_BIT12 (0x00000800u)
#define LB_BIT13 (0x00001000u)
#define LB_BIT14 (0x00002000u)
#define LB_BIT15 (0x00004000u)
#define LB_BIT16 (0x00008000u)

#define LB_BIT17 (0x00010000u)
#define LB_BIT18 (0x00020000u)
#define LB_BIT19 (0x00040000u)
#define LB_BIT20 (0x00080000u)
#define LB_BIT21 (0x00100000u)
#define LB_BIT22 (0x00200000u)
#define LB_BIT23 (0x00400000u)
#define LB_BIT24 (0x00800000u)

#define LB_BIT25 (0x01000000u)
#define LB_BIT26 (0x02000000u)
#define LB_BIT27 (0x04000000u)
#define LB_BIT28 (0x08000000u)
#define LB_BIT29 (0x10000000u)
#define LB_BIT30 (0x20000000u)
#define LB_BIT31 (0x40000000u)
#define LB_BIT32 (0x80000000u)

#define LB_BIT33 (0x0000000100000000ull)
#define LB_BIT34 (0x0000000200000000ull)
#define LB_BIT35 (0x0000000400000000ull)
#define LB_BIT36 (0x0000000800000000ull)
#define LB_BIT37 (0x0000001000000000ull)
#define LB_BIT38 (0x0000002000000000ull)
#define LB_BIT39 (0x0000004000000000ull)
#define LB_BIT40 (0x0000008000000000ull)

#define LB_BIT41 (0x0000010000000000ull)
#define LB_BIT42 (0x0000020000000000ull)
#define LB_BIT43 (0x0000040000000000ull)
#define LB_BIT44 (0x0000080000000000ull)
#define LB_BIT45 (0x0000100000000000ull)
#define LB_BIT46 (0x0000200000000000ull)
#define LB_BIT47 (0x0000400000000000ull)
#define LB_BIT48 (0x0000800000000000ull)

#define LB_BIT49 (0x0001000000000000ull)
#define LB_BIT50 (0x0002000000000000ull)
#define LB_BIT51 (0x0004000000000000ull)
#define LB_BIT52 (0x0008000000000000ull)
#define LB_BIT53 (0x0010000000000000ull)
#define LB_BIT54 (0x0020000000000000ull)
#define LB_BIT55 (0x0040000000000000ull)
#define LB_BIT56 (0x0080000000000000ull)

#define LB_BIT57 (0x0100000000000000ull)
#define LB_BIT58 (0x0200000000000000ull)
#define LB_BIT59 (0x0400000000000000ull)
#define LB_BIT60 (0x0800000000000000ull)
#define LB_BIT61 (0x1000000000000000ull)
#define LB_BIT62 (0x2000000000000000ull)
#define LB_BIT63 (0x4000000000000000ull)
#define LB_BIT64 (0x8000000000000000ull)

#define LB_BIT_ALL_32  (0xffffffffu)
#define LB_BIT_ALL_64  (0xffffffffffffffffull)
#define LB_BIT_NONE (0)

#define LB_1KB   (1024)
#define LB_10KB  (10240)
#define LB_100KB (102400)
#define LB_1MB   (1048576)
#define LB_10MB  (10485760)
#define LB_100MB (104857600)

#define LB_16KB  (16384)
#define LB_32KB  (32768)
#define LB_64KB  (65536)
#define LB_128KB (131072)
#define LB_48MB  (50331648)
#define LB_64MB  (67108864)

/** @cond IGNORE */
struct EqCompressorInfo;
typedef std::vector< EqCompressorInfo > EqCompressorInfos;
typedef EqCompressorInfos::const_iterator EqCompressorInfosCIter;
struct GLEWContextStruct;
struct WGLEWContextStruct;
typedef struct GLEWContextStruct GLEWContext;
typedef struct WGLEWContextStruct WGLEWContext;
/** @endcond */

namespace lunchbox
{
/** A vector of std::strings @version 1.0 */
typedef std::vector< std::string > Strings;
typedef Strings::const_iterator StringsCIter;
typedef Strings::iterator StringsIter;

class Clock;
class Lock;
class NonCopyable;
class Plugin;
class PluginRegistry;
class Referenced;
class RequestHandler;
class Servus;
class SpinLock;
class UUID;
class Uploader;
class uint128_t;

template< class > class Atomic;
template< class > class Buffer;
template< class > class Monitor;
template< class, class > class LFVectorIterator;
template< class, class > class PluginVisitorT;
template< class, class > class Lockable;
template< class, int32_t > class LFVector;

typedef Atomic< int32_t > a_int32_t; //!< An atomic 32 bit integer variable
typedef Atomic< ssize_t > a_ssize_t; //!< An atomic signed size variable
typedef Buffer< uint8_t > Bufferb; //!< a byte buffer

typedef std::vector< Plugin* > Plugins;
typedef Plugins::const_iterator PluginsCIter;

typedef PluginVisitorT< Plugin, EqCompressorInfo > PluginVisitor;
typedef PluginVisitorT< const Plugin,
                        const EqCompressorInfo > ConstPluginVisitor;

/** @cond IGNORE */
struct CompressorInfo;
typedef std::vector< CompressorInfo > CompressorInfos;
typedef CompressorInfos::const_iterator CompressorInfosCIter;
typedef CompressorInfos::iterator CompressorInfosIter;
/** @endcond */
}

#endif //LUNCHBOX_TYPES_H
