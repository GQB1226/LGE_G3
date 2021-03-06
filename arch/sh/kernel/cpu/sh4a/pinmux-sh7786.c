/*
 * SH7786 Pinmux
 *
 * Copyright (C) 2008, 2009  Renesas Solutions Corp.
 * Kuninori Morimoto <morimoto.kuninori@renesas.com>
 *
 *  Based on SH7785 pinmux
 *
 *  Copyright (C) 2008  Magnus Damm
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <cpu/sh7786.h>

enum {
	PINMUX_RESERVED = 0,

	PINMUX_DATA_BEGIN,
	PA7_DATA, PA6_DATA, PA5_DATA, PA4_DATA,
	PA3_DATA, PA2_DATA, PA1_DATA, PA0_DATA,
	PB7_DATA, PB6_DATA, PB5_DATA, PB4_DATA,
	PB3_DATA, PB2_DATA, PB1_DATA, PB0_DATA,
	PC7_DATA, PC6_DATA, PC5_DATA, PC4_DATA,
	PC3_DATA, PC2_DATA, PC1_DATA, PC0_DATA,
	PD7_DATA, PD6_DATA, PD5_DATA, PD4_DATA,
	PD3_DATA, PD2_DATA, PD1_DATA, PD0_DATA,
	PE7_DATA, PE6_DATA,
	PF7_DATA, PF6_DATA, PF5_DATA, PF4_DATA,
	PF3_DATA, PF2_DATA, PF1_DATA, PF0_DATA,
	PG7_DATA, PG6_DATA, PG5_DATA,
	PH7_DATA, PH6_DATA, PH5_DATA, PH4_DATA,
	PH3_DATA, PH2_DATA, PH1_DATA, PH0_DATA,
	PJ7_DATA, PJ6_DATA, PJ5_DATA, PJ4_DATA,
	PJ3_DATA, PJ2_DATA, PJ1_DATA,
	PINMUX_DATA_END,

	PINMUX_INPUT_BEGIN,
	PA7_IN, PA6_IN, PA5_IN, PA4_IN,
	PA3_IN, PA2_IN, PA1_IN, PA0_IN,
	PB7_IN, PB6_IN, PB5_IN, PB4_IN,
	PB3_IN, PB2_IN, PB1_IN, PB0_IN,
	PC7_IN, PC6_IN, PC5_IN, PC4_IN,
	PC3_IN, PC2_IN, PC1_IN, PC0_IN,
	PD7_IN, PD6_IN, PD5_IN, PD4_IN,
	PD3_IN, PD2_IN, PD1_IN, PD0_IN,
	PE7_IN, PE6_IN,
	PF7_IN, PF6_IN, PF5_IN, PF4_IN,
	PF3_IN, PF2_IN, PF1_IN, PF0_IN,
	PG7_IN, PG6_IN, PG5_IN,
	PH7_IN, PH6_IN, PH5_IN, PH4_IN,
	PH3_IN, PH2_IN, PH1_IN, PH0_IN,
	PJ7_IN, PJ6_IN, PJ5_IN, PJ4_IN,
	PJ3_IN, PJ2_IN, PJ1_IN,
	PINMUX_INPUT_END,

	PINMUX_INPUT_PULLUP_BEGIN,
	PA7_IN_PU, PA6_IN_PU, PA5_IN_PU, PA4_IN_PU,
	PA3_IN_PU, PA2_IN_PU, PA1_IN_PU, PA0_IN_PU,
	PB7_IN_PU, PB6_IN_PU, PB5_IN_PU, PB4_IN_PU,
	PB3_IN_PU, PB2_IN_PU, PB1_IN_PU, PB0_IN_PU,
	PC7_IN_PU, PC6_IN_PU, PC5_IN_PU, PC4_IN_PU,
	PC3_IN_PU, PC2_IN_PU, PC1_IN_PU, PC0_IN_PU,
	PD7_IN_PU, PD6_IN_PU, PD5_IN_PU, PD4_IN_PU,
	PD3_IN_PU, PD2_IN_PU, PD1_IN_PU, PD0_IN_PU,
	PE7_IN_PU, PE6_IN_PU,
	PF7_IN_PU, PF6_IN_PU, PF5_IN_PU, PF4_IN_PU,
	PF3_IN_PU, PF2_IN_PU, PF1_IN_PU, PF0_IN_PU,
	PG7_IN_PU, PG6_IN_PU, PG5_IN_PU,
	PH7_IN_PU, PH6_IN_PU, PH5_IN_PU, PH4_IN_PU,
	PH3_IN_PU, PH2_IN_PU, PH1_IN_PU, PH0_IN_PU,
	PJ7_IN_PU, PJ6_IN_PU, PJ5_IN_PU, PJ4_IN_PU,
	PJ3_IN_PU, PJ2_IN_PU, PJ1_IN_PU,
	PINMUX_INPUT_PULLUP_END,

	PINMUX_OUTPUT_BEGIN,
	PA7_OUT, PA6_OUT, PA5_OUT, PA4_OUT,
	PA3_OUT, PA2_OUT, PA1_OUT, PA0_OUT,
	PB7_OUT, PB6_OUT, PB5_OUT, PB4_OUT,
	PB3_OUT, PB2_OUT, PB1_OUT, PB0_OUT,
	PC7_OUT, PC6_OUT, PC5_OUT, PC4_OUT,
	PC3_OUT, PC2_OUT, PC1_OUT, PC0_OUT,
	PD7_OUT, PD6_OUT, PD5_OUT, PD4_OUT,
	PD3_OUT, PD2_OUT, PD1_OUT, PD0_OUT,
	PE7_OUT, PE6_OUT,
	PF7_OUT, PF6_OUT, PF5_OUT, PF4_OUT,
	PF3_OUT, PF2_OUT, PF1_OUT, PF0_OUT,
	PG7_OUT, PG6_OUT, PG5_OUT,
	PH7_OUT, PH6_OUT, PH5_OUT, PH4_OUT,
	PH3_OUT, PH2_OUT, PH1_OUT, PH0_OUT,
	PJ7_OUT, PJ6_OUT, PJ5_OUT, PJ4_OUT,
	PJ3_OUT, PJ2_OUT, PJ1_OUT,
	PINMUX_OUTPUT_END,

	PINMUX_FUNCTION_BEGIN,
	PA7_FN, PA6_FN, PA5_FN, PA4_FN,
	PA3_FN, PA2_FN, PA1_FN, PA0_FN,
	PB7_FN, PB6_FN, PB5_FN, PB4_FN,
	PB3_FN, PB2_FN, PB1_FN, PB0_FN,
	PC7_FN, PC6_FN, PC5_FN, PC4_FN,
	PC3_FN, PC2_FN, PC1_FN, PC0_FN,
	PD7_FN, PD6_FN, PD5_FN, PD4_FN,
	PD3_FN, PD2_FN, PD1_FN, PD0_FN,
	PE7_FN, PE6_FN,
	PF7_FN, PF6_FN, PF5_FN, PF4_FN,
	PF3_FN, PF2_FN, PF1_FN, PF0_FN,
	PG7_FN, PG6_FN, PG5_FN,
	PH7_FN, PH6_FN, PH5_FN, PH4_FN,
	PH3_FN, PH2_FN, PH1_FN, PH0_FN,
	PJ7_FN, PJ6_FN, PJ5_FN, PJ4_FN,
	PJ3_FN, PJ2_FN, PJ1_FN,
	P1MSEL14_0, P1MSEL14_1,
	P1MSEL13_0, P1MSEL13_1,
	P1MSEL12_0, P1MSEL12_1,
	P1MSEL11_0, P1MSEL11_1,
	P1MSEL10_0, P1MSEL10_1,
	P1MSEL9_0, P1MSEL9_1,
	P1MSEL8_0, P1MSEL8_1,
	P1MSEL7_0, P1MSEL7_1,
	P1MSEL6_0, P1MSEL6_1,
	P1MSEL5_0, P1MSEL5_1,
	P1MSEL4_0, P1MSEL4_1,
	P1MSEL3_0, P1MSEL3_1,
	P1MSEL2_0, P1MSEL2_1,
	P1MSEL1_0, P1MSEL1_1,
	P1MSEL0_0, P1MSEL0_1,

	P2MSEL15_0, P2MSEL15_1,
	P2MSEL14_0, P2MSEL14_1,
	P2MSEL13_0, P2MSEL13_1,
	P2MSEL12_0, P2MSEL12_1,
	P2MSEL11_0, P2MSEL11_1,
	P2MSEL10_0, P2MSEL10_1,
	P2MSEL9_0, P2MSEL9_1,
	P2MSEL8_0, P2MSEL8_1,
	P2MSEL7_0, P2MSEL7_1,
	P2MSEL6_0, P2MSEL6_1,
	P2MSEL5_0, P2MSEL5_1,
	P2MSEL4_0, P2MSEL4_1,
	P2MSEL3_0, P2MSEL3_1,
	P2MSEL2_0, P2MSEL2_1,
	P2MSEL1_0, P2MSEL1_1,
	P2MSEL0_0, P2MSEL0_1,
	PINMUX_FUNCTION_END,

	PINMUX_MARK_BEGIN,
	DCLKIN_MARK, DCLKOUT_MARK, ODDF_MARK,
	VSYNC_MARK, HSYNC_MARK, CDE_MARK, DISP_MARK,
	DR0_MARK, DR1_MARK, DR2_MARK, DR3_MARK, DR4_MARK, DR5_MARK,
	DG0_MARK, DG1_MARK, DG2_MARK, DG3_MARK, DG4_MARK, DG5_MARK,
	DB0_MARK, DB1_MARK, DB2_MARK, DB3_MARK, DB4_MARK, DB5_MARK,
	ETH_MAGIC_MARK, ETH_LINK_MARK, ETH_TX_ER_MARK, ETH_TX_EN_MARK,
	ETH_MDIO_MARK, ETH_RX_CLK_MARK, ETH_MDC_MARK, ETH_COL_MARK,
	ETH_TX_CLK_MARK, ETH_CRS_MARK, ETH_RX_DV_MARK, ETH_RX_ER_MARK,
	ETH_TXD3_MARK, ETH_TXD2_MARK, ETH_TXD1_MARK, ETH_TXD0_MARK,
	ETH_RXD3_MARK, ETH_RXD2_MARK, ETH_RXD1_MARK, ETH_RXD0_MARK,
	HSPI_CLK_MARK, HSPI_CS_MARK, HSPI_RX_MARK, HSPI_TX_MARK,
	SCIF0_CTS_MARK, SCIF0_RTS_MARK,
	SCIF0_SCK_MARK, SCIF0_RXD_MARK, SCIF0_TXD_MARK,
	SCIF1_SCK_MARK, SCIF1_RXD_MARK, SCIF1_TXD_MARK,
	SCIF3_SCK_MARK, SCIF3_RXD_MARK, SCIF3_TXD_MARK,
	SCIF4_SCK_MARK, SCIF4_RXD_MARK, SCIF4_TXD_MARK,
	SCIF5_SCK_MARK, SCIF5_RXD_MARK, SCIF5_TXD_MARK,
	BREQ_MARK, IOIS16_MARK, CE2B_MARK, CE2A_MARK, BACK_MARK,
	FALE_MARK, FRB_MARK, FSTATUS_MARK,
	FSE_MARK, FCLE_MARK,
	DACK0_MARK, DACK1_MARK, DACK2_MARK, DACK3_MARK,
	DREQ0_MARK, DREQ1_MARK, DREQ2_MARK, DREQ3_MARK,
	DRAK0_MARK, DRAK1_MARK, DRAK2_MARK, DRAK3_MARK,
	USB_OVC1_MARK, USB_OVC0_MARK,
	USB_PENC1_MARK, USB_PENC0_MARK,
	HAC_RES_MARK,
	HAC1_SDOUT_MARK, HAC1_SDIN_MARK, HAC1_SYNC_MARK, HAC1_BITCLK_MARK,
	HAC0_SDOUT_MARK, HAC0_SDIN_MARK, HAC0_SYNC_MARK, HAC0_BITCLK_MARK,
	SSI0_SDATA_MARK, SSI0_SCK_MARK, SSI0_WS_MARK, SSI0_CLK_MARK,
	SSI1_SDATA_MARK, SSI1_SCK_MARK, SSI1_WS_MARK, SSI1_CLK_MARK,
	SSI2_SDATA_MARK, SSI2_SCK_MARK, SSI2_WS_MARK,
	SSI3_SDATA_MARK, SSI3_SCK_MARK, SSI3_WS_MARK,
	SDIF1CMD_MARK, SDIF1CD_MARK, SDIF1WP_MARK, SDIF1CLK_MARK,
	SDIF1D3_MARK, SDIF1D2_MARK, SDIF1D1_MARK, SDIF1D0_MARK,
	SDIF0CMD_MARK, SDIF0CD_MARK, SDIF0WP_MARK, SDIF0CLK_MARK,
	SDIF0D3_MARK, SDIF0D2_MARK, SDIF0D1_MARK, SDIF0D0_MARK,
	TCLK_MARK,
	IRL7_MARK, IRL6_MARK, IRL5_MARK, IRL4_MARK,
	PINMUX_MARK_END,
};

static pinmux_enum_t pinmux_data[] = {

	/*         */
	PINMUX_DATA(PA7_DATA, PA7_IN, PA7_OUT, PA7_IN_PU),
	PINMUX_DATA(PA6_DATA, PA6_IN, PA6_OUT, PA6_IN_PU),
	PINMUX_DATA(PA5_DATA, PA5_IN, PA5_OUT, PA5_IN_PU),
	PINMUX_DATA(PA4_DATA, PA4_IN, PA4_OUT, PA4_IN_PU),
	PINMUX_DATA(PA3_DATA, PA3_IN, PA3_OUT, PA3_IN_PU),
	PINMUX_DATA(PA2_DATA, PA2_IN, PA2_OUT, PA2_IN_PU),
	PINMUX_DATA(PA1_DATA, PA1_IN, PA1_OUT, PA1_IN_PU),
	PINMUX_DATA(PA0_DATA, PA0_IN, PA0_OUT, PA0_IN_PU),

	/*         */
	PINMUX_DATA(PB7_DATA, PB7_IN, PB7_OUT, PB7_IN_PU),
	PINMUX_DATA(PB6_DATA, PB6_IN, PB6_OUT, PB6_IN_PU),
	PINMUX_DATA(PB5_DATA, PB5_IN, PB5_OUT, PB5_IN_PU),
	PINMUX_DATA(PB4_DATA, PB4_IN, PB4_OUT, PB4_IN_PU),
	PINMUX_DATA(PB3_DATA, PB3_IN, PB3_OUT, PB3_IN_PU),
	PINMUX_DATA(PB2_DATA, PB2_IN, PB2_OUT, PB2_IN_PU),
	PINMUX_DATA(PB1_DATA, PB1_IN, PB1_OUT, PB1_IN_PU),
	PINMUX_DATA(PB0_DATA, PB0_IN, PB0_OUT, PB0_IN_PU),

	/*         */
	PINMUX_DATA(PC7_DATA, PC7_IN, PC7_OUT, PC7_IN_PU),
	PINMUX_DATA(PC6_DATA, PC6_IN, PC6_OUT, PC6_IN_PU),
	PINMUX_DATA(PC5_DATA, PC5_IN, PC5_OUT, PC5_IN_PU),
	PINMUX_DATA(PC4_DATA, PC4_IN, PC4_OUT, PC4_IN_PU),
	PINMUX_DATA(PC3_DATA, PC3_IN, PC3_OUT, PC3_IN_PU),
	PINMUX_DATA(PC2_DATA, PC2_IN, PC2_OUT, PC2_IN_PU),
	PINMUX_DATA(PC1_DATA, PC1_IN, PC1_OUT, PC1_IN_PU),
	PINMUX_DATA(PC0_DATA, PC0_IN, PC0_OUT, PC0_IN_PU),

	/*         */
	PINMUX_DATA(PD7_DATA, PD7_IN, PD7_OUT, PD7_IN_PU),
	PINMUX_DATA(PD6_DATA, PD6_IN, PD6_OUT, PD6_IN_PU),
	PINMUX_DATA(PD5_DATA, PD5_IN, PD5_OUT, PD5_IN_PU),
	PINMUX_DATA(PD4_DATA, PD4_IN, PD4_OUT, PD4_IN_PU),
	PINMUX_DATA(PD3_DATA, PD3_IN, PD3_OUT, PD3_IN_PU),
	PINMUX_DATA(PD2_DATA, PD2_IN, PD2_OUT, PD2_IN_PU),
	PINMUX_DATA(PD1_DATA, PD1_IN, PD1_OUT, PD1_IN_PU),
	PINMUX_DATA(PD0_DATA, PD0_IN, PD0_OUT, PD0_IN_PU),

	/*         */
	PINMUX_DATA(PE7_DATA, PE7_IN, PE7_OUT, PE7_IN_PU),
	PINMUX_DATA(PE6_DATA, PE6_IN, PE6_OUT, PE6_IN_PU),

	/*         */
	PINMUX_DATA(PF7_DATA, PF7_IN, PF7_OUT, PF7_IN_PU),
	PINMUX_DATA(PF6_DATA, PF6_IN, PF6_OUT, PF6_IN_PU),
	PINMUX_DATA(PF5_DATA, PF5_IN, PF5_OUT, PF5_IN_PU),
	PINMUX_DATA(PF4_DATA, PF4_IN, PF4_OUT, PF4_IN_PU),
	PINMUX_DATA(PF3_DATA, PF3_IN, PF3_OUT, PF3_IN_PU),
	PINMUX_DATA(PF2_DATA, PF2_IN, PF2_OUT, PF2_IN_PU),
	PINMUX_DATA(PF1_DATA, PF1_IN, PF1_OUT, PF1_IN_PU),
	PINMUX_DATA(PF0_DATA, PF0_IN, PF0_OUT, PF0_IN_PU),

	/*         */
	PINMUX_DATA(PG7_DATA, PG7_IN, PG7_OUT, PG7_IN_PU),
	PINMUX_DATA(PG6_DATA, PG6_IN, PG6_OUT, PG6_IN_PU),
	PINMUX_DATA(PG5_DATA, PG5_IN, PG5_OUT, PG5_IN_PU),

	/*         */
	PINMUX_DATA(PH7_DATA, PH7_IN, PH7_OUT, PH7_IN_PU),
	PINMUX_DATA(PH6_DATA, PH6_IN, PH6_OUT, PH6_IN_PU),
	PINMUX_DATA(PH5_DATA, PH5_IN, PH5_OUT, PH5_IN_PU),
	PINMUX_DATA(PH4_DATA, PH4_IN, PH4_OUT, PH4_IN_PU),
	PINMUX_DATA(PH3_DATA, PH3_IN, PH3_OUT, PH3_IN_PU),
	PINMUX_DATA(PH2_DATA, PH2_IN, PH2_OUT, PH2_IN_PU),
	PINMUX_DATA(PH1_DATA, PH1_IN, PH1_OUT, PH1_IN_PU),
	PINMUX_DATA(PH0_DATA, PH0_IN, PH0_OUT, PH0_IN_PU),

	/*         */
	PINMUX_DATA(PJ7_DATA, PJ7_IN, PJ7_OUT, PJ7_IN_PU),
	PINMUX_DATA(PJ6_DATA, PJ6_IN, PJ6_OUT, PJ6_IN_PU),
	PINMUX_DATA(PJ5_DATA, PJ5_IN, PJ5_OUT, PJ5_IN_PU),
	PINMUX_DATA(PJ4_DATA, PJ4_IN, PJ4_OUT, PJ4_IN_PU),
	PINMUX_DATA(PJ3_DATA, PJ3_IN, PJ3_OUT, PJ3_IN_PU),
	PINMUX_DATA(PJ2_DATA, PJ2_IN, PJ2_OUT, PJ2_IN_PU),
	PINMUX_DATA(PJ1_DATA, PJ1_IN, PJ1_OUT, PJ1_IN_PU),

	/*       */
	PINMUX_DATA(CDE_MARK,		P1MSEL2_0, PA7_FN),
	PINMUX_DATA(DISP_MARK,		P1MSEL2_0, PA6_FN),
	PINMUX_DATA(DR5_MARK,		P1MSEL2_0, PA5_FN),
	PINMUX_DATA(DR4_MARK,		P1MSEL2_0, PA4_FN),
	PINMUX_DATA(DR3_MARK,		P1MSEL2_0, PA3_FN),
	PINMUX_DATA(DR2_MARK,		P1MSEL2_0, PA2_FN),
	PINMUX_DATA(DR1_MARK,		P1MSEL2_0, PA1_FN),
	PINMUX_DATA(DR0_MARK,		P1MSEL2_0, PA0_FN),
	PINMUX_DATA(ETH_MAGIC_MARK,	P1MSEL2_1, PA7_FN),
	PINMUX_DATA(ETH_LINK_MARK,	P1MSEL2_1, PA6_FN),
	PINMUX_DATA(ETH_TX_ER_MARK,	P1MSEL2_1, PA5_FN),
	PINMUX_DATA(ETH_TX_EN_MARK,	P1MSEL2_1, PA4_FN),
	PINMUX_DATA(ETH_TXD3_MARK,	P1MSEL2_1, PA3_FN),
	PINMUX_DATA(ETH_TXD2_MARK,	P1MSEL2_1, PA2_FN),
	PINMUX_DATA(ETH_TXD1_MARK,	P1MSEL2_1, PA1_FN),
	PINMUX_DATA(ETH_TXD0_MARK,	P1MSEL2_1, PA0_FN),

	/*       */
	PINMUX_DATA(VSYNC_MARK,		P1MSEL3_0, PB7_FN),
	PINMUX_DATA(ODDF_MARK,		P1MSEL3_0, PB6_FN),
	PINMUX_DATA(DG5_MARK,		P1MSEL2_0, PB5_FN),
	PINMUX_DATA(DG4_MARK,		P1MSEL2_0, PB4_FN),
	PINMUX_DATA(DG3_MARK,		P1MSEL2_0, PB3_FN),
	PINMUX_DATA(DG2_MARK,		P1MSEL2_0, PB2_FN),
	PINMUX_DATA(DG1_MARK,		P1MSEL2_0, PB1_FN),
	PINMUX_DATA(DG0_MARK,		P1MSEL2_0, PB0_FN),
	PINMUX_DATA(HSPI_CLK_MARK,	P1MSEL3_1, PB7_FN),
	PINMUX_DATA(HSPI_CS_MARK,	P1MSEL3_1, PB6_FN),
	PINMUX_DATA(ETH_MDIO_MARK,	P1MSEL2_1, PB5_FN),
	PINMUX_DATA(ETH_RX_CLK_MARK,	P1MSEL2_1, PB4_FN),
	PINMUX_DATA(ETH_MDC_MARK,	P1MSEL2_1, PB3_FN),
	PINMUX_DATA(ETH_COL_MARK,	P1MSEL2_1, PB2_FN),
	PINMUX_DATA(ETH_TX_CLK_MARK,	P1MSEL2_1, PB1_FN),
	PINMUX_DATA(ETH_CRS_MARK,	P1MSEL2_1, PB0_FN),

	/*       */
	PINMUX_DATA(DCLKIN_MARK,	P1MSEL3_0, PC7_FN),
	PINMUX_DATA(HSYNC_MARK,		P1MSEL3_0, PC6_FN),
	PINMUX_DATA(DB5_MARK,		P1MSEL2_0, PC5_FN),
	PINMUX_DATA(DB4_MARK,		P1MSEL2_0, PC4_FN),
	PINMUX_DATA(DB3_MARK,		P1MSEL2_0, PC3_FN),
	PINMUX_DATA(DB2_MARK,		P1MSEL2_0, PC2_FN),
	PINMUX_DATA(DB1_MARK,		P1MSEL2_0, PC1_FN),
	PINMUX_DATA(DB0_MARK,		P1MSEL2_0, PC0_FN),

	PINMUX_DATA(HSPI_RX_MARK,	P1MSEL3_1, PC7_FN),
	PINMUX_DATA(HSPI_TX_MARK,	P1MSEL3_1, PC6_FN),
	PINMUX_DATA(ETH_RXD3_MARK,	P1MSEL2_1, PC5_FN),
	PINMUX_DATA(ETH_RXD2_MARK,	P1MSEL2_1, PC4_FN),
	PINMUX_DATA(ETH_RXD1_MARK,	P1MSEL2_1, PC3_FN),
	PINMUX_DATA(ETH_RXD0_MARK,	P1MSEL2_1, PC2_FN),
	PINMUX_DATA(ETH_RX_DV_MARK,	P1MSEL2_1, PC1_FN),
	PINMUX_DATA(ETH_RX_ER_MARK,	P1MSEL2_1, PC0_FN),

	/*       */
	PINMUX_DATA(DCLKOUT_MARK,	PD7_FN),
	PINMUX_DATA(SCIF1_SCK_MARK,	PD6_FN),
	PINMUX_DATA(SCIF1_RXD_MARK,	PD5_FN),
	PINMUX_DATA(SCIF1_TXD_MARK,	PD4_FN),
	PINMUX_DATA(DACK1_MARK,		P1MSEL13_1, P1MSEL12_0, PD3_FN),
	PINMUX_DATA(BACK_MARK,		P1MSEL13_0, P1MSEL12_1, PD3_FN),
	PINMUX_DATA(FALE_MARK,		P1MSEL13_0, P1MSEL12_0, PD3_FN),
	PINMUX_DATA(DACK0_MARK,		P1MSEL14_1, PD2_FN),
	PINMUX_DATA(FCLE_MARK,		P1MSEL14_0, PD2_FN),
	PINMUX_DATA(DREQ1_MARK,		P1MSEL10_0, P1MSEL9_1, PD1_FN),
	PINMUX_DATA(BREQ_MARK,		P1MSEL10_1, P1MSEL9_0, PD1_FN),
	PINMUX_DATA(USB_OVC1_MARK,	P1MSEL10_0, P1MSEL9_0, PD1_FN),
	PINMUX_DATA(DREQ0_MARK,		P1MSEL11_1, PD0_FN),
	PINMUX_DATA(USB_OVC0_MARK,	P1MSEL11_0, PD0_FN),

	/*       */
	PINMUX_DATA(USB_PENC1_MARK,	PE7_FN),
	PINMUX_DATA(USB_PENC0_MARK,	PE6_FN),

	/*       */
	PINMUX_DATA(HAC1_SDOUT_MARK,	P2MSEL15_0, P2MSEL14_0, PF7_FN),
	PINMUX_DATA(HAC1_SDIN_MARK,	P2MSEL15_0, P2MSEL14_0, PF6_FN),
	PINMUX_DATA(HAC1_SYNC_MARK,	P2MSEL15_0, P2MSEL14_0, PF5_FN),
	PINMUX_DATA(HAC1_BITCLK_MARK,	P2MSEL15_0, P2MSEL14_0, PF4_FN),
	PINMUX_DATA(HAC0_SDOUT_MARK,	P2MSEL13_0, P2MSEL12_0, PF3_FN),
	PINMUX_DATA(HAC0_SDIN_MARK,	P2MSEL13_0, P2MSEL12_0, PF2_FN),
	PINMUX_DATA(HAC0_SYNC_MARK,	P2MSEL13_0, P2MSEL12_0, PF1_FN),
	PINMUX_DATA(HAC0_BITCLK_MARK,	P2MSEL13_0, P2MSEL12_0, PF0_FN),
	PINMUX_DATA(SSI1_SDATA_MARK,	P2MSEL15_0, P2MSEL14_1, PF7_FN),
	PINMUX_DATA(SSI1_SCK_MARK,	P2MSEL15_0, P2MSEL14_1, PF6_FN),
	PINMUX_DATA(SSI1_WS_MARK,	P2MSEL15_0, P2MSEL14_1, PF5_FN),
	PINMUX_DATA(SSI1_CLK_MARK,	P2MSEL15_0, P2MSEL14_1, PF4_FN),
	PINMUX_DATA(SSI0_SDATA_MARK,	P2MSEL13_0, P2MSEL12_1, PF3_FN),
	PINMUX_DATA(SSI0_SCK_MARK,	P2MSEL13_0, P2MSEL12_1, PF2_FN),
	PINMUX_DATA(SSI0_WS_MARK,	P2MSEL13_0, P2MSEL12_1, PF1_FN),
	PINMUX_DATA(SSI0_CLK_MARK,	P2MSEL13_0, P2MSEL12_1, PF0_FN),
	PINMUX_DATA(SDIF1CMD_MARK,	P2MSEL15_1, P2MSEL14_0, PF7_FN),
	PINMUX_DATA(SDIF1CD_MARK,	P2MSEL15_1, P2MSEL14_0, PF6_FN),
	PINMUX_DATA(SDIF1WP_MARK,	P2MSEL15_1, P2MSEL14_0, PF5_FN),
	PINMUX_DATA(SDIF1CLK_MARK,	P2MSEL15_1, P2MSEL14_0, PF4_FN),
	PINMUX_DATA(SDIF1D3_MARK,	P2MSEL13_1, P2MSEL12_0, PF3_FN),
	PINMUX_DATA(SDIF1D2_MARK,	P2MSEL13_1, P2MSEL12_0, PF2_FN),
	PINMUX_DATA(SDIF1D1_MARK,	P2MSEL13_1, P2MSEL12_0, PF1_FN),
	PINMUX_DATA(SDIF1D0_MARK,	P2MSEL13_1, P2MSEL12_0, PF0_FN),

	/*       */
	PINMUX_DATA(SCIF3_SCK_MARK,	P1MSEL8_0, PG7_FN),
	PINMUX_DATA(SSI2_SDATA_MARK,	P1MSEL8_1, PG7_FN),
	PINMUX_DATA(SCIF3_RXD_MARK,	P1MSEL7_0, P1MSEL6_0, PG6_FN),
	PINMUX_DATA(SSI2_SCK_MARK,	P1MSEL7_1, P1MSEL6_0, PG6_FN),
	PINMUX_DATA(TCLK_MARK,		P1MSEL7_0, P1MSEL6_1, PG6_FN),
	PINMUX_DATA(SCIF3_TXD_MARK,	P1MSEL5_0, P1MSEL4_0, PG5_FN),
	PINMUX_DATA(SSI2_WS_MARK,	P1MSEL5_1, P1MSEL4_0, PG5_FN),
	PINMUX_DATA(HAC_RES_MARK,	P1MSEL5_0, P1MSEL4_1, PG5_FN),

	/*       */
	PINMUX_DATA(DACK3_MARK,		P2MSEL4_0, PH7_FN),
	PINMUX_DATA(SDIF0CMD_MARK,	P2MSEL4_1, PH7_FN),
	PINMUX_DATA(DACK2_MARK,		P2MSEL4_0, PH6_FN),
	PINMUX_DATA(SDIF0CD_MARK,	P2MSEL4_1, PH6_FN),
	PINMUX_DATA(DREQ3_MARK,		P2MSEL4_0, PH5_FN),
	PINMUX_DATA(SDIF0WP_MARK,	P2MSEL4_1, PH5_FN),
	PINMUX_DATA(DREQ2_MARK,		P2MSEL3_0, P2MSEL2_1, PH4_FN),
	PINMUX_DATA(SDIF0CLK_MARK,	P2MSEL3_1, P2MSEL2_0, PH4_FN),
	PINMUX_DATA(SCIF0_CTS_MARK,	P2MSEL3_0, P2MSEL2_0, PH4_FN),
	PINMUX_DATA(SDIF0D3_MARK,	P2MSEL1_1, P2MSEL0_0, PH3_FN),
	PINMUX_DATA(SCIF0_RTS_MARK,	P2MSEL1_0, P2MSEL0_0, PH3_FN),
	PINMUX_DATA(IRL7_MARK,		P2MSEL1_0, P2MSEL0_1, PH3_FN),
	PINMUX_DATA(SDIF0D2_MARK,	P2MSEL1_1, P2MSEL0_0, PH2_FN),
	PINMUX_DATA(SCIF0_SCK_MARK,	P2MSEL1_0, P2MSEL0_0, PH2_FN),
	PINMUX_DATA(IRL6_MARK,		P2MSEL1_0, P2MSEL0_1, PH2_FN),
	PINMUX_DATA(SDIF0D1_MARK,	P2MSEL1_1, P2MSEL0_0, PH1_FN),
	PINMUX_DATA(SCIF0_RXD_MARK,	P2MSEL1_0, P2MSEL0_0, PH1_FN),
	PINMUX_DATA(IRL5_MARK,		P2MSEL1_0, P2MSEL0_1, PH1_FN),
	PINMUX_DATA(SDIF0D0_MARK,	P2MSEL1_1, P2MSEL0_0, PH0_FN),
	PINMUX_DATA(SCIF0_TXD_MARK,	P2MSEL1_0, P2MSEL0_0, PH0_FN),
	PINMUX_DATA(IRL4_MARK,		P2MSEL1_0, P2MSEL0_1, PH0_FN),

	/*       */
	PINMUX_DATA(SCIF5_SCK_MARK,	P2MSEL11_1, PJ7_FN),
	PINMUX_DATA(FRB_MARK,		P2MSEL11_0, PJ7_FN),
	PINMUX_DATA(SCIF5_RXD_MARK,	P2MSEL10_0, PJ6_FN),
	PINMUX_DATA(IOIS16_MARK,	P2MSEL10_1, PJ6_FN),
	PINMUX_DATA(SCIF5_TXD_MARK,	P2MSEL10_0, PJ5_FN),
	PINMUX_DATA(CE2B_MARK,		P2MSEL10_1, PJ5_FN),
	PINMUX_DATA(DRAK3_MARK,		P2MSEL7_0, PJ4_FN),
	PINMUX_DATA(CE2A_MARK,		P2MSEL7_1, PJ4_FN),
	PINMUX_DATA(SCIF4_SCK_MARK,	P2MSEL9_0, P2MSEL8_0, PJ3_FN),
	PINMUX_DATA(DRAK2_MARK,		P2MSEL9_0, P2MSEL8_1, PJ3_FN),
	PINMUX_DATA(SSI3_WS_MARK,	P2MSEL9_1, P2MSEL8_0, PJ3_FN),
	PINMUX_DATA(SCIF4_RXD_MARK,	P2MSEL6_1, P2MSEL5_0, PJ2_FN),
	PINMUX_DATA(DRAK1_MARK,		P2MSEL6_0, P2MSEL5_1, PJ2_FN),
	PINMUX_DATA(FSTATUS_MARK,	P2MSEL6_0, P2MSEL5_0, PJ2_FN),
	PINMUX_DATA(SSI3_SDATA_MARK,	P2MSEL6_1, P2MSEL5_1, PJ2_FN),
	PINMUX_DATA(SCIF4_TXD_MARK,	P2MSEL6_1, P2MSEL5_0, PJ1_FN),
	PINMUX_DATA(DRAK0_MARK,		P2MSEL6_0, P2MSEL5_1, PJ1_FN),
	PINMUX_DATA(FSE_MARK,		P2MSEL6_0, P2MSEL5_0, PJ1_FN),
	PINMUX_DATA(SSI3_SCK_MARK,	P2MSEL6_1, P2MSEL5_1, PJ1_FN),
};

