cmake_minimum_required(VERSION 3.0)

project(fec
    LANGUAGES C
    VERSION 3.0.1
    DESCRIPTION "fec library from Phil Karn, slightly modified to be build on modern x64 pcs."
    HOMEPAGE_URL "http://www.ka9q.net/code/fec/"
)

add_executable(gen_ccsds gen_ccsds.c init_rs_char.c)
add_custom_command(
    OUTPUT ccsds_tab.c
    DEPENDS gen_ccsds
    COMMAND ./gen_ccsds > ccsds_tab.c
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(gen_ccsds_tal gen_ccsds_tal.c)
add_custom_command(
    OUTPUT ccsds_tal.c
    DEPENDS gen_ccsds_tal
    COMMAND ./gen_ccsds_tal > ccsds_tal.c
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set(LIBFEC_SOURCES
    cpu_mode_port.c
    fec.c
    sim.c
    viterbi27.c
    viterbi27_port.c
    viterbi29.c
    viterbi29_port.c
    viterbi39.c
    viterbi39_port.c
    viterbi615.c
    viterbi615_port.c
    encode_rs_char.c
    encode_rs_int.c
    encode_rs_8.c
    decode_rs_char.c
    decode_rs_int.c
    decode_rs_8.c
    init_rs_char.c
    init_rs_int.c
    encode_rs_ccsds.c
    decode_rs_ccsds.c
    dotprod.c
    dotprod_port.c
    peakval.c
    peakval_port.c
    sumsq.c
    sumsq_port.c
    ccsds_tab.c
    ccsds_tal.c
)

add_library(fec SHARED ${LIBFEC_SOURCES})
target_link_libraries(fec m)

target_include_directories(fec
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/fec.h
    DESTINATION include
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/simd-viterbi.3
        ${CMAKE_CURRENT_SOURCE_DIR}/rs.3
        ${CMAKE_CURRENT_SOURCE_DIR}/dsp.3
    DESTINATION man/man3
)

add_library(fec::fec ALIAS fec)

message(STATUS "created ALIAS target fec::fec")
message(STATUS "Files will be installed to ${CMAKE_INSTALL_PREFIX}")

# Add uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

# export target
install(TARGETS fec EXPORT fecTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(EXPORT fecTargets
    FILE fecTargets.cmake
    NAMESPACE fec::
    DESTINATION lib/cmake/fec
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("fecConfigVersion.cmake"
    VERSION ${fec_VERSION}
    COMPATIBILITY SameMinorVersion
)

install(
    FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/fecConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/fecConfigVersion.cmake"
    DESTINATION lib/cmake/fec
)
