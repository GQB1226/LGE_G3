#ifndef _ALPHA_USER_H
#define _ALPHA_USER_H

#include <linux/sched.h>
#include <linux/ptrace.h>

#include <asm/page.h>
#include <asm/reg.h>

/*
                                                                    
                                                                      
                                                                          
                  
  
                                                            
                                                         
                                                               
                                                                
                                                               
                      
                                                                     
                                                                     
                                                                    
                                                                    
                                                                    
                                               
                                                                     
                                                    
                                                                      
                                       
 */
struct user {
	unsigned long	regs[EF_SIZE/8+32];	/*                     */
	size_t		u_tsize;		/*                   */
	size_t		u_dsize;		/*                   */
	size_t		u_ssize;		/*                    */
	unsigned long	start_code;		/*                       */
	unsigned long	start_data;		/*                       */
	unsigned long	start_stack;		/*                        */
	long int	signal;			/*                          */
	unsigned long	u_ar0;			/*                         */
	unsigned long	magic;			/*                        */
	char		u_comm[32];		/*                   */
};

#define NBPG			PAGE_SIZE
#define UPAGES			1
#define HOST_TEXT_START_ADDR	(u.start_code)
#define HOST_DATA_START_ADDR	(u.start_data)
#define HOST_STACK_END_ADDR	(u.start_stack + u.u_ssize * NBPG)

#endif /*               */