static struct pinmux_gpio pinmux_gpios[] = {
	/*    */
	PINMUX_GPIO(GPIO_PA7, PA7_DATA),
	PINMUX_GPIO(GPIO_PA6, PA6_DATA),
	PINMUX_GPIO(GPIO_PA5, PA5_DATA),
	PINMUX_GPIO(GPIO_PA4, PA4_DATA),
	PINMUX_GPIO(GPIO_PA3, PA3_DATA),
	PINMUX_GPIO(GPIO_PA2, PA2_DATA),
	PINMUX_GPIO(GPIO_PA1, PA1_DATA),
	PINMUX_GPIO(GPIO_PA0, PA0_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PB7, PB7_DATA),
	PINMUX_GPIO(GPIO_PB6, PB6_DATA),
	PINMUX_GPIO(GPIO_PB5, PB5_DATA),
	PINMUX_GPIO(GPIO_PB4, PB4_DATA),
	PINMUX_GPIO(GPIO_PB3, PB3_DATA),
	PINMUX_GPIO(GPIO_PB2, PB2_DATA),
	PINMUX_GPIO(GPIO_PB1, PB1_DATA),
	PINMUX_GPIO(GPIO_PB0, PB0_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PC7, PC7_DATA),
	PINMUX_GPIO(GPIO_PC6, PC6_DATA),
	PINMUX_GPIO(GPIO_PC5, PC5_DATA),
	PINMUX_GPIO(GPIO_PC4, PC4_DATA),
	PINMUX_GPIO(GPIO_PC3, PC3_DATA),
	PINMUX_GPIO(GPIO_PC2, PC2_DATA),
	PINMUX_GPIO(GPIO_PC1, PC1_DATA),
	PINMUX_GPIO(GPIO_PC0, PC0_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PD7, PD7_DATA),
	PINMUX_GPIO(GPIO_PD6, PD6_DATA),
	PINMUX_GPIO(GPIO_PD5, PD5_DATA),
	PINMUX_GPIO(GPIO_PD4, PD4_DATA),
	PINMUX_GPIO(GPIO_PD3, PD3_DATA),
	PINMUX_GPIO(GPIO_PD2, PD2_DATA),
	PINMUX_GPIO(GPIO_PD1, PD1_DATA),
	PINMUX_GPIO(GPIO_PD0, PD0_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PE5, PE7_DATA),
	PINMUX_GPIO(GPIO_PE4, PE6_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PF7, PF7_DATA),
	PINMUX_GPIO(GPIO_PF6, PF6_DATA),
	PINMUX_GPIO(GPIO_PF5, PF5_DATA),
	PINMUX_GPIO(GPIO_PF4, PF4_DATA),
	PINMUX_GPIO(GPIO_PF3, PF3_DATA),
	PINMUX_GPIO(GPIO_PF2, PF2_DATA),
	PINMUX_GPIO(GPIO_PF1, PF1_DATA),
	PINMUX_GPIO(GPIO_PF0, PF0_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PG7, PG7_DATA),
	PINMUX_GPIO(GPIO_PG6, PG6_DATA),
	PINMUX_GPIO(GPIO_PG5, PG5_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PH7, PH7_DATA),
	PINMUX_GPIO(GPIO_PH6, PH6_DATA),
	PINMUX_GPIO(GPIO_PH5, PH5_DATA),
	PINMUX_GPIO(GPIO_PH4, PH4_DATA),
	PINMUX_GPIO(GPIO_PH3, PH3_DATA),
	PINMUX_GPIO(GPIO_PH2, PH2_DATA),
	PINMUX_GPIO(GPIO_PH1, PH1_DATA),
	PINMUX_GPIO(GPIO_PH0, PH0_DATA),

