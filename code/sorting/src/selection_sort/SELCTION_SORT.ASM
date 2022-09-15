; Author:   SYEED MOHD AMEEN 
; Email:    ameensyeed2@gmail.com


;---------------------------------------------------------------;
;                 SELECTION SORT SUBROUTINE                     ;     
;---------------------------------------------------------------;


;----------------------------------------------------------------;
;                   FUNCTION PARAMETERS                          ;
;----------------------------------------------------------------;   
;   1.  push number of element in array                          ;
;   2.  push base address of Array                               ;
;----------------------------------------------------------------;



SELSORT:
    POP AX                               ;POP RET ADDRESS OF SUBROUTINE 
    POP SI                               ;BASE ADDRESS OF ARRAY 
    POP CX                               ;COUNTER REGISTER
    PUSH AX                              ;PUSH RET ADDRESS OF SUBROUTINE 

COUNTER_SELSORT:        EQU 0X4500
DPTR_SELSORT:           EQU 0X4510 


    MOV ES:[COUNTER_SELSORT],CX 
    MOV ES:[COUNTER_SELSORT+2],CX
    MOV ES:[DPTR_SELSORT],SI 
    XOR BX,BX                           ;CLEAR INDEX REGISTER 
    
REPEAT2_SELSORT:
    MOV AH,[SI+BX]                      ;MOVE INITIAL ELEMENT AND COMPARE IN ENTIRE ARRAY 

REPEAT1_SELSORT:
    CMP AH,[SI+BX+1]                    
    JC NOSWAP_SELSORT   
        XCHG AH,[SI+BX+1]       
    NOSWAP_SELSORT:
    INC SI                              ;INCREMENT INDEX REGISTER 
    LOOP REPEAT1_SELSORT                ;REPEAT UNTIL COUNTER != 0 
    MOV SI,ES:[DPTR_SELSORT]            ;MOVE BASE ADDRESS OF ARRAY 
    DEC ES:[COUNTER_SELSORT+2]
    MOV CX,ES:[COUNTER_SELSORT+2]       ;MOVE COUNTER INTO CX REG.
    INC BX                              ;INCREMENT INDEX REGISTER 
    CMP BX,ES:[COUNTER_SELSORT]     
    JNE SKIP_SELSORT                    ;IF BX == ES:[COUNTER_SELSORT] RET SUBROUTINE 
        RET                             ;RETURN SUBROUTINE 
    SKIP_SELSORT:   
    JMP REPEAT2_SELSORT  
