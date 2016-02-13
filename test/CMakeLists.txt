CMAKE_MINIMUM_REQUIRED(VERSION 3.3)

SET(FragmentTests_SOURCE_FILES
	main.cpp
   TestVector2.cpp)

SET(FragmentTests_INCLUDE_DIR 
   ${UnitTestPP_INCLUDE_DIR}
   ${Fragment_INCLUDE_DIR}
)

SET(FragmentTests_LINK_LIBRARIES 
   ${UnitTestPP_LIBRARY}
   Fragment
)

ADD_EXECUTABLE(FragmentTests 
   ${FragmentTests_SOURCE_FILES}
)

TARGET_INCLUDE_DIRECTORIES(FragmentTests PRIVATE
   ${FragmentTests_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES(FragmentTests PRIVATE
   ${FragmentTests_LINK_LIBRARIES}
)
