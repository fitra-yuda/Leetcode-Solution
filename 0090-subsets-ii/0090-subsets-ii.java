class Solution {
    
    private void construct(int[] nums, List<List<Integer>> subsets, List<Integer> subset, int index) {
        subsets.add(List.copyOf(subset));

        for (int i = index; i < nums.length; i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            subset.add(nums[i]);
            construct(nums, subsets, subset, i + 1); 
            subset.removeLast();
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();

        Arrays.sort(nums);
        this.construct(nums, subsets, subset, 0);

        return subsets;
    }
}