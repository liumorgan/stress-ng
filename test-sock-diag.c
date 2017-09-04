/*
 * Copyright (C) 2013-2017 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * This code is a complete clean re-write of the stress tool by
 * Colin Ian King <colin.king@canonical.com> and attempts to be
 * backwardly compatible with the stress tool by Amos Waterland
 * <apw@rossby.metr.ou.edu> but has more stress tests and more
 * functionality.
 *
 */
#if defined(__linux__)
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/sock_diag.h>
#include <linux/unix_diag.h>
#endif

#if defined(AF_NETLINK) &&		\
    defined(NETLINK_SOCK_DIAG) &&	\
    defined(SOCK_DIAG_BY_FAMILY) &&	\
    defined(NLM_F_REQUEST) &&		\
    defined(NLM_F_DUMP) &&		\
    defined(UDIAG_SHOW_NAME) &&		\
    defined(UDIAG_SHOW_VFS) &&		\
    defined(UDIAG_SHOW_PEER) &&		\
    defined(UDIAG_SHOW_ICONS) &&	\
    defined(UDIAG_SHOW_RQLEN) &&	\
    defined(UDIAG_SHOW_MEMINFO)

int main(void)
{
	int unix_diag[] = {
		UNIX_DIAG_NAME,
		UNIX_DIAG_PEER
	};

	(void)unix_diag;

	return 0;
}

#else

#error sock_diag not supported

#endif
