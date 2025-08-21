#include <iostream>
#include <vector>
using namespace std;
int trapRainWater(vector<int>& height) {
    int n=height.size();
    int left=0, right=n-1;
    int leftMax=0, rightMax=0;
    int ans=0;

    while (left<right) {
        if (height[left]<height[right]) {
            if (height[left]>=leftMax)
                leftMax=height[left];
            else
                ans+=leftMax-height[left];
            left++;
        } else {
            if (height[right]>=rightMax)
                rightMax=height[right];
            else
                ans+=rightMax-height[right];
            right--;
        }
    }
    return ans;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"Trapped water = "<<trapRainWater(height)<<endl;
    return 0;
}
