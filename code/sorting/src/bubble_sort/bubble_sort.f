!/* Part of Cosmos by OpenGenus Foundation */
!Fortran implementation of bubble sorting algorithm

program bubblesort

parameter (nkt = 8)
real unsorted(nkt)
real sorted(nkt)

data unsorted/144, 89, 4, 9, 95, 12, 86, 25/

  REAL :: temp
  INTEGER :: i, j
  LOGICAL :: swap
 
  DO j = SIZE(unsorted)-1, 1, -1
    swap = .FALSE.
    DO i = 1, j
      IF (unsorted(i) > unsorted(i+1)) THEN
        temp = unsorted(i)
        unsorted(i) = unsorted(i+1)
        unsorted(i+1) = temp
        swap = .TRUE.
        
      END IF
    END DO
    IF (.NOT. swap) EXIT
    sorted(j) = unsorted(j)
  END DO


write(*,10) unsorted

10	FORMAT( F6.2 ) 

end program bubblesort
