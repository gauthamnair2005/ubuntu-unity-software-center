python_mod = import('python')
python3 = python_mod.find_installation('python3')

sample_sources = files(
  'app-info/xmls/org.unitysoftware.sample.xml',
  'appdata/org.unitysoftware.sample.appdata.xml',
  'metainfo/org.unitysoftware.sample.appdata.xml',
  'applications/org.unitysoftware.sample.desktop',
  'README.md',
)

custom_target(
  'install-sample-data',
  input: sample_sources,
  output: 'sample-data.stamp',
  command: [
    python3,
    join_paths(meson.project_source_root(), 'contrib', 'install-sample-data.py'),
    meson.current_source_dir(),
    meson.build_root(),
    '@OUTPUT@',
  ],
  depend_files: [
    join_paths(meson.project_source_root(), 'data', 'icons', 'hicolor', 'scalable', 'org.ubuntuunity.software.svg'),
    join_paths(meson.project_source_root(), 'data', 'icons', 'hicolor', 'symbolic', 'org.ubuntuunity.software-symbolic.svg'),
    join_paths(meson.project_source_root(), 'data', 'icons', 'hicolor', 'scalable', 'software-installed-symbolic.svg'),
  ],
  build_by_default: false,
  build_always_stale: true,
)
