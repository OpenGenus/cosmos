; Author:   SYEED MOHD AMEEN 
; Email:    ameensyeed2@gmail.com



;----------------------------------------------------------------;
;                  Binary Searching Subroutine                   ; 
;----------------------------------------------------------------;


;----------------------------------------------------------------;
;                   FUNCTION PARAMETERS                          ;
;----------------------------------------------------------------;   
;   1.  push KEY element                                         ;
;   2.  push no. of element in Array                             ;
;   3.  push base address of Array                               ;
;----------------------------------------------------------------;


BINSEARCH:
    POP AX      ;RETURN ADDRESS OF SUBROUTINE
    POP SI      ;BASE ADDRESS OF ARRAY (DATA STRUCTURE)
    POP CX      ;COUNTER REGISTER 
    POP DX      ;KEY ELEMENT       
    PUSH AX     ;RETURN ADDRESS OF SUBROUTINE 

TEMP_LOW:           EQU 0X1000 
TEMP_HIGH:          EQU 0X1002 
TEMP_COUNTER:       EQU 0X1004
TEMP_MID:           EQU 0X1006

    MOV [TEMP_LOW],0000
    MOV [TEMP_HIGH],CX 

REPEAT_BINSEARCH:
    PUSH [TEMP_LOW]             ;PUSH LOW AND HIGH INDEX TO CALCULATE MID POSITION 
    PUSH [TEMP_HIGH]
    CALL MID_BINSEARCH
    POP [TEMP_MID]
    MOV BX,[TEMP_MID]           ;BX = (MID INDEX POITNTER) FOR INDEX ADDRESSING            

    CMP [SI+BX],DX              ;A[MID] == KEY (SUCESSFUL) ELSE (UNSUCESSFUL)
    JNE NOFOUND_BINSEARCH       
    POP AX 
    ADD [TEMP_MID],SI           ;IF SUCESSFUL RETURN ADDRESS OF KEY ELEMENT 
    PUSH [TEMP_MID]
    PUSH AX 
    RET

NOFOUND_BINSEARCH:
    CMP DX,[SI+BX]
    JNC GREATER_BINSEARCH       ;JUMP (KEY > A[MID]) UPDATE LOW INDEX POINTER 
    MOV [TEMP_HIGH],[TEMP_MID]  ;HIGH = MID - 1
    DEC [TEMP_HIGH]             
    JMP REPEAT_BINSEARCH

GREATER_BINSEARCH:
    MOV [TEMP_LOW],[TEMP_MID]   ;LOW = MID + 1 
    INC [TEMP_LOW]
    JMP REPEAT_BINSEARCH

;-----------------------------------------------;
;          MID CALCULATION SUBROUTINE           ;
;-----------------------------------------------;
MID_BINSEARCH:
    POP AX 
    POP BX                      ;DIVISOR
    POP CX                      ;DIVIDEND 
    PUSH AX            
        
    ADD BX,CX                   ;ADD DIVISIOR AND DIVIDEND  
    MOV AX,BX                   
    IDIV AX,+2                  ;IMMEDATE DIVIDE BY 2 
    POP CX         
    PUSH AX                     ;PUSH MID INDEX 
    PUSH CX 
    RET  
