
IF(NOT DEPENDENCIES_DIR)
   MESSAGE("no dependencies dir")
ELSE(DEPENDENCIES_DIR)
   MESSAGE("dependencies dir: " ${DEPENDENCIES_DIR})
ENDIF(DEPENDENCIES_DIR)

FIND_PATH(UnitTestPP_INCLUDE_DIR UnitTestpp.h
   "/usr/include"
   "/usr/local/include"
	DOC "The directory where UnitTest++.h resides")

IF(NOT UnitTestPP_INCLUDE_DIR)
   MESSAGE(FAT"The directory where UnitTest++.h resides")
ENDIF(NOT UnitTestPP_INCLUDE_DIR)

IF(UnitTestPP_FOUND)
    SET(UnitTestPP_INCLUDE_DIR "${GLM_INCLUDE_DIR}")

    MESSAGE(STATUS "UnitTestPP_INCLUDE_DIR = ${GLM_INCLUDE_DIR}")
ENDIF(UnitTestPP_FOUND)