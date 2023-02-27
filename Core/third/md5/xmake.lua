-- md5
-- 1.0 30774d0c9ecf82fb003fc15978b1f21bc85858f7
-- https://github.com/JieweiWei/md5

target('third.md5', function()
	set_group('source/third')
	set_kind('static')
	add_headerfiles(
		'./md5.h',
		{ install = false }
	)
	add_files(
		'./md5.cpp',
		{}
	)
	on_load(function(target)
		import('custom')
		custom.apply_compiler_option_basic(target)
		custom.apply_compiler_option_warning_disable(target)
	end)
end)
