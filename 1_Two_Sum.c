#define HASH_SIZE 10000
#define OUTPUT_SIZE 2
//要把key 數值mapping 壓縮到 hashtable裝起來

typedef struct HASH_TABLE
{
    int key;
    int value;
    bool exist;

}st_HASH_TABLE;

static int hash(int);

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int index = 0;
    int* outputResult = malloc(OUTPUT_SIZE * sizeof(int));
    st_HASH_TABLE* pHashTable = malloc(HASH_SIZE * sizeof(st_HASH_TABLE));

    *returnSize = OUTPUT_SIZE;
    memset(outputResult, 0, OUTPUT_SIZE * sizeof(int));
    memset(pHashTable, 0, HASH_SIZE * sizeof(st_HASH_TABLE));

    //index = 0 ;
    //put nums[0] to pHashTable[]
    pHashTable[hash(nums[0])].key = nums[0];
    pHashTable[hash(nums[0])].value = 0;
    pHashTable[hash(nums[0])].exist = true;
    for (index = 1; index < numsSize ; index ++)
    {
        //check pHashTable(target - nums[index] ) exist  => check key wheather statisfy target - nums
        if( (pHashTable[hash(target-nums[index])].exist) && 
            (pHashTable[hash(target-nums[index])].key == (target - nums[index])) )
        {
            outputResult[0] = index;
            outputResult[1] = pHashTable[hash(target-nums[index])].value;
        }
        else
        {
            pHashTable[hash(nums[index])].key = nums[index];
            pHashTable[hash(nums[index])].value = index;
            pHashTable[hash(nums[index])].exist = true;
        }

    }
    return outputResult;
}


int hash(int k)
{
    return (abs(k) % HASH_SIZE) ;
}






/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
//注意這個大小也是很重要
#define HASHTABLE_SIZE  10001 


typedef struct hashtable
{
    int key;
    int value;
    int exist;
} HASHTABLE;

static int hashfunc(int key);

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i ;
    int* outputArray = malloc(2 * sizeof(int));
    HASHTABLE* _hashTable = malloc(HASHTABLE_SIZE * sizeof(HASHTABLE));

    memset (_hashTable, 0, HASHTABLE_SIZE * sizeof(HASHTABLE));
    
    memset (outputArray, 0, 2 * sizeof(int));

    *returnSize = 2;

    //i=0 先放入hashtable
    //key = nums[0]
    //value = i = 0 value就是Index
    _hashTable[ hashfunc(nums[0])].exist = 1;
    _hashTable[ hashfunc(nums[0])].key = nums[0]; //hashfunc(nums[0]);
    _hashTable[ hashfunc(nums[0])].value = 0;
    for(i=1 ; i<numsSize ; i ++)
    {
        printf("i=%d \n", i);
        //檢查target - nums[i] 是否存在於hashtable內?
        //並檢查hashtable內的key 是不是真的跟nums相加 等於target
        if( (_hashTable[hashfunc(target - nums[i])].exist == 1) && ((target - nums[i])==_hashTable[hashfunc(target - nums[i])].key)  )
        {
            //輸出i , 及_hashTable[hashfunc(target - nums[i])].value
            outputArray[0] = i;
            outputArray[1] = _hashTable[hashfunc(target - nums[i])].value;
            //printf("outputArray[0]=%d \n", outputArray[0]);
            //printf("outputArray[1]=%d \n", outputArray[1]);
            //printf("nums[outputArray[0]]=%d \n", nums[outputArray[0]]);
            //printf("nums[outputArray[1]]=%d \n", nums[outputArray[1]]);
            break;
        }
        else
        {
            //把i放到hashtable 
            _hashTable[ hashfunc(nums[i])].exist = 1;
            _hashTable[ hashfunc(nums[i])].key = nums[i]; //hashfunc(nums[i]);
            _hashTable[ hashfunc(nums[i])].value = i;
        }


    }


    return outputArray;
}

int hashfunc(int key)
{
    return abs(key) % HASHTABLE_SIZE;
}

*/

/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int i, j = 0;
    int* output_result;
    *returnSize = 2;
    //printf("numsSize = %d \n", numsSize);
    output_result = malloc(2 * sizeof(int));
    memset(output_result, 0, 2 * sizeof(int));
    
    for(i = 0 ; i < numsSize ; i++)
    {
        for(j = i+1 ; j < numsSize ; j++)
        {
            if (nums[j] == (target - nums[i]) )
            {
                output_result[0] = i;
                output_result[1] = j;
                break;
            }
        }
        
    }

    //printf("i=%d,j=%d",output_result[0],output_result[1]);
    return output_result;
    
}
*/



/*
為什麼格子編號不夠？

hash function 是一種「壓縮」：它把很大的 key 範圍映射到很小的格子數量。例如 table size 是 10001 時，下面這些數字都會落在格子 1：

1, 10002, 20003, -10000, ...

所以你看到格子 1 有人，只知道「有某個數字 ≡ 1 (mod 10001)」，不知道是哪一個。

另外，格子編號也不一定是 key 的計算結果。碰撞時會用線性探測往下找空格，key 可能被放在 hash(key)+1、hash(key)+2... 的位置。也就是說，即使你知道 hash(need)，真正的資料也可能不在那一格。

所以查找的正確流程是：

用 key 算出起始格子。
如果格子有人，比對格子裡的 key 是不是你要的。
不是就繼續探測，直到找到相同的 key 或遇到空格。

這就是為什麼格子裡要存原始 key
*/