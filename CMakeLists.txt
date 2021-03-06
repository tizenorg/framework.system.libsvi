CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(svi C)

SET(PREFIX ${CMAKE_INSTALL_PREFIX})
SET(EXEC_PREFIX "\${prefix}")
SET(LIBDIR "\${prefix}/lib")
SET(INCLUDEDIR "\${prefix}/include/${PROJECT_NAME}")
SET(VERSION 0.1.4)
SET(TESTSVI svi_test)

SET(SRCS
	svi.c)

SET(TEST_SRCS
	test/svi_test.c)

SET(HEADERS
	SLP_SVI_PG.h
	include/svi.h
	include/svi-ids.h)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

INCLUDE(FindPkgConfig)
pkg_check_modules(pkgs REQUIRED vconf devman_haptic mm-keysound dlog)

FOREACH(flag ${pkgs_CFLAGS})
	SET(EXTRA_CFLAGS "${EXTRA_CFLAGS} ${flag}")
ENDFOREACH(flag)

SET(EXTRA_CFLAGS "${EXTRA_CFLAGS} -fvisibility=hidden")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EXTRA_CFLAGS}")

ADD_DEFINITIONS("-DPREFIX=\"${PREFIX}\"")
ADD_DEFINITIONS("-DFACTORYFS=\"$ENV{FACTORYFS}\"")
ADD_DEFINITIONS("-DDATAFS=\"$ENV{DATADIR}\"")

#ADD_DEFINITIONS("-DENABLE_LED_NOTIFICATION")

ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRCS})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES SOVERSION 0)
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES VERSION ${VERSION})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${pkgs_LDFLAGS})

ADD_EXECUTABLE(${TESTSVI} ${TEST_SRCS})
TARGET_LINK_LIBRARIES(${TESTSVI} ${exppkgs_LDFLAGS})
TARGET_LINK_LIBRARIES(${TESTSVI} ${PROJECT_NAME})

CONFIGURE_FILE(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)
#CONFIGURE_FILE(${PROJECT_NAME}.pc.in ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc @ONLY)

FOREACH(hfile ${HEADERS})
	INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${hfile} DESTINATION include/${PROJECT_NAME})
ENDFOREACH(hfile)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib COMPONENT RuntimeLibraries)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION lib/pkgconfig)
INSTALL(TARGETS ${TESTSVI} DESTINATION bin)
