# Load HTTP archive rule
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Group the sources of the library so that CMake rules have access to it
# all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

# Load external C/C++ build system rules
# http_archive(
#    name = "rules_foreign_cc",
#    strip_prefix = "rules_foreign_cc-master",
#    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/master.zip",
# )
# load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")
#
# # Load default external C/C++ toolchains (cmake, ninja)
# rules_foreign_cc_dependencies()

# Project dependencies
http_archive(
    name = "cpp-httplib",
    build_file = "@//third_party:cpp-httplib.BUILD",
    sha256 = "e18dab82b3b395290514baf3804c7b74892beb654bd8020600a9d9dfdc49c32a",
    strip_prefix = "cpp-httplib-0.5.5",
    url = "https://github.com/yhirose/cpp-httplib/archive/v0.5.5.tar.gz",
)

http_archive(
    name = "cpp-dotenv",
    build_file = "@//third_party:cpp-dotenv.BUILD",
    sha256 = "d29ce2dd7169786f1fc489a075115791cea349df9915137c46b1d441f2e82556",
    strip_prefix = "cpp-dotenv-49f18104290fb860ab5bf0f3f1eacd77c17cf01c",
    url = "https://github.com/adeharo9/cpp-dotenv/archive/49f18104290fb860ab5bf0f3f1eacd77c17cf01c.tar.gz",
)

http_archive(
    name = "spdlog",
    build_file = "@//third_party:spdlog.BUILD",
    sha256 = "b38e0bbef7faac2b82fed550a0c19b0d4e7f6737d5321d4fd8f216b80f8aee8a",
    strip_prefix = "spdlog-1.5.0",
    url = "https://github.com/gabime/spdlog/archive/v1.5.0.tar.gz",
)

http_archive(
    name = "fmtlib",
    build_file = "@//third_party:fmtlib.BUILD",
    sha256 = "1cafc80701b746085dddf41bd9193e6d35089e1c6ec1940e037fcb9c98f62365",
    strip_prefix = "fmt-6.1.2",
    url = "https://github.com/fmtlib/fmt/archive/6.1.2.tar.gz",
)

http_archive(
    name = "json",
    build_file = "@//third_party:json.BUILD",
    sha256 = "249548f4867417d66ae46b338dfe0a2805f3323e81c9e9b83c89f3adbfde6f31",
    strip_prefix = "json-3.7.3",
    url = "https://github.com/nlohmann/json/archive/v3.7.3.tar.gz",
)
