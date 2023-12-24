#include <iostream>

/*
                    Q. reverse pairs            (hard problem)

                explanation -  we will be given an array -  arr[] = {40, 25, 19, 12, 9, 6, 2}

                                we have to find the nmbr of pairs where the left element is greater than twice of the right element
                                        i.e,    i < j    &&    arr[i] > (2 * arr[j])

                                    desired o/p - 15

        Brute force -  we stand at an element of the array and iterate through whole right.
                        then we move to next element and iterate through whole right elements.

    pseudo code
for(i=0->n-1)
{
    for(j=i+1->n)
    {
        if(a[i] > (2 * a[j]))
            cnt++;
    }
}

            TC - O(N^2)                 // nearly
            SC - O(1)                   // not using any extra space


        Optimal sol -  video for solution

    pseudo code
cnt = 0, right = mid + 1
for(i = low->mid)
{
    while(right <= high && a[i] > (2 * a[right]))
        right++;

    cnt = cnt + (right - (mid+1))
}

    
    Actual code

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for(int i = low; i <= mid; i++)
    {
        while(right <= high  &&  arr[i] > (2 * arr[right]))
            right++;

        cnt += (right - (mid + 1)); 
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) 
{
    int cnt = 0;
    if (low >= high) 
        return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int team(vector<int> &skill, int n)
{
    return mergeSort(skill, 0, n-1);
    
}

            TC - O(2NlogN)
            SC - O(N)
*/

int main()
{
    std::cout << "Hello World!\n";
}