load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "json",
    hdrs = ["single_include/nlohmann/json.hpp"],
    includes = ["single_include"],
    strip_include_prefix = "single_include/nlohmann",
    visibility = ["//visibility:public"],
)
