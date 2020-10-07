; Author:   SYEED MOHD AMEEN 
; Email:    ameensyeed2@gmail.com



;----------------------------------------------------------------;
;                    Shortest Job First                          ;
;----------------------------------------------------------------;

;----------------------------------------------------------------;
;                   FUNCTION PARAMETERS                          ;
;----------------------------------------------------------------;   
;   1.  push ready queue base address                            ;
;   2.  push base address of process queue                       ;
;   3.  push no. of process in process queue                     ;
;----------------------------------------------------------------;


SJF:  
    POP AX                               ;POP RET ADDRESS OF SUBROUTINE 
    POP CX                               ;NO. OF PROCESS 
    POP SI                               ;BASE ADDRESS OF PROCESS LENGTH 
    POP DI                               ;READY QUEUE BASE ADDRESS  
    PUSH AX                              ;RETURN ADDRESS OF SUBROUTINE 

; CALL SELECTION SORT TO SORT (PROCESS JOBS) {According to Burst Time}
    PUSH CX 
    PUSH SI 
    CALL SELSORT

; ENTER SHORTED PROCESS INTO (READY QUEUE) 
REPEAT_SJF:
    MOV [DI],[SI]                        ;ENTER PROCESS INTO READY QUEUE 
    INC DI                           
    INC SI               
    LOOP REPEAT_SJF              
    RET                                  ;RETURN SJF SUBROUTINE 


;--------------------------------------;
;           SELECTION SORT             ;     
;--------------------------------------;
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
