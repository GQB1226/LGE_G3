/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 1998, 1999, 2001, 2003 Ralf Baechle
 * Copyright (C) 2000, 2001 Silicon Graphics, Inc.
 */
#ifndef _ASM_SIGINFO_H
#define _ASM_SIGINFO_H


#define __ARCH_SIGEV_PREAMBLE_SIZE (sizeof(long) + 2*sizeof(int))
#undef __ARCH_SI_TRAPNO	/*                                        */

#define HAVE_ARCH_SIGINFO_T

/*
                                                                             
                
 */
#define HAVE_ARCH_COPY_SIGINFO
struct siginfo;

/*
                                                    
 */
#ifdef CONFIG_32BIT
#define __ARCH_SI_PREAMBLE_SIZE (3 * sizeof(int))
#endif
#ifdef CONFIG_64BIT
#define __ARCH_SI_PREAMBLE_SIZE (4 * sizeof(int))
#endif

#include <asm-generic/siginfo.h>

typedef struct siginfo {
	int si_signo;
	int si_code;
	int si_errno;
	int __pad0[SI_MAX_SIZE / sizeof(int) - SI_PAD_SIZE - 3];

	union {
		int _pad[SI_PAD_SIZE];

		/*        */
		struct {
			pid_t _pid;		/*              */
			__ARCH_SI_UID_T _uid;	/*              */
		} _kill;

		/*                 */
		struct {
			timer_t _tid;		/*          */
			int _overrun;		/*               */
			char _pad[sizeof( __ARCH_SI_UID_T) - sizeof(int)];
			sigval_t _sigval;	/*               */
			int _sys_private;       /*                          */
		} _timer;

		/*                  */
		struct {
			pid_t _pid;		/*              */
			__ARCH_SI_UID_T _uid;	/*              */
			sigval_t _sigval;
		} _rt;

		/*         */
		struct {
			pid_t _pid;		/*             */
			__ARCH_SI_UID_T _uid;	/*              */
			int _status;		/*           */
			clock_t _utime;
			clock_t _stime;
		} _sigchld;

		/*              */
		struct {
			pid_t _pid;		/*             */
			clock_t _utime;
			int _status;		/*           */
			clock_t _stime;
		} _irix_sigchld;

		/*                                 */
		struct {
			void __user *_addr; /*                           */
#ifdef __ARCH_SI_TRAPNO
			int _trapno;	/*                                */
#endif
			short _addr_lsb;
		} _sigfault;

		/*                               */
		struct {
			__ARCH_SI_BAND_T _band;	/*                             */
			int _fd;
		} _sigpoll;
	} _sifields;
} siginfo_t;

/*
                 
                                                      
 */
#undef SI_ASYNCIO
#undef SI_TIMER
#undef SI_MESGQ
#define SI_ASYNCIO	-2	/*                        */
#define SI_TIMER __SI_CODE(__SI_TIMER, -3) /*                          */
#define SI_MESGQ __SI_CODE(__SI_MESGQ, -4) /*                                     */

#ifdef __KERNEL__

/*
                                                                     
 */
#include <linux/string.h>

static inline void copy_siginfo(struct siginfo *to, struct siginfo *from)
{
	if (from->si_code < 0)
		memcpy(to, from, sizeof(*to));
	else
		/*                                                     */
		memcpy(to, from, 3*sizeof(int) + sizeof(from->_sifields._sigchld));
}

#endif

#endif /*                */
