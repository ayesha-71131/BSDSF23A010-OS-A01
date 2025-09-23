# Feature 4
## Position-Independent Code (-fPIC)
-fPIC compiles code that can run at any memory address. It is Required for shared libraries because multiple programs can load the same library at different memory locations.
Without PIC, the library would be locked to one memory address.

## File Size Difference
Static client: ~45KB (contains entire library code copied inside)  
Dynamic client: ~20KB (only has references to external library)
Why: Static linking embeds the library code. Dynamic linking loads it at runtime.

## LD_LIBRARY_PATH
It is Environment variable that tells the dynamic loader where to find shared libraries.
it is needed because Linux's loader searches standard system paths by default. And our custom library isn't in those paths, so we must specify its location.
