#pragma once


/*
 * Includes
*/
#include <stdint.h> // uint8_t, uint16_t, uint32_t


/*
 * Macros
*/
#define ETH_P_ARP 0x0806 /* Address Resolution packet */


#define ARP_HTYPE_ETHER 1  /* Ethernet ARP type */
#define ARP_PTYPE_IPv4 0x0800 /* Internet Protocol packet */
#define ARP_REQUEST 1 // a revoir
#define ARP_REPLY 0 // a revoir
#define ETH_ALEN 6


/*
 * Structures
*/
/* Ethernet frame header (14 bytes) */
typedef struct __attribute__((packed)) {
	uint8_t  dst[ETH_ALEN];  /* Destination MAC address */
	uint8_t  src[ETH_ALEN];  /* Source MAC address */
	uint16_t ethertype;      /* Ethernet type (ETH_P_ARP) */
} ether_hdr;

/* ARP packet (Ethernet / IPv4) as defined in RFC 826 */
typedef struct __attribute__((packed)) {
	uint16_t htype;          /* Hardware type (ARP_HTYPE_ETHER) */
	uint16_t ptype;          /* Protocol type (ETH_P_IP) */
	uint8_t  hlen;           /* Hardware address length (6) */
	uint8_t  plen;           /* Protocol address length (4) */
	uint16_t opcode;         /* ARP opcode (REQUEST / REPLY) */
	uint8_t  sha[ETH_ALEN];  /* Sender hardware address (MAC) */
	uint32_t spa;            /* Sender protocol address (IPv4) */
	uint8_t  tha[ETH_ALEN];  /* Target hardware address (MAC) */
	uint32_t tpa;            /* Target protocol address (IPv4) */
} arp_hdr;


/*
 * Prototypes
*/
int parse_input(int argc, char **argv);
void ft_malcolm();
