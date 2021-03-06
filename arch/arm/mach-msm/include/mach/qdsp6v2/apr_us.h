/* Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __APR_US_H__
#define __APR_US_H__

#include <mach/qdsp6v2/apr.h>

/*                                                                         */
/*                         */

#define USM_SESSION_CMD_RUN				0x00012306
struct usm_stream_cmd_run {
	struct apr_hdr hdr;
	u32            flags;
	u32            msw_ts;
	u32            lsw_ts;
} __packed;

/*                       */
#define USM_STREAM_CMD_OPEN_READ			0x00012309
struct usm_stream_cmd_open_read {
	struct apr_hdr hdr;
	u32            uMode;
	u32            src_endpoint;
	u32            pre_proc_top;
	u32            format;
} __packed;

#define USM_STREAM_CMD_OPEN_WRITE			0x00011271
struct usm_stream_cmd_open_write {
	struct apr_hdr hdr;
	u32            format;
} __packed;


#define USM_STREAM_CMD_CLOSE				0x0001230A

/*                                   */
#define USM_STREAM_CMD_SET_ENC_PARAM			0x0001230B
/*                                   */
#define USM_DATA_CMD_MEDIA_FORMAT_UPDATE		0x00011272

/*                                     */
#define USM_PARAM_ID_ENCDEC_ENC_CFG_BLK			0x0001230D

/*                                            */
#define USM_MAX_PORT_NUMBER 8

/*                                                       */
#define USM_MAX_CFG_DATA_SIZE 100

/*                                                                       */
/*                     */
struct usm_cfg_common {
	u16 ch_cfg;
	u16 bits_per_sample;
	u32 sample_rate;
	u32 dev_id;
	u8 data_map[USM_MAX_PORT_NUMBER];
} __packed;

struct us_encdec_cfg {
	u32 format_id;
	struct usm_cfg_common cfg_common;
	u16 params_size;
	u8 *params;
} __packed;

/*                                */
#define USM_SESSION_CMD_SIGNAL_DETECT_MODE		0x00012719

struct usm_session_cmd_detect_info {
	struct apr_hdr hdr;
	u32 detect_mode;
	u32 skip_interval;
	u32 algorithm_cfg_size;
} __packed;

/*                            */
#define USM_SESSION_EVENT_SIGNAL_DETECT_RESULT		0x00012720

#endif /*              */
