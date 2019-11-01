cmake_minimum_required(VERSION 3.0)

project(fec LANGUAGES C)

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


install(TARGETS fec DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/fec.h DESTINATION include
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/simd-viterbi.3
        ${CMAKE_CURRENT_SOURCE_DIR}/rs.3
        ${CMAKE_CURRENT_SOURCE_DIR}/dsp.3
    DESTINATION man/man3
)

add_library(ka9q::fec ALIAS fec)
