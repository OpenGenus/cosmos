#for Cpp
.PHONY: all generate_dependency append_command

all: generate_dependency append_command;
G++FLAGS = -Wall -std=c++11


# warning: the '^^^^^^^^^^' cannot be used in file-name
COSMOS_ROOT_PATH := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
RECOVER-NAME = $(subst ^^^^^^^^^^,\ ,$(strip $1))
RECOVER-NAME2 = $(subst ^^^^^^^^^^,\\\ ,$(strip $1))
CONVERT-CPP-TO-DEPENDENCY-NAME = $(subst .cpp,.d,$(1))
CONVERT-DEPENDENCY-TO-CPP-NAME = $(subst .d,.cpp,$(1))
FIND-CPP-TESTS = $(shell find "$(COSMOS_ROOT_PATH)/code/" -name "test_*.cpp" | sed 's: :^^^^^^^^^^:g')
FIND-CPP-SOURCES = $(filter-out $(cpp_tests),$(cpp_all_files))
FIND-CPP-TEST-DEPENDENCIES = $(shell find "$(COSMOS_ROOT_PATH)/code/" -name "test_*.d" | sed 's: :^^^^^^^^^^:g')
FIND-CPP-SOURCE-DEPENDENCIES = $(filter-out $(cpp_test_dependencies),$(cpp_all_dependencies))


cpp_all_files = $(shell find "$(COSMOS_ROOT_PATH)/code/" -name "*.cpp" | sed 's: :^^^^^^^^^^:g')
cpp_tests = $(call FIND-CPP-TESTS)
cpp_sources = $(call FIND-CPP-SOURCES)

# the var i is used for prevent if has same target name
ins = $(eval i=$(shell echo $$(($(i)+1))))

# get dependencies of all files,
# only contains one target:prerequisites in each file.
# e.g. %.o: %.cpp other.cpp\n

# generate dependencies
# detail
# GENERATE-SOURCE-DEPENDENCIES = @$(foreach file,$(cpp_sources),echo printf $(i) '>' $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 															  printf '${i}' > $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 															  echo $(CXX) -MM $(call RECOVER-NAME,$(file)) '>>' $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 														 	  $(CXX) -MM $(call RECOVER-NAME,$(file)) >> $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 															  echo "cat $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)))";\
# 															  cat $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 															  printf $(i)$(notdir $(call RECOVER-NAME2,$(subst .cpp,.o,$(file))))" " >> dependencies_list;\
# 															  echo $(call ins);\
# 														   	  echo "";)

# brief
GENERATE-SOURCE-DEPENDENCIES = @$(foreach file,$(cpp_sources),printf '${i}' > $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
														 	  $(CXX) -MM $(call RECOVER-NAME,$(file)) >> $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
															  printf $(i)$(notdir $(call RECOVER-NAME2,$(subst .cpp,.o,$(file))))" " >> dependencies_list;\
															  $(call ins))


# append gcc script
# detail
# GENERATE-TEST-DEPENDENCIES = @$(foreach file,$(cpp_tests),echo printf $(i) '>' $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 														  printf '${i}' > $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 														  echo $(CXX) -MM $(call RECOVER-NAME,$(file)) '>>' $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 														  $(CXX) -MM $(call RECOVER-NAME,$(file)) >> $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 														  echo "cat $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)))";\
# 														  cat $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
# 														  printf $(i)$(notdir $(call RECOVER-NAME2,$(subst .cpp,.o,$(file))))" " >> dependencies_list;\
# 														  echo $(call ins);\
# 													   	  echo "";)

# brief
GENERATE-TEST-DEPENDENCIES = @$(foreach file,$(cpp_tests),printf '${i}' > $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
														  $(CXX) -MM $(call RECOVER-NAME,$(file)) >> $(call RECOVER-NAME,$(call CONVERT-CPP-TO-DEPENDENCY-NAME,$(file)));\
														  printf $(i)$(notdir $(call RECOVER-NAME2,$(subst .cpp,.o,$(file))))" " >> dependencies_list;\
														  $(call ins))


##############################################
# add target and prerequisites to dependencies
##############################################

generate_dependency:
	@echo "\n###############################\n\
		   \r# generating dependencies ... #\n\
		   \r###############################"
# clear list
	@printf "" > dependencies_list
	$(call GENERATE-SOURCE-DEPENDENCIES)
	$(call GENERATE-TEST-DEPENDENCIES)


cpp_all_dependencies = $(shell find "$(COSMOS_ROOT_PATH)/code/" -name "*.d" | sed 's: :^^^^^^^^^^:g')
cpp_test_dependencies = $(call FIND-CPP-TEST-DEPENDENCIES)
cpp_source_dependencies = $(call FIND-CPP-SOURCE-DEPENDENCIES)

# detail
# APPEND-SOURCE-COMMAND = @$(foreach file,$(cpp_source_dependencies),echo '$(CXX) -c $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' '>>' $(call RECOVER-NAME,$(file));\
# 															 	   echo '\t$(CXX) -c $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' >> $(call RECOVER-NAME,$(file));\
# 															 	   echo "cat $(call RECOVER-NAME,$(file))";\
# 															 	   cat $(call RECOVER-NAME,$(file));\
# 															   	   echo "";)
# APPEND-TEST-COMMAND = @$(foreach file,$(cpp_test_dependencies),echo '$(CXX) -o $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' '>>' $(call RECOVER-NAME,$(file));\
# 															   echo '\t$(CXX) -o $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' >> $(call RECOVER-NAME,$(file));\
# 															   echo "cat $(call RECOVER-NAME,$(file))";\
# 															   cat $(call RECOVER-NAME,$(file));\
# 															   echo "";)

# brief
APPEND-SOURCE-COMMAND = @$(foreach file,$(cpp_source_dependencies),echo '\t$(CXX) -c $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' >> $(call RECOVER-NAME,$(file));)
APPEND-TEST-COMMAND = @$(foreach file,$(cpp_test_dependencies),echo '\t$(CXX) -o $(G++FLAGS) $(call RECOVER-NAME,$(call CONVERT-DEPENDENCY-TO-CPP-NAME,$(file)))' >> $(call RECOVER-NAME,$(file));)


############################
# add command to dependencies
############################

append_command:
	@echo "\n##################################\n\
		   \r# generating_compile command ... #\n\
		   \r##################################"
	$(call APPEND-SOURCE-COMMAND)
	$(call APPEND-TEST-COMMAND)

