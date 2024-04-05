dynalo_test_shlib_sources = [
    './shared.cpp',
]
dynalo_test_shlib_include = include_directories('.')
dynalo_test_shlib_lflags = []

dynalo_test_shlib_lib = shared_library('dynalo_test_shlib',
  dynalo_test_shlib_sources,
  include_directories : dynalo_test_shlib_include,
  dependencies : [dynalo_dep],
  link_args : dynalo_test_shlib_lflags,
)

dynalo_test_loader_sources = [
  './loader.cpp',
]
dynalo_test_loader_include = include_directories('.')
dynalo_test_loader_lflags = []

dynalo_test_loader_exe = executable('dynalo_test_loader',
  dynalo_test_loader_sources,
  include_directories : dynalo_test_loader_include,
  link_with : [dynalo_test_shlib_lib],
  dependencies : [dynalo_dep],
  link_args : dynalo_test_loader_lflags,
)
