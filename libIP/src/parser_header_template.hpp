/******************************************************************************
* parser_header_template: Self-generated template structs for the parser      *
* Jeferson Santiago da Silva (eng.jefersonsantiago@gmail.com)                 *
******************************************************************************/

#include <iostream>
#include <math.h>
#include <string>
#include <array>

#include "pktBasics.hpp"

#ifndef _PARSER_HEADER_TEMP_HPP_
#define _PARSER_HEADER_TEMP_HPP_

#define HEADER_NUM 10

#define MAX_SUPP_HEADERS 10

#define MAX_HEADER_SIZE 40

#define MAX_HEADER_SIZE_BITS bytes2Bits(MAX_HEADER_SIZE)

#define ETHERNET_HEADER_SIZE 14

#define ETHERNET_HEADER_SIZE_BITS bytes2Bits(ETHERNET_HEADER_SIZE)

#define ETHERNET_NUM_FIELDS 3

const HeaderFormat<14, 3, ap_uint<16>, 5, MAX_SUPP_HEADERS> ethernet_t
{
	(ap_uint<112>("5192296858534827628530496329220095")),
	{
		{
			{0, 48 IF_SOFTWARE(, "dstAddr")},
			{48, 48 IF_SOFTWARE(, "srcAddr")},
			{96, 16 IF_SOFTWARE(, "etherType")}
		},
	},
	{
		{
			{0x0800, 65535, 6 IF_SOFTWARE(, "ipv4")},
			{0x8100, 65535, 3 IF_SOFTWARE(, "inner_vlan")},
			{0x9100, 65535, 2 IF_SOFTWARE(, "outer_vlan")},
			{0x8847, 65535, 4 IF_SOFTWARE(, "outer_mpls")},
			{0x86dd, 65535, 7 IF_SOFTWARE(, "ipv6")}
		},
	},
	std::pair<ap_uint<7>, ap_uint<7>>{96,16},
	(false)
	IF_SOFTWARE(, "ethernet_t")
};

#define OUTER_VLAN_HEADER_SIZE 4

#define OUTER_VLAN_HEADER_SIZE_BITS bytes2Bits(OUTER_VLAN_HEADER_SIZE)

#define OUTER_VLAN_NUM_FIELDS 4

const HeaderFormat<4, 4, ap_uint<16>, 1, MAX_SUPP_HEADERS> vlan_outer_t
{
	(ap_uint<32>("4294967295")),
	{
		{
			{0, 3 IF_SOFTWARE(, "PCP")},
			{3, 1 IF_SOFTWARE(, "DEI")},
			{4, 12 IF_SOFTWARE(, "VID")},
			{16, 16 IF_SOFTWARE(, "etherType")}
		},
	},
	{
		{
			{0x8100, 65535, 3 IF_SOFTWARE(, "inner_vlan")}
		},
	},
	std::pair<ap_uint<6>, ap_uint<6>>{16,16},
	(false)
	IF_SOFTWARE(, "vlan_outer_t")
};

#define INNER_VLAN_HEADER_SIZE 4

#define INNER_VLAN_HEADER_SIZE_BITS bytes2Bits(INNER_VLAN_HEADER_SIZE)

#define INNER_VLAN_NUM_FIELDS 4

const HeaderFormat<4, 4, ap_uint<16>, 2, MAX_SUPP_HEADERS> vlan_inner_t
{
	(ap_uint<32>("4294967295")),
	{
		{
			{0, 3 IF_SOFTWARE(, "PCP")},
			{3, 1 IF_SOFTWARE(, "DEI")},
			{4, 12 IF_SOFTWARE(, "VID")},
			{16, 16 IF_SOFTWARE(, "etherType")}
		},
	},
	{
		{
			{0x0800, 65535, 6 IF_SOFTWARE(, "ipv4")},
			{0x86dd, 65535, 7 IF_SOFTWARE(, "ipv6")}
		},
	},
	std::pair<ap_uint<6>, ap_uint<6>>{16,16},
	(false)
	IF_SOFTWARE(, "vlan_inner_t")
};

#define OUTER_MPLS_HEADER_SIZE 4

