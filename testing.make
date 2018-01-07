.PHONY: all

G++FLAGS = -Wall

###########################
# add prerequisites
###########################

# TODO we could save testing time on reduce *.d files.
files_d = $(shell find -name '*.d' | sed 's: :\\ :g')
files_o = $(foreach file,$(files_d),$(subst .d,.o,$(file)))
all: $(files_o);

###########################
# include dependent targets
###########################

dependencies = $(shell find -name '*.d' | sed 's: :\\ :g')
include $(dependencies)
