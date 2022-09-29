/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: 'C:\\ProgramData\\chocolatey\\lib\\gperf\\tools\\gperf.exe' -C -c -G -D -t -T --word-array-name=word_list --lookup-function-name=attr_id_from_hash --hash-function-name=gperf_hash --output-file='components\\attributes\\bl5340_dvk\\src\\attr_hash.c' 'components\\attributes\\bl5340_dvk\\src\\attr.gperf'  */
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

#define TOTAL_KEYWORDS 53
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 22
#define MIN_HASH_VALUE 12
#define MAX_HASH_VALUE 121
/* maximum key range = 110, duplicates = 0 */

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
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		30,  122, 122, 122, 5,	 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 30,
		122, 20,  35,  35,  10,	 15,  30,  50,	10,  30,  122, 45,  15,	 5,   35,  20,
		5,   0,	  40,  0,   0,	 40,  20,  122, 10,  5,	  122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122,
		122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122
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
	{ "smp_auth_req", 32 },
	{ "smp_auth_timeout", 34 },
	{ "tel_key_path", 44 },
	{ "shell_password", 42 },
	{ "p2p_key_path", 50 },
	{ "dm_trust_path", 45 },
	{ "lwm2m_security", 9 },
	{ "lwm2m_telem_endpoint", 36 },
	{ "lwm2m_pwr_src_volt", 19 },
	{ "lwm2m_short_id", 13 },
	{ "lwm2m_telem_security", 37 },
	{ "lwm2m_psk_id", 10 },
	{ "lwm2m_telem_psk_id", 38 },
	{ "lwm2m_endpoint", 8 },
	{ "lwm2m_telem_short_id", 40 },
	{ "lwm2m_server_url", 7 },
	{ "lwm2m_telem_enable", 41 },
	{ "dump_path", 3 },
	{ "board", 5 },
	{ "lwm2m_telem_server_url", 35 },
	{ "fs_trust_path", 47 },
	{ "load_path", 4 },
	{ "log_on_boot", 6 },
	{ "dm_cnx_delay", 27 },
	{ "lwm2m_sn", 16 },
	{ "device_id", 31 },
	{ "dm_key_path", 46 },
	{ "factory_load_path", 30 },
	{ "lwm2m_mn", 15 },
	{ "tel_trust_path", 43 },
	{ "lwm2m_batt_stat", 22 },
	{ "dm_cnx_delay_max", 29 },
	{ "lwm2m_sw_ver", 20 },
	{ "lwm2m_pwr_src", 18 },
	{ "p2p_trust_path", 49 },
	{ "lwm2m_bootstrap", 12 },
	{ "bluetooth_address", 26 },
	{ "lwm2m_psk", 11 },
	{ "lwm2m_telem_psk", 39 },
	{ "lwm2m_hw_ver", 21 },
	{ "lwm2m_fup_pkg_name", 23 },
	{ "lwm2m_mfg", 14 },
	{ "fs_key_path", 48 },
	{ "lwm2m_fup_proxy_srv", 25 },
	{ "ipv4_addr", 51 },
	{ "dm_cnx_delay_min", 28 },
	{ "reserved0", 0 },
	{ "gw_smp_auth_req", 33 },
	{ "lwm2m_fw_ver", 17 },
	{ "lwm2m_fup_pkg_ver", 24 },
	{ "api_version", 1 },
	{ "gw_ipv4_addr", 52 },
	{ "firmware_version", 2 }
};

static const signed char lookup[] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  -1, -1, -1, 1,  -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, 2,  -1, 3,  -1, -1, 4,	5,  6,	7,  -1, -1, 8,	9,  10, -1,
	11, 12, 13, 14, 15, -1, 16, 17, 18, -1, 19, 20, 21, -1, 22, 23, 24, 25, -1, 26, 27,
	28, 29, 30, 31, 32, 33, 34, 35, -1, 36, -1, 37, 38, -1, 39, 40, 41, -1, 42, -1, -1,
	43, -1, -1, -1, -1, 44, -1, 45, -1, -1, 46, 47, -1, 48, -1, -1, -1, -1, 49, -1, -1,
	-1, 50, 51, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 52
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
