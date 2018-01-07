#for Cpp
.PHONY: all generate_dependency append_command

all: generate_dependency append_command;

G++FLAGS = -Wall


# warning: the '^^^^^^^^^^' cannot be used in file-name
RECOVER-NAME = $(subst ^^^^^^^^^^,\ ,$(strip $1))
CONVERT-CPP-TO-DEPENDENCY-NAME = $(subst .cpp,.d,$(1))
CONVERT-DEPENDENCY-TO-CPP-NAME = $(subst .d,.cpp,$(1))
FIND-CPP-TESTS = $(shell find -name 'test_*.cpp' | sed 's: :^^^^^^^^^^:g')
FIND-CPP-SOURCES = $(filter-out $(cpp_tests),$(cpp_all_files))
FIND-CPP-TEST-DEPENDENCIES = $(shell find -name 'test_*.d' | sed 's: :^^^^^^^^^^:g')
FIND-CPP-SOURCE-DEPENDENCIES = $(filter-out $(cpp_test_dependencies),$(cpp_all_dependencies))


cpp_all_files = $(shell find -name '*.cpp' | sed 's: :^^^^^^^^^^:g')
cpp_tests = $(call FIND-CPP-TESTS)
cpp_sources = $(call FIND-CPP-SOURCES)


# get dependencies of all files,
# only contains one target:prerequisites in each file.
# e.g. %.o: %.cpp other.cpp\n
GENERATE-SOURCE-DEPENDENCIES = @$(foreach file,$(cpp_sources),echo $(CXX) -MM $(call RECOVER-NAME,$(file)) '>' $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
														 $(CXX) -MM $(call RECOVER-NAME,$(file)) > $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));)
GENERATE-TEST-DEPENDENCIES = @$(foreach file,$(cpp_tests),echo $(CXX) -MM $(call RECOVER-NAME,$(file)) '>' $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
														 $(CXX) -MM $(call RECOVER-NAME,$(file)) > $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));)


##############################################
# add target and prerequisites to dependencies
##############################################

generate_dependency:
	$(call GENERATE-SOURCE-DEPENDENCIES)
	$(call GENERATE-TEST-DEPENDENCIES)
	@echo "generate_dependency done."


cpp_all_dependencies = $(shell find -name '*.d' | sed 's: :^^^^^^^^^^:g')
cpp_test_dependencies = $(call FIND-CPP-TEST-DEPENDENCIES)
cpp_source_dependencies = $(call FIND-CPP-SOURCE-DEPENDENCIES)

APPEND-SOURCE-COMMAND = @$(foreach file,$(cpp_source_dependencies),echo '$(CXX) -c $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' '>>' $(call RECOVER-NAME,$(file));\
															 echo '\t$(CXX) -c $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' >> $(call RECOVER-NAME,$(file));)
APPEND-TEST-COMMAND = @$(foreach file,$(cpp_test_dependencies),echo '$(CXX) -o $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' '>>' $(call RECOVER-NAME,$(file));\
															   echo '\t$(CXX) -o $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' >> $(call RECOVER-NAME,$(file));)


############################
# add command to dependencies
############################

append_command:
	$(call APPEND-SOURCE-COMMAND)
	$(call APPEND-TEST-COMMAND)
	@echo "append_command done."
