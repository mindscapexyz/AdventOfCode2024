#
add_library(day_1 STATIC src/common.cpp)

#
add_executable(day_1_part_1 src/part_1.cpp)
target_link_libraries(day_1_part_1 PRIVATE day_1)

#
add_executable(day_1_part_2 src/part_2.cpp)
target_link_libraries(day_1_part_2 PRIVATE day_1)

#
add_custom_command(TARGET day_1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/lib/day_1/src/input.txt
        ${CMAKE_CURRENT_BINARY_DIR}/input.txt
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/lib/day_1/src/test-input.txt
        ${CMAKE_CURRENT_BINARY_DIR}/test-input.txt
)

#
target_include_directories(day_1
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS day_1
        EXPORT day_1Config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
install(EXPORT day_1Config DESTINATION share/day_1/cmake)
export(TARGETS day_1 FILE day_1Config.cmake)