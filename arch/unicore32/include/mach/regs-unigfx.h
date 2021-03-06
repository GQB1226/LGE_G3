/*
                           
 */

#define UDE_BASE      (PKUNITY_UNIGFX_BASE + 0x1400)
#define UGE_BASE      (PKUNITY_UNIGFX_BASE + 0x0000)

/*
                            
 */
/*
                      
 */
#define UDE_CFG       (UDE_BASE + 0x0000)
/*
                                        
 */
#define UDE_FSA       (UDE_BASE + 0x0004)
/*
                       
 */
#define UDE_LS        (UDE_BASE + 0x0008)
/*
                        
 */
#define UDE_PS        (UDE_BASE + 0x000C)
/*
                                     
 */
#define UDE_HAT       (UDE_BASE + 0x0010)
/*
                                    
 */
#define UDE_HBT       (UDE_BASE + 0x0014)
/*
                                   
 */
#define UDE_HST       (UDE_BASE + 0x0018)
/*
                                   
 */
#define UDE_VAT       (UDE_BASE + 0x001C)
/*
                                  
 */
#define UDE_VBT       (UDE_BASE + 0x0020)
/*
                                 
 */
#define UDE_VST       (UDE_BASE + 0x0024)
/*
                          
 */
#define UDE_CXY       (UDE_BASE + 0x0028)
/*
                             
 */
#define UDE_CC0       (UDE_BASE + 0x002C)
/*
                                  
 */
#define UDE_CC1       (UDE_BASE + 0x0030)
/*
                         
 */
#define UDE_VXY       (UDE_BASE + 0x0034)
/*
                                  
 */
#define UDE_VSA       (UDE_BASE + 0x0040)
/*
                        
 */
#define UDE_VS        (UDE_BASE + 0x004C)

/*
                            
 */
/*
                       
 */
#define UGE_SRCXY     (UGE_BASE + 0x0000)
/*
                       
 */
#define UGE_DSTXY     (UGE_BASE + 0x0004)
/*
                      
 */
#define UGE_PITCH     (UGE_BASE + 0x0008)
/*
                             
 */
#define UGE_SRCSTART  (UGE_BASE + 0x000C)
/*
                             
 */
#define UGE_DSTSTART  (UGE_BASE + 0x0010)
/*
                                 
 */
#define UGE_WIDHEIGHT (UGE_BASE + 0x0014)
/*
                             
 */
#define UGE_ROPALPHA  (UGE_BASE + 0x0018)
/*
                         
 */
#define UGE_FCOLOR    (UGE_BASE + 0x001C)
/*
                              
 */
#define UGE_BCOLOR    (UGE_BASE + 0x0020)
/*
                                       
 */
#define UGE_SCH       (UGE_BASE + 0x0024)
/*
                                       
 */
#define UGE_DCH       (UGE_BASE + 0x0028)
/*
                                      
 */
#define UGE_SCL       (UGE_BASE + 0x002C)
/*
                                      
 */
#define UGE_DCL       (UGE_BASE + 0x0030)
/*
                       
 */
#define UGE_CLIP0     (UGE_BASE + 0x0034)
/*
                       
 */
#define UGE_CLIP1     (UGE_BASE + 0x0038)
/*
                          
 */
#define UGE_COMMAND   (UGE_BASE + 0x003C)
/*
                   
 */
#define UGE_P0        (UGE_BASE + 0x0040)
#define UGE_P1        (UGE_BASE + 0x0044)
#define UGE_P2        (UGE_BASE + 0x0048)
#define UGE_P3        (UGE_BASE + 0x004C)
#define UGE_P4        (UGE_BASE + 0x0050)
#define UGE_P5        (UGE_BASE + 0x0054)
#define UGE_P6        (UGE_BASE + 0x0058)
#define UGE_P7        (UGE_BASE + 0x005C)
#define UGE_P8        (UGE_BASE + 0x0060)
#define UGE_P9        (UGE_BASE + 0x0064)
#define UGE_P10       (UGE_BASE + 0x0068)
#define UGE_P11       (UGE_BASE + 0x006C)
#define UGE_P12       (UGE_BASE + 0x0070)
#define UGE_P13       (UGE_BASE + 0x0074)
#define UGE_P14       (UGE_BASE + 0x0078)
#define UGE_P15       (UGE_BASE + 0x007C)
#define UGE_P16       (UGE_BASE + 0x0080)
#define UGE_P17       (UGE_BASE + 0x0084)
#define UGE_P18       (UGE_BASE + 0x0088)
#define UGE_P19       (UGE_BASE + 0x008C)
#define UGE_P20       (UGE_BASE + 0x0090)
#define UGE_P21       (UGE_BASE + 0x0094)
#define UGE_P22       (UGE_BASE + 0x0098)
#define UGE_P23       (UGE_BASE + 0x009C)
#define UGE_P24       (UGE_BASE + 0x00A0)
#define UGE_P25       (UGE_BASE + 0x00A4)
#define UGE_P26       (UGE_BASE + 0x00A8)
#define UGE_P27       (UGE_BASE + 0x00AC)
#define UGE_P28       (UGE_BASE + 0x00B0)
#define UGE_P29       (UGE_BASE + 0x00B4)
#define UGE_P30       (UGE_BASE + 0x00B8)
#define UGE_P31       (UGE_BASE + 0x00BC)

#define UDE_CFG_DST_MASK	FMASK(2, 8)
#define UDE_CFG_DST8            FIELD(0x0, 2, 8)
#define UDE_CFG_DST16           FIELD(0x1, 2, 8)
#define UDE_CFG_DST24           FIELD(0x2, 2, 8)
#define UDE_CFG_DST32           FIELD(0x3, 2, 8)

/*
                                  
 */
#define UDE_CFG_GDEN_ENABLE     FIELD(1, 1, 3)
/*
                                  
 */
#define UDE_CFG_VDEN_ENABLE     FIELD(1, 1, 4)
/*
                                  
 */
#define UDE_CFG_CDEN_ENABLE     FIELD(1, 1, 5)
/*
                                      
 */
#define UDE_CFG_TIMEUP_ENABLE   FIELD(1, 1, 6)
