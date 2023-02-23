import numpy as np
from os import system, remove

def test():
    with open('Testcase.txt', 'w') as file:
        file.write('1000\n')

        array = np.random.randint(999999, size=(1000))

        for value in array:
            file.write('{}\n'.format(value))

        file.close()

    res = system("(./algorithms < Testcase.txt) > out.txt")

    with open('out.txt', 'r') as file:
        content = file.readline()
        content = content.replace(' ', '')
        content = content.replace('[', '')
        content = content.replace(']', '')
        content = content.replace('\n', '')

        content = content.split(',')

        number_array = [ int(number) for number in content ]

        file.close()

    errors = 0

    for i in range(0, len(number_array) - 1):
        if number_array[i] > number_array[i + 1]:
            print("Number {} in position {}  is larger than number {} in the next position".format(number_array[i], i, number_array[i + 1]))
            errors += 1

    remove("out.txt")
    remove("Testcase.txt")

    return errors

def main():
    for i in range(1000):
        errors = test()

        if errors:
            break
    
    if errors:
        print('{} numbers out of place found.'.format(errors))
    else:
        print('Working fine!')

if __name__ == '__main__':
    main()
