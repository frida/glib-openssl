/*
 * gtlsdatabase-openssl.h
 *
 * Copyright (C) 2015 NICE s.r.l.
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, when the library is used with OpenSSL, a special
 * exception applies. Refer to the LICENSE_EXCEPTION file for details.
 *
 * Authors: Ignacio Casal Quinteiro
 */

#ifndef __G_TLS_DATABASE_OPENSSL_H__
#define __G_TLS_DATABASE_OPENSSL_H__

#include <gio/gio.h>

#include "gtlscertificate-openssl.h"

G_BEGIN_DECLS

typedef enum {
  G_TLS_DATABASE_OPENSSL_PINNED_CERTIFICATE = 1,
  G_TLS_DATABASE_OPENSSL_ANCHORED_CERTIFICATE = 2,
} GTlsDatabaseOpensslAssertion;

#define G_TYPE_TLS_DATABASE_OPENSSL            (g_tls_database_openssl_get_type ())
#define G_TLS_DATABASE_OPENSSL(inst)           (G_TYPE_CHECK_INSTANCE_CAST ((inst), G_TYPE_TLS_DATABASE_OPENSSL, GTlsDatabaseOpenssl))
#define G_TLS_DATABASE_OPENSSL_CLASS(class)    (G_TYPE_CHECK_CLASS_CAST ((class), G_TYPE_TLS_DATABASE_OPENSSL, GTlsDatabaseOpensslClass))
#define G_IS_TLS_DATABASE_OPENSSL(inst)        (G_TYPE_CHECK_INSTANCE_TYPE ((inst), G_TYPE_TLS_DATABASE_OPENSSL))
#define G_IS_TLS_DATABASE_OPENSSL_CLASS(class) (G_TYPE_CHECK_CLASS_TYPE ((class), G_TYPE_TLS_DATABASE_OPENSSL))
#define G_TLS_DATABASE_OPENSSL_GET_CLASS(inst) (G_TYPE_INSTANCE_GET_CLASS ((inst), G_TYPE_TLS_DATABASE_OPENSSL, GTlsDatabaseOpensslClass))

typedef struct _GTlsDatabaseOpensslClass GTlsDatabaseOpensslClass;
typedef struct _GTlsDatabaseOpenssl      GTlsDatabaseOpenssl;

struct _GTlsDatabaseOpensslClass
{
  GTlsDatabaseClass parent_class;
};

struct _GTlsDatabaseOpenssl
{
  GTlsDatabase parent_instance;
};

GType          g_tls_database_openssl_get_type              (void) G_GNUC_CONST;

G_END_DECLS

#endif /* __G_TLS_DATABASE_OPENSSL_H___ */
