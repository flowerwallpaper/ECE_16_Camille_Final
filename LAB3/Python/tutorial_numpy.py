import numpy as np

def question_1():
    array1 = np.array([0, 10, 4, 12])
    array1 -= 20
    print(array1)
    # array1 is [-20, -10, -16, -8]
    # it is still one-dimensional. 20 is subtracted from each element

def question_2():
    array2 = np.array([[0, 10, 4, 12],[1, 20, 3, 41]])
    array2_new = array2[0:2, 2:4]
    array2_new.reshape(2, 2)
    print(array2_new)
    # I used slicing and restructuring

def question_3():
    a = np.array([0, 10, 4, 12])
    a = np.hstack((a,a))
    a = np.vstack((a,a))
    a = np.vstack((a,a))
    print(a.shape)
    print(a)

def question_4():
    array41  = np.arange(-3, 16, 6)
    array42 = np.arange(-7, -20, -2)
    print(array41)
    print(array42)

def question_5():
    array5 = np.linspace(0, 100, 49, True)
    array5 = np.array(array5)
    print(array5)
    # This is different from arange() because it can use non-whole numbers to
    # get the values evenly spaced. I would use arange to get numbers a particular distance apart, and 
    # linspace to get numbers evenly apart

def question_6():
    array6 = np.zeros((3, 4))
    array6[0] = [12, 3, 1, 2]
    array6[1, 0] = 0
    array6[:,1] = [3, 0, 2]
    array6[2, :2] = [4, 2]
    array6[2, 2:] = [3, 1]
    array6[:,2] = [1, 1, 3]
    array6[1,3] = 2
    print(array6)

def question_7():
    string7 = "1,2,3,4"
    values = string7.split(',')
    row = np.array([int(val) for val in values])
    rows = []
    for _ in range(100):
        rows.append(row)
    array7 = np.vstack(rows)
    print(array7)

def main():
    question_7()

if __name__ == "__main__":
    main()