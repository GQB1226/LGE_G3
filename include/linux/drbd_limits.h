/*
               
                                                                  
*/

/*
                           
                                
                                                                          
                                                                    
 */

#ifndef DRBD_LIMITS_H
#define DRBD_LIMITS_H 1

#define DEBUG_RANGE_CHECK 0

#define DRBD_MINOR_COUNT_MIN 1
#define DRBD_MINOR_COUNT_MAX 256
#define DRBD_MINOR_COUNT_DEF 32

#define DRBD_DIALOG_REFRESH_MIN 0
#define DRBD_DIALOG_REFRESH_MAX 600

/*                   */
#define DRBD_PORT_MIN 1
#define DRBD_PORT_MAX 0xffff

/*           */
  /*                                         */
#define DRBD_WFC_TIMEOUT_MIN 0
#define DRBD_WFC_TIMEOUT_MAX 300000
#define DRBD_WFC_TIMEOUT_DEF 0

#define DRBD_DEGR_WFC_TIMEOUT_MIN 0
#define DRBD_DEGR_WFC_TIMEOUT_MAX 300000
#define DRBD_DEGR_WFC_TIMEOUT_DEF 0

#define DRBD_OUTDATED_WFC_TIMEOUT_MIN 0
#define DRBD_OUTDATED_WFC_TIMEOUT_MAX 300000
#define DRBD_OUTDATED_WFC_TIMEOUT_DEF 0
/*  */

/*       */
  /*                            
                                                */
#define DRBD_TIMEOUT_MIN 1
#define DRBD_TIMEOUT_MAX 600
#define DRBD_TIMEOUT_DEF 60       /*           */

  /*                                                */
#define DRBD_CONNECT_INT_MIN 1
#define DRBD_CONNECT_INT_MAX 120
#define DRBD_CONNECT_INT_DEF 10   /*         */

  /*                             */
#define DRBD_PING_INT_MIN 1
#define DRBD_PING_INT_MAX 120
#define DRBD_PING_INT_DEF 10

 /*                              */
#define DRBD_PING_TIMEO_MIN  1
#define DRBD_PING_TIMEO_MAX  100
#define DRBD_PING_TIMEO_DEF  5

  /*                                                     */
#define DRBD_MAX_EPOCH_SIZE_MIN 1
#define DRBD_MAX_EPOCH_SIZE_MAX 20000
#define DRBD_MAX_EPOCH_SIZE_DEF 2048

  /*                                                                 */
#define DRBD_SNDBUF_SIZE_MIN  0
#define DRBD_SNDBUF_SIZE_MAX  (10<<20)
#define DRBD_SNDBUF_SIZE_DEF  0

#define DRBD_RCVBUF_SIZE_MIN  0
#define DRBD_RCVBUF_SIZE_MAX  (10<<20)
#define DRBD_RCVBUF_SIZE_DEF  0

  /*                               */
#define DRBD_MAX_BUFFERS_MIN  32
#define DRBD_MAX_BUFFERS_MAX  131072
#define DRBD_MAX_BUFFERS_DEF  2048

  /*                             */
#define DRBD_UNPLUG_WATERMARK_MIN  1
#define DRBD_UNPLUG_WATERMARK_MAX  131072
#define DRBD_UNPLUG_WATERMARK_DEF (DRBD_MAX_BUFFERS_DEF/16)

  /*               
                                                                 */
#define DRBD_KO_COUNT_MIN  0
#define DRBD_KO_COUNT_MAX  200
#define DRBD_KO_COUNT_DEF  0
/*   */

/*          */
  /*                              */
#define DRBD_RATE_MIN 1
/*                                           */
#define DRBD_RATE_MAX (4 << 20)
#define DRBD_RATE_DEF 250  /*           */

  /*                                                 
                                                  
                                     */
#define DRBD_AL_EXTENTS_MIN  7
#define DRBD_AL_EXTENTS_MAX  3833
#define DRBD_AL_EXTENTS_DEF  127

#define DRBD_AFTER_MIN  -1
#define DRBD_AFTER_MAX  255
#define DRBD_AFTER_DEF  -1

/*   */

/*                         
                                                                     
                                                                       
                        */
/*                  */
#define DRBD_DISK_SIZE_SECT_MIN  0
#define DRBD_DISK_SIZE_SECT_MAX  (1 * (2LLU << 40))
#define DRBD_DISK_SIZE_SECT_DEF  0 /*                              */

#define DRBD_ON_IO_ERROR_DEF EP_PASS_ON
#define DRBD_FENCING_DEF FP_DONT_CARE
#define DRBD_AFTER_SB_0P_DEF ASB_DISCONNECT
#define DRBD_AFTER_SB_1P_DEF ASB_DISCONNECT
#define DRBD_AFTER_SB_2P_DEF ASB_DISCONNECT
#define DRBD_RR_CONFLICT_DEF ASB_DISCONNECT
#define DRBD_ON_NO_DATA_DEF OND_IO_ERROR
#define DRBD_ON_CONGESTION_DEF OC_BLOCK

#define DRBD_MAX_BIO_BVECS_MIN 0
#define DRBD_MAX_BIO_BVECS_MAX 128
#define DRBD_MAX_BIO_BVECS_DEF 0

#define DRBD_C_PLAN_AHEAD_MIN  0
#define DRBD_C_PLAN_AHEAD_MAX  300
#define DRBD_C_PLAN_AHEAD_DEF  0 /*                                        */

#define DRBD_C_DELAY_TARGET_MIN 1
#define DRBD_C_DELAY_TARGET_MAX 100
#define DRBD_C_DELAY_TARGET_DEF 10

#define DRBD_C_FILL_TARGET_MIN 0
#define DRBD_C_FILL_TARGET_MAX (1<<20) /*                 */
#define DRBD_C_FILL_TARGET_DEF 0 /*                                                   */

#define DRBD_C_MAX_RATE_MIN     250 /*           */
#define DRBD_C_MAX_RATE_MAX     (4 << 20)
#define DRBD_C_MAX_RATE_DEF     102400

#define DRBD_C_MIN_RATE_MIN     0 /*           */
#define DRBD_C_MIN_RATE_MAX     (4 << 20)
#define DRBD_C_MIN_RATE_DEF     4096

#define DRBD_CONG_FILL_MIN	0
#define DRBD_CONG_FILL_MAX	(10<<21) /*                    */
#define DRBD_CONG_FILL_DEF	0

#define DRBD_CONG_EXTENTS_MIN	DRBD_AL_EXTENTS_MIN
#define DRBD_CONG_EXTENTS_MAX	DRBD_AL_EXTENTS_MAX
#define DRBD_CONG_EXTENTS_DEF	DRBD_AL_EXTENTS_DEF

#undef RANGE
#endif
