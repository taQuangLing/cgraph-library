add_executable(main main.c)
add_library(cgraph STATIC cgraph/cgraph_queue.c 
			   cgraph/cgraph_constructors.c 
			   cgraph/cgraph_paths.c
			   cgraph/cgraph_color.c
			   cgraph/cgraph_dfs.c
			   cgraph/cgraph_pruferCode.c
			   cgraph/cgraph_MST.c)

add_subdirectory(cgraph/libfdr)
target_link_libraries(main cgraph fdr)
