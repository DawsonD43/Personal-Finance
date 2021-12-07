cmake_minimum_required(VERSION 3.20)
project(PersonalFinance)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

set(SOURCE_FILES include/app/App.h src/app/App.cpp src/app/MainWindow.cpp include/app/MainWindow.h include/app/id.h
    include/Account.h include/Expense.h include/formulas.h include/main.h include/Money.h include/Income.h
    src/Account.cpp src/Expense.cpp src/formulas.cpp src/Income.cpp src/Money.cpp
)

add_executable(PersonalFinance ${SOURCE_FILES})

set(wxWidgets_ROOT_DIR ${CMAKE_SOURCE_DIR}\\lib\\wxWidgets-3.1.5)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS gl base core REQUIRED)
include(${wxWidgets_USE_FILE})

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.10.4)

FetchContent_GetProperties(json)
if (NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()
target_link_libraries(PersonalFinance PRIVATE nlohmann_json::nlohmann_json PUBLIC ${wxWidgets_LIBRARIES})
