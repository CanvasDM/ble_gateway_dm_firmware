/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -C -c -G -D -t -T --word-array-name=word_list --lookup-function-name=attr_id_from_hash --hash-function-name=gperf_hash --output-file=/Users/ryan/git/zephyr_workspace/ble_gateway_dm_firmware/components/attributes/bl5340_none/src/attr_hash.c /Users/ryan/git/zephyr_workspace/ble_gateway_dm_firmware/components/attributes/bl5340_none/src/attr.gperf  */
/* Computed positions: -k'1,7,$' */

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

#define TOTAL_KEYWORDS 45
#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 19
#define MIN_HASH_VALUE 10
#define MAX_HASH_VALUE 89
/* maximum key range = 80, duplicates = 0 */

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
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90,  0, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90,  5, 90,  5,  0,  0,
       5, 40, 10, 40, 20, 20, 90, 50,  0,  5,
       5, 15, 10,  0, 40,  0,  5,  5, 35, 90,
      10,  0, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 90, 90, 90, 90, 90
    };
  register unsigned int hval = len;

  switch (hval)
    {
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

static const struct attr_hash_entry word_list[] =
  {
    {"board", 5},
    {"lwm2m_sn", 16},
    {"lwm2m_security", 9},
    {"lwm2m_server_url", 7},
    {"smp_auth_req", 32},
    {"lwm2m_mn", 15},
    {"lwm2m_short_id", 13},
    {"lwm2m_batt_stat", 22},
    {"log_on_boot", 6},
    {"dm_cnx_delay", 27},
    {"lwm2m_pwr_src", 18},
    {"device_id", 31},
    {"lwm2m_bootstrap", 12},
    {"smp_auth_timeout", 34},
    {"lwm2m_psk_id", 10},
    {"shell_password", 35},
    {"dm_cnx_delay_min", 28},
    {"bluetooth_address", 26},
    {"lwm2m_pwr_src_volt", 19},
    {"load_path", 4},
    {"dm_cnx_delay_max", 29},
    {"tel_key_path", 37},
    {"dm_trust_path", 38},
    {"dump_path", 3},
    {"dm_key_path", 39},
    {"p2p_key_path", 43},
    {"fs_trust_path", 40},
    {"tel_trust_path", 36},
    {"fs_key_path", 41},
    {"factory_load_path", 30},
    {"p2p_trust_path", 42},
    {"lwm2m_sw_ver", 20},
    {"lwm2m_mfg", 14},
    {"lwm2m_endpoint", 8},
    {"gw_smp_auth_req", 33},
    {"api_version", 1},
    {"lwm2m_fw_ver", 17},
    {"lwm2m_fup_proxy_srv", 25},
    {"lwm2m_fup_pkg_ver", 24},
    {"lwm2m_fup_pkg_name", 23},
    {"lwm2m_psk", 11},
    {"firmware_version", 2},
    {"lwm2m_hw_ver", 21},
    {"ipv4_addr", 44},
    {"reserved0", 0}
  };

static const signed char lookup[] =
  {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1,  1,
     2, -1,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    -1, 15, -1, 16, 17, 18, 19, -1, 20, 21, 22, 23, -1, 24,
    25, 26, 27, -1, 28, 29, -1, 30, -1, -1, 31, -1, 32, -1,
    -1, -1, -1, 33, 34, 35, 36, -1, 37, -1, -1, 38, 39, 40,
    -1, 41, 42, -1, 43, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 44
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
