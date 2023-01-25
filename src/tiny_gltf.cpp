#define TINYGLTF_IMPLEMENTATION

// Since TINYGLTF_IMPLEMENTATION is defined, this compiles all the tinygltf function implementation which are exported by this
// library to be used externally, notably from polykit and open3d. In the context of other libraries that include tiny_gltf.h,
// TINYGLTF_IMPLEMENTATION isn't defined so the header just declares but doesn't define the function implementations.
#include <tiny_gltf.h>
