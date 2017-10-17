cc_library(
    name = "red_black_tree_c",
    hdrs = ["red_black.h"],
    srcs = ["red_black.c"],
)

cc_test(
    name = "red_black_tree_c_test",
    srcs = ["red_black_test.c"],
    deps = [":red_black_tree_c"],
)

cc_library(
    name = "red_black_tree_cpp",
    srcs = ["red_black_tree.cpp"],
)

cc_test(
    name = "red_black_tree_cpp_test",
    deps = [":red_black_tree_cpp"],
)

java_library(
    name = "RedBlackTreeJava",
    srcs = ["RedBlackTree.java"],
)

java_test(
    name = "RedBlackTreeJavaTest",
    main_class = "RedBlackTree",
    use_testrunner = 0,
    srcs = ["RedBlackTree.java"],
)
