/* Keyring key type
 *
 * Copyright (C) 2008 Red Hat, Inc. All Rights Reserved.
 * Written by David Howells (dhowells@redhat.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */

#ifndef _KEYS_KEYRING_TYPE_H
#define _KEYS_KEYRING_TYPE_H

#include <linux/key.h>
#include <linux/rcupdate.h>

/*
                                                                          
             
 */
struct keyring_list {
	struct rcu_head	rcu;		/*                   */
	unsigned short	maxkeys;	/*                             */
	unsigned short	nkeys;		/*                               */
	unsigned short	delkey;		/*                           */
	struct key	*keys[0];
};


#endif /*                      */
