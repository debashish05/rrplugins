cmake_minimum_required(VERSION 2.8)
project(plugins)

#Give all plugins access to headers in the following folders
include_directories(
	${TLP_ROOT}/source
	${TLP_ROOT}/wrappers/C
    ${THIRD_PARTY_INSTALL_FOLDER}/include
)

OPTION (TLP_BUILD_STAT_PLUGIN	                "Build the STAT (statistics) Plugin"	        ON)

if(${TLP_BUILD_STAT_PLUGIN} STREQUAL ON)
    add_subdirectory(statistics)
endif()

