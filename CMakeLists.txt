cmake_minimum_required(VERSION 3.10)

project(FuraiEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui")

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
)

set(IMGUI_BACKENDS
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

set(FURAI_GRAPHIC_SOURCE
    include/graphic/GUIComponent.cpp
    include/graphic/graphics.cpp
    include/graphic/shader.cpp
    include/graphic/mesh.cpp
    include/graphic/camera.cpp
    include/graphic/shape/rectangle.cpp
    include/graphic/shape/polygon.cpp
    include/input/input.cpp
    include/core/time.cpp
)

add_executable(app
    src/main.cpp 
    lib/glad/glad.c
    ${FURAI_GRAPHIC_SOURCE}
    ${IMGUI_SOURCES} 
    ${IMGUI_BACKENDS}
)

target_include_directories(app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${FURAI_CORE_SOURCE}
    ${IMGUI_DIR}            
    ${IMGUI_DIR}/backends   
)

target_link_directories(app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

target_link_libraries(app PRIVATE 
    glfw3dll
    opengl32
)

add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3.dll"
    $<TARGET_FILE_DIR:app>

    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/include/graphic/shaders"
    $<TARGET_FILE_DIR:app>/include/graphic/shaders

    COMMENT "Copying glfw3.dll to binary directory..."
)