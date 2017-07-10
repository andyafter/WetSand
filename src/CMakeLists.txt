set(SOURCE_FILES
  "main.cpp"
  "sceneStructs.h"
  "utilities.cpp"
  "utilities.h"
  "scene.cpp"
  "scene.h"
  )


#[[cuda_add_library(src
    ${SOURCE_FILES}
    OPTIONS -arch=sm_20
    )
]]
