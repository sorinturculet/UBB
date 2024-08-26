# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\practicoop_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\practicoop_autogen.dir\\ParseCache.txt"
  "practicoop_autogen"
  )
endif()