	/*    */
	PINMUX_GPIO(GPIO_PJ7, PJ7_DATA),
	PINMUX_GPIO(GPIO_PJ6, PJ6_DATA),
	PINMUX_GPIO(GPIO_PJ5, PJ5_DATA),
	PINMUX_GPIO(GPIO_PJ4, PJ4_DATA),
	PINMUX_GPIO(GPIO_PJ3, PJ3_DATA),
	PINMUX_GPIO(GPIO_PJ2, PJ2_DATA),
	PINMUX_GPIO(GPIO_PJ1, PJ1_DATA),

	/*    */
	PINMUX_GPIO(GPIO_FN_CDE,		CDE_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_MAGIC,		ETH_MAGIC_MARK),
	PINMUX_GPIO(GPIO_FN_DISP,		DISP_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_LINK,		ETH_LINK_MARK),
	PINMUX_GPIO(GPIO_FN_DR5,		DR5_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_TX_ER,		ETH_TX_ER_MARK),
	PINMUX_GPIO(GPIO_FN_DR4,		DR4_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_TX_EN,		ETH_TX_EN_MARK),
	PINMUX_GPIO(GPIO_FN_DR3,		DR3_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_TXD3,		ETH_TXD3_MARK),
	PINMUX_GPIO(GPIO_FN_DR2,		DR2_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_TXD2,		ETH_TXD2_MARK),
	PINMUX_GPIO(GPIO_FN_DR1,		DR1_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_TXD1,		ETH_TXD1_MARK),
	PINMUX_GPIO(GPIO_FN_DR0,		DR0_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_TXD0,		ETH_TXD0_MARK),
	PINMUX_GPIO(GPIO_FN_VSYNC,		VSYNC_MARK),
	PINMUX_GPIO(GPIO_FN_HSPI_CLK,		HSPI_CLK_MARK),
	PINMUX_GPIO(GPIO_FN_ODDF,		ODDF_MARK),
	PINMUX_GPIO(GPIO_FN_HSPI_CS,		HSPI_CS_MARK),
	PINMUX_GPIO(GPIO_FN_DG5,		DG5_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_MDIO,		ETH_MDIO_MARK),
	PINMUX_GPIO(GPIO_FN_DG4,		DG4_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_RX_CLK,		ETH_RX_CLK_MARK),
	PINMUX_GPIO(GPIO_FN_DG3,		DG3_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_MDC,		ETH_MDC_MARK),
	PINMUX_GPIO(GPIO_FN_DG2,		DG2_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_COL,		ETH_COL_MARK),
	PINMUX_GPIO(GPIO_FN_DG1,		DG1_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_TX_CLK,		ETH_TX_CLK_MARK),
	PINMUX_GPIO(GPIO_FN_DG0,		DG0_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_CRS,		ETH_CRS_MARK),
	PINMUX_GPIO(GPIO_FN_DCLKIN,		DCLKIN_MARK),
	PINMUX_GPIO(GPIO_FN_HSPI_RX,		HSPI_RX_MARK),
	PINMUX_GPIO(GPIO_FN_HSYNC,		HSYNC_MARK),
	PINMUX_GPIO(GPIO_FN_HSPI_TX,		HSPI_TX_MARK),
	PINMUX_GPIO(GPIO_FN_DB5,		DB5_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_RXD3,		ETH_RXD3_MARK),
	PINMUX_GPIO(GPIO_FN_DB4,		DB4_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_RXD2,		ETH_RXD2_MARK),
	PINMUX_GPIO(GPIO_FN_DB3,		DB3_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_RXD1,		ETH_RXD1_MARK),
	PINMUX_GPIO(GPIO_FN_DB2,		DB2_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_RXD0,		ETH_RXD0_MARK),
	PINMUX_GPIO(GPIO_FN_DB1,		DB1_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_RX_DV,		ETH_RX_DV_MARK),
	PINMUX_GPIO(GPIO_FN_DB0,		DB0_MARK),
	PINMUX_GPIO(GPIO_FN_ETH_RX_ER,		ETH_RX_ER_MARK),
	PINMUX_GPIO(GPIO_FN_DCLKOUT,		DCLKOUT_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF1_SCK,		SCIF1_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF1_RXD,		SCIF1_RXD_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF1_TXD,		SCIF1_TXD_MARK),
	PINMUX_GPIO(GPIO_FN_DACK1,		DACK1_MARK),
	PINMUX_GPIO(GPIO_FN_BACK,		BACK_MARK),
	PINMUX_GPIO(GPIO_FN_FALE,		FALE_MARK),
	PINMUX_GPIO(GPIO_FN_DACK0,		DACK0_MARK),
	PINMUX_GPIO(GPIO_FN_FCLE,		FCLE_MARK),
	PINMUX_GPIO(GPIO_FN_DREQ1,		DREQ1_MARK),
	PINMUX_GPIO(GPIO_FN_BREQ,		BREQ_MARK),
	PINMUX_GPIO(GPIO_FN_USB_OVC1,		USB_OVC1_MARK),
	PINMUX_GPIO(GPIO_FN_DREQ0,		DREQ0_MARK),
	PINMUX_GPIO(GPIO_FN_USB_OVC0,		USB_OVC0_MARK),
	PINMUX_GPIO(GPIO_FN_USB_PENC1,		USB_PENC1_MARK),
	PINMUX_GPIO(GPIO_FN_USB_PENC0,		USB_PENC0_MARK),
	PINMUX_GPIO(GPIO_FN_HAC1_SDOUT,		HAC1_SDOUT_MARK),
	PINMUX_GPIO(GPIO_FN_SSI1_SDATA,		SSI1_SDATA_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1CMD,		SDIF1CMD_MARK),
	PINMUX_GPIO(GPIO_FN_HAC1_SDIN,		HAC1_SDIN_MARK),
	PINMUX_GPIO(GPIO_FN_SSI1_SCK,		SSI1_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1CD,		SDIF1CD_MARK),
	PINMUX_GPIO(GPIO_FN_HAC1_SYNC,		HAC1_SYNC_MARK),
	PINMUX_GPIO(GPIO_FN_SSI1_WS,		SSI1_WS_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1WP,		SDIF1WP_MARK),
	PINMUX_GPIO(GPIO_FN_HAC1_BITCLK,	HAC1_BITCLK_MARK),
	PINMUX_GPIO(GPIO_FN_SSI1_CLK,		SSI1_CLK_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1CLK,		SDIF1CLK_MARK),
	PINMUX_GPIO(GPIO_FN_HAC0_SDOUT,		HAC0_SDOUT_MARK),
	PINMUX_GPIO(GPIO_FN_SSI0_SDATA,		SSI0_SDATA_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1D3,		SDIF1D3_MARK),
	PINMUX_GPIO(GPIO_FN_HAC0_SDIN,		HAC0_SDIN_MARK),
	PINMUX_GPIO(GPIO_FN_SSI0_SCK,		SSI0_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1D2,		SDIF1D2_MARK),
	PINMUX_GPIO(GPIO_FN_HAC0_SYNC,		HAC0_SYNC_MARK),
	PINMUX_GPIO(GPIO_FN_SSI0_WS,		SSI0_WS_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1D1,		SDIF1D1_MARK),
	PINMUX_GPIO(GPIO_FN_HAC0_BITCLK,	HAC0_BITCLK_MARK),
	PINMUX_GPIO(GPIO_FN_SSI0_CLK,		SSI0_CLK_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF1D0,		SDIF1D0_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF3_SCK,		SCIF3_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_SSI2_SDATA,		SSI2_SDATA_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF3_RXD,		SCIF3_RXD_MARK),
	PINMUX_GPIO(GPIO_FN_TCLK,		TCLK_MARK),
	PINMUX_GPIO(GPIO_FN_SSI2_SCK,		SSI2_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF3_TXD,		SCIF3_TXD_MARK),
	PINMUX_GPIO(GPIO_FN_HAC_RES,		HAC_RES_MARK),
	PINMUX_GPIO(GPIO_FN_SSI2_WS,		SSI2_WS_MARK),
	PINMUX_GPIO(GPIO_FN_DACK3,		DACK3_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0CMD,		SDIF0CMD_MARK),
	PINMUX_GPIO(GPIO_FN_DACK2,		DACK2_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0CD,		SDIF0CD_MARK),
	PINMUX_GPIO(GPIO_FN_DREQ3,		DREQ3_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0WP,		SDIF0WP_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF0_CTS,		SCIF0_CTS_MARK),
	PINMUX_GPIO(GPIO_FN_DREQ2,		DREQ2_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0CLK,		SDIF0CLK_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF0_RTS,		SCIF0_RTS_MARK),
	PINMUX_GPIO(GPIO_FN_IRL7,		IRL7_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0D3,		SDIF0D3_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF0_SCK,		SCIF0_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_IRL6,		IRL6_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0D2,		SDIF0D2_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF0_RXD,		SCIF0_RXD_MARK),
	PINMUX_GPIO(GPIO_FN_IRL5,		IRL5_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0D1,		SDIF0D1_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF0_TXD,		SCIF0_TXD_MARK),
	PINMUX_GPIO(GPIO_FN_IRL4,		IRL4_MARK),
	PINMUX_GPIO(GPIO_FN_SDIF0D0,		SDIF0D0_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF5_SCK,		SCIF5_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_FRB,		FRB_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF5_RXD,		SCIF5_RXD_MARK),
	PINMUX_GPIO(GPIO_FN_IOIS16,		IOIS16_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF5_TXD,		SCIF5_TXD_MARK),
	PINMUX_GPIO(GPIO_FN_CE2B,		CE2B_MARK),
	PINMUX_GPIO(GPIO_FN_DRAK3,		DRAK3_MARK),
	PINMUX_GPIO(GPIO_FN_CE2A,		CE2A_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF4_SCK,		SCIF4_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_DRAK2,		DRAK2_MARK),
	PINMUX_GPIO(GPIO_FN_SSI3_WS,		SSI3_WS_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF4_RXD,		SCIF4_RXD_MARK),
	PINMUX_GPIO(GPIO_FN_DRAK1,		DRAK1_MARK),
	PINMUX_GPIO(GPIO_FN_SSI3_SDATA,		SSI3_SDATA_MARK),
	PINMUX_GPIO(GPIO_FN_FSTATUS,		FSTATUS_MARK),
	PINMUX_GPIO(GPIO_FN_SCIF4_TXD,		SCIF4_TXD_MARK),
	PINMUX_GPIO(GPIO_FN_DRAK0,		DRAK0_MARK),
	PINMUX_GPIO(GPIO_FN_SSI3_SCK,		SSI3_SCK_MARK),
	PINMUX_GPIO(GPIO_FN_FSE,		FSE_MARK),
};

