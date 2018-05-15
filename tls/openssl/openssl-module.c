/*
 * gtlsbio.c
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

#include "config.h"

#include <gio/gio.h>

#include "gtlsbackend-openssl.h"


void
g_io_module_load (GIOModule *module)
{
  g_tls_backend_openssl_register (module);
}

void
g_io_module_unload (GIOModule *module)
{
}

gchar **
g_io_module_query (void)
{
  return g_strsplit (G_TLS_BACKEND_EXTENSION_POINT_NAME, "!", -1);
}
