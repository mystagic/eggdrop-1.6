/* 
 * blowfish.h -- part of blowfish.mod
 * 
 * modified 19jul1996 by robey -- uses autoconf values now
 * 
 * $Id: blowfish.h,v 1.4 2000/01/02 02:42:10 fabian Exp $
 */

#ifndef _EGG_MOD_BLOWFISH_BLOWFISH_H
#define _EGG_MOD_BLOWFISH_BLOWFISH_H

#define MAXKEYBYTES 56		/* 448 bits */
#define bf_N             16
#define noErr            0
#define DATAERROR        -1
#define KEYBYTES         8

#define UBYTE_08bits  u_8bit_t
#define UWORD_16bits  u_16bit_t
#define UWORD_32bits  u_32bit_t

/* choose a byte order for your hardware */

#ifdef WORDS_BIGENDIAN
/* ABCD - big endian - motorola */
union aword {
  UWORD_32bits word;
  UBYTE_08bits byte[4];
  struct {
    unsigned int byte0:8;
    unsigned int byte1:8;
    unsigned int byte2:8;
    unsigned int byte3:8;
  } w;
};

#endif				/* WORDS_BIGENDIAN */

#ifndef WORDS_BIGENDIAN
/* DCBA - little endian - intel */
union aword {
  UWORD_32bits word;
  UBYTE_08bits byte[4];
  struct {
    unsigned int byte3:8;
    unsigned int byte2:8;
    unsigned int byte1:8;
    unsigned int byte0:8;
  } w;
};

#endif				/* !WORDS_BIGENDIAN */

#endif				/* _EGG_MOD_BLOWFISH_BLOWFISH_H */
