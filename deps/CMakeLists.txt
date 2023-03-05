# sigslot
if(NOT TARGET sigslot)
  add_library(sigslot INTERFACE)
  target_include_directories(sigslot SYSTEM INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/sigslot/include)
endif()