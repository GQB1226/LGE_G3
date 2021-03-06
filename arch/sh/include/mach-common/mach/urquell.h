#ifndef __MACH_URQUELL_H
#define __MACH_URQUELL_H

/*
                                                         
                                               
                                                         
                                                        
                                                         
                            
         
                                                         
                            
                                                         
                                                  
                                                         
                                       
                                                         
                                       
                                                         
 */

#define NOR_FLASH_ADDR	0x00000000
#define NOR_FLASH_SIZE	0x04000000

#define CS1_BASE	0x05000000
#define CS5_BASE	0x15000000
#define FPGA_BASE	CS1_BASE

#define BOARDREG(ofs)	(FPGA_BASE + ofs##_OFS)
#define UBOARDREG(ofs)	(0xa0000000 + FPGA_BASE + ofs##_OFS)

#define SRSTR_OFS	0x0000 /*                       */
#define BDMR_OFS	0x0010 /*                               */
#define IRL0SR_OFS	0x0020 /*                      */
#define IRL0MSKR_OFS	0x0030 /*                    */
#define IRL1SR_OFS	0x0040 /*                      */
#define IRL1MSKR_OFS	0x0050 /*                    */
#define IRL2SR_OFS	0x0060 /*                      */
#define IRL2MSKR_OFS	0x0070 /*                    */
#define IRL3SR_OFS	0x0080 /*                      */
#define IRL3MSKR_OFS	0x0090 /*                    */
#define SOFTINTR_OFS	0x0120 /*                             */
#define SLEDR_OFS	0x0130 /*                      */
#define MAPSCIFSWR_OFS	0x0140 /*                          */
#define FPVERR_OFS	0x0150 /*                       */
#define FPDATER_OFS	0x0160 /*                    */
#define FPYEARR_OFS	0x0170 /*                    */
#define TCLKCR_OFS	0x0180 /*                       */
#define DIPSWMR_OFS	0x1000 /*                        */
#define FPODR_OFS	0x1010 /*                           */
#define ATACNR_OFS	0x1020 /*                                */
#define FPINDR_OFS	0x1030 /*                          */
#define MDSWMR_OFS	0x1040 /*                          */
#define DDR3BUPCR_OFS	0x1050 /*                              */
#define SSICODECCR_OFS	0x1060 /*                            */
#define PCIESLOTSR_OFS	0x1070 /*                                 */
#define ETHERPORTSR_OFS	0x1080 /*                               */
#define LATCHCR_OFS	0x3000 /*                        */
#define LATCUAR_OFS	0x3010 /*                              */
#define LATCLAR_OFS	0x3012 /*                              */
#define LATCLUDR_OFS	0x3024 /*                       */
#define LATCLLDR_OFS	0x3026 /*                      */

#define CHARLED_OFS	0x2000 /*               */

#endif  /*                  */

