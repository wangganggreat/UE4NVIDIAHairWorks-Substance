#
# Build LowLevelDynamics
#

SET(GW_DEPS_ROOT $ENV{GW_DEPS_ROOT})
FIND_PACKAGE(PxShared REQUIRED)

SET(PHYSX_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../)

SET(LL_SOURCE_DIR ${PHYSX_SOURCE_DIR}/LowLevelDynamics/src)

FIND_PACKAGE(nvToolsExt REQUIRED)

SET(LOWLEVELDYNAMICS_PLATFORM_INCLUDES
	${NVTOOLSEXT_INCLUDE_DIRS}
	${PHYSX_SOURCE_DIR}/Common/src/linux
	${PHYSX_SOURCE_DIR}/LowLevel/software/include/linux
	${PHYSX_SOURCE_DIR}/LowLevelDynamics/include/linux
	${PHYSX_SOURCE_DIR}/LowLevel/common/include/pipeline/linux
)

# Use generator expressions to set config specific preprocessor definitions
SET(LOWLEVELDYNAMICS_COMPILE_DEFS
	# Common to all configurations
	${PHYSX_ANDROID_COMPILE_DEFS};PX_PHYSX_STATIC_LIB
)

if(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")
	LIST(APPEND LOWLEVELDYNAMICS_COMPILE_DEFS
		${PHYSX_ANDROID_DEBUG_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=DEBUG;
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "checked")
	LIST(APPEND LOWLEVELDYNAMICS_COMPILE_DEFS
		${PHYSX_ANDROID_CHECKED_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=CHECKED;
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "profile")
	LIST(APPEND LOWLEVELDYNAMICS_COMPILE_DEFS
		${PHYSX_ANDROID_PROFILE_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=PROFILE;
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "release")
	LIST(APPEND LOWLEVELDYNAMICS_COMPILE_DEFS
		${PHYSX_ANDROID_RELEASE_COMPILE_DEFS}
	)
else(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")
	MESSAGE(FATAL_ERROR "Unknown configuration ${CMAKE_BUILD_TYPE}")
endif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")


# include common low level dynamics settings
INCLUDE(../common/LowLevelDynamics.cmake)

# Add linked libraries
TARGET_LINK_LIBRARIES(LowLevelDynamics PUBLIC ${NVTOOLSEXT_LIBRARIES})

# enable -fPIC so we can link static libs with the editor
SET_TARGET_PROPERTIES(LowLevelDynamics PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
