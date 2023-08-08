int search(vector<int> &nums, int target)
        {
            int n = nums.size();
            int low = 0;
            int high = n - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target)
                    return mid;
               	//Index found
                else if (nums[low] <= nums[mid])
               	//Left half
                {
                    if (nums[low] <= target && target <= nums[mid])
                    {
                    //right half eliminated
                        high = mid - 1;
                    }
                    else
                   	//left half eliminated
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                   	//right half
                    if (nums[mid] <= target && target <= nums[high])
                   	//left half eliminated
                    {
                        low = mid + 1;
                    }
                   	//right half eliminated
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            //Index not found
            return -1;
        }