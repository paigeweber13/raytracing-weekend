##############
# VARIABLES #
##############

# if desired, change the directories
set(sourceDirectory "src/")
set(testDirectory "tests/")

# IMPORTANT: when you add source files, introduce them here

## these files must be in ${sourceDirectory}
# sources
list(APPEND sourcesList "image.cpp")
# headers
list(APPEND sourcesList "image.hpp" "dataStructures/ray.hpp" "dataStructures/vec3.hpp")
# main
set(mainFile "main.cpp")

# these files must be in ${testDirectory}
set(testList "catch-main.cpp" "test-01-image-output.cpp" "test-02-vec3.cpp")

# change these to match your project
project(WeberRaytracing)
set(execName wrtx)

# optionally, change the test suffix or change the name completely
set(testExecName ${execName}-test)


###################
# Everything else #
###################

# you probably won't need to change anything in this section

### Configuration
cmake_minimum_required(VERSION 2.8.12)

add_definitions("-std=c++14")

### Adding dependencies

# find packages
find_package(fmt)

# these will all be used in "target_link_libraries" later
list(APPEND LIBS fmt::fmt)


### Primary executable

# this automatically prepends each source in sourcesList with the sourceDirectory
foreach (sourceFull IN LISTS sourcesList)
    string(PREPEND sourceFull ${sourceDirectory})
    list(APPEND sourcesListFull ${sourceFull})
endforeach ()

# prepend main file with sourceDirectory
string(PREPEND mainFile ${sourceDirectory})

message(STATUS "sources: ${sourcesListFull}")
message(STATUS "main file: ${mainFile}")
add_executable(${execName} ${mainFile} ${sourcesListFull})
target_link_libraries(${execName} ${LIBS})


#### Testing with Catch2
find_package(Catch2)

IF (Catch2_FOUND)
    message(STATUS "Catch2 found, generating test executable")
    # this automatically prepends each test in sourcesList with the sourceDirectory
    foreach (testFull IN LISTS testList)
        string(PREPEND testFull ${testDirectory})
        list(APPEND testListFull ${testFull})
    endforeach ()
    message(STATUS "test files: ${testListFull}")

    # must manually include sourceDirectory or test files won't be able to find source headers
    include_directories(${sourceDirectory})

    add_executable(${testExecName} ${sourcesListFull} ${testListFull})
    target_link_libraries(${testExecName} PUBLIC ${LIBS} PRIVATE
            Catch2::Catch2)
ELSE ()
    message(STATUS "Catch2 not found, not generating test executable")
ENDIF ()