static struct pinmux_cfg_reg pinmux_config_regs[] = {
	{ PINMUX_CFG_REG("PACR", 0xffcc0000, 16, 2) {
		PA7_FN, PA7_OUT, PA7_IN, PA7_IN_PU,
		PA6_FN, PA6_OUT, PA6_IN, PA6_IN_PU,
		PA5_FN, PA5_OUT, PA5_IN, PA5_IN_PU,
		PA4_FN, PA4_OUT, PA4_IN, PA4_IN_PU,
		PA3_FN, PA3_OUT, PA3_IN, PA3_IN_PU,
		PA2_FN, PA2_OUT, PA2_IN, PA2_IN_PU,
		PA1_FN, PA1_OUT, PA1_IN, PA1_IN_PU,
		PA0_FN, PA0_OUT, PA0_IN, PA0_IN_PU }
	},
	{ PINMUX_CFG_REG("PBCR", 0xffcc0002, 16, 2) {
		PB7_FN, PB7_OUT, PB7_IN, PB7_IN_PU,
		PB6_FN, PB6_OUT, PB6_IN, PB6_IN_PU,
		PB5_FN, PB5_OUT, PB5_IN, PB5_IN_PU,
		PB4_FN, PB4_OUT, PB4_IN, PB4_IN_PU,
		PB3_FN, PB3_OUT, PB3_IN, PB3_IN_PU,
		PB2_FN, PB2_OUT, PB2_IN, PB2_IN_PU,
		PB1_FN, PB1_OUT, PB1_IN, PB1_IN_PU,
		PB0_FN, PB0_OUT, PB0_IN, PB0_IN_PU }
	},
	{ PINMUX_CFG_REG("PCCR", 0xffcc0004, 16, 2) {
		PC7_FN, PC7_OUT, PC7_IN, PC7_IN_PU,
		PC6_FN, PC6_OUT, PC6_IN, PC6_IN_PU,
		PC5_FN, PC5_OUT, PC5_IN, PC5_IN_PU,
		PC4_FN, PC4_OUT, PC4_IN, PC4_IN_PU,
		PC3_FN, PC3_OUT, PC3_IN, PC3_IN_PU,
		PC2_FN, PC2_OUT, PC2_IN, PC2_IN_PU,
		PC1_FN, PC1_OUT, PC1_IN, PC1_IN_PU,
		PC0_FN, PC0_OUT, PC0_IN, PC0_IN_PU }
	},
	{ PINMUX_CFG_REG("PDCR", 0xffcc0006, 16, 2) {
		PD7_FN, PD7_OUT, PD7_IN, PD7_IN_PU,
		PD6_FN, PD6_OUT, PD6_IN, PD6_IN_PU,
		PD5_FN, PD5_OUT, PD5_IN, PD5_IN_PU,
		PD4_FN, PD4_OUT, PD4_IN, PD4_IN_PU,
		PD3_FN, PD3_OUT, PD3_IN, PD3_IN_PU,
		PD2_FN, PD2_OUT, PD2_IN, PD2_IN_PU,
		PD1_FN, PD1_OUT, PD1_IN, PD1_IN_PU,
		PD0_FN, PD0_OUT, PD0_IN, PD0_IN_PU }
	},
	{ PINMUX_CFG_REG("PECR", 0xffcc0008, 16, 2) {
		PE7_FN, PE7_OUT, PE7_IN, PE7_IN_PU,
		PE6_FN, PE6_OUT, PE6_IN, PE6_IN_PU,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0, }
	},
	{ PINMUX_CFG_REG("PFCR", 0xffcc000a, 16, 2) {
		PF7_FN, PF7_OUT, PF7_IN, PF7_IN_PU,
		PF6_FN, PF6_OUT, PF6_IN, PF6_IN_PU,
		PF5_FN, PF5_OUT, PF5_IN, PF5_IN_PU,
		PF4_FN, PF4_OUT, PF4_IN, PF4_IN_PU,
		PF3_FN, PF3_OUT, PF3_IN, PF3_IN_PU,
		PF2_FN, PF2_OUT, PF2_IN, PF2_IN_PU,
		PF1_FN, PF1_OUT, PF1_IN, PF1_IN_PU,
		PF0_FN, PF0_OUT, PF0_IN, PF0_IN_PU }
	},
	{ PINMUX_CFG_REG("PGCR", 0xffcc000c, 16, 2) {
		PG7_FN, PG7_OUT, PG7_IN, PG7_IN_PU,
		PG6_FN, PG6_OUT, PG6_IN, PG6_IN_PU,
		PG5_FN, PG5_OUT, PG5_IN, PG5_IN_PU,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0, }
	},
	{ PINMUX_CFG_REG("PHCR", 0xffcc000e, 16, 2) {
		PH7_FN, PH7_OUT, PH7_IN, PH7_IN_PU,
		PH6_FN, PH6_OUT, PH6_IN, PH6_IN_PU,
		PH5_FN, PH5_OUT, PH5_IN, PH5_IN_PU,
		PH4_FN, PH4_OUT, PH4_IN, PH4_IN_PU,
		PH3_FN, PH3_OUT, PH3_IN, PH3_IN_PU,
		PH2_FN, PH2_OUT, PH2_IN, PH2_IN_PU,
		PH1_FN, PH1_OUT, PH1_IN, PH1_IN_PU,
		PH0_FN, PH0_OUT, PH0_IN, PH0_IN_PU }
	},
	{ PINMUX_CFG_REG("PJCR", 0xffcc0010, 16, 2) {
		PJ7_FN, PJ7_OUT, PJ7_IN, PJ7_IN_PU,
		PJ6_FN, PJ6_OUT, PJ6_IN, PJ6_IN_PU,
		PJ5_FN, PJ5_OUT, PJ5_IN, PJ5_IN_PU,
		PJ4_FN, PJ4_OUT, PJ4_IN, PJ4_IN_PU,
		PJ3_FN, PJ3_OUT, PJ3_IN, PJ3_IN_PU,
		PJ2_FN, PJ2_OUT, PJ2_IN, PJ2_IN_PU,
		PJ1_FN, PJ1_OUT, PJ1_IN, PJ1_IN_PU,
		0, 0, 0, 0, }
	},
	{ PINMUX_CFG_REG("P1MSELR", 0xffcc0080, 16, 1) {
		0, 0,
		P1MSEL14_0, P1MSEL14_1,
		P1MSEL13_0, P1MSEL13_1,
		P1MSEL12_0, P1MSEL12_1,
		P1MSEL11_0, P1MSEL11_1,
		P1MSEL10_0, P1MSEL10_1,
		P1MSEL9_0,  P1MSEL9_1,
		P1MSEL8_0,  P1MSEL8_1,
		P1MSEL7_0,  P1MSEL7_1,
		P1MSEL6_0,  P1MSEL6_1,
		P1MSEL5_0,  P1MSEL5_1,
		P1MSEL4_0,  P1MSEL4_1,
		P1MSEL3_0,  P1MSEL3_1,
		P1MSEL2_0,  P1MSEL2_1,
		P1MSEL1_0,  P1MSEL1_1,
		P1MSEL0_0,  P1MSEL0_1 }
	},
	{ PINMUX_CFG_REG("P2MSELR", 0xffcc0082, 16, 1) {
		P2MSEL15_0, P2MSEL15_1,
		P2MSEL14_0, P2MSEL14_1,
		P2MSEL13_0, P2MSEL13_1,
		P2MSEL12_0, P2MSEL12_1,
		P2MSEL11_0, P2MSEL11_1,
		P2MSEL10_0, P2MSEL10_1,
		P2MSEL9_0,  P2MSEL9_1,
		P2MSEL8_0,  P2MSEL8_1,
		P2MSEL7_0,  P2MSEL7_1,
		P2MSEL6_0,  P2MSEL6_1,
		P2MSEL5_0,  P2MSEL5_1,
		P2MSEL4_0,  P2MSEL4_1,
		P2MSEL3_0,  P2MSEL3_1,
		P2MSEL2_0,  P2MSEL2_1,
		P2MSEL1_0,  P2MSEL1_1,
		P2MSEL0_0,  P2MSEL0_1 }
	},
	{}
};

