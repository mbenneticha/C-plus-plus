/*********************************************************************
 * Program: findMode.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7.30.15
 * Description: This function takes an array and the array's size as
                parameters. It then loops through the values in the 
                array and counts how many of each value there are,
                checking for duplicates. These are stored in a vector
                called highFreq. It then determines what the
                largest frequency of any value is and the frequency
                of each value is compared to the largest frequency.
                The values that are equal to the largest frequency
                are pushed into a new vector named repeatVal.
                The vector repeatVal is then sorted into ascending
                order and is used to push one copy of each repeated
                value into the last vector, resultMode by using a loop
                resultMode is then sorted into ascending order and 
                returned from the function.
**********************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************
 *  Declaring of function that returns a vector *
 *            and parameter types               *
 ************************************************/
//FUNCTION
vector<int>findMode(int* , int);


/************************************************
 *        Main function used for testing        *
 *                    purposes.                 *
 ************************************************/

int main(){
    //Declare variables and variable types.
    int arraySize;

    //Determine how large user's array is
    cout << "How many elements in your array?" <<endl;
    cin >> arraySize;

    //Initialize user-defined array for testing purposes.
    int array[arraySize];
    cout << "Enter values for array:" <<endl;
    for (int i=0; i<arraySize; i++){
        cin >> array[i];
     }

     //Print user-defined array values:
     cout << "Your array is: ";
     for (int i=0; i<arraySize; i++){
         cout << array[i] << " ";
     }
     cout <<endl;

     //Use function to find the mode of the user-defined array.
     findMode(array,arraySize);

     return 0;
 }




/************************************************
 *        findMode() function that takes        *
 *          the array and arraySize as          *
 *          parameters. Returns vector          *
 *               containing mode.               *
 ************************************************/

/************************************************
 *        Declaring of vectors, function,       *
 *            and parameter types               *
 ************************************************/
//FUNCTION and FUNCTION PARAMATERS.
vector<int>findMode(int* nums, int size) {
    
//VECTORS
    /********************************************************
    *Declare vector called repeatVal: stores repeated values*
    ********************************************************/
    vector<int> repeatVal;
    
    /********************************************************
    *  Declare vector called highFreq: stores frequency of  *
    *                    repeated #s                        *
    ********************************************************/
    vector<int> highFreq;
    
    /********************************************************
     *  Declare vector called resultMode: that stores the   *
     *  value(s)with highest frequency or the mode values.  *
     *******************************************************/
    vector<int> resultMode;
    
    /********************************************************
     *    Iterate through and determine frequency values.   *
     *******************************************************/
    int counter;
    for (int i = 0; i < size; i++){
        counter = 0;
        for(int j = 0; j < size; j++){
            if (nums[i] == nums[j]){ //then this is a duplicate
                ++counter;
            }
            else if (nums[i] != nums[j]){
                counter = counter;
            }
        }
        //cout << "frequency is " << counter <<endl;
        //push_counter++ into vector called highFreq
        highFreq.push_back(counter);
    }
    
    /********************************************************
     *    Iterate through highFreq and determine highest    *
     *                  frequency value.                    *
     *******************************************************/
    int maxFreq = 0;
    
    for (int i = 0; i < highFreq.at(i); i++){
        vector<int>::iterator iter = max_element(highFreq.begin(), highFreq.end());
        
        //cout << "The highest frequency value in the vector is ";
        //cout << *iter <<endl;
        
        maxFreq = *iter;
    }
    
    /********************************************************
     *            Print out values and vectors:             *
     *            maxFreq value, highFreq vector            *
     *******************************************************/
/************************************************************************
    //cout << "maxFreq is " << maxFreq <<endl;
    
    //print out highFreq vector
    cout << "highFreq contains: ";
    for (vector<int>::iterator it=highFreq.begin(); it!=highFreq.end();++it){
      cout << *it;
    }
    cout << endl;
************************************************************************/
    
    
    /********************************************************
     *    Iterate through array and compare counts for      *
     *        each value to highest frequency value         *
     *******************************************************/
    for (int i = 0; i < size; i++){
        
        //cout <<nums[i] << endl;
        
        counter = 0;
        
        for(int j = 0; j < size; j++){
            
            //cout << nums[j] <<endl;
            
            if (nums[i] == nums[j]){ //then this is a duplicate
                ++counter;
            }
            else if (nums[i] != nums[j]){
                counter = counter;
            }
            
            //cout << "frequency is " << counter <<endl;
            
    /********************************************************
     *      push_back 'counter' into highFreq vector.       *
     *  highFreq will contain frequency that corresponding  *
     *                value appears in array.               *
     *******************************************************/
            highFreq.push_back(counter);
        }
        
     /********************************************************
      *  Compare counts for each value to highest frequency. *
      *       aka. compare highFreq.at(i) to maxFreq         *
      *******************************************************/
        if (highFreq.at(i) == maxFreq){
            
            //cout << nums[i] <<endl;
            
     /********************************************************
      *     push_back array nums[i] into repeatVal vector.   *
      *        repeatVal will contain all mode values.       *
      *******************************************************/
            repeatVal.push_back(nums[i]);
        }
        
        else if (highFreq.at(i) != maxFreq){
            //cout << "NOT EQUAL" <<endl;
        }
        
    }
    
    /********************************************************
     *                 Print out vector:                    *
     *                 repeatVal vector                     *
     *******************************************************/
/***********************************************************************
    cout << "repeatVal contains: ";
    for (vector<int>::iterator it=repeatVal.begin(); it!=repeatVal.end();++it){
        cout << *it;
    }
    cout << endl;
 ***********************************************************************/
    
    
    /********************************************************
     *          Sort vector to ascending order:             *
     *                 repeatVal vector                     *
     *******************************************************/
    sort (repeatVal.begin(), repeatVal.begin()+(repeatVal.size()));
    
    
    /********************************************************
     *                 Print out vector:                    *
     *                 repeatVal vector                     *
     *******************************************************/
/***********************************************************************
    cout << "repeatVal contains: ";
    for (vector<int>::iterator it=repeatVal.begin(); it!=repeatVal.end();++it){
        cout << *it;
    }
    cout << endl;
 ***********************************************************************/

    
    /********************************************************
     *    Iterate through repeatVal and push one copy       *
     *    of each repeating value to resultMode vector.     *
     *******************************************************/
    if (maxFreq == 1) {
        
        for (int i = 0; i < (repeatVal.size()-1); i++){
            resultMode.push_back(repeatVal.at(i+maxFreq));
        }
        
        resultMode.push_back(repeatVal.at(0));
    }
    
    if ((maxFreq > 1)&&(repeatVal.size() > maxFreq)){
        
        for (int i = 0; i < maxFreq; i++){
            resultMode.push_back(repeatVal.at(i*maxFreq));
        }
    }
    
    else if ((maxFreq > 1)&&(repeatVal.size() <= maxFreq)){
        resultMode.push_back(repeatVal.at(0));
    }

    
    /********************************************************
     *          Sort vector to ascending order:             *
     *                 resultMode vector                    *
     *******************************************************/
    sort (resultMode.begin(), resultMode.begin()+(resultMode.size()));
    
    /********************************************************
     *                 Print out vector:                    *
     *                 resultMode vector                    *
     *******************************************************/

    cout << "resultMode contains: " ;
    for (vector<int>::iterator it=resultMode.begin(); it!=resultMode.end();++it){
        cout << *it << " ";
    }
    cout << endl;

    
    
    /********************************************************
     *          Return vector containing mode:              *
     *                 resultMode vector                    *
     *******************************************************/
    return resultMode;
}
