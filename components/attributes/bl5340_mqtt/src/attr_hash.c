/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: 'C:\\ProgramData\\chocolatey\\lib\\gperf\\tools\\gperf.exe' -C -c -G -D -t -T --word-array-name=word_list --lookup-function-name=attr_id_from_hash --hash-function-name=gperf_hash --output-file='components\\attributes\\bl5340_mqtt\\src\\attr_hash.c' 'components\\attributes\\bl5340_mqtt\\src\\attr.gperf'  */
/* Computed positions: -k'1,7,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) && ('%' == 37) && ('&' == 38) &&    \
      ('\'' == 39) && ('(' == 40) && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) &&   \
      ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) && ('1' == 49) && ('2' == 50) &&    \
      ('3' == 51) && ('4' == 52) && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) &&    \
      ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) && ('=' == 61) && ('>' == 62) &&    \
      ('?' == 63) && ('A' == 65) && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) &&    \
      ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) && ('J' == 74) && ('K' == 75) &&    \
      ('L' == 76) && ('M' == 77) && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) &&    \
      ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) && ('V' == 86) && ('W' == 87) &&    \
      ('X' == 88) && ('Y' == 89) && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) &&   \
      ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) && ('c' == 99) && ('d' == 100) &&   \
      ('e' == 101) && ('f' == 102) && ('g' == 103) && ('h' == 104) && ('i' == 105) &&              \
      ('j' == 106) && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) &&              \
      ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) && ('s' == 115) &&              \
      ('t' == 116) && ('u' == 117) && ('v' == 118) && ('w' == 119) && ('x' == 120) &&              \
      ('y' == 121) && ('z' == 122) && ('{' == 123) && ('|' == 124) && ('}' == 125) &&              \
      ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif


#include "attr_hash.h"

#define TOTAL_KEYWORDS 66
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 26
#define MIN_HASH_VALUE 13
#define MAX_HASH_VALUE 144
/* maximum key range = 132, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
	static unsigned int
	gperf_hash(register const char *str, register size_t len)
{
	static const unsigned char asso_values[] = {
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		65,  145, 145, 145, 5,	 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 25,
		145, 45,  5,   55,  5,	 20,  10,  40,	30,  75,  145, 25,  0,	 0,   5,   50,
		40,  0,	  5,   5,   20,	 60,  30,  145, 70,  10,  145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
		145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145
	};
	register unsigned int hval = len;

	switch (hval) {
	default:
		hval += asso_values[(unsigned char)str[6]];
	/*FALLTHROUGH*/
	case 6:
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
		hval += asso_values[(unsigned char)str[0]];
		break;
	}
	return hval + asso_values[(unsigned char)str[len - 1]];
}

static const struct attr_hash_entry word_list[] = {
	{ "lwm2m_mn", 15 },
	{ "board", 5 },
	{ "mqtt_id", 49 },
	{ "lwm2m_sn", 16 },
	{ "mqtt_id_random", 57 },
	{ "lwm2m_server_url", 7 },
	{ "lwm2m_sw_ver", 20 },
	{ "mqtt_ble_delimiter", 61 },
	{ "lwm2m_short_id", 13 },
	{ "lwm2m_fw_ver", 17 },
	{ "lwm2m_security", 9 },
	{ "mqtt_use_credentials", 54 },
	{ "mqtt_ble_network_id_filter", 64 },
	{ "lwm2m_fup_pkg_ver", 24 },
	{ "mqtt_ble_quote", 63 },
	{ "mqtt_ble_enable", 58 },
	{ "firmware_version", 2 },
	{ "smp_auth_req", 32 },
	{ "mqtt_endpoint", 47 },
	{ "mqtt_user_name", 45 },
	{ "lwm2m_batt_stat", 22 },
	{ "mqtt_id_randomize", 56 },
	{ "device_id", 31 },
	{ "mqtt_peer_verify", 52 },
	{ "lwm2m_hw_ver", 21 },
	{ "lwm2m_fup_pkg_name", 23 },
	{ "lwm2m_mfg", 14 },
	{ "dm_cnx_delay_min", 28 },
	{ "dm_cnx_delay", 27 },
	{ "dm_trust_path", 38 },
	{ "lwm2m_endpoint", 8 },
	{ "log_on_boot", 6 },
	{ "lwm2m_psk_id", 10 },
	{ "fs_trust_path", 40 },
	{ "lwm2m_fup_proxy_srv", 25 },
	{ "lwm2m_bootstrap", 12 },
	{ "smp_auth_timeout", 34 },
	{ "gw_ipv4_addr", 65 },
	{ "mqtt_password", 46 },
	{ "shell_password", 35 },
	{ "api_version", 1 },
	{ "factory_load_path", 30 },
	{ "mqtt_ble_topic", 59 },
	{ "dm_key_path", 39 },
	{ "tel_key_path", 37 },
	{ "lwm2m_psk", 11 },
	{ "fs_key_path", 41 },
	{ "bluetooth_address", 26 },
	{ "lwm2m_pwr_src_volt", 19 },
	{ "mqtt_port", 48 },
	{ "gw_smp_auth_req", 33 },
	{ "mqtt_publish_qos", 51 },
	{ "mqtt_subscribe_qos", 53 },
	{ "load_path", 4 },
	{ "mqtt_ble_prefix", 60 },
	{ "mqtt_ble_postfix", 62 },
	{ "dump_path", 3 },
	{ "p2p_key_path", 43 },
	{ "mqtt_connect_on_request", 55 },
	{ "ipv4_addr", 44 },
	{ "mqtt_watchdog", 50 },
	{ "reserved0", 0 },
	{ "lwm2m_pwr_src", 18 },
	{ "dm_cnx_delay_max", 29 },
	{ "tel_trust_path", 36 },
	{ "p2p_trust_path", 42 }
};

static const signed char lookup[] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	-1, 1,	-1, 2,	3,  4,	-1,
	5,  6,	7,  8,	-1, -1, 9,  -1, 10, 11, 12, 13, -1, 14, 15, 16, 17, 18, 19, 20, -1,
	21, -1, 22, -1, 23, 24, 25, 26, -1, 27, 28, 29, 30, -1, 31, 32, 33, 34, 35, 36, 37,
	38, 39, -1, 40, 41, -1, 42, -1, 43, 44, -1, 45, -1, 46, 47, 48, 49, 50, 51, -1, 52,
	53, 54, 55, -1, -1, 56, -1, -1, 57, 58, 59, -1, -1, -1, 60, 61, -1, -1, -1, -1, -1,
	-1, -1, -1, 62, -1, -1, -1, -1, -1, -1, -1, 63, -1, -1, -1, -1, -1, -1, -1, 64, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 65
};

const struct attr_hash_entry *attr_id_from_hash(register const char *str, register size_t len)
{
	if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH) {
		register unsigned int key = gperf_hash(str, len);

		if (key <= MAX_HASH_VALUE) {
			register int index = lookup[key];

			if (index >= 0) {
				register const char *s = word_list[index].name;

				if (*str == *s && !strncmp(str + 1, s + 1, len - 1) &&
				    s[len] == '\0')
					return &word_list[index];
			}
		}
	}
	return 0;
}
