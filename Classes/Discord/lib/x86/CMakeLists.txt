add_library(dgsdk ${PROJECT_SOURCE_DIR}/Classes/Discord/lib/x86/discord_game_sdk.dll ${PROJECT_SOURCE_DIR}/Classes/Discord/lib/x86/dgsdk.lib)
set_target_properties(dgsdk PROPERTIES LINKER_LANGUAGE CXX)

file(COPY ${PROJECT_SOURCE_DIR}/Classes/Discord/lib/x86/discord_game_sdk.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../../../../bin/OpenGD)
file(COPY ${PROJECT_SOURCE_DIR}/Classes/Discord/lib/x86/dgsdk.lib DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../../../../Classes/Discord/lib/x86)