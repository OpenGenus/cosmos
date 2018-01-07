.PHONY: all

G++FLAGS = -Wall

###########################
# add prerequisites
###########################

# TODO we could save testing time on reduce *.d files.
files_o = $(shell cat dependencies_list)
all: $(files_o);

###########################
# include dependent targets
###########################

dependencies = $(shell find *.d | sed 's: :\\ :g')
include $(dependencies)
