include 'premake'
include 'conanbuildinfo.premake.lua'

make_solution 'inter_thread_bench'
    conan_basic_setup()

    removeplatforms {'x32'}

    includedirs {
    	'deps/hayai/src',
    }

    libdirs {
    	'lib/nano/lib'
    }

    filter { 'system:linux' }
        links 'pthread'
    filter {}


    make_console_app('itbench',{
    	'src/**.cpp',
        'src/**.hpp',
        'src/**.h',
    	'premake5.lua'
    })

    use_standard 'c++11'
