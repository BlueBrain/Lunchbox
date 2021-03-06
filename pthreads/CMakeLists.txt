# Copyright (c) 2010 Daniel Pfeifer <daniel@pfeifer-mail.de>
#               2011-2013 Stefan Eilemann <eile@eyescale.ch>

find_package(Threads REQUIRED QUIET)

set(PTHREAD_LIBRARIES pthread)

if(CMAKE_USE_PTHREADS_INIT)
  return()
endif()

IF(NOT WIN32)
  message(FATAL_ERROR "Lunchbox requires pthreads.")
ENDIF(NOT WIN32)

message(STATUS "Pthreads-win32 will be built by Lunchbox.")

set(PTHREADS_NAME pthreads-w32-2011-03-16)
set(PTHREADS_TGZ ${CMAKE_CURRENT_SOURCE_DIR}/pthreads/${PTHREADS_NAME}.tar.gz)
set(PTHREADS_DIR ${CMAKE_BINARY_DIR}/${PTHREADS_NAME})

if(NOT EXISTS ${PTHREADS_DIR})
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf
    ${PTHREADS_TGZ} WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

file(COPY ${PTHREADS_DIR}/pthread.h ${PTHREADS_DIR}/sched.h
     DESTINATION ${PROJECT_BINARY_DIR}/include)

add_definitions(/wd4267) # conversion from 'size_t' to 'long'

add_library(pthread SHARED
  ${PTHREADS_DIR}/attr.c
  ${PTHREADS_DIR}/barrier.c
  ${PTHREADS_DIR}/cancel.c
  ${PTHREADS_DIR}/cleanup.c
  ${PTHREADS_DIR}/condvar.c
  ${PTHREADS_DIR}/create.c
  ${PTHREADS_DIR}/dll.c
  ${PTHREADS_DIR}/exit.c
  ${PTHREADS_DIR}/fork.c
  ${PTHREADS_DIR}/global.c
  ${PTHREADS_DIR}/misc.c
  ${PTHREADS_DIR}/mutex.c
  ${PTHREADS_DIR}/private.c
  ${PTHREADS_DIR}/rwlock.c
  ${PTHREADS_DIR}/sched.c
  ${PTHREADS_DIR}/semaphore.c
  ${PTHREADS_DIR}/spin.c
  ${PTHREADS_DIR}/sync.c
  ${PTHREADS_DIR}/tsd.c
  ${PTHREADS_DIR}/nonportable.c
  )

set_target_properties(pthread PROPERTIES COMPILE_DEFINITIONS PTW32_BUILD=1
  FOLDER "${PROJECT_NAME}")
target_include_directories(pthread PRIVATE ${PTHREADS_DIR})
target_link_libraries(pthread ws2_32)

install(TARGETS pthread
  EXPORT LunchboxTargets
  ARCHIVE DESTINATION lib COMPONENT codev
  LIBRARY DESTINATION lib COMPONENT codev
  RUNTIME DESTINATION bin COMPONENT colib
  )
