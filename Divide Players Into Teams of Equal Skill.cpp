class Solution {
    public long dividePlayers(int[] skills) {
		Arrays.sort(skills);
		int i = 0;
		int j = skills.length-1;
        int reqSkill = skills[i] + skills[j];
        
        long ans = 0;
		while (i < j) {
			if (skills[i] + skills[j] == reqSkill) {
				ans += skills[i++] * skills[j--];
			}
			else return -1;
		}
        
        return ans;	
    }
}
