CMAKE_MINIMUM_REQUIRED(VERSION 3.3)

SET(FragmentDemo_SOURCE_FILES
	main.cpp)

SET(FragmentDemo_INCLUDE_DIR
   ${Fragment_INCLUDE_DIR}
)

SET(FragmentDemo_LINK_LIBRARIES 
   Fragment
)

ADD_EXECUTABLE(FragmentDemo 
   ${FragmentDemo_SOURCE_FILES}
)

TARGET_INCLUDE_DIRECTORIES(FragmentDemo PRIVATE 
   ${FragmentDemo_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES(FragmentDemo PUBLIC
   ${FragmentDemo_LINK_LIBRARIES}
)