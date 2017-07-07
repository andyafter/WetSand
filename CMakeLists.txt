cmake_minimum_required(VERSION 3.0)

project(physics)

# current opengl version:
# glew-2.0.0, glfw-3.2.1, glm-0.9.8.4
# Set up include and lib paths
set(EXTERNAL "external")
include_directories("${EXTERNAL}")
include_directories("${EXTERNAL}/include")
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(EXTERNAL_LIB_PATH "${EXTERNAL}/lib/osx")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(EXTERNAL_LIB_PATH "${EXTERNAL}/lib/linux" "/usr/lib64")
elseif(WIN32)
    set(EXTERNAL_LIB_PATH "${EXTERNAL}/lib/win")
endif()
link_directories(${EXTERNAL_LIB_PATH})
list(APPEND CMAKE_LIBRARY_PATH "${EXTERNAL_LIB_PATH}")


# Find up and set up core dependency libs
set(GLFW_INCLUDE_DIR "${EXTERNAL}/include")
set(GLFW_LIBRARY_DIR "${CMAKE_LIBRARY_PATH}")
find_library(GLFW_LIBRARY "glfw3" HINTS "${GLFW_LIBRARY_DIR}")

set(GLEW_INCLUDE_DIR "${EXTERNAL}/include")
set(GLEW_LIBRARY_DIR "${CMAKE_LIBRARY_PATH}")
add_definitions(-DGLEW_STATIC)

find_package(GLEW)

find_package(OpenGL)


set(CORELIBS
    "${GLFW_LIBRARY}"
    "${OPENGL_LIBRARY}"
    "${GLEW_LIBRARY}"
    )

  
# Enable C++11 for host code
set(CMAKE_CXX_STANDARD 11)


include_directories(.)
#add_subdirectory(stream_compaction)  # TODO: uncomment if using your stream compaction
add_subdirectory(src)

add_executable(${CMAKE_PROJECT_NAME}
    "src/main.cpp"
    )


target_link_libraries(${CMAKE_PROJECT_NAME}
    #src
    #stream_compaction  # TODO: uncomment if using your stream compaction
    ${CORELIBS}
    )
