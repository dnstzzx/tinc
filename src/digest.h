#ifndef TINC_DIGEST_H
#define TINC_DIGEST_H

/*
    digest.h -- header file digest.c
    Copyright (C) 2007-2016 Guus Sliepen <guus@tinc-vpn.org>

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

#include "system.h"

#define DIGEST_MAX_SIZE 64
#define DIGEST_ALGO_SIZE ((size_t) -1)

#ifndef DISABLE_LEGACY

#ifdef HAVE_OPENSSL
#include "openssl/digest.h"
#elif HAVE_LIBGCRYPT
#include "gcrypt/digest.h"
#else
#error Incorrect cryptographic library, please reconfigure.
#endif

typedef struct digest digest_t;

extern bool digest_open_by_name(digest_t *digest, const char *name, size_t maclength);
extern bool digest_open_by_nid(digest_t *digest, int nid, size_t maclength);
extern digest_t *digest_alloc() __attribute__((__malloc__));
extern void digest_free(digest_t **digest);
extern void digest_close(digest_t *digest);
extern bool digest_create(digest_t *digest, const void *indata, size_t inlen, void *outdata) __attribute__((__warn_unused_result__));
extern bool digest_verify(digest_t *digest, const void *indata, size_t inlen, const void *digestdata) __attribute__((__warn_unused_result__));
extern bool digest_set_key(digest_t *digest, const void *key, size_t len) __attribute__((__warn_unused_result__));
extern int digest_get_nid(const digest_t *digest);
extern size_t digest_keylength(const digest_t *digest);
extern size_t digest_length(const digest_t *digest);
extern bool digest_active(const digest_t *digest);

#endif // DISABLE_LEGACY

#endif // TINC_DIGEST_H
