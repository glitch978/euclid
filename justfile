type_default  := 'debug'
cxx_default   := 'clang++'
build_default := 'native'

default: run

build build=build_default:
    meson compile -C build/{{build}}

reconf cxx=cxx_default build=build_default:
    CXX={{cxx}} meson --reconfigure build/{{build_default}}

run: build
    ./build/native/euclid

setup type=type_default cxx=cxx_default:
   CXX={{cxx}} meson setup -Dcpp_thread_count=7 --prefer-static --buildtype {{type}} \
   build

clean build=build_default:
    meson compile -C build/{{build}} --clean

cloc:
    cloc --fullpath --not-match-d="src/ext/" src/
