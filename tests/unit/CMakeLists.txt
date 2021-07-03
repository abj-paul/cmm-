
add_executable(my_run_tests)
target_sources(my_run_tests PRIVATE "./main.cpp"
                                 "./block_separator.cpp"
                                 "./block_identifier.cpp"
                                 "./inlines.cpp")
target_include_directories(my_run_tests PRIVATE "../../src/cmm-lib/include")
target_link_libraries(my_run_tests cmm)
catch_discover_tests(my_run_tests)

