.PHONY: all

G++FLAGS = -Wall

#####################
# add prerequisites #
#####################

# TODO we could save testing time on reduce *.d files.
files_o = $(shell cat dependencies_list)
all: $(files_o);

#############################
# include dependent targets #
#############################

COSMOS_ROOT_PATH := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
dependencies = $(shell find "$(COSMOS_ROOT_PATH)/code/" -name "*.d" | sed 's: :\\ :g')
include $(dependencies)
