/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: 'C:\\ProgramData\\chocolatey\\lib\\gperf\\tools\\gperf.exe' -C -c -G -D -t -T --word-array-name=word_list --lookup-function-name=attr_id_from_hash --hash-function-name=gperf_hash --output-file='components\\attributes\\p100_mqtt\\src\\attr_hash.c' 'components\\attributes\\p100_mqtt\\src\\attr.gperf'  */
/* Computed positions: -k'2,5,7,9,$' */

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

#define TOTAL_KEYWORDS 88
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 26
#define MIN_HASH_VALUE 5
#define MAX_HASH_VALUE 214
/* maximum key range = 210, duplicates = 0 */

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
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		0,   215, 45,  215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 0,
		215, 20,  30,  60,  0,	 0,   10,  5,	5,   65,  215, 5,   0,	 35,  0,   0,
		50,  0,	  0,   20,  5,	 25,  45,  25,	50,  60,  215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215,
		215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215
	};
	register unsigned int hval = len;

	switch (hval) {
	default:
		hval += asso_values[(unsigned char)str[8]];
	/*FALLTHROUGH*/
	case 8:
	case 7:
		hval += asso_values[(unsigned char)str[6]];
	/*FALLTHROUGH*/
	case 6:
	case 5:
		hval += asso_values[(unsigned char)str[4]];
	/*FALLTHROUGH*/
	case 4:
	case 3:
	case 2:
		hval += asso_values[(unsigned char)str[1]];
		break;
	}
	return hval + asso_values[(unsigned char)str[len - 1]];
}

static const struct attr_hash_entry word_list[] = {
	{ "board", 5 },
	{ "mqtt_id", 72 },
	{ "reserved0", 0 },
	{ "mqtt_ble_quote", 86 },
	{ "mqtt_ble_enable", 81 },
	{ "log_on_boot", 6 },
	{ "mqtt_id_randomize", 79 },
	{ "mqtt_ble_delimiter", 84 },
	{ "mqtt_port", 71 },
	{ "lte_log_lvl", 61 },
	{ "lte_rat", 60 },
	{ "lte_data_total", 67 },
	{ "mqtt_ble_network_id_filter", 87 },
	{ "lte_network_state", 50 },
	{ "mqtt_connect_on_request", 78 },
	{ "lte_sn", 48 },
	{ "lte_apn", 53 },
	{ "lte_sinr", 55 },
	{ "mqtt_user_name", 68 },
	{ "load_path", 4 },
	{ "bluetooth_address", 26 },
	{ "mqtt_id_random", 80 },
	{ "dm_cnx_delay_min", 28 },
	{ "mqtt_password", 69 },
	{ "tel_trust_path", 36 },
	{ "fs_key_path", 41 },
	{ "fs_trust_path", 40 },
	{ "ipv4_addr", 44 },
	{ "mqtt_use_credentials", 77 },
	{ "mqtt_publish_qos", 74 },
	{ "lte_rsrp", 54 },
	{ "dump_path", 3 },
	{ "mqtt_ble_prefix", 83 },
	{ "mqtt_ble_postfix", 85 },
	{ "lte_startup_state", 51 },
	{ "mqtt_endpoint", 70 },
	{ "device_id", 31 },
	{ "dm_key_path", 39 },
	{ "smp_auth_req", 32 },
	{ "dm_trust_path", 38 },
	{ "mqtt_ble_topic", 82 },
	{ "mqtt_peer_verify", 75 },
	{ "lwm2m_hw_ver", 21 },
	{ "lwm2m_endpoint", 8 },
	{ "smp_auth_timeout", 34 },
	{ "lwm2m_fw_ver", 17 },
	{ "mqtt_subscribe_qos", 76 },
	{ "lte_bands", 56 },
	{ "lwm2m_sn", 16 },
	{ "shell_password", 35 },
	{ "lte_sleep_state", 59 },
	{ "lwm2m_sw_ver", 20 },
	{ "lte_operator_index", 58 },
	{ "lwm2m_short_id", 13 },
	{ "lwm2m_server_url", 7 },
	{ "mqtt_watchdog", 73 },
	{ "p2p_trust_path", 42 },
	{ "gw_smp_auth_req", 33 },
	{ "dm_cnx_delay_max", 29 },
	{ "factory_load_path", 30 },
	{ "lwm2m_mn", 15 },
	{ "firmware_version", 2 },
	{ "dm_cnx_delay", 27 },
	{ "lte_active_bands", 57 },
	{ "lwm2m_mfg", 14 },
	{ "lwm2m_batt_stat", 22 },
	{ "lte_fup_status", 62 },
	{ "lte_tcp_rx", 66 },
	{ "lte_tcp_tx", 65 },
	{ "lte_version", 49 },
	{ "lwm2m_psk_id", 10 },
	{ "lwm2m_psk", 11 },
	{ "tel_key_path", 37 },
	{ "lwm2m_pwr_src_volt", 19 },
	{ "lwm2m_fup_pkg_ver", 24 },
	{ "lwm2m_fup_pkg_name", 23 },
	{ "lte_iccid", 46 },
	{ "lte_udp_rx", 64 },
	{ "lte_imei", 45 },
	{ "lte_udp_tx", 63 },
	{ "lte_init_error", 52 },
	{ "lwm2m_bootstrap", 12 },
	{ "lte_imsi", 47 },
	{ "api_version", 1 },
	{ "p2p_key_path", 43 },
	{ "lwm2m_pwr_src", 18 },
	{ "lwm2m_fup_proxy_srv", 25 },
	{ "lwm2m_security", 9 }
};

static const signed char lookup[] = {
	-1, -1, -1, -1, -1, 0,	-1, 1,	-1, 2,	-1, -1, -1, -1, 3,  4,	5,  6,	7,  8,	-1, 9,
	10, -1, 11, -1, 12, 13, 14, -1, -1, 15, 16, 17, 18, -1, -1, -1, -1, 19, -1, -1, -1, -1,
	-1, -1, -1, 20, -1, 21, -1, 22, -1, 23, 24, -1, 25, -1, 26, 27, 28, 29, -1, 30, 31, 32,
	33, 34, 35, 36, -1, 37, 38, 39, 40, -1, 41, 42, -1, 43, -1, 44, 45, 46, 47, -1, -1, -1,
	48, 49, 50, -1, 51, 52, 53, -1, 54, -1, 55, 56, 57, 58, 59, 60, -1, -1, 61, 62, -1, -1,
	-1, 63, -1, -1, 64, 65, -1, -1, -1, 66, 67, -1, -1, -1, -1, 68, 69, 70, -1, 71, -1, -1,
	72, 73, -1, -1, -1, 74, 75, 76, 77, -1, -1, 78, -1, 79, -1, -1, -1, 80, -1, -1, -1, -1,
	-1, 81, -1, -1, -1, -1, -1, -1, -1, 82, -1, -1, -1, -1, -1, -1, -1, 83, -1, -1, -1, -1,
	-1, 84, -1, -1, -1, -1, -1, 85, 86, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 87
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
