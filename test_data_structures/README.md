# Adding external .so

## In the library project:

* C/C++ Build -> Settings -> Tool Settings -> Cross GCc Linker -> Shared Library Settings: 
    * Check Shared
    * Give it a name in Shared object name (TestSO.so)
    
* C/C++ Build -> Settings -> Build Artifact -> Change to Shared Library

* C/C++ Build -> Settings  -> Tool Settings -> Cross GCC Compiler -> Misc -> Other Flags add "-fPIC"

## In the executable

 * C/C++ Build -> Settings -> Tool Settings -> Includes
        Add from folder pointing to include of other lib.
        
 * C/C++ Build -> Settings -> Tool Settings -> Cross GCC Linker -> Libraries
        Add library name (without lib or .so) so TestSO
        Add library search path all the way to the dir the .so is in.
        
 * C/C++ Build -> Settings -> Build Steps add command to copy the .so without lib on it:
        cp /home/mark2v/Projects/c_demos/DataStructures/Debug/libDataStructures.so "${CWD}/DataStructures.so";

## In the executable run/debug dialog

 * To run, have to modify the LD_LIBRARY_PATH to point to 
        Run configuration -> Environment -> $(project_loc)/Debug or wherever it is.