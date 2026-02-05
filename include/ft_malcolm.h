#pragma once


/*
 * Includes
*/

#include <stdint.h> // uint8_t, uint16_t, uint32_t
#include <linux/if_ether.h> // ETH_ALEN


/*
 * Structures
*/

/* Ethernet frame header */
typedef struct __attribute__((packed)) {
	uint8_t  dest_addr[ETH_ALEN];  /* Destination hardware address */
	uint8_t  src_addr[ETH_ALEN];   /* Source hardware address */
	uint16_t frame_type;           /* Ethernet frame type */
} ether_hdr;

/* Ethernet ARP packet from RFC 826 */
typedef struct {
	uint16_t ar_hrd;            /* Format of hardware address */
	uint16_t ar_pro;            /* Format of protocol address */
	uint8_t  ar_hln;            /* Length of hardware address */
	uint8_t  ar_pln;            /* Length of protocol address */
	uint16_t ar_op;             /* ARP opcode (command) */
	uint8_t  ar_sha[ETH_ALEN];  /* Sender hardware address */
	uint32_t ar_sip;            /* Sender IP address */
	uint8_t  ar_tha[ETH_ALEN];  /* Target hardware address */
	uint32_t ar_tip;            /* Target IP address */
} arp_ether_ipv4;


/*
 * Prototypes
*/

int parse_input(int argc, char **argv);