#ifndef _ASM_GENERIC_TERMIOS_H
#define _ASM_GENERIC_TERMIOS_H
/*
                                                                
                                                               
                                                               
               
                                                          
 */

#include <asm/termbits.h>
#include <asm/ioctls.h>

struct winsize {
	unsigned short ws_row;
	unsigned short ws_col;
	unsigned short ws_xpixel;
	unsigned short ws_ypixel;
};

#define NCC 8
struct termio {
	unsigned short c_iflag;		/*                  */
	unsigned short c_oflag;		/*                   */
	unsigned short c_cflag;		/*                    */
	unsigned short c_lflag;		/*                  */
	unsigned char c_line;		/*                 */
	unsigned char c_cc[NCC];	/*                    */
};

/*             */
#define TIOCM_LE	0x001
#define TIOCM_DTR	0x002
#define TIOCM_RTS	0x004
#define TIOCM_ST	0x008
#define TIOCM_SR	0x010
#define TIOCM_CTS	0x020
#define TIOCM_CAR	0x040
#define TIOCM_RNG	0x080
#define TIOCM_DSR	0x100
#define TIOCM_CD	TIOCM_CAR
#define TIOCM_RI	TIOCM_RNG
#define TIOCM_OUT1	0x2000
#define TIOCM_OUT2	0x4000
#define TIOCM_LOOP	0x8000

/*                                                                 */

#ifdef __KERNEL__

#include <asm/uaccess.h>

/*                                    
                                  
                                  
                                         
        
*/
#define INIT_C_CC "\003\034\177\025\004\0\1\0\021\023\032\0\022\017\027\026\0"

/*
                                                        
 */
static inline int user_termio_to_kernel_termios(struct ktermios *termios,
						const struct termio __user *termio)
{
	unsigned short tmp;

	if (get_user(tmp, &termio->c_iflag) < 0)
		goto fault;
	termios->c_iflag = (0xffff0000 & termios->c_iflag) | tmp;

	if (get_user(tmp, &termio->c_oflag) < 0)
		goto fault;
	termios->c_oflag = (0xffff0000 & termios->c_oflag) | tmp;

	if (get_user(tmp, &termio->c_cflag) < 0)
		goto fault;
	termios->c_cflag = (0xffff0000 & termios->c_cflag) | tmp;

	if (get_user(tmp, &termio->c_lflag) < 0)
		goto fault;
	termios->c_lflag = (0xffff0000 & termios->c_lflag) | tmp;

	if (get_user(termios->c_line, &termio->c_line) < 0)
		goto fault;

	if (copy_from_user(termios->c_cc, termio->c_cc, NCC) != 0)
		goto fault;

	return 0;

 fault:
	return -EFAULT;
}

/*
                                                        
 */
static inline int kernel_termios_to_user_termio(struct termio __user *termio,
						struct ktermios *termios)
{
	if (put_user(termios->c_iflag, &termio->c_iflag) < 0 ||
	    put_user(termios->c_oflag, &termio->c_oflag) < 0 ||
	    put_user(termios->c_cflag, &termio->c_cflag) < 0 ||
	    put_user(termios->c_lflag, &termio->c_lflag) < 0 ||
	    put_user(termios->c_line,  &termio->c_line) < 0 ||
	    copy_to_user(termio->c_cc, termios->c_cc, NCC) != 0)
		return -EFAULT;

	return 0;
}

#ifdef TCGETS2
static inline int user_termios_to_kernel_termios(struct ktermios *k,
						 struct termios2 __user *u)
{
	return copy_from_user(k, u, sizeof(struct termios2));
}

static inline int kernel_termios_to_user_termios(struct termios2 __user *u,
						 struct ktermios *k)
{
	return copy_to_user(u, k, sizeof(struct termios2));
}

static inline int user_termios_to_kernel_termios_1(struct ktermios *k,
						   struct termios __user *u)
{
	return copy_from_user(k, u, sizeof(struct termios));
}

static inline int kernel_termios_to_user_termios_1(struct termios __user *u,
						   struct ktermios *k)
{
	return copy_to_user(u, k, sizeof(struct termios));
}
#else /*         */
static inline int user_termios_to_kernel_termios(struct ktermios *k,
						 struct termios __user *u)
{
	return copy_from_user(k, u, sizeof(struct termios));
}

static inline int kernel_termios_to_user_termios(struct termios __user *u,
						 struct ktermios *k)
{
	return copy_to_user(u, k, sizeof(struct termios));
}
#endif /*         */

#endif	/*            */

#endif /*                        */
