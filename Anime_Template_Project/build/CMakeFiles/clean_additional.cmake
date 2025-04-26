# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AnimeComponents_autogen"
  "CMakeFiles/AnimeComponents_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/AnimeComponents_autogen.dir/ParseCache.txt"
  )
endif()
