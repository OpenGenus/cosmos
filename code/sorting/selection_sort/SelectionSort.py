class SelectionSort():
    def sort(self, array):
        for i in range(len(array)-1):
            minimumValue = i
            for j in range(i+1, len(array)):
                if array[j] < array[minimumValue]:
                    minimumValue = j
            temp = array[minimumValue]
            array[minimumValue] = array[i]
            array[i] = temp
        return array

    def printArray(self, array):
        array = self.sort(array)
        for i in range(len(array)):
            print(array[i])
        return array

list = [64, 25, 12, 22, 11]
s = SelectionSort()
s.printArray(list)