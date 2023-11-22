def accept_marks(fds_marks):
    
    n=int(input("enter total students in a class "))
    print("enter marks of FDS ")
    for i in range(n) :
        x=int(input())
        fds_marks.append(x)

def average(fds_marks):
    n=len(fds_marks)
    total_marks=0
    for i in range(n):
        total_marks=total_marks+fds_marks[i]
    avg=total_marks/n
    print("Avg Mark of FDS test of class is ",avg)

def display(fds_marks):
    for i in range(len(fds_marks)):
        n=len(fds_marks)
        print("marks of Roll no %d is %d "%(i+1,fds_marks[i]))

def higest(fds_marks):   
    max=-1
    for i in range (len(fds_marks)):
        if(max < fds_marks[i]):
            max=fds_marks[i]
    print("higest marks in the class is %d "%max)


def lowest(fds_marks):   
    min=31
    for i in range (len(fds_marks)):
        if(min > fds_marks[i] and fds_marks[i]>0):
            min=fds_marks[i]
    print("lowest marks in the class is %d "%min)



def main():
    fds_marks=[]
    accept_marks(fds_marks)
    display(fds_marks)
    average(fds_marks)
    higest(fds_marks)
    lowest(fds_marks)
    
main()