#define OUTER_MPLS_HEADER_SIZE_BITS bytes2Bits(OUTER_MPLS_HEADER_SIZE)

#define OUTER_MPLS_NUM_FIELDS 4

const HeaderFormat<4, 4, ap_uint<3>, 1, MAX_SUPP_HEADERS> mpls_outer_t
{
	(ap_uint<32>("4294967295")),
	{
		{
			{0, 20 IF_SOFTWARE(, "label")},
			{20, 3 IF_SOFTWARE(, "TC")},
			{23, 1 IF_SOFTWARE(, "S")},
			{24, 8 IF_SOFTWARE(, "TTL")}
		},
	},
	{
		{
			{0x00, 7, 5 IF_SOFTWARE(, "inner_mpls")}
		},
	},
	std::pair<ap_uint<6>, ap_uint<6>>{20,3},
	(false)
	IF_SOFTWARE(, "mpls_outer_t")
};

#define INNER_MPLS_HEADER_SIZE 4

#define INNER_MPLS_HEADER_SIZE_BITS bytes2Bits(INNER_MPLS_HEADER_SIZE)

#define INNER_MPLS_NUM_FIELDS 4

const HeaderFormat<4, 4, ap_uint<1>, 1, MAX_SUPP_HEADERS> mpls_inner_t
{
	(ap_uint<32>("4294967295")),
	{
		{
			{0, 20 IF_SOFTWARE(, "label")},
			{20, 3 IF_SOFTWARE(, "TC")},
			{23, 1 IF_SOFTWARE(, "S")},
			{24, 8 IF_SOFTWARE(, "TTL")}
		},
	},
	{
		{
			{1, 1, 0 IF_SOFTWARE(, "Last Header")}
		},
	},
	std::pair<ap_uint<6>, ap_uint<6>>{0,1},
	(true)
	IF_SOFTWARE(, "mpls_inner_t")
};

#define IPV4_HEADER_SIZE 20

#define IPV4_HEADER_SIZE_BITS bytes2Bits(IPV4_HEADER_SIZE)

#define IPV4_NUM_FIELDS 12

const HeaderFormat<20, 12, ap_uint<8>, 3, MAX_SUPP_HEADERS> ipv4_t
{
	(ap_uint<160>("1461501637330902918203684832716283019655932542975")),
	{
		{
			{0, 4 IF_SOFTWARE(, "version")},
			{4, 4 IF_SOFTWARE(, "ihl")},
			{8, 8 IF_SOFTWARE(, "diffserv")},
			{16, 16 IF_SOFTWARE(, "totalLen")},
			{32, 16 IF_SOFTWARE(, "identification")},
			{48, 3 IF_SOFTWARE(, "flags")},
			{51, 13 IF_SOFTWARE(, "fragOffset")},
			{64, 8 IF_SOFTWARE(, "ttl")},
			{72, 8 IF_SOFTWARE(, "protocol")},
			{80, 16 IF_SOFTWARE(, "hdrChecksum")},
			{96, 32 IF_SOFTWARE(, "srcAddr")},
			{128, 32 IF_SOFTWARE(, "dstAddr")}
		},
	},
	{
		{
			{0x01, 255, 10 IF_SOFTWARE(, "icmp")},
			{0x11, 255, 8 IF_SOFTWARE(, "udp")},
			{0x06, 255, 9 IF_SOFTWARE(, "tcp")}
		},
	},
	std::pair<ap_uint<8>, ap_uint<8>>{72,8},
	(false)
	IF_SOFTWARE(, "ipv4_t")
};

#define IPV6_HEADER_SIZE 40

#define IPV6_HEADER_SIZE_BITS bytes2Bits(IPV6_HEADER_SIZE)

#define IPV6_NUM_FIELDS 8

