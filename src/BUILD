load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "@cpp-dotenv//:cpp-dotenv",
        "@cpp-httplib//:cpp-httplib",
        "@json//:json",
        "@spdlog",
    ],
)
