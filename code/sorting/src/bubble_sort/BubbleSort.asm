; Author:   SYEED MOHD AMEEN 
; Email:    ameensyeed2@gmail.com


;----------------------------------------------------------------;
;                 BUBBLESORT SORT SUBROUTINE                     ; 
;----------------------------------------------------------------;


;----------------------------------------------------------------;
;                   FUNCTION PARAMETERS                          ;
;----------------------------------------------------------------;   
;   1.  push number of element in array                          ;
;   2.  push base address of Array                               ;
;----------------------------------------------------------------;

BUBBLESORT:
    POP AX                                     ;RET ADDRESS OF SUBROUTINE 
    POP SI                                     ;BASE ADDRESS OF ARRAY 
    POP CX                                     ;COUNTER REGISTER 
    PUSH AX                                    ;RET ADDRESS PUSH INTO STACK

COUNTER_BUBBLESORT:            EQU 0X4000      ;CREATE UPTO EIGHT 16-BIT COUNTER VARIABLE
DPTR_BUBBLESORT:               EQU 0X4010      ;DATA POINTER 


    MOV DS:[COUNTER_BUBBLESORT],CX             ;TEMP STORE UPPER COUNTER 
    MOV DS:[COUNTER_BUBBLESORT+2],CX           ;TEMP STORE LOWER COUNTER 
    MOV DS:[DPTR_BUBBLESORT],SI                ;TEMP STORE BASE ADDRESS OF ARRAY 

REPEAT_BUBBLESORT: 
    MOV AH,[SI]                                ;MOV A[I] INTO AH REG.
    CMP AH,[SI+1]                              ;COMPARE AH WITH A[I+1]
    JC NOSWAP_BUBBLESORT                       ;JUMP IF A[I] < A[I+1]  
        XCHG AH,[SI+1]                         ;SWAP ELEMENTS 
    NOSWAP_BUBBLESORT:                             
    INC SI                                     ;INC ARRAY INDEX REG. (SOURCE INDEX)
    LOOP REPEAT_BUBBLESORT
    
    MOV CX,DS:[COUNTER_BUBBLESORT+2]           ;FETCH COUNTER INTO CX REG.
    MOV SI,DS:[DPTR_BUBBLESORT]                ;MOVE STARTING INDEX INTO SI REG.
    DEC [COUNTER_BUBBLESORT]                   ;DEC UPPER COUNTER 
    JNZ REPEAT_BUBBLESORT                      ;REPEAT UNTIL COUNTER != 0
    RET                                        ;RET SUBROUTINE 



