cc_binary(
    name = "aom",
    srcs = [
        "src/aom.cpp",
    ],
    deps = [
        ":map",
    ],
)

cc_library(
    name = "map",
    hdrs = [
        "src/map.h",
    ],
    srcs = [
        "src/map.cpp",
    ],
    deps = [
      ":maploc",
    ],
)

cc_library(
    name = "maploc",
    hdrs = [
        "src/maploc.h",
    ],
    srcs = [
        "src/maploc.cpp",
    ],
    deps = [],
)
