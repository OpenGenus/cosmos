Module selection_sort

    ' Part of Cosmos by OpenGenus Foundation
    Sub Main()
        ' Example array
        Dim arr() As Integer = {1, 5, 2, 5, 2, 9, 7}

        selection_sort.Sort(arr)

        ' Print the array
        For i = 0 To arr.Length - 1
            Console.Write(arr(i))
            If i < arr.Length - 1 Then
                Console.Write(", ")
            End If
        Next
        Console.ReadKey()
    End Sub

    Sub Sort(arr() As Integer)
        For i = 0 To arr.Length - 1
            Dim min As Integer = i
            For j = i + 1 To arr.Length - 1
                ' Find local min
                If arr(j) < arr(min) Then
                    min = j
                End If
            Next
            selection_sort.Swap(arr, i, min)

        Next
    End Sub

    ' A basic swap method
    Sub Swap(arr() As Integer, j As Integer, i As Integer)
        Dim temp As Integer = arr(i)
        arr(i) = arr(j)
        arr(j) = temp
    End Sub

End Module
