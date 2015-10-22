include 'premake'

make_solution 'inter_thread_bench'

removeplatforms {'x64','x32'}

nanomsg_root = 'deps/nanomsg-0.6-beta'

function post_build_deploy(what)
	local command
	if os.get() == 'windows' then
		command = [[xcopy "]]..path.getabsolute(what):gsub('/','\\')..[[" "$(TargetDir)" /s /d /y]]
	else
		command = 'cp ' .. path.getabsolute(what) .. [[ "$(TARGETDIR)"]]
	end
	-- print(command)
	postbuildcommands {
		command
	}
end

function os_dependent_links()
	filter { 'system:linux' }
		links 'pthread'
	filter {}
end

includedirs {
	'deps/cppnanomsg',
	'deps/cereal/include',
	'deps/hayai/src',
	'deps/msgpack/include',
	'lib/nano/include',
}

libdirs {
	'lib/nano/lib'
}

make_console_app('itbench',{
	'src/*.*',
	'premake5.lua'	
})
use_standard 'c++11'


newaction {
    trigger = 'nano',
    description = 'build nanomsg',

    -- todo
    execute = function()
    	local OS = os.get()
    	if OS=='macosx' or OS=='linux' then
	    	os.execute(nanomsg_root..'/configure --prefix=/')
	    	os.execute('make install DESTDIR='..path.getabsolute('lib/nano'))
	    end
    end,
}
