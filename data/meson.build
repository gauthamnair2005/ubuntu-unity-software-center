subdir('appdata')
subdir('icons')
subdir('assets')
subdir('sample-data')

compiled_schemas = gnome.compile_schemas()
install_data('org.ubuntuunity.software.gschema.xml',
             install_dir : 'share/glib-2.0/schemas')

if get_option('external_appstream')
  # replace @libexecdir@
  conf_data = configuration_data()
  conf_data.set('libexecdir', join_paths(get_option('prefix'),
                                         get_option('libexecdir')))
  out = configure_file(
    input : 'org.ubuntuunity.software.external-appstream.policy.in.in',
    output : 'org.ubuntuunity.software.external-appstream.policy.in',
    install: false,
    configuration : conf_data,
  )
  i18n.merge_file(
    input : out,
    output : 'org.ubuntuunity.software.external-appstream.policy',
    po_dir: join_paths(meson.source_root(), 'po'),
    install: true,
    install_dir: join_paths(get_option('datadir'), 'polkit-1', 'actions'),
  )
endif
