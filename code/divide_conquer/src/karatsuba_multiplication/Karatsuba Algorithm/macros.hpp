/*!
  \file   macros.hpp
  \brief  Macros para la pantalla
  \author 
  \date   
  \note  http://isthe.com/chongo/tech/comp/ansi_escapes.html
*/


#ifndef _MACROS_HPP_
#define _MACROS_HPP_ //!< Macros for the screen

#include <stdio.h>

#define PLACE(x,y)   printf("\033[%d;%dH",x,y) //!< Place

#define CLEAR_SCREEN        "\33[2J" //!< Clear the screen

#define CLEAR_REST_OF_LINE "\33[K"  //!< Clear until the end of line

#define RESET	    "\e[0m"  //!< Reset
#define INTENSITY   "\e[1m"  //!< Intensity
#define FAINT       "\e[2m"  //!< Barely perceptible
#define ITALIC      "\e[3m"  //!< Italic

#define UNDERLINE   "\e[4m"  //!< subrayado
#define BLINK       "\e[5m"  //!< Blink

#define INVERSE     "\e[7m"  //!< Inverse


//!< regular colors
#define BLACK		"\e[0;30m"  //!< Black
#define RED		    "\e[0;31m"  //!< Red
#define GREEN		"\e[0;32m"  //!< Green
#define YELLOW		"\e[0;33m"  //!< Yellow
#define BLUE		"\e[0;34m"  //!< Blue
#define PURPLE		"\e[0;35m"  //!< Purple
#define CYAN		"\e[0;36m"  //!< Cyan
#define WHITE		"\e[0;37m"  //!< White

//!< bold
#define BBLACK		"\e[1;30m"  //!< Black
#define BRED		"\e[1;31m"  //!< Red
#define BGREEN		"\e[1;32m"  //!< Green
#define BYELLOW		"\e[1;33m"  //!< Yellow
#define BBLUE		"\e[1;34m"  //!< Blue
#define BPURPLE		"\e[1;35m"  //!< Purple
#define BCYAN		"\e[1;36m"  //!< Cyan
#define BWHITE		"\e[1;37m"  //!< White

//!< underline
#define UBLACK		"\e[4;30m"  //!< Black
#define URED		"\e[4;31m"  //!< Red
#define UGREEN		"\e[4;32m"  //!< Green
#define UYELLOW		"\e[4;33m"  //!< Yellow
#define UBLUE		"\e[4;34m"  //!< Blue
#define UPURPLE		"\e[4;35m"  //!< Purple
#define UCYAN		"\e[4;36m"  //!< Cyan
#define UWHITE		"\e[4;37m"  //!< White

//!< background
#define ONBLACK		"\e[40m"	//!< Black
#define ONRED		"\e[41m"    //!< Red
#define ONGREEN		"\e[42m"	//!< Green
#define ONYELLOW	"\e[43m"	//!< Yellow
#define ONBLUE		"\e[44m"    //!< Blue
#define ONPURPLE	"\e[45m"	//!< Purple
#define ONCYAN		"\e[46m"    //!< Cyan
#define ONWHITE		"\e[47m"	//!< White

//!< high intensity
#define IBLACK		"\e[0;90m"      //!< Black
#define IRED		"\e[0;91m"  //!< Red
#define IGREEN		"\e[0;92m"  //!< Green
#define IYELLOW		"\e[0;93m"  //!< Yellow
#define IBLUE		"\e[0;94m"  //!< Blue
#define IPURPLE		"\e[0;95m"  //!< Purple
#define ICYAN		"\e[0;96m"  //!< Cyan
#define IWHITE		"\e[0;97m"  //!< White

//!< bold high intensity
#define BIBLACK		"\e[1;90m"  //!< Black
#define BIRED		"\e[1;91m"  //!< Red
#define BIGREEN		"\e[1;92m"  //!< Green
#define BIYELLOW	"\e[1;93m"	//!< Yellow
#define BIBLUE		"\e[1;94m"  //!< Blue
#define BIPURPLE	"\e[1;95m"	//!< Purple
#define BICYAN		"\e[1;96m"  //!< Cyan
#define BIWHITE		"\e[1;97m"  //!< White

//!< high intensity backgrounds
#define ONIBLACK	"\e[0;100m"	//!< Black
#define ONIRED		"\e[0;101m" //!< Red
#define ONIGREEN	"\e[0;102m"	//!< Green
#define ONIYELLOW	"\e[0;103m"	//!< Yellow
#define ONIBLUE		"\e[0;104m"	//!< Blue
#define ONIPURPLE	"\e[0;105m"	//!< Purple
#define ONICYAN		"\e[0;106m"	//!< Cyan
#define ONIWHITE	"\e[0;107m"	//!< White


#endif  // _MACROS_HPP_

