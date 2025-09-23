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

##Feature 3 Answers
###Makefile Comparison (Part 2 vs Part 3)
-Part 2 (Multi-file):
Single build rule: .c → .o → executable
All .c files compiled together directly
Simple linking: gcc *.o -o executable

-Part 3 (Static Library):
Two-stage build: .c → .o → .a → executable
Separate library and main program compilation
Library creation: ar rcs libmputils.a *.o
Linking with flags: -Llib -lmputils

###ar Command Purpose
ar - Archiver utility that bundles object files into static libraries.
ranlib - Generates an index for faster symbol lookup.

###nm Analysis of client_static
Yes, mystrlen symbols are present in the executable.
This means that Static linking copies the entire library code directly into the final executable. The program becomes self-contained and no external library needed at runtime.
