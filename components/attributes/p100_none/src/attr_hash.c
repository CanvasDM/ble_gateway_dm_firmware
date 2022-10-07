/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -C -c -G -D -t -T --word-array-name=word_list --lookup-function-name=attr_id_from_hash --hash-function-name=gperf_hash --output-file=/Users/ryan/git/zephyr_workspace/ble_gateway_dm_firmware/components/attributes/p100_none/src/attr_hash.c /Users/ryan/git/zephyr_workspace/ble_gateway_dm_firmware/components/attributes/p100_none/src/attr.gperf  */
/* Computed positions: -k'2,5,7,9,15' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif


#include "attr_hash.h"

#define TOTAL_KEYWORDS 68
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 19
#define MIN_HASH_VALUE 8
#define MAX_HASH_VALUE 124
/* maximum key range = 117, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
gperf_hash (register const char *str, register size_t len)
{
  static const unsigned char asso_values[] =
    {
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125,  45, 125,
        0, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125,   0, 125,  10,  75,  75,
       10,  15,  20,   0,  35,  25, 125,  25,   0,   0,
       15,   0,  30,   0,   0,  10,   5,  20,  20,   0,
      125,  25, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125, 125, 125, 125, 125,
      125, 125, 125, 125, 125, 125
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[14]];
      /*FALLTHROUGH*/
      case 14:
      case 13:
      case 12:
      case 11:
      case 10:
      case 9:
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
  return hval;
}

static const struct attr_hash_entry word_list[] =
  {
    {"lwm2m_mn", 15},
    {"lwm2m_mfg", 14},
    {"log_on_boot", 6},
    {"lte_rsrp", 54},
    {"board", 5},
    {"lte_log_lvl", 61},
    {"lte_rat", 60},
    {"lwm2m_sn", 16},
    {"lte_sn", 48},
    {"lwm2m_sw_ver", 20},
    {"dm_trust_path", 38},
    {"lwm2m_short_id", 13},
    {"lwm2m_server_url", 7},
    {"smp_auth_req", 32},
    {"lwm2m_fw_ver", 17},
    {"fs_trust_path", 40},
    {"lte_data_total", 67},
    {"gw_smp_auth_req", 33},
    {"dm_key_path", 39},
    {"lte_apn", 53},
    {"lte_sinr", 55},
    {"lwm2m_endpoint", 8},
    {"firmware_version", 2},
    {"dm_cnx_delay", 27},
    {"lwm2m_pwr_src", 18},
    {"p2p_trust_path", 42},
    {"fs_key_path", 41},
    {"lwm2m_hw_ver", 21},
    {"lte_imsi", 47},
    {"ipv4_addr", 44},
    {"lte_tcp_rx", 66},
    {"smp_auth_timeout", 34},
    {"lte_network_state", 50},
    {"lte_imei", 45},
    {"load_path", 4},
    {"lte_tcp_tx", 65},
    {"dm_cnx_delay_max", 29},
    {"lte_startup_state", 51},
    {"tel_trust_path", 36},
    {"lte_version", 49},
    {"factory_load_path", 30},
    {"lte_operator_index", 58},
    {"lwm2m_psk", 11},
    {"lte_udp_rx", 64},
    {"lte_active_bands", 57},
    {"lwm2m_psk_id", 10},
    {"lwm2m_pwr_src_volt", 19},
    {"lte_init_error", 52},
    {"lte_udp_tx", 63},
    {"dm_cnx_delay_min", 28},
    {"bluetooth_address", 26},
    {"dump_path", 3},
    {"lte_fup_status", 62},
    {"lwm2m_fup_pkg_name", 23},
    {"reserved0", 0},
    {"api_version", 1},
    {"lwm2m_fup_pkg_ver", 24},
    {"shell_password", 35},
    {"lte_sleep_state", 59},
    {"p2p_key_path", 43},
    {"lwm2m_fup_proxy_srv", 25},
    {"lwm2m_security", 9},
    {"lwm2m_batt_stat", 22},
    {"tel_key_path", 37},
    {"device_id", 31},
    {"lte_bands", 56},
    {"lwm2m_bootstrap", 12},
    {"lte_iccid", 46}
  };

static const signed char lookup[] =
  {
    -1, -1, -1, -1, -1, -1, -1, -1,  0,  1, -1,  2, -1,  3,
    -1,  4,  5,  6,  7, -1, -1,  8,  9, 10, 11, -1, 12, 13,
    -1, -1, -1, -1, 14, 15, 16, 17, 18, 19, 20, 21, -1, 22,
    23, 24, 25, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
    36, 37, -1, 38, -1, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, -1, 51, -1, -1, -1, -1, 52, -1, -1, -1, 53,
    54, -1, 55, 56, -1, 57, 58, -1, 59, -1, 60, -1, -1, -1,
    -1, 61, 62, -1, -1, -1, -1, -1, -1, 63, -1, 64, -1, -1,
    -1, -1, 65, -1, -1, -1, -1, -1, 66, -1, -1, -1, 67
  };

const struct attr_hash_entry *
attr_id_from_hash (register const char *str, register size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = gperf_hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = word_list[index].name;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &word_list[index];
            }
        }
    }
  return 0;
}