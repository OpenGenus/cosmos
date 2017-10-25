Perl Code Style Guidelines

Indentation:
Tabs should be used to indent all code blocks.  Spaces should never be used to indent code blocks.  Mixing tabs and spaces results in misaligned code blocks for other developers who prefer different indentation settings.

if ($total_hours >= 24) {
	return 1;
}
else {
	if ($for_imaging) {
		return 1;
	}
	else {
		return 0;
	}
}

Comments:
There should always be at least 1 space between the # character and the beginning of the comment.  This makes it a little easier to read multi-line comments:
# Comments are your friend, they help

Subroutine & Variable Names:
Single letter variable names should never be used unless for a loop iterator:

Avoid abbreviations:
my $ip_addr; ->No
my $ip_address; ->Yes

Use underscores to separate words:
sub get_computer_name {

All subroutine names should be entirely lowercase:
sub update_request_state {

All class variables defined at the top of a .pm file should be entirely uppercase:
our $SOURCE_CONFIGURATION_DIRECTORY = "$TOOLS/Windows";

POD Documentation
All modules and subroutines must contain a POD documentation block describing what it does. POD is "Plain Old Documentation".

Each subroutine should begin with a POD block with the following format:
#/////////////////////////////////////////////////////////////////////////////
 
=head2 my_subroutine_name
 
 Parameters  : none
 Returns     : boolean
 Description : This is what the subroutine does. These lines must be 80
               characters or less. Additional lines must be indented with
               spaces, not tabs.
 
=cut
 
sub my_subroutine_name {
 
}

Curly Brackets, Parenthesis:
There should be a space between every control/loop keyword and the opening parenthesis:
if ($loop_count <= 10) {

If/Else Statements:
'else' & 'elsif' statements should be on a separate line after the previous closing curly brace:
if ($end_time < $now) {
   ...
}
else {
   ...
}