const HeaderFormat<40, 8, ap_uint<8>, 3, MAX_SUPP_HEADERS> ipv6_t
{
	(ap_uint<320>("2135987035920910082395021706169552114602704522356652769947041607822219725780640550022962086936575")),
	{
		{
			{0, 4 IF_SOFTWARE(, "version")},
			{4, 8 IF_SOFTWARE(, "trafficClass")},
			{12, 20 IF_SOFTWARE(, "flowLabel")},
			{32, 16 IF_SOFTWARE(, "payloadLen")},
			{48, 8 IF_SOFTWARE(, "nextHdr")},
			{56, 8 IF_SOFTWARE(, "hopLimit")},
			{64, 128 IF_SOFTWARE(, "srcAddr")},
			{192, 128 IF_SOFTWARE(, "dstAddr")}
		},
	},
	{
		{
			{0x3a, 255, 10 IF_SOFTWARE(, "icmp")},
			{0x11, 255, 8 IF_SOFTWARE(, "udp")},
			{0x06, 255, 9 IF_SOFTWARE(, "tcp")}
		},
	},
	std::pair<ap_uint<9>, ap_uint<9>>{48,8},
	(false)
	IF_SOFTWARE(, "ipv6_t")
};

#define UDP_HEADER_SIZE 8

#define UDP_HEADER_SIZE_BITS bytes2Bits(UDP_HEADER_SIZE)

#define UDP_NUM_FIELDS 4

const HeaderFormat<8, 4, ap_uint<1>, 1, MAX_SUPP_HEADERS> udp_t
{
	(ap_uint<64>("18446744073709551615")),
	{
		{
			{0, 16 IF_SOFTWARE(, "srcPort")},
			{16, 16 IF_SOFTWARE(, "dstPort")},
			{32, 16 IF_SOFTWARE(, "hdrLength")},
			{48, 16 IF_SOFTWARE(, "chksum")}
		},
	},
	{
		{
			{1, 1, 0 IF_SOFTWARE(, "Last Header")}
		},
	},
	std::pair<ap_uint<7>, ap_uint<7>>{0,1},
	(true)
	IF_SOFTWARE(, "udp_t")
};

#define TCP_HEADER_SIZE 20

#define TCP_HEADER_SIZE_BITS bytes2Bits(TCP_HEADER_SIZE)

#define TCP_NUM_FIELDS 10

const HeaderFormat<20, 10, ap_uint<1>, 1, MAX_SUPP_HEADERS> tcp_t
{
	(ap_uint<160>("1461501637330902918203684832716283019655932542975")),
	{
		{
			{0, 16 IF_SOFTWARE(, "srcPort")},
			{16, 16 IF_SOFTWARE(, "dstPort")},
			{32, 32 IF_SOFTWARE(, "seqNum")},
			{64, 32 IF_SOFTWARE(, "ackNum")},
			{96, 4 IF_SOFTWARE(, "dataOffset")},
			{100, 6 IF_SOFTWARE(, "unused")},
			{106, 6 IF_SOFTWARE(, "flags")},
			{112, 16 IF_SOFTWARE(, "windowSize")},
			{128, 16 IF_SOFTWARE(, "chksum")},
			{144, 16 IF_SOFTWARE(, "urgPtr")}
		},
	},
	{
		{
			{1, 1, 0 IF_SOFTWARE(, "Last Header")}
		},
	},
	std::pair<ap_uint<8>, ap_uint<8>>{0,1},
	(true)
	IF_SOFTWARE(, "tcp_t")
};

#define ICMP_HEADER_SIZE 6

#define ICMP_HEADER_SIZE_BITS bytes2Bits(ICMP_HEADER_SIZE)

#define ICMP_NUM_FIELDS 4

const HeaderFormat<6, 4, ap_uint<1>, 1, MAX_SUPP_HEADERS> icmp_t
{
	(ap_uint<48>("281474976710655")),
	{
		{
			{0, 8 IF_SOFTWARE(, "mtype")},
			{8, 8 IF_SOFTWARE(, "code")},
			{16, 16 IF_SOFTWARE(, "chksum")},
			{32, 16 IF_SOFTWARE(, "body")}
		},
	},
	{
		{
			{1, 1, 0 IF_SOFTWARE(, "Last Header")}
		},
	},
	std::pair<ap_uint<6>, ap_uint<6>>{0,1},
	(true)
	IF_SOFTWARE(, "icmp_t")
};

#endif //_PARSER_HEADER_TEMP_HPP_
