# Report

## 1. Linking Rule in Makefile
Rule `$(TARGET): $(OBJECTS)` means the final program depends on all object files. When objects are ready the linker combines them into the executable.  
If we link with a library, we add extra flags like `-lm` (this is for math lib). That’s the main difference.

## 2. Git Tags
A git tag marks a commit like a check point or bookmark.  
- Simple tag: simply just points to a commit.  
- Annotated tag: has message + metadata.  

## 3. GitHub Releases
A release makes a tagged version easy to share. we can write notes/changelog there. Attaching binaries (like the client exe here) helps others run it directly without compiling and downloading all source files.
