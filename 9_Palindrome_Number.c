/*
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

bool isPalindrome(int x) {

    // 1. x < 0 : return false
    // 2. 先知道有幾位數 ex 3位數
    // 3. malloc 宣告兩個大小為3的矩陣
    // 4. 得出所有位元的數字 高位到低位 放A array,  低到高位放Aarray
    // 5. 判斷A B 矩陣是否相等
    bool result = true;
    int IntNum = 0;
    int *A_Array, *B_Array;
    int tempX = x;
    int index;

    if (tempX < 0)
        return false;

    while (tempX > 0) {
        IntNum++;
        tempX /= 10;
    }
    // printf("IntNum = %d \r\n", IntNum);

    A_Array = malloc(IntNum * sizeof(int));
    B_Array = malloc(IntNum * sizeof(int));

    tempX = x;

    for (index = 0; index < IntNum; index++) {
        A_Array[index] = tempX % 10;
        B_Array[IntNum - 1 - index] = tempX % 10;
        tempX /= 10;
    }

#if 1
    for (index = 0; index < IntNum; index++) {
        if (A_Array[index] != B_Array[index]) {
            result = false;
            break;
        }

        // printf("index = %d \r\n", index);
        // printf("A_Array = %d \r\n", A_Array[index]);
        // printf("B_Array = %d \r\n", B_Array[index]);
    }
#endif
    return result;
}


//version 2

bool isPalindrome(int x) {

    long inverseNum = 0; //if declar as int, it may occur overflow 
    int TempX = x;

    if (x < 0)
        return false;

    while (TempX > 0) {
        inverseNum = (inverseNum * 10) + (TempX % 10);
        TempX /= 10;
    }

    if (inverseNum == x)
        return true;
    else
        return false;
}