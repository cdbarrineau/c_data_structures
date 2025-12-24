# C Data Structures

This repo contains various C data structures.  This is broken up into two projects:
1. A shared object library (data_structures.so)
2. A test driver to test the data structuress.

## Eclipse Settings
There are several settings that must be setup in Eclipse (C/C++).

### In the shared library
1. C/C++ Build -> Settings -> Tool Settings -> Cross GCC Linker -> Shared Library Settings:
    * Check Shared
    * Give it a name in Shared object name without the "lib" prefix (data_structures.so)
2. C/C++ Build -> Settings -> Build Artifact
    * Make sure the Shared Library is selected
3. C/C++ Build -> Settings -> Tool Settings -> Cross GCC Compiler -> Miscellaneous -> Other Flags
    * Add -fPIC
    * This is needed when linking in standard libraries.

### In the main executable
1. C/C++ Build -> Settings -> Tool Settings -> Includes
    * Add from folder pointing to include of other lib.
2. C/C++ Build -> Settings -> Tool Settings -> Cross GCC Linker -> Libraries
    * Add library name (without lib or .so)
        - Ex: data_structures
    * Add library search path all the way to the dir the .so is in:
        - Ex: /home/mark2v/Projects/c_data_structures/data_structures/Debug
3. C/C++ Build -> Settings -> Build Steps
    * Add Post-Build step to copy the .so into the executable's runtime directory:
        - Ex: cp /home/mark2v/Projects/c_data_structures/data_structures/Debug/libdata_structures.so  "${CWD}/data_structures.so"; 

4. Maybe Project References, check the library project.  This might allow for debugging across projects.

### In the Run/Debug/Profiling settings
1. Under Environment, add path to the .so:
    * Key: LD_LIBRARY_PATH
    * Value: /home/mark2v/Projects/c_data_structures/test_data_structures/Debug

### Run from the command line.
1. Add path to .so to LD_LIBRARY_PATH:
    * export LD_LIBRARY_PATH=/home/mark2v/Projects/c_data_structures/test_data_structures/Debug
    