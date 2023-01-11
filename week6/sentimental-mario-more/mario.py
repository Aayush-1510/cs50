from cs50 import get_int
def main():
    while(True):
        h = get_int("Enter the height of the pyramid: ")

        if h > 0 and h < 9:
            break
        else:
            print("<ERROR>\n<Please renter>\n")

    for i in range(0,h,1):
        for a in range(h,i+1,-1):
            print(" ", end='')
        for j in range(0,i+1,1):
            print("#",end='')
        print("  ",end='')
        for k in range(0,i+1,1):
            print("#",end='')
        print()

main()


