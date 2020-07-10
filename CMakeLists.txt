cmake_minimum_required(VERSION 3.4.1)

set(TARGET_NAME igeGameAnalytics)
set(LIBS_MODE MD)

project(${TARGET_NAME})

set(PIXYE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

find_package(PythonInterp 3.7 REQUIRED)
find_package(PythonLibs 3.7 REQUIRED)

set(APP_STYLE SHARED)

file(GLOB SRC
    "*.h"    
    "*.cpp"
    "win32/*.h"
    "win32/*.cpp"
)

add_library(${TARGET_NAME} ${APP_STYLE} ${SRC})

set_target_properties(
    ${TARGET_NAME}
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME ${TARGET_NAME}
        LINKER_LANGUAGE C
)

if(WIN32)
    set_target_properties(
        ${TARGET_NAME}
        PROPERTIES
        SUFFIX ".pyd"
    )   
endif()
  
set(INCLUDE_DIR
	${PIXYE_ROOT}/module/igeGameAnalytics
	${PIXYE_ROOT}/module/igeGameAnalytics/win32
	${PYTHON_INCLUDE_DIRS}
)
target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIR})

target_link_libraries(${TARGET_NAME}
    ${PYTHON_LIBRARIES}
)