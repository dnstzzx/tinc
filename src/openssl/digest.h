#ifndef TINC_OPENSSL_DIGEST_H
#define TINC_OPENSSL_DIGEST_H

/*
    digest.h -- header file digest.c
    Copyright (C) 2013 Guus Sliepen <guus@tinc-vpn.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <openssl/evp.h>
#include <openssl/hmac.h>

struct digest {
	const EVP_MD *digest;
	HMAC_CTX *hmac_ctx;
	EVP_MD_CTX *md_ctx;
	size_t maclength;
};

#endif
