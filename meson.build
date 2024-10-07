project('euclid', 'cpp',
  version: '0.1',
  default_options: [
    'warning_level=3', 
    'cpp_std=c++20',
    'buildtype=debug'
  ]
)

cwd = meson.project_source_root()
cxx = meson.get_compiler('cpp')

glfw_lib  = cxx.find_library('glfw3', dirs: [cwd / 'lib/glfw/src'])
glfw_inc  = include_directories('./lib/glfw/include/')

glad_lib  = cxx.find_library('glad', dirs: [cwd / 'lib/glad/'])
glad_inc  = include_directories('./lib/glad/include/')

glm_lib   = cxx.find_library('glm', dirs: [cwd / 'lib/glm/glm'])
glm_inc   = include_directories('./lib/glm/')

logc_lib  = cxx.find_library('logc', dirs: [cwd / 'lib/logc'])
logc_inc  = include_directories('./lib/logc/include')

threads_dep = dependency('threads', required: true)
openmp_dep  = dependency('openmp', required: true)

deps = [
  glfw_lib,
  glad_lib,
  glm_lib,
  logc_lib,
  threads_dep,
  openmp_dep,
]

incs = [
  include_directories('./src/'),
  include_directories('./lib/'),
  glfw_inc,
  glad_inc,
  glm_inc,
  logc_inc,
]

source = files([
  'src/main.cpp',
  'src/platform/glfw/callback.cpp',
  'src/gfx/init.cpp',
  'src/gfx/shader.cpp',
  'src/util/string.cpp'
])

executable('euclid',
  sources: source,
  dependencies: deps,
  include_directories: incs
)
