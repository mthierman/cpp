include(FetchContent)

FetchContent_Declare(
    cmake-modules
    GIT_REPOSITORY "https://github.com/mthierman/cmake-modules.git"
    GIT_TAG "main"
)

FetchContent_MakeAvailable(cmake-modules)
