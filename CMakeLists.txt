cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

project(BF)

set(BF_SOURCES
    src/bloom_filter.cpp
)


# include_directories(bf ${CMAKE_SOURCE_DIR}/include)

add_library(bf 
    # ${BF_INCLUDES}
    ${BF_SOURCES} 
)



add_executable(run
    "src/main.cpp"
)

target_link_libraries(run bf)