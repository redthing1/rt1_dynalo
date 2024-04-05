project('dynalo', 'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_std=c++17',
  ]
)

cxx = meson.get_compiler('cpp')
host_os = host_machine.system()

dynalo_include = include_directories('include')

# system libraries
dynalo_deps = []

if host_os == 'linux'
  libdl_dep = cxx.find_library('dl', required : true)
  dynalo_deps += libdl_dep
elif host_os == 'windows'
  kernel32_dep = cxx.find_library('kernel32', required : true)
  dynalo_deps += kernel32_dep
elif host_os == 'darwin'
  # dyld should already be linked on macOS
else
  error('Unsupported OS: ' + host_os)
endif

dynalo_dep = declare_dependency(
  include_directories : dynalo_include,
  dependencies : dynalo_deps,
)

subdir('test')
