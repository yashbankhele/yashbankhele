

def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
   for i in range(n):
      x = float(input("Enter the  first year percentage of student %d : "%(i+1)))
      A.append(x)
   print("Array accepted successfully\n\n");

def display_array(A): 
   n = len(A)
   if(n == 0) :
      print("\nNo records in the database")
   else :
      print("Array of FE Marks : ",end=' ')
      for i in range(n) :
         print("%.2f  "%A[i],end=' ')
      print("\n");


def Selection_sort(A) :                  
   n = len(A)
   for pos in range(n-1):
      min_ind = pos
      for i in range(pos + 1, n) :
         if(A[i] < A[min_ind]) :
            min_ind = i
      temp = A[pos]
      A[pos] = A[min_ind]
      A[min_ind] = temp

      
def Main() :   
   A = []
   print ("\t3 : Bubble sort Descending order ")
   print("Marks before sorting")
   display_array(A)
   Selection_sort(A)
   print("Marks after sorting")
   display_array(A)
Main()

