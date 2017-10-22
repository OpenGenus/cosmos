'Binary Search Algorithm in VB
'can be implement in any vb program..

Private Sub Command1_Click()
    
    Dim testArr(10) As Integer, ret As String
    For i = 0 To 10
        testArr(i) = i
    Next
    ret = CStr(arrayFind(testArr, Trim(Text1.Text)))
    Label1.Caption = "Element found? " & ret
End Sub

Function arrayFind(theArray() As Integer, target As Integer) As Boolean
    Dim low As Integer
    low = 0
    Dim high As Integer
    high = UBound(theArray)
    Dim i As Integer
    Dim result As Boolean
    
    Do While low <= high
        i = (low + high) / 2
        If target = theArray(i) Then
            arrayFind = True
            Exit Do
        ElseIf target < theArray(i) Then
            high = (i - 1)
        Else
            low = (i + 1)
        End If
    Loop
    
    If Not arrayFind Then
        arrayFind = False
    End If
End Function

Private Sub Form_Load()
    Text1.Text = 7
    Label1.Caption = "Binary Search Test"
End Sub 
