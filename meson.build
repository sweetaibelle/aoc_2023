project('aoc', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

sources = files([
	'util/util.cpp',
	'util/util.h',
	'day_1/day_1_p_1.cpp',
	'day_1/day_1_p_2.cpp',
	'day_1/day_1.h',
	'day_2/day_2_p_1.cpp',
	'day_2/day_2_p_2.cpp',
	'day_2/day_2.h',
	'day_3/day_3_p_1.cpp',
	'day_3/day_3_p_2.cpp',
	'day_3/day_3.h',
	'aoc.cpp'
])

exe = executable('aoc', sources,
  install : true)

test('basic', exe)
