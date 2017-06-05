/******************************************************************************
* Generic types and constants                                                 *
* Jeferson Santiago da Silva (eng.jefersonsantiago@gmail.com)                 *
******************************************************************************/
#include <features.h>
#include "ap_int.h"

#ifndef _DEF_TYPES_H_
#define _DEF_TYPES_H_

// Signed
typedef int int_32;
typedef long long int int_64;
typedef short int int_16;
typedef char int_8;

// Unsigned
typedef unsigned int uint;
typedef unsigned long long int uint_64;
typedef unsigned int uint_32;
typedef unsigned short int uint_16;
typedef unsigned char uint_8;

//FIFO parameters
constexpr uint MAX_PKT_SIZE = 1518;
//constexpr uint MAX_PKT_SIZE = 64;
constexpr uint MIN_PKT_SIZE = 64;
constexpr uint FIFO_ELEMENT_SIZE = 64;
constexpr uint FIFO_SIZE = 4;     // Number of maximum sized packets
//constexpr uint FIFO_SIZE = 1;             // Number of maximum sized packets

// FIFO basic element
template<typename T>
struct FifoElement
{
    T Element;
    bool PacketIni;
    bool PacketEnd;
    FifoElement() : PacketIni{0}, PacketEnd{0}, Element{} {}
};

// Workaround non constexpr log and ceil
// Reference: https://hbfs.wordpress.com/2016/03/22/log2-with-c-metaprogramming/
template<typename T>
constexpr uint Log2(T n) {
	return ((n<2) ? 1 : 1+Log2(n>>2));
}

template<typename T>
constexpr int_64 Ceil(T n) {
	return ((n==(uint)(n)) ? (uint)(n) : (uint)(n) + 1);
}

#endif //_DEF_TYPES_H_
