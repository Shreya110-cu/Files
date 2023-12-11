def binary_search(a, b):
    low = 0 
    high = len(a) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if a[mid] < b:
            low = mid + 1
        elif a[mid] > b:
            high = mid - 1
        else:
            return mid
    return -1

def fibonacci_search(a, b):
    fib2 = 0
    fib1 = 1
    fib = fib1 + fib2

    while (fib < len(a)):
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2

    offset = -1

    while (fib > 1):
        i = min(offset + fib2, len(a) - 1)

        if (a[i] < b):
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i

        elif (a[i] > b):
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1

        else:
            return i

    if(fib1 and a[offset + 1] == b):
        return offset + 1

    return -1

phonebook = {}
stud = int(input("Enter how many contacts you want to save: "))
for i in range(0, stud):
    con = input("Enter name= ")
    phn = int(input("Enter 10-digit contact number= "))
    phonebook[con] = phn

print(phonebook)

while True:
    names = list(phonebook.keys())
    names.sort()
    s = {i: phonebook[i] for i in names}

    n = input("Enter contact name that you want to search (or 'exit' to quit): ")

    if n.lower() == 'exit':
        break

    search_choice = input("Choose search method ('binary' or 'fibonacci'): ").lower()

    if search_choice == 'binary':
        res = binary_search(names, n)
    elif search_choice == 'fibonacci':
        res = fibonacci_search(names, n)
    else:
        print("Invalid search method. Please choose 'binary' or 'fibonacci'.")
        continue

    if res == -1:
        choice = input(f"Contact '{n}' not present. Do you want to insert it? (yes/no): ").lower()
        if choice == 'yes':
            phn = int(input(f"Enter 10-digit contact number for '{n}': "))
            phonebook[n] = phn
            print(f"Contact '{n}' with phone number '{phn}' has been added.")
        else:
            print("Contact not inserted.")
    else:
        print(f"Contact '{n}' is present at index {res}")

# This will only be reached when the user types 'exit'
print("Exiting the program.")

