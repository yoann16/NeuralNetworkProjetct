set(_BMPEDITOR
  # ${CMAKE_CURRENT_SOURCE_DIR}/Registry/AssetRegistry.h
  # ${CMAKE_CURRENT_SOURCE_DIR}/Registry/AssetEngine.h
)

set(_MLP
  # ${CMAKE_CURRENT_SOURCE_DIR}/Security/Checksum.h
  # ${CMAKE_CURRENT_SOURCE_DIR}/Security/ProtectionPolicy.h
  # ${CMAKE_CURRENT_SOURCE_DIR}/Security/ProtectionPolicy.cpp
)

set(_TEST
  # ${CMAKE_CURRENT_SOURCE_DIR}/Test.h
  # ${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp
)

add_executable(${CMAKE_PROJECT_NAME}
  main.cpp
  ${_BMPEDITOR}
  ${_MLP}
  ${_TEST}
)

source_group(TREE ${CMAKE_SOURCE_DIR} FILES
  ${_BMPEDITOR}
  ${_MLP}
  ${_TEST}
)

#Set the program's working directory to
#CMAKE_SOURCE_DIR when Visual Studio launches the program
# With: program working directory at \bor-3m-gamegear-s1p2-06
# Without: the program's working directory at \bor-3m-gamegear-s1p2-06\build-vs2022\CPU_Engine
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  )

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)


# target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
#   bcrypt
# )

# add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#   # COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/Assets"
#   # "$<TARGET_FILE_DIR:Asset_Engine>/Assets"
#   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:MLP>
#   $<TARGET_FILE_DIR:MLP>
#   COMMAND_EXPAND_LISTS
#   )
