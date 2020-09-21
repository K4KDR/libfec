/* User include file for libfec
 * Copyright 2004, Phil Karn, KA9Q
 * May be used under the terms of the GNU Lesser General Public License (LGPL)
 */

#ifndef _FEC_H_
#define _FEC_H_

#pragma GCC diagnostic ignored "-Wconversion"

#if __has_include("fec_export.h")
#include "fec_export.h"
#else
#define FEC_EXPORT
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/* r=1/2 k=7 convolutional encoder polynomials
 * The NASA-DSN convention is to use V27POLYA inverted, then V27POLYB
 * The CCSDS/NASA-GSFC convention is to use V27POLYB, then V27POLYA inverted
 */
#define	V27POLYA	0x6d
#define	V27POLYB	0x4f

FEC_EXPORT void *create_viterbi27(int len);
FEC_EXPORT void set_viterbi27_polynomial(int polys[2]);
FEC_EXPORT int init_viterbi27(void *vp,int starting_state);
FEC_EXPORT int update_viterbi27_blk(void *vp,unsigned char sym[],int npairs);
FEC_EXPORT int chainback_viterbi27(void *vp, unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi27(void *vp);

#ifdef __VEC__
FEC_EXPORT void *create_viterbi27_av(int len);
FEC_EXPORT void set_viterbi27_polynomial_av(int polys[2]);
FEC_EXPORT int init_viterbi27_av(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi27_av(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi27_av(void *p);
FEC_EXPORT int update_viterbi27_blk_av(void *p,unsigned char *syms,int nbits);
#endif

#ifdef __i386__
FEC_EXPORT void *create_viterbi27_mmx(int len);
FEC_EXPORT void set_viterbi27_polynomial_mmx(int polys[2]);
FEC_EXPORT int init_viterbi27_mmx(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi27_mmx(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi27_mmx(void *p);
FEC_EXPORT int update_viterbi27_blk_mmx(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi27_sse(int len);
FEC_EXPORT void set_viterbi27_polynomial_sse(int polys[2]);
FEC_EXPORT int init_viterbi27_sse(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi27_sse(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi27_sse(void *p);
FEC_EXPORT int update_viterbi27_blk_sse(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi27_sse2(int len);
FEC_EXPORT void set_viterbi27_polynomial_sse2(int polys[2]);
FEC_EXPORT int init_viterbi27_sse2(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi27_sse2(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi27_sse2(void *p);
FEC_EXPORT int update_viterbi27_blk_sse2(void *p,unsigned char *syms,int nbits);
#endif

FEC_EXPORT void *create_viterbi27_port(int len);
FEC_EXPORT void set_viterbi27_polynomial_port(int polys[2]);
FEC_EXPORT int init_viterbi27_port(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi27_port(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi27_port(void *p);
FEC_EXPORT int update_viterbi27_blk_port(void *p,unsigned char *syms,int nbits);

/* r=1/2 k=9 convolutional encoder polynomials */
#define	V29POLYA	0x1af
#define	V29POLYB	0x11d

FEC_EXPORT void *create_viterbi29(int len);
FEC_EXPORT void set_viterbi29_polynomial(int polys[2]);
FEC_EXPORT int init_viterbi29(void *vp,int starting_state);
FEC_EXPORT int update_viterbi29_blk(void *vp,unsigned char syms[],int nbits);
FEC_EXPORT int chainback_viterbi29(void *vp, unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi29(void *vp);

#ifdef __VEC__
FEC_EXPORT void *create_viterbi29_av(int len);
FEC_EXPORT void set_viterbi29_polynomial_av(int polys[2]);
FEC_EXPORT int init_viterbi29_av(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi29_av(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi29_av(void *p);
FEC_EXPORT int update_viterbi29_blk_av(void *p,unsigned char *syms,int nbits);
#endif

#ifdef __i386__
FEC_EXPORT void *create_viterbi29_mmx(int len);
FEC_EXPORT void set_viterbi29_polynomial_mmx(int polys[2]);
FEC_EXPORT int init_viterbi29_mmx(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi29_mmx(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi29_mmx(void *p);
FEC_EXPORT int update_viterbi29_blk_mmx(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi29_sse(int len);
FEC_EXPORT void set_viterbi29_polynomial_sse(int polys[2]);
FEC_EXPORT int init_viterbi29_sse(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi29_sse(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi29_sse(void *p);
FEC_EXPORT int update_viterbi29_blk_sse(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi29_sse2(int len);
FEC_EXPORT void set_viterbi29_polynomial_sse2(int polys[2]);
FEC_EXPORT int init_viterbi29_sse2(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi29_sse2(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi29_sse2(void *p);
FEC_EXPORT int update_viterbi29_blk_sse2(void *p,unsigned char *syms,int nbits);
#endif

FEC_EXPORT void *create_viterbi29_port(int len);
FEC_EXPORT void set_viterbi29_polynomial_port(int polys[2]);
FEC_EXPORT int init_viterbi29_port(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi29_port(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi29_port(void *p);
FEC_EXPORT int update_viterbi29_blk_port(void *p,unsigned char *syms,int nbits);

/* r=1/3 k=9 convolutional encoder polynomials */
#define	V39POLYA	0x1ed
#define	V39POLYB	0x19b
#define	V39POLYC	0x127

FEC_EXPORT void *create_viterbi39(int len);
FEC_EXPORT void set_viterbi39_polynomial(int polys[3]);
FEC_EXPORT int init_viterbi39(void *vp,int starting_state);
FEC_EXPORT int update_viterbi39_blk(void *vp,unsigned char syms[],int nbits);
FEC_EXPORT int chainback_viterbi39(void *vp, unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi39(void *vp);

#ifdef __VEC__
FEC_EXPORT void *create_viterbi39_av(int len);
FEC_EXPORT void set_viterbi39_polynomial_av(int polys[3]);
FEC_EXPORT int init_viterbi39_av(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi39_av(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi39_av(void *p);
FEC_EXPORT int update_viterbi39_blk_av(void *p,unsigned char *syms,int nbits);
#endif

#ifdef __i386__
FEC_EXPORT void *create_viterbi39_mmx(int len);
FEC_EXPORT void set_viterbi39_polynomial_mmx(int polys[3]);
FEC_EXPORT int init_viterbi39_mmx(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi39_mmx(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi39_mmx(void *p);
FEC_EXPORT int update_viterbi39_blk_mmx(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi39_sse(int len);
FEC_EXPORT void set_viterbi39_polynomial_sse(int polys[3]);
FEC_EXPORT int init_viterbi39_sse(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi39_sse(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi39_sse(void *p);
FEC_EXPORT int update_viterbi39_blk_sse(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi39_sse2(int len);
FEC_EXPORT void set_viterbi39_polynomial_sse2(int polys[3]);
FEC_EXPORT int init_viterbi39_sse2(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi39_sse2(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi39_sse2(void *p);
FEC_EXPORT int update_viterbi39_blk_sse2(void *p,unsigned char *syms,int nbits);
#endif

FEC_EXPORT void *create_viterbi39_port(int len);
FEC_EXPORT void set_viterbi39_polynomial_port(int polys[3]);
FEC_EXPORT int init_viterbi39_port(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi39_port(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi39_port(void *p);
FEC_EXPORT int update_viterbi39_blk_port(void *p,unsigned char *syms,int nbits);


/* r=1/6 k=15 Cassini convolutional encoder polynomials without symbol inversion
 * dfree = 56
 * These bits may be left-right flipped from some textbook representations;
 * here I have the bits entering the shift register from the right (low) end
 *
 * Some other spacecraft use the same code, but with the polynomials in a different order.
 * E.g., Mars Pathfinder and STEREO swap POLYC and POLYD. All use alternate symbol inversion,
 * so use set_viterbi615_polynomial() as appropriate.
 */
#define	V615POLYA	042631
#define	V615POLYB	047245
#define V615POLYC       056507
#define V615POLYD       073363
#define V615POLYE       077267
#define V615POLYF       064537

FEC_EXPORT void *create_viterbi615(int len);
FEC_EXPORT void set_viterbi615_polynomial(int polys[6]);
FEC_EXPORT int init_viterbi615(void *vp,int starting_state);
FEC_EXPORT int update_viterbi615_blk(void *vp,unsigned char *syms,int nbits);
FEC_EXPORT int chainback_viterbi615(void *vp, unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi615(void *vp);

#ifdef __VEC__
FEC_EXPORT void *create_viterbi615_av(int len);
FEC_EXPORT void set_viterbi615_polynomial_av(int polys[6]);
FEC_EXPORT int init_viterbi615_av(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi615_av(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi615_av(void *p);
FEC_EXPORT int update_viterbi615_blk_av(void *p,unsigned char *syms,int nbits);
#endif

#ifdef __i386__
FEC_EXPORT void *create_viterbi615_mmx(int len);
FEC_EXPORT void set_viterbi615_polynomial_mmx(int polys[6]);
FEC_EXPORT int init_viterbi615_mmx(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi615_mmx(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi615_mmx(void *p);
FEC_EXPORT int update_viterbi615_blk_mmx(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi615_sse(int len);
FEC_EXPORT void set_viterbi615_polynomial_sse(int polys[6]);
FEC_EXPORT int init_viterbi615_sse(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi615_sse(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi615_sse(void *p);
FEC_EXPORT int update_viterbi615_blk_sse(void *p,unsigned char *syms,int nbits);

FEC_EXPORT void *create_viterbi615_sse2(int len);
FEC_EXPORT void set_viterbi615_polynomial_sse2(int polys[6]);
FEC_EXPORT int init_viterbi615_sse2(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi615_sse2(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi615_sse2(void *p);
FEC_EXPORT int update_viterbi615_blk_sse2(void *p,unsigned char *syms,int nbits);

#endif

FEC_EXPORT void *create_viterbi615_port(int len);
FEC_EXPORT void set_viterbi615_polynomial_port(int polys[6]);
FEC_EXPORT int init_viterbi615_port(void *p,int starting_state);
FEC_EXPORT int chainback_viterbi615_port(void *p,unsigned char *data,unsigned int nbits,unsigned int endstate);
FEC_EXPORT void delete_viterbi615_port(void *p);
FEC_EXPORT int update_viterbi615_blk_port(void *p,unsigned char *syms,int nbits);


/* General purpose RS codec, 8-bit symbols */
FEC_EXPORT void encode_rs_char(void *rs,unsigned char *data,unsigned char *parity);
FEC_EXPORT int decode_rs_char(void *rs,unsigned char *data,int *eras_pos,
		   int no_eras);
FEC_EXPORT void *init_rs_char(int symsize,int gfpoly,
		   int fcr,int prim,int nroots,
		   int pad);
FEC_EXPORT void free_rs_char(void *rs);

/* General purpose RS codec, integer symbols */
FEC_EXPORT void encode_rs_int(void *rs,int *data,int *parity);
FEC_EXPORT int decode_rs_int(void *rs,int *data,int *eras_pos,int no_eras);
FEC_EXPORT void *init_rs_int(int symsize,int gfpoly,int fcr,
		  int prim,int nroots,int pad);
FEC_EXPORT void free_rs_int(void *rs);

/* CCSDS standard (255,223) RS codec with conventional (*not* dual-basis)
 * symbol representation
 */
FEC_EXPORT void encode_rs_8(unsigned char *data,unsigned char *parity,int pad);
FEC_EXPORT int decode_rs_8(unsigned char *data,int *eras_pos,int no_eras,int pad);

/* CCSDS standard (255,223) RS codec with dual-basis symbol representation */
FEC_EXPORT void encode_rs_ccsds(unsigned char *data,unsigned char *parity,int pad);
FEC_EXPORT int decode_rs_ccsds(unsigned char *data,int *eras_pos,int no_eras,int pad);

/* Tables to map from conventional->dual (Taltab) and
 * dual->conventional (Tal1tab) bases
 */
extern unsigned char Taltab[],Tal1tab[];


/* CPU SIMD instruction set available */
extern enum cpu_mode {UNKNOWN=0,PORT,MMX,SSE,SSE2,ALTIVEC} Cpu_mode;
FEC_EXPORT void find_cpu_mode(void); /* Call this once at startup to set Cpu_mode */

/* Determine parity of argument: 1 = odd, 0 = even */
#ifdef __i386__
static inline int parityb(unsigned char x){
  __asm__ __volatile__ ("test %1,%1;setpo %0" : "=q"(x) : "q" (x));
  return x;
}
#else
FEC_EXPORT void partab_init();

static inline int parityb(unsigned char x){
  extern unsigned char Partab[256];
  extern int P_init;
  if(!P_init){
    partab_init();
  }
  return Partab[x];
}
#endif


static inline int parity(int x){
  /* Fold down to one byte */
  x ^= (x >> 16);
  x ^= (x >> 8);
  return parityb(x);
}

/* Useful utilities for simulation */
FEC_EXPORT double normal_rand(double mean, double std_dev);
FEC_EXPORT unsigned char addnoise(int sym,double amp,double gain,double offset,int clip);

extern int Bitcnt[];

/* Dot product functions */
FEC_EXPORT  void *initdp(signed short coeffs[],int len);
FEC_EXPORT void freedp(void *dp);
FEC_EXPORT long dotprod(void *dp,signed short a[]);

FEC_EXPORT void *initdp_port(signed short coeffs[],int len);
FEC_EXPORT void freedp_port(void *dp);
FEC_EXPORT long dotprod_port(void *dp,signed short a[]);

#ifdef __i386__
FEC_EXPORT void *initdp_mmx(signed short coeffs[],int len);
FEC_EXPORT void freedp_mmx(void *dp);
FEC_EXPORT long dotprod_mmx(void *dp,signed short a[]);

FEC_EXPORT void *initdp_sse(signed short coeffs[],int len);
FEC_EXPORT void freedp_sse(void *dp);
FEC_EXPORT long dotprod_sse(void *dp,signed short a[]);

FEC_EXPORT void *initdp_sse2(signed short coeffs[],int len);
FEC_EXPORT void freedp_sse2(void *dp);
FEC_EXPORT long dotprod_sse2(void *dp,signed short a[]);
#endif

#ifdef __VEC__
FEC_EXPORT void *initdp_av(signed short coeffs[],int len);
FEC_EXPORT void freedp_av(void *dp);
FEC_EXPORT long dotprod_av(void *dp,signed short a[]);
#endif

/* Sum of squares - accepts signed shorts, produces unsigned long long */
FEC_EXPORT unsigned long long sumsq(signed short *in,int cnt);
FEC_EXPORT unsigned long long sumsq_port(signed short *in,int cnt);

#ifdef __i386__
FEC_EXPORT unsigned long long sumsq_mmx(signed short *in,int cnt);
FEC_EXPORT unsigned long long sumsq_sse(signed short *in,int cnt);
FEC_EXPORT unsigned long long sumsq_sse2(signed short *in,int cnt);
#endif
#ifdef __VEC__
FEC_EXPORT unsigned long long sumsq_av(signed short *in,int cnt);
#endif


/* Low-level data structures and routines */

FEC_EXPORT int cpu_features(void);

#ifdef __cplusplus
} /* END extern "C" */
#endif

#endif /* _FEC_H_ */