static struct pinmux_data_reg pinmux_data_regs[] = {
	{ PINMUX_DATA_REG("PADR", 0xffcc0020, 8) {
		PA7_DATA, PA6_DATA, PA5_DATA, PA4_DATA,
		PA3_DATA, PA2_DATA, PA1_DATA, PA0_DATA }
	},
	{ PINMUX_DATA_REG("PBDR", 0xffcc0022, 8) {
		PB7_DATA, PB6_DATA, PB5_DATA, PB4_DATA,
		PB3_DATA, PB2_DATA, PB1_DATA, PB0_DATA }
	},
	{ PINMUX_DATA_REG("PCDR", 0xffcc0024, 8) {
		PC7_DATA, PC6_DATA, PC5_DATA, PC4_DATA,
		PC3_DATA, PC2_DATA, PC1_DATA, PC0_DATA }
	},
	{ PINMUX_DATA_REG("PDDR", 0xffcc0026, 8) {
		PD7_DATA, PD6_DATA, PD5_DATA, PD4_DATA,
		PD3_DATA, PD2_DATA, PD1_DATA, PD0_DATA }
	},
	{ PINMUX_DATA_REG("PEDR", 0xffcc0028, 8) {
		PE7_DATA, PE6_DATA,
		0, 0, 0, 0, 0, 0 }
	},
	{ PINMUX_DATA_REG("PFDR", 0xffcc002a, 8) {
		PF7_DATA, PF6_DATA, PF5_DATA, PF4_DATA,
		PF3_DATA, PF2_DATA, PF1_DATA, PF0_DATA }
	},
	{ PINMUX_DATA_REG("PGDR", 0xffcc002c, 8) {
		PG7_DATA, PG6_DATA, PG5_DATA, 0,
		0, 0, 0, 0 }
	},
	{ PINMUX_DATA_REG("PHDR", 0xffcc002e, 8) {
		PH7_DATA, PH6_DATA, PH5_DATA, PH4_DATA,
		PH3_DATA, PH2_DATA, PH1_DATA, PH0_DATA }
	},
	{ PINMUX_DATA_REG("PJDR", 0xffcc0030, 8) {
		PJ7_DATA, PJ6_DATA, PJ5_DATA, PJ4_DATA,
		PJ3_DATA, PJ2_DATA, PJ1_DATA, 0 }
	},
	{ },
};

static struct pinmux_info sh7786_pinmux_info = {
	.name = "sh7786_pfc",
	.reserved_id = PINMUX_RESERVED,
	.data = { PINMUX_DATA_BEGIN, PINMUX_DATA_END },
	.input = { PINMUX_INPUT_BEGIN, PINMUX_INPUT_END },
	.input_pu = { PINMUX_INPUT_PULLUP_BEGIN, PINMUX_INPUT_PULLUP_END },
	.output = { PINMUX_OUTPUT_BEGIN, PINMUX_OUTPUT_END },
	.mark = { PINMUX_MARK_BEGIN, PINMUX_MARK_END },
	.function = { PINMUX_FUNCTION_BEGIN, PINMUX_FUNCTION_END },

	.first_gpio = GPIO_PA7,
	.last_gpio = GPIO_FN_FSE,

	.gpios = pinmux_gpios,
	.cfg_regs = pinmux_config_regs,
	.data_regs = pinmux_data_regs,

	.gpio_data = pinmux_data,
	.gpio_data_size = ARRAY_SIZE(pinmux_data),
};

static int __init plat_pinmux_setup(void)
{
	return register_pinmux(&sh7786_pinmux_info);
}

arch_initcall(plat_pinmux_setup);
