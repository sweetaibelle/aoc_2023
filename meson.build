project('aoc', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

sources = files([
	'util/util.cpp',
	'util/util.h',
	'src/day_1_p_1.cpp',
	'src/day_1_p_2.cpp',
	'src/day_2_p_1.cpp',
	'src/day_2_p_2.cpp',
	'src/day_3_p_1.cpp',
	'src/day_3_p_2.cpp',
	'src/day_4_p_1.cpp',
	'src/day_4_p_2.cpp',
	'src/day_5_p_1.cpp',
	'src/day_5_p_2.cpp',
	'src/day_6_p_1.cpp',
	'src/day_6_p_2.cpp',
	'src/day_7_p_1.cpp',
	'src/day_7_p_2.cpp',
	'src/days.h',
	'src/aoc.cpp'
])

exe = executable('aoc', sources,
  install : true)

test('basic', exe)
