// my first program in C++
#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include <iomanip>




/**
 *Cubic maximum contiguous subsequence sum algorithm.
 */
 double maxSubSum1(int arr[], int size)
 {
    double start;
    double end;

    int maxSum = 0;
    start = (double)clock();
    for( int i = 0; i < size; ++i)
      for(int j = i; j < size; ++j)
      {

        int thisSum = 0;

        for( int k = i; k <= j; ++k)
          thisSum  += arr[k];

        if( thisSum > maxSum)
          maxSum = thisSum;
      }
    std::cout << "Algorithm1: " << maxSum << std::endl;
    end = clock();
   // cout << (start/CLOCKS_PER_SEC) * 1000000 << endl;
    //cout << (end/CLOCKS_PER_SEC) * 1000000 << endl;
    double lapsedtime = ((end-start)/CLOCKS_PER_SEC) * 1000000;
    return lapsedtime;



  }

  /**
  *Quadratic maximum contiguous subsequence sum algorithm.
  */
  double maxSubSum2(int arr[], int size)
  {
    double start;
    double end;

    int maxSum = 0;
    start = (double)clock();
    for( int i = 0; i < size; ++i)
    {
      int thisSum = 0;
      for (int j = 1; j < size; ++j)
      {
        thisSum += arr[j];

        if( thisSum > maxSum)
          maxSum = thisSum;
      }
    }

    std::cout << "Algorithm2: " << maxSum <<std::endl;
    end = (double) clock();
    //cout << (start/CLOCKS_PER_SEC) * 1000000 << endl;
    //cout << (end/CLOCKS_PER_SEC) * 1000000 << endl;
    double lapsedtime = ((end-start)/CLOCKS_PER_SEC) * 1000000;
    return lapsedtime;

  }

  int max3(int a, int b, int c)
  {
    int max = a;
    if(b > max){
      max = b;
    }
    if(c > max){
      max = c;
    }
    return max;

  }
  /**
  * Recursive maximum contiguous subsequence sum algorithm.
  * Finds maximum sum in subarray spanning a[left..right].
  *Does not attempt to maintain actual best sequence.
  */

  int maxSumRec(int arr[], int left, int right)
  {
    if(left == right){ //Base case
      if(arr[left] > 0){
        return arr[left];
      }else{
        return 0;
        }
    }
      int center = (left + right)/2;
      int maxLeftSum = maxSumRec(arr, left, center);
      int maxRightSum = maxSumRec(arr, center + 1, right);

      int maxLeftBorderSum = 0, leftBorderSum = 0;
      for(int i = center; i >= left; --i)
      {
        leftBorderSum += arr[i];
        if( leftBorderSum > maxLeftBorderSum){
          maxLeftBorderSum = leftBorderSum;
          }
      }

      int maxRightBorderSum = 0, rightBorderSum = 0;
      for(int j = center + 1; j <= right; ++j)
      {
        rightBorderSum += arr[j];
        if(rightBorderSum > maxRightBorderSum){
          maxRightBorderSum = rightBorderSum;
          }
      }

      return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);



  }

  /**
  * Driver for divide-and-conquer maximum contiguous
  * subsequence sum algorithm.
  */

  double maxSubSum3(int arr[], int size)
  {
    double start;
    double end;
    start = clock();
    std::cout << "Algorithm3: " <<  maxSumRec(arr, 0, size-1) << std::endl;
    end = clock();
    //cout << (start/CLOCKS_PER_SEC) * 1000000 << endl;
    //cout << (end/CLOCKS_PER_SEC) * 1000000 << endl;
    double lapsedtime = ((end-start)/CLOCKS_PER_SEC) * 1000000;
    return lapsedtime;

  }





  /**
  * Linear-time maximum contiguous subsequence sum algorithm.
  */
  double maxSubSum4(int arr[], int size){
    double start;
    double end;

    int maxSum = 0, thisSum = 0;
    start = clock();
    for( int j = 0; j < size; ++j)
    {
      thisSum += arr[j];

      if(thisSum>maxSum)
        maxSum = thisSum;
      else if(thisSum < 0)
        thisSum = 0;
    }


    std::cout << "Algorithm4: " << maxSum << std::endl;
    end = clock();
    //cout << (start/CLOCKS_PER_SEC) * 1000000 << endl;
    //cout << (end/CLOCKS_PER_SEC) * 1000000 << endl;
    double lapsedtime = ((end-start)/CLOCKS_PER_SEC) * 1000000;
    return lapsedtime;

  }

int main()
{
  int temp[2500];
  int i = 0;

  while(std::cin){
    std::cin >> temp[i];
    ++i;
  }

  double alg1 =  maxSubSum1(temp, i);
  double alg2 =  maxSubSum2(temp, i);
  double alg3 =  maxSubSum3(temp, i);
  double alg4 =  maxSubSum4(temp, i);

  std::cout << "Final Results" << std::endl;
  std::cout << "Algorithm1 : "  << alg1 << " ms" << std::endl;
  std::cout << "Algorithm2 : "  << alg2 << " ms"<< std::endl;
  std::cout << "Algorithm3 : "  << alg3 << " ms"<< std::endl;
  std::cout << "Algorithm4 : "  << alg4 << " ms"<< std::endl;



}