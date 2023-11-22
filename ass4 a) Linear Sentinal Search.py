def accept_array(A): 
   n = int(input("Enter the total no. of student : "))
   for i in range(n):
      x = int(input("Enter the  roll no of student : "))
      A.append(x)
   print("Student Info accepted successfully\n\n")
   return n

def display_array(A,n): 
   if(n == 0) :
      print("\nNo records in the database")
   else :
      print("Students  Array : ",end=' ')
      for i in range(n) :
         print("%d  "%A[i],end=' ')
      print("\n")


def Linear_Search(A,n,X) :
   for i in range(n) :
      if(A[i] == X) :
         return i      
   return -1      



def Main() :   
   A = []
   n = accept_array(A)
   display_array(A,n)  
   X = int(input("Enter the roll_no to be searched : "))
   flag  = Linear_Search(A,n,X)
   if(flag == -1) :
      print("\tRoll no to be Searched not Found\n")
   else :
      print("\tRoll no found at location %d"%(flag + 1))

Main()
quit()
