def partition(array, low, high):
  pivot = array[high]
  i = low - 1
  for j in range(low, high):
    if array[j] <= pivot:
      i = i + 1
      (array[i], array[j]) = (array[j], array[i])
  (array[i + 1], array[high]) = (array[high], array[i + 1])
  return i + 1

def quickSort(array, low, high):
  if low < high:
    pi = partition(array, low, high)
    quickSort(array, low, pi - 1)
    quickSort(array, pi + 1, high)

n=int(input("Enter no of student - "))
data = []
for i in range(n):
    data.append(float(input("Enter percentage - ")))
print("Unsorted Array : ",data)

size = len(data)

quickSort(data, 0, size - 1)
print('Sorted Array in Ascending Order : ',data)

end=size-1
for i in range(5):
    print("Top ",i+1," scores - ",data[end])
    end -= 1
    

