tlsopenssl_sources = [
  'openssl-module.c',
  'gtlsbackend-openssl.c',
  'gtlscertificate-openssl.c',
  'gtlsconnection-openssl.c',
  'gtlsserverconnection-openssl.c',
  'gtlsclientconnection-openssl.c',
  'gtlsdatabase-openssl.c',
  'gtlsfiledatabase-openssl.c',
  'gtlsbio.c',
  'openssl-util.c',
]

platform_deps = [ openssl, gio, glib, gobject ]

tlsopenssl = static_library('tlsopenssl',
                            tlsopenssl_sources,
                            dependencies: [tlsbase_dep, platform_deps],
                            include_directories: config_h_include)

tlsopenssl_dep = declare_dependency(link_with: tlsopenssl,
                                    include_directories: include_directories('.', '../base'),
                                    dependencies: platform_deps)

if gio_supports_plugins
  gioopenssl = shared_module('gioopenssl',
                             tlsopenssl_sources,
                             dependencies: [tlsopenssl_dep],
                             include_directories: config_h_include,
                             install: true,
                             install_dir: gio_module_dir,
                             c_args: [extra_args + common_flags])
endif

install_headers(['glib-openssl-static.h'])
install_data(['glib-openssl-static.vapi'], install_dir: 'share/vala/vapi')

gioopenssl_static = static_library('gioopenssl-static',
                                   tlsopenssl_sources,
                                   dependencies: platform_deps,
                                   objects: tlsbase.extract_all_objects(),
                                   include_directories: [config_h_include, tlsbase_incdir],
                                   install: true,
                                   install_dir: gio_module_dir,
                                   c_args: [extra_args + common_flags] + ['-DG_IO_MODULE_BUILD_STATIC'])

pkg = import('pkgconfig')
pkg.generate(filebase: 'glib-openssl-static',
             name: 'glib-openssl-static',
             version: meson.project_version(),
             description: 'Network-related GIO module for GLib using OpenSSL',
             requires: ['glib-2.0', 'gobject-2.0', 'gio-2.0'],
             libraries: [gioopenssl_static])

# Internal dependency, for tests and benchmarks
tlsopenssl_inc = include_directories([ '.', '..' ])
tlsopenssl_dep = declare_dependency(link_with: tlsopenssl,
                                    include_directories: [ tlsopenssl_inc, config_h_include ],
                                    dependencies: platform_deps)
