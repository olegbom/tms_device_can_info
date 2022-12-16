TMS microcontroller device CAN info
-----------------------------------

How to use:
1. Add a repository to a project as a git submodule
2. Add the following line to pre-build steps:
```
"${PROJECT_ROOT}/tms_device_can_info/git_info/gitInfoToProject.bat" "${PROJECT_ROOT}/tms_device_can_info/git_info/include/git_defines.h"
```
3. Add the following line to Predefined Symbols (Pre-define NAME)
```
__PROJECTNAME__=\"${ProjName}\"
```
